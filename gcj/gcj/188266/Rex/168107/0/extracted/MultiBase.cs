using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ.MultiBase
{
    public class MultiBase
    {
        InputHandler Handler { get; set; }

        public void Solve(string filePath)
        {
            InputHandler handler = new InputHandler(filePath);
            List<string> answers = new List<string>();
            int result=1;
            foreach (List<int> bases in handler.Bases)
            {
                bool isAllowed = false;
                int lowestNum = 2;                
                while (!isAllowed)
                {
                    bool allZero = true;
                    foreach (int b in bases)
                    {
                        OldNums = new List<string>();
                        allZero = CheckForAllowed(lowestNum, b);
                        if (!allZero) break;
                    }

                    if (allZero)
                    {
                        answers.Add(string.Format("Case #{0}: {1}", result++, lowestNum));
                        break;
                    }
                    lowestNum++;
                }

            }

            //answers.ForEach(a => Console.WriteLine(a));
            File.WriteAllLines(@"C:\Temp\GCJ\GCJ\MultiBase\Input\A-small-attempt0.answer.in", answers.ToArray());
        }

        List<string> OldNums { get; set; }
        bool CheckForAllowed(int number, int b)
        {
            List<int> num = ConvertToBase(number, b);
            long sum = 0;
            num.ForEach(a => sum += (long)Math.Pow(a, 2));
            //Console.WriteLine("Sum is=" + sum);
            if (sum == 1) return true;
            if (OldNums.Contains(GetNum(num))) return false;

            string op = string.Empty;
            num.ForEach(a => op += a);
            OldNums.Add(op);
            return CheckForAllowed((int)sum, b);
        }

        string GetNum(List<int> digits)
        {
            string op = string.Empty;
            digits.ForEach(a => op += a);
            return op;
        }

        List<int> ConvertToBase(int num, int destBase)
        {
            List<int> finalRepresentation = new List<int>();

            while (num > 0)
            {
                int r = num % destBase;
                finalRepresentation.Add(r);
                num = num - r;
                num = num / destBase;
            }
            finalRepresentation.Reverse();
            return finalRepresentation;
        }
    }
}
