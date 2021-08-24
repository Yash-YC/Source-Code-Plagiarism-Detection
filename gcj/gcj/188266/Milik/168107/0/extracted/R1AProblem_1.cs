using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace R_P_A
{
    class R1AProblem_1
    {
        static Int16[,] calc = new Int16[11, 4000000];

        private static string toBase(Int64 num, int bas)
        {
            if (num < bas) { return (num.ToString()); }
            else { return (toBase(num / bas, bas) + (num % bas).ToString()); }
        }


        private static bool isHappy(long val, int bas)
        {
            if (calc[bas, val] == 0 || calc[bas, val] == 2)
            {
                return (false);
            }
            else if (calc[bas, val] == 1)
            {
                return (true);
            }
            else
            {
                Int64 res = 0;
                //Calculate
                
                String temp = toBase(val, bas);

                for (int q1 = 0; q1 < temp.Length; q1++)
                {
                    int tn = Int32.Parse(temp.Substring(q1, 1));
                    res += tn * tn; 
                }
                
                if (res == 1)
                {
                    calc[bas, val] = 1;
                    return (true);
                }
                else
                {
                    calc[bas, val] = 2;
                    if (isHappy(res, bas))
                    {
                        calc[bas, val] = 1;
                        return (true);
                    }
                    else
                    {
                        calc[bas, val] = 0;
                        return (false);
                    }
                }
            }
        }

        static void Main(string[] args)
        {
            
            for (int q1 = 0; q1 < 11; q1++)
            {
                for (int q2 = 0; q2 < 4000000; q2++)
                {
                    calc[q1, q2] = -1;
                }
            }

            String fileData = File.ReadAllText("DataR1_1.txt");
            String[] temp = fileData.Split('\n');
            int N;
            N = Int32.Parse(temp[0].Split(' ')[0]);
            for (int i = 0; i < N; i++)
            {
                int[] basi;
                String[] linedata = temp[1 + i].Split(' ');
                List<int> tempi = new List<int>();
                foreach (String tsss in linedata)
                {
                    tempi.Add(Int32.Parse(tsss));
                }
                basi = tempi.ToArray();


                int happyNum = 2;

                while (true)
                {
                    bool res = true;
                    foreach (int baska in basi)
                    {
                        res = isHappy(happyNum, baska);
                        if (res == false) { break; }
                    }
                    if (res == true) { break; }
                    happyNum++;
                }

                if (i > 0)
                {
                    File.AppendAllText("outputR1_1.txt", "\n");
                }
                else
                {
                    File.WriteAllText("outputR1_1.txt", "");
                }
                File.AppendAllText("outputR1_1.txt", "Case #" + (i + 1).ToString() + ": " + happyNum);

                Console.WriteLine("Case #" + (i + 1).ToString() + ": " + happyNum);
            }
        }
    }
}
