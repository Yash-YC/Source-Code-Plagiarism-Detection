using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    
    class Program
    {

        static string ConvertToBase(int num, int pbase)
        {
            string ret = "";
            while (num != 0)
            {
                ret = (num % pbase).ToString() + ret;
                num /= pbase;
            }
            return ret;
        }

        static bool IsHappy(string n, int b)
        {
            Dictionary<string, bool> memo = new Dictionary<string, bool>();

            while (!memo.ContainsKey(n))
            {
                memo.Add(n, true);
                int sum = 0;
                for (int i = 0; i < n.Length; i++)
                {
                    int tmp = (n[i] - '0');
                    sum += tmp * tmp;
                }
                if (sum == 1) return true;
                n = ConvertToBase(sum,b);
            }

            return false;
        }
        
        static void Main(string[] args)
        {

            FileStream output = new FileStream("output.txt", FileMode.Create, FileAccess.Write);
            StreamWriter sw = new StreamWriter(output);

            FileStream input = new FileStream("input.txt", FileMode.Open, FileAccess.Read);
            StreamReader sr = new StreamReader(input);

            int ntestCases = int.Parse(sr.ReadLine());

            for (int t = 1; t <= ntestCases; t++)
            {
                string tmp = sr.ReadLine();
                string[] bases = tmp.Split(' ');

                for (int i = 2; ; i++)
                {
                    bool ok = true;
                    for (int j = 0; j < bases.Length; j++)
                    {
                        int b = int.Parse(bases[j]);
                        string converted = ConvertToBase(i, b);
                        if (!IsHappy(converted,b))
                        {
                            ok = false;
                            break;
                        }
                    }

                    if (ok)
                    {
                        sw.WriteLine("Case #" + t.ToString() + ": " + i.ToString());
                        break;
                    }

                }
                    
                sw.Flush();
            }



        }
    }
}
