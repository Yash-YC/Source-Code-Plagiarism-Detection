using System;
using System.Collections.Generic;
using System.IO;


public class Round1AA
{
    static void Main(string[] args)
    {
        StreamReader si;
        StreamWriter sw;
        string line;

        int c, i, j, k, n, r, result, t, u, v, w;
        bool flag;
        string[] ss;
        int[] b = new int[10];
        int max = 1000000;
        bool[,] happy = new bool[max, 11];
        bool[,] unhappy = new bool[max, 11];
        string[] loop = {
                      "", "", "",
                      "2 11 12 22",
                      "",
                      "4 31 20 23 33",
                      "32 21 5 41 25 45 105 42",
                      "2 4 22 11 34 13 23 16 52 41 63 44",
                      "4 20 5 31 12 32 15 24 64",
                      "55 58 108 72 45 75 82",
                      "4 16 37 58 89 145 42 20"};

        si = new StreamReader("A-small-attempt0.in");
        sw = new StreamWriter("A-small-attempt0.out");

        line = si.ReadLine().Trim();
        t = Int32.Parse(line);

        for (i = 3; i <= 10; i++)
        {
            ss = loop[i].Split(' ');
            for (j = 0; j < ss.Length; j++)
            {
                u = 0;
                w = 1;
                for (k = ss[j].Length - 1; k >= 0; k--)
                {
                    u += w * (ss[j][k] - '0');
                    w *= i;
                }
                unhappy[u, i] = true;
            }
            k = 1;
            while (k < max)
            {
                happy[k, i] = true;
                k *= i;
            }
        }

        for (i = 3; i <= 10; i++)
        {
            if (i == 4) continue;
            for (j = 2; j < max; j++)
            {
                if (!unhappy[j, i] && !happy[j, i])
                {
                    flag = true;
                    u = j;
                    while (flag)
                    {
                        w = u;
                        u = 0;
                        while (w >= 1)
                        {
                            r = w % i;
                            u += r * r;
                            w = w / i;
                        }
                        if (unhappy[u, i])
                        {
                            unhappy[j, i] = true;
                            flag = false;
                        }
                        if (happy[u, i])
                        {
                            happy[j, i] = true;
                            flag = false;
                        }
                    }
                }
            }
        }

        for (c = 0; c < t; c++)
        {
            line = si.ReadLine().Trim();
            ss = line.Split(' ');
            n = ss.Length;
            for (i = 0; i < n; i++)
            {
                b[i] = Int32.Parse(ss[i]);
            }
            result = 0;
            for (i = 2; i < max; i++)
            {
                flag = true;
                for (j = 0; j < n; j++)
                {
                    if (b[j] == 2 || b[j] == 4)
                    {
                        continue;
                    }
                    if (unhappy[i, b[j]])
                    {
                        flag = false;
                    }
                }
                if (flag)
                {
                    result = i;
                    break;
                }
            }
            sw.WriteLine("Case #{0}: {1}", c + 1, result);
        }
        sw.Close();
    }
}