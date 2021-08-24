using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace GCJ
{
    public partial class GCJ : Form
    {
        const int base10 = 10;
        char[] cHexa = new char[] { 'A', 'B', 'C', 'D', 'E', 'F' };
        int[] iHexaNumeric = new int[] { 10, 11, 12, 13, 14, 15 };
        int[] iHexaIndices = new int[] { 0, 1, 2, 3, 4, 5 };
        const int asciiDiff = 48;
        
        public GCJ()
        {
            InitializeComponent();
        }

        private void BrowseButton_Click(object sender, EventArgs e)
        {
            OpenFileDialog objFileDialog = new OpenFileDialog();
            objFileDialog.Filter = "Input Files|*.in";

            if (objFileDialog.ShowDialog() == DialogResult.OK)
            {
                FileNameTextBox.Text = objFileDialog.FileName;
            }
        }

        private void ExecuteButton_Click(object sender, EventArgs e)
        {
#if (DEBUG)
            OutputTextBox.Text = string.Empty;
#endif

            if ((FileNameTextBox.Text == null) || (FileNameTextBox.Text == string.Empty))
            {
                return;
            }

            StreamReader objInputFile = new StreamReader(FileNameTextBox.Text);
            StreamWriter objOutputFile = new StreamWriter(Path.GetDirectoryName(FileNameTextBox.Text) + Path.DirectorySeparatorChar + Path.GetFileNameWithoutExtension(FileNameTextBox.Text) + ".out");

            try
            {
                // Getting the number of test cases
                string input = objInputFile.ReadLine().Trim();
                int numTestCases = int.Parse(input);

                for (int i = 1; i <= numTestCases; i++)
                {
                    input = objInputFile.ReadLine().Trim();
                    string[] inputs = input.Split();

                    int[] bases = new int[inputs.Length];
                    for (int j = 0; j < inputs.Length; j++)
                    {
                        bases[j] = int.Parse(inputs[j]);
                    }

                    int num = 2;

                    while (true)
                    {
                        int j = 0;
                        for (; j < bases.Length; j++)
                        {
                            if (IsHappyAtBase(num, bases[j]) == false)
                            {
                                num++;
                                break;
                            }
                        }

                        if (j == bases.Length)
                            break;
                    }

                    
                    string output = "Case #" + i + ": " + num;
                    objOutputFile.WriteLine(output);

#if (DEBUG)
                    OutputTextBox.Text += (output + Environment.NewLine);
#endif
                }

                MessageBox.Show("Output file generated successfully!", "Success");
            }
            finally
            {
                if (objInputFile != null)
                {
                    objInputFile.Close();
                }

                if (objOutputFile != null)
                {
                    objOutputFile.Close();
                }
            }
        }

        private bool IsHappyAtBase(int num, int Base)
        {
            string strNum = DecimalToBase(num, Base);

            List<int> pastNumbers = new List<int>();
            int sumOfSquares = 0;
            while (true)
            {
                sumOfSquares = 0;
                for (int i = 0; i < strNum.Length; i++)
                {
                    int digit = (int)(strNum[i] - '0');
                    sumOfSquares += (int)Math.Pow(digit, 2);
                }

                if (pastNumbers.Contains(sumOfSquares) == true)
                {
                    break;
                }

                pastNumbers.Add(sumOfSquares);
                strNum = DecimalToBase(sumOfSquares, Base);
            }

            if (sumOfSquares == 1)
            {
                return true;
            }
            return false;
        }

        string DecimalToBase(int iDec, int numbase)
        {
            string strBin = "";
            int[] result = new int[32];
            int MaxBit = 32;
            for (; iDec > 0; iDec /= numbase)
            {
                int rem = iDec % numbase;
                result[--MaxBit] = rem;
            }
            for (int i = 0; i < result.Length; i++)
                if ((int)result.GetValue(i) >= base10)
                    strBin += cHexa[(int)result.GetValue(i) % base10];
                else
                    strBin += result.GetValue(i);
            strBin = strBin.TrimStart(new char[] { '0' });
            return strBin;
        }

        int BaseToDecimal(string sBase, int numbase)
        {
            int dec = 0;
            int b;
            int iProduct = 1;
            string sHexa = "";
            if (numbase > base10)
                for (int i = 0; i < cHexa.Length; i++)
                    sHexa += cHexa.GetValue(i).ToString();
            for (int i = sBase.Length - 1; i >= 0; i--, iProduct *= numbase)
            {
                string sValue = sBase[i].ToString();
                if (sValue.IndexOfAny(cHexa) >= 0)
                    b = iHexaNumeric[sHexa.IndexOf(sBase[i])];
                else
                    b = (int)sBase[i] - asciiDiff;
                dec += (b * iProduct);
            }
            return dec;
        }


    }
}
