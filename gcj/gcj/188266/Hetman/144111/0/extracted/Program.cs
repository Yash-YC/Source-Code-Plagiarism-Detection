﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace B
{
    class Program
    {
        static long when_start(long x0, int s, int w, int t, bool north_south)
        {
            long r = ((x0 + s + w) - t)%(s+w);
            if (north_south)
            {
                if (r < s) return x0;
                else return x0 + (s + w - r);
            }
            else
            {
                if (r >= s) return x0;
                else return x0+(s - r);
            }
        }

        static long testCase()
        {
            string[] s = Console.ReadLine().Split(' ');
            int N = int.Parse(s[0]), M = int.Parse(s[1]);
            int[,] S = new int[N, M], W = new int[N, M], T = new int[N, M];
            for (int i = 0; i < N; i++)
            {
                s = Console.ReadLine().Split(' ');
                for (int j = 0; j < M; j++)
                {
                    S[i, j] = int.Parse(s[j * 3]);
                    W[i, j] = int.Parse(s[j * 3 + 1]);
                    T[i, j] = int.Parse(s[j * 3 + 2]) % (S[i, j] + W[i, j]);
                }
            }
            int N2 = N * 2;
            int M2 = M * 2; 

            long[,] times = new long[N2, M2];
            bool[,] changes = new bool[N2, M2];
            for (int i = 0; i <N2; i++)
                for (int j = 0; j <M2; j++)
                {
                    times[i, j] = -1;
                    changes[i, j] = false;
                }
            times[ N2-1,0] = 0;
            changes[ N2-1,0] = true;

            bool changed = true;

            while (changed)
            {
                changed = false;
                for (int i = 0; i <N2; i++)
                    for (int j = 0; j <M2; j++)
                    {
                        if (times[i, j]>=0)
                        {
                            int wier = i / 2;
                            int kol = j / 2;

                            long p, l,g,d;
                            if (j % 2 == 0)
                            {
                                p = 1+when_start(times[i, j], S[wier, kol], W[wier, kol], T[wier, kol], false);
                                l = times[i, j] + 2;
                            }
                            else
                            {
                                l = 1 + when_start(times[i, j], S[wier, kol], W[wier, kol], T[wier, kol], false);
                                p = times[i, j] + 2;
                            }

                            if (i % 2 == 0)
                            {
                                g = times[i, j] + 2;
                                d = 1 + when_start(times[i, j], S[wier, kol], W[wier, kol], T[wier, kol], true);
                            }
                            else
                            {
                                d = times[i, j] + 2;
                                g = 1 + when_start(times[i, j], S[wier, kol], W[wier, kol], T[wier, kol], true);
                            }

                            if (i > 0 && (g < times[i - 1, j] ||times[i - 1, j]<0) )
                            {
                                changed = true;
                                changes[i - 1, j] = true;
                                times[i - 1, j] = g;
                            }
                            if (i <N2-1 && (d < times[i + 1, j] || times[i + 1, j] < 0))
                            {
                                changed = true;
                                changes[i + 1, j] = true;
                                times[i + 1, j] = d;
                            }
                            if (j > 0 && (l < times[i, j-1] || times[i, j-1] < 0))
                            {
                                changed = true;
                                changes[i, j-1] = true;
                                times[i, j-1] = l;
                            }
                            if (j < M2-1 && (p < times[i, j + 1] || times[i, j + 1] < 0))
                            {
                                changed = true;
                                changes[i, j + 1] = true;
                                times[i, j + 1] = p;
                            }
                        }
                    }
            }




            return times[ 0, M2-1];
        }

        static void Main(string[] args)
        {
            
            int T = int.Parse(Console.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                Console.WriteLine("Case #" + i + ": " + testCase());
            }
        }
    }
}
