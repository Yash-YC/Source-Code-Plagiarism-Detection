using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CollectingCards
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader rd = new StreamReader("input.txt");
            StreamWriter wt = new StreamWriter("output.txt", false);
            String line = rd.ReadLine();

            Int32 T = Convert.ToInt32(line);
            for (Int32 i = 1; i <= T; i++)
            {
                line = rd.ReadLine();
                String[] param = line.Split(' ');
                Int32 C = Convert.ToInt32(param[0]);
                Int32 N = Convert.ToInt32(param[1]);

                wt.WriteLine("Case #{0}: {1}",i,pr(C,C,N));
                Console.WriteLine("Case #{0}: {1}", i, pr(C, C, N));

            }

            wt.Close();
        }

        static Double pr(Int32 x, Int32 c, Int32 n)
        {
            if (x <= n)
                return 1;

            return pr(x - 1, c, n) + c * c / (double)n / (c - x + 1);
        }
    }
}
