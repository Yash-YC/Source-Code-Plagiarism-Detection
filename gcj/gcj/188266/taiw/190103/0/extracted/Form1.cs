using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace GoogleSolve.SOLVE2009.Round1.Solve3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            this.txtOutput.Text = solveText1(this.txtInput.Text);
        }
        private string solveText1(string input)
        {
            string[] buffer = input.Split();
            int c = int.Parse(buffer[0]);
            int k = int.Parse(buffer[1]);
            return calc(c, k).ToString("0.0000000");
        }

        private decimal calc(int c, int k)
        {
            int remain = c - k;
            decimal allPos = fact(c) / (fact(k) * fact(c - k));
            decimal remainPos = fact(remain) / (fact(1) * fact(remain - 1));
            if (allPos - remainPos == 0)
            {
                return 1;
            }
            decimal need = remain / ((allPos - remainPos) / allPos);
            return 1 + need;
        }

        private Int64 fact(int input)
        {
            Int64 returnV = 1;
            for (int i = 2; i <= input; i++)
            {
                returnV *= i;
            }
            return returnV;
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