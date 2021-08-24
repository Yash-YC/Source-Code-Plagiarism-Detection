using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace GoogleSolve.SOLVE2009.Round1.Solve1
{
    public partial class Form1 : Form
    {
        Dictionary<int, List<string>> loop = new Dictionary<int, List<string>>();
        List<string> happy10 = new List<string>();
        public Form1()
        {
            InitializeComponent();
            List<string> test = new List<string>();
            test.Add("2");
            test.Add("11");
            test.Add("12");
            test.Add("22");
            loop.Add(3, test);
            test = new List<string>();
            test.Add("4");
            test.Add("31");
            test.Add("20");
            test.Add("23");
            test.Add("33");
            loop.Add(5, test);
            test = new List<string>();
            test.Add("32");
            test.Add("21");
            test.Add("5");
            test.Add("41");
            test.Add("25");
            test.Add("45");
            test.Add("105");
            test.Add("42");
            loop.Add(6, test);
            test = new List<string>();
            test.Add("2");
            test.Add("4");
            test.Add("22");
            test.Add("11");
            test.Add("34");
            test.Add("13");
            test.Add("23");
            test.Add("16");
            test.Add("52");
            test.Add("41");
            test.Add("23");
            test.Add("63");
            test.Add("44");
            loop.Add(7, test);
            test = new List<string>();
            test.Add("4");
            test.Add("20");
            test.Add("5");
            test.Add("31");
            test.Add("12");
            test.Add("32");
            test.Add("24");
            test.Add("64");
            loop.Add(8, test);
            test = new List<string>();
            test.Add("55");
            test.Add("58");
            test.Add("108");
            test.Add("72");
            test.Add("45");
            test.Add("75");
            test.Add("82");
            loop.Add(9, test);
            happy10.AddRange(new string[] { "1", "7", "10", "13", "19", "23", "28", "31", "32", "44", "49", "68", "70", "79", "82", "86", "91", "94", "97", "100", "103", "109", "129", "130", "133", "139", "167", "176", "188", "190", "192", "193", "203", "208", "219", "226", "230", "236", "239", "262", "263", "280", "291", "293", "301", "302", "310", "313", "319", "320", "326", "329", "331", "338", "356", "362", "365", "367", "368", "376", "379", "383", "386", "391", "392", "397", "404", "409", "440", "446", "464", "469", "478", "487", "490", "496" });
        }
        private void button1_Click(object sender, EventArgs e)
        {
            this.txtOutput.Text = solveText1(this.txtInput.Text);
        }
        private string solveText1(string input)
        {
            string[] buffer = input.Split();
            List<int> baseN = new List<int>();
            foreach (string item in buffer)
            {
                baseN.Add(int.Parse(item));
            }
            return solveData(baseN).ToString();
        }

        private int solveData(List<int> input)
        {
            int retVal = 2;
            bool isSolve = false;
            do
            {
                isSolve = true;
                foreach (int inC in input)
                {
                    if (!(inC == 2 || inC == 4))
                    {
                        int run = retVal;
                        bool isH = false;
                        while (run > 1)
                        {
                            string data = convertBase(run, inC);
                            if (inC != 10)
                            {
                                if (loop[inC].Contains(data))
                                {
                                    break;
                                }
                            }
                            else
                            {
                                if (happy10.Contains(data))
                                {
                                    isH = true;
                                    break;
                                }
                                else if (run < 500)
                                {
                                    isH = false;
                                    break;
                                }
                            }
                            int buf = calc(data);
                            if (buf == run)
                            {
                                break;
                            }
                            run = buf;
                            if (run == 1)
                            {
                                isH = true;
                            }
                        }
                        if (!isH)
                        {
                            retVal++;
                            isSolve = false;
                            break;
                        }
                    }
                    //if (!ca(retVal, intC))
                    //{
                    //    retVal++;
                    //    break;
                    //}
                }
            }
            while (!isSolve);
            return retVal;
        }

        private string convertBase(int input, int baseN)
        {
            string retVal = "";
            int run = input;
            do
            {
                int m = run % baseN;
                retVal = m.ToString() + retVal;
                run = (int)((run - m) / baseN);
            } while (run > 0);
            return retVal;
        }

        private int calc(string checkVal)
        {
            int nSum = 0;
            for (int i = 0; i < checkVal.Length; i++)
            {
                int b = int.Parse(checkVal.Substring(i, 1));
                nSum += b * b;
            }
            return nSum;
        }

        private string solveText(string input)
        {
            string[] lines = input.Replace("\r\n", "\n").Split('\n');
            string[] buffer = lines[0].Split();
            //int wordLength = int.Parse(buffer[0]);
            //int wordCount = int.Parse(buffer[1]);
            //int testCase = int.Parse(buffer[2]);
            //List<string> words = new List<string>();
            //for (int i = 1; i <= wordCount; i++)
            //{
            //    words.Add(lines[i]);
            //}
            //StringBuilder oSB = new StringBuilder();
            //for (int i = 1; i <= testCase; i++)
            //{
            //    oSB.AppendFormat("Case #{0}: {1}", i, solveData(words, createPattern(lines[i + wordCount])));
            //    oSB.AppendLine();
            //}
            //return oSB.ToString();
            return input;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                System.IO.StreamReader oSR = System.IO.File.OpenText(openFileDialog1.FileName);
                System.IO.StreamWriter oSW = System.IO.File.CreateText(openFileDialog1.FileName.Replace(".in", ".out"));
                int caseCount = int.Parse(oSR.ReadLine());
                string input = "";
                for (int i = 1; i <= caseCount; i++)
                {
                    input = oSR.ReadLine();
                    oSW.WriteLine("Case #{0}: {1}", i, solveText1(input));
                }
                oSR.Close();
                oSW.Close();
            }
        }

    }
}