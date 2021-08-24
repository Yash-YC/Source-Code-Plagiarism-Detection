using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    
    class Program
    {
        static Random rand = new Random();

        static int countBits(int x)
        {
            int c = 0, tmp = x;
            while (tmp > 0) { c++; tmp &= (tmp - 1); }
            return c;
        }

        static void Main(string[] args)
        {

            FileStream output = new FileStream("output.txt", FileMode.Create, FileAccess.Write);
            StreamWriter sw = new StreamWriter(output);

            FileStream input = new FileStream("input.txt", FileMode.Open, FileAccess.Read);
            StreamReader sr = new StreamReader(input);

            int REPETITIONS = 1000000;

            int ntestCases = int.Parse(sr.ReadLine());

            for (int t = 1; t <= ntestCases; t++)
            {
                string line = sr.ReadLine();
                string[] splitted = line.Split(' ');
                int C = int.Parse(splitted[0]);
                int N = int.Parse(splitted[1]);

                List<int> masks = new List<int>();
                for(int i=0; i<(1<<C); i++)
                {
                    if(countBits(i)==N)
                    {
                        masks.Add(i);
                    }
                }

                int avg = 0;
                int final = (1<<C)-1;
                for (int i = 0; i < REPETITIONS; i++)
                {
                    int tmp = 0;
                    while (tmp != final)
                    {
                        int mask = masks[rand.Next(0, masks.Count)];
                        tmp |= mask;
                        avg++;
                    }

                }

                double ret = avg / (double)REPETITIONS;

                sw.WriteLine("Case #" + t.ToString() + ": " + ret.ToString());
                sw.Flush();
            }



        }
    }
}
