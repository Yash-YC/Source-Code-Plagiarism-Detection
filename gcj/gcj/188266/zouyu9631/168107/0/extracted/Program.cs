using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.IO;


public class Round1A
{
    const int N = 1000000;
    static short[,] NHappyB = new short[N, 11];

    public static void Main(string[] args)
    {
        DateTime start = DateTime.Now;

        StreamReader sr = new StreamReader(@"C:\Users\yuzou\Documents\TestProgram\CSharpTest\CSharpTest\CSharpTest\in.txt");
        //StreamWriter sw = new StreamWriter(@"C:\Users\yuzou\Documents\TestProgram\CSharpTest\CSharpTest\CSharpTest\out.txt");

        string str = sr.ReadLine();
        int tt = int.Parse(str);

        for (int t = 1; t <= tt; t++)
        {
            str = sr.ReadLine().Trim();
            string[] sbases = str.Split(' ');
            List<int> bases = new List<int>();
            foreach (string s in sbases)
            {
                bases.Add(int.Parse(s));
            }
            //for (int i = 0; i < bases.Count; i++)
            //{
            //    Console.WriteLine(bases[i]);
            //}
            Console.Write("Case #{0}: ", t);
            for (int n = 2; n < N; n++)
            {
                int i = 0;
                for (; i < bases.Count; i++)
                {
                    HashSet<int> hash = new HashSet<int>();
                    if (!IsHappy(n, bases[i], hash))
                        break;
                }
                if (i == bases.Count)
                {
                    Console.WriteLine(n);
                    break;
                }
            }
        }


        //StreamWriter sw = new StreamWriter(@"C:\Users\yuzou\Documents\TestProgram\CSharpTest\CSharpTest\CSharpTest\out.txt");
        //for (int mask = 1; mask < 512; mask++)
        //{
        //    for (int i = 0; i < 9; i++)
        //    {
        //        if (((mask >> i) & 1) == 1)
        //            sw.Write("{0} ", i + 2);
        //    }
        //    sw.WriteLine();
        //}


        DateTime end = DateTime.Now;
        Console.WriteLine(end - start);
    }

    private static bool IsHappy(int n, int B, HashSet<int> hash)
    {
        if (hash.Contains(n))
            return false;
        if (n == 1) return true;

        if (NHappyB[n, B] != 0)
            return NHappyB[n, B] == 2;
        hash.Add(n);
        int nn = 0;
        int tn = 0;
        while (n != 0)
        {
            tn = n % B;
            nn += tn * tn;
            n /= B;
        }
        if (IsHappy(nn, B, hash))
        {
            NHappyB[n, B] = 2;
        }
        else
            NHappyB[n, B] = 1;
        return NHappyB[n, B] == 2; 
    }

}
