using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam2009
{
    public class Problem1A
    {

        public Problem1A(String inputFile, String outputFile)
        {
            StreamReader sr = new StreamReader(inputFile);
            StreamWriter sw = new StreamWriter(outputFile);
            //Parse the input
            int total = int.Parse(sr.ReadLine());
            List<List<int>> cases = new List<List<int>>();
            for (int i = 0; i < total; i++)
            {
                List<int> current = sr.ReadLine().Split(" ".ToCharArray()).Select(a => int.Parse(a)).ToList();
                cases.Add(current);
            }
            //Calculate the result

            List<int> result = new List<int>();
            for (int i = 0; i < total; i++)
            {
                int j = 2;
                bool amHappy = false;
                while (!amHappy)
                {
                    amHappy = true;
                    for (int k = 0; k < cases[i].Count; k++)
                    {
                        List<int> test = new List<int>();
                        amHappy &= Happy(ref test, j, cases[i][k]);
                    }
                    j++;
                }
                result.Add(j - 1);
            }

            //Create the output
            for (int i = 0; i < total; i++)
            {
                sw.WriteLine("Case #" + (i + 1).ToString() + ": " + result[i].ToString());
            }
            sr.Close();
            sw.Flush();
            sw.Close();
        }

        bool Happy(ref List<int> checkedOut, int value, int toBase)
        {
            if (value == 1)
                return true;
            else if (checkedOut.Contains(value))
                return false;
            else
            {
                List<int> CurrentList = new List<int>();
                ConvertToBase(ref CurrentList, value, toBase);
                int newValue = CurrentList.Select(a => a * a).Sum();
                checkedOut.Add(value);
                return Happy(ref checkedOut, newValue, toBase);
            }
        }


        void ConvertToBase(ref List<int> currentList, int value, int toBase)
        {
            if (value != 0)
            {
                currentList.Add(value % toBase);
                ConvertToBase(ref currentList, (value-currentList.Last()) / toBase, toBase);
            }
        }
    }
}
