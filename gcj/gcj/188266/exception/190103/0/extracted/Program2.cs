using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    public class Factorial
    {
        // The "Calc" static method calculates the factorial value for the
        // specified integer passed in:

    }

    class Program
    {
        public static Int64 Calc(int i)
        {
            return ((i <= 1) ? 1 : (i * Calc(i - 1)));
        }

        static void Main(string[] args)
        {
            TextReader tr = new StreamReader("C:\\Documents and Settings\\avparate\\Desktop\\input.txt");
            TextWriter tw = new StreamWriter("C:\\Documents and Settings\\avparate\\Desktop\\output.txt");

            int csno;
            csno = int.Parse(tr.ReadLine());

            string input = null;
                        
            for (int caseno = 1; caseno <= csno; caseno++)
            {
                input = tr.ReadLine();
                string[] first_line = input.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                int C = int.Parse(first_line[0]);
                int N = int.Parse(first_line[1]);

                //Int64 ii = Calc(C);
                //Int64 jj = Calc(N);
                //Int64 kk = Calc(C - N);

                //double ll = (double)ii / ((double)jj * (double)kk);
                int CC = C*2;
                CC--;
                double xx = (double)CC / (double)N;


                //double xx = ll / (double)N;
                // Print output line
                tw.WriteLine("Case #{0}: {1:F7}", caseno,xx); 

            }

            tr.Close();
            tw.Close();
        }
    }
}