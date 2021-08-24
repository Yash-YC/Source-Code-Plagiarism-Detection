using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProgrammingContestPractice
{
    class Multi_base_happiness
    {
        static int cacheL = 100000;
        static long[][] luckyCache = new long[cacheL][];
        static void Main(string[] args)
        {
            for (int n = 0; n < cacheL; n++)
            {
                luckyCache[n] = new long[11];
            }

            string strInputFile = "C:\\GoogleCodeJamInputOutput\\Multi_base_happiness\\A-small-attempt0.in";
            //string strInputFile = "C:\\GoogleCodeJamInputOutput\\Multi_base_happiness\\A-large-practice.in";
            //string strInputFile = "C:\\GoogleCodeJamInputOutput\\Multi_base_happiness\\sample.in";
            System.IO.TextReader tr = new StreamReader(strInputFile);
            System.IO.TextWriter tw = new StreamWriter(strInputFile + ".out.txt");
            int iTotalTestCases = Int32.Parse(tr.ReadLine());
            for (int iCase = 0; iCase < iTotalTestCases; iCase++)
            {
                String[] strLine = tr.ReadLine().Split(' ');
                tw.WriteLine("Case #{0}: {1}", (1 + iCase), getMinLuckyNum(strLine.Select(x=>Int32.Parse(x)).ToArray()));
            }

            tr.Close();
            tw.Close();

            Console.WriteLine("press any key to continue");

            /*
            Console.WriteLine("::" + getMinLuckyNum(new int[] { 2, 3 }));
            Console.WriteLine("::" + getMinLuckyNum(new int[] { 2, 3, 7 }));
            Console.WriteLine("::" + getMinLuckyNum(new int[] { 9, 10 }));
            */
            Console.ReadKey();
        }

        static long getMinLuckyNum(int[] bases)
        {
            long i = 2;
            while (true)
            {
                //Console.WriteLine("dealing:: {0}", i);
                int baseLuckyCount = 0;
                foreach (int b in bases)
                {
                    if (luckyCache[i][b] == 1) {baseLuckyCount++;}
                    else if (luckyCache[i][b] == -1) break; ;
                    HashSet<long> dup = new HashSet<long>();
                    long n = i;
                    while (true)//n >= b)
                    {   
                        if (dup.Contains(n)) {
                            //Console.WriteLine("CYCLE!!");
                            break;
                        }
                        dup.Add(n);
                        //Console.WriteLine(">>> b:{0} {1} {2}", b, convert(n, b), sumOfSqr(convert(n, b)));
                        n = convert(n, b);
                        n = sumOfSqr(n);
                    }
                    if (n == 1) {
                        luckyCache[i][b] = 1;
                        baseLuckyCount++; 
                    }
                    else
                    {
                        luckyCache[i][b] = -1;
                        //Console.WriteLine("BREAk!!!");
                        break;
                    }
                }
                if (baseLuckyCount == bases.Length)
                {
                    return i;
                }
                i++;
                //if (i > 92) return i;
            }
        }
        static long sumOfSqr(long n)
        {
            long ret = 0;
            while (n > 0)
            {
                long nn = n / 10;
                long ld = (n - nn * 10);
                ret += ld * ld;
                n = nn;
            }
            return ret;
        }
        static long convert(long n, int ibase){
            StringBuilder ret = new StringBuilder();
            while (n >= ibase)
            {
                long r = n % ibase;
                long q = n / ibase;
                ret.Insert(0, r);
                n = q;
            }
            ret.Insert(0,n);
            return Int64.Parse(ret.ToString());
        }
    }
}
