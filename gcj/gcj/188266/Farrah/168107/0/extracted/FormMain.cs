using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Collections;
namespace CodeJamProject1
{
    public partial class FormMain : Form
    {
        public FormMain()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string sResult;
            OpenFileDialog ofd = new OpenFileDialog();
            if (ofd.ShowDialog() == DialogResult.OK)
            {
                sResult = Calculate(ofd.FileName);
                SaveFileDialog sfd = new SaveFileDialog();

                using (StreamWriter writer = new StreamWriter(ofd.FileName.Replace(".in", ".out")))
                {
                    writer.Write(sResult);
                }
                MessageBox.Show("Finish");
            }
        }
        private string Calculate(string sFileName)
        {
            string sRetStr = string.Empty;
            using (StreamReader reader = new StreamReader(sFileName))
            {

                int iCaseNum = int.Parse(reader.ReadLine());
                for (int i = 0; i < iCaseNum; i++)
                {
                    string sLine = reader.ReadLine();
                    string[] sBases = sLine.Split(new char[] { ' ' });
                    int[] iBases = new int[sBases.Length];
                    for (int j = 0; j < sBases.Length; j++)
                    {
                        iBases[j] = int.Parse(sBases[j]);
                    }
                    int N = 2;
                    while (true)
                    {
                        bool bHappy = true;
                        foreach (int iBase in iBases)
                        {
                            if (!IsHappyValue(N, iBase))
                                bHappy = false;
                        }
                        if (bHappy == true) break;
                        N++;
                    }
                    sRetStr += "Case #" + (i + 1).ToString() + ": " + N.ToString() + Environment.NewLine;
                }


            }


            return sRetStr;
        }
        private string CalcInBase(long iNum, int iBase)
        {
            string sRet = "";
            while (iNum > 0)
            {
                sRet = iNum % iBase + sRet;
                iNum /= iBase;
            }
            return sRet;
        }
        private bool IsHappyValue(int N, int iBase)
        {
            List<long> numArray = new List<long>();

            long newN = N;
            while (true)
            {
                string sNew = CalcInBase(newN, iBase);
                int[] iNumbers = new int[sNew.Length];
                newN = 0;
                for (int i = 0; i < sNew.Length; i++)
                {
                    iNumbers[i] = int.Parse(sNew.Substring(i,1));
                    newN += iNumbers[i] * iNumbers[i];
                }
                
                if(newN == 1)
                    return true;
                if(numArray.Contains(newN))
                    return false;
                numArray.Add(newN);
            }
        }
    }
}
