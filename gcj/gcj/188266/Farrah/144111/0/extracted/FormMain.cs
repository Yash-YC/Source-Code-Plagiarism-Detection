using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Collections;
namespace CodeJamProject2
{
    public partial class FormMain : Form
    {
        public FormMain()
        {
            InitializeComponent();
        }
        public const int South = 0;
        public const int East = 1;
        public const int West = 2;
        public const int North = 3;
        public int N;
        public int M;
        public struct sSingleCross
        {
            public long s;
            public long w;
            public long t;
        };
        public long[,] lValue;
        public sSingleCross[,] Cross;
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
                //put the codes here
                int iCaseNum = int.Parse(reader.ReadLine());
                for (int i = 0; i < iCaseNum; i++)
                {
                    string sLine = reader.ReadLine();
                    string[] sNumbers = sLine.Split(new char[] { ' ' });
                    N = int.Parse(sNumbers[0]);
                    M = int.Parse(sNumbers[1]);
                    lValue = new long[2*N , 2*M];
                    Cross = new sSingleCross[N, M];
                    for (int j = 0; j < N; j++)
                    {
                        sLine = reader.ReadLine();
                        sNumbers = sLine.Split(new char[] { ' ' });
                        for (int k = 0; k < M; k++)
                        {
                            Cross[j, k] = new sSingleCross();
                            Cross[j,k].s = int.Parse(sNumbers[3 * k]);
                            Cross[j, k].w = int.Parse(sNumbers[3 * k + 1]);
                            Cross[j, k].t = int.Parse(sNumbers[3 * k + 2]);
                        }
                        
                    }
                    for (int j = 0; j < 2*N ; j++)
                    {
                        for (int k = 0; k <2* M; k++)
                        {
                            lValue[j, k] = long.MaxValue;
                        }
                    }
                    lValue[0, 0] = 0; 
                    Update(0, 0);
                    sRetStr += "Case #" + (i + 1).ToString() + ": " + (lValue[2 * N - 1, 2 * M - 1]+2).ToString() + Environment.NewLine;
                }

            }


            return sRetStr;
        }
        private void Update(int i, int j)
        {

            long lOri = lValue[i, j];
            long lNew;
            long[] dValues = new long[4];
            if (i != 0 || j != 0)
            {
                if (i == 0)
                    dValues[West] = long.MaxValue;
                else
                {
                    dValues[West] = (lValue[i - 1, j] == long.MaxValue) ? long.MaxValue :( lValue[i - 1, j] + getCrossTime(i - 1, j, East));

                }

                if (j == 0)
                    dValues[South] = long.MaxValue;
                else
                {
                    dValues[South] = (lValue[i, j - 1] == long.MaxValue) ? long.MaxValue :( lValue[i, j - 1] + getCrossTime(i, j - 1, North));
                }
                if (i == 2 * N - 1)
                    dValues[East] = long.MaxValue;
                else
                    dValues[East] = (lValue[i + 1, j] == long.MaxValue) ? long.MaxValue:( lValue[i + 1, j] + getCrossTime(i + 1, j, West));
                if (j == 2 * M - 1)
                    dValues[North] = long.MaxValue;
                else
                    dValues[North] = (lValue[i, j + 1]==long.MaxValue)?long.MaxValue:(lValue[i, j + 1] + getCrossTime(i, j + 1, South));
                lNew = dValues[0];
                for (int l = 0; l < 4; l++)
                    if (dValues[l] < lNew)
                        lNew = dValues[l];

                if (lNew < lOri)
                    lValue[i, j] = lNew;
                if (lNew < lOri )
                {
                    if (i != 0)
                        Update(i - 1, j);
                    if (j != 0)
                        Update(i, j - 1);
                    if (i != 2 * N - 1)
                        Update(i + 1, j);
                    if (j != 2 * M - 1)
                        Update(i, j + 1);
                }
            }
            else
            {

                if (i != 2 * N - 1)
                    Update(i + 1, j);
                if (j != 2 * M - 1)
                    Update(i, j + 1);
            }
        }
        private long getCrossTime(int i, int j, int direct)
        {

            if (direct == West)
            {
                if (j % 2 == 0) return 2;
                long iNow = (lValue[i, j] - Cross[i/2, j /2].t) % (Cross[i /2, j /2].s + Cross[i /2, j /2].w);
                if (iNow >= Cross[i /2, j /2].s) return 1;
                else return Cross[i /2, j /2].s - iNow + 1;
            }
            else if (direct == East)
            {
                if (j % 2 == 1) return 2;
                long iNow = (lValue[i, j] - Cross[i / 2, j / 2].t) % (Cross[i / 2, j / 2].s + Cross[i / 2, j / 2].w);
                if (iNow >= Cross[i / 2, j / 2].s) return 1;
                else return Cross[i / 2, j / 2].s - iNow + 1;
            }
            else if (direct == South)
            {
                if (i % 2 == 0) return 2;
                long iNow = (lValue[i, j] - Cross[i / 2, j / 2].t) % (Cross[i / 2, j / 2].s + Cross[i / 2, j / 2].w);
                if (iNow < Cross[i / 2, j / 2].s) return 1;
                else return Cross[i / 2, j / 2].s + Cross[i / 2, j / 2].w - iNow + 1;
            }
            else //if (direct == North)
            {
                if (i % 2 == 1) return 2;
                long iNow = (lValue[i, j] - Cross[i / 2, j / 2].t) % (Cross[i / 2, j / 2].s + Cross[i / 2, j / 2].w);
                if (iNow < Cross[i / 2, j / 2].s) return 1;
                else return Cross[i / 2, j / 2].s + Cross[i / 2, j / 2].w - iNow + 1;
            }

        }

    }   
}
