using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
{
    class Program
    {
        static int feliz(int n, int ibase)
        {
            int x, nn, d;

            if ((ibase == 2) || (ibase == 4)) return 1;

            for (x = 0; x < 20; x++)
            {
                nn = 0;
                while (n > 0)
                {
                    d = n % ibase;
                    n = n / ibase;
                    nn += d * d;
                }
                n = nn;
                if (n == 1) return 1;
            }
            return 0;
        }

        static void Main(string[] args)
        {
            String fileName = "A-large";
            //String fileName = "A-small";

            // Load file
            TextReader tr = new StreamReader(@"C:\Temp\A\" + fileName + ".in");
            String sCases = tr.ReadLine();

            // create a writer and open the file
            TextWriter tw = new StreamWriter(@"C:\Temp\A\" + fileName + ".out");

            int Cases = Int32.Parse(sCases);

            char[] delim = { ' ' };

            int n, nb, tb = 0;
            bool end;
            
            // Run cases
            for (int k = 1; k <= Cases; k++)
            {
                String[] sBases = tr.ReadLine().Split(delim);
                int[] iBases = new int[sBases.Length];

                for (int i = 0; i < sBases.Length; i++)
                {
                    iBases[i] = Int32.Parse(sBases[i]);
                }

                Array.Sort<int>(iBases);
                Array.Reverse(iBases);

                n = 1;
                nb = iBases.Length;
                end = false;
                while ((n < 100000) && (!end))
                {
                    n++;
                    tb = 0;
                    while ((tb < nb) && (feliz(n, iBases[tb]) == 1))
                    {
                        tb++;
                    }
                    end = (tb == nb);
                }

                tw.WriteLine("Case #" + k.ToString() + ": " + n.ToString());
            }

            // close the stream
            tw.Close();
            tr.Close();

            Console.Write("Finish");
            Console.Read();
        }
    }
}
