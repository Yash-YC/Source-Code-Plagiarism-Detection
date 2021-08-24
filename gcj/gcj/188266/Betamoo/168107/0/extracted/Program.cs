using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace R1A_A
{
    class Program
    {
        static void Main(string[] args)
        {
            A a = new A();
            StreamReader sr = new StreamReader("in.in");
            StreamWriter SW = new StreamWriter("out.out");
            int N = int.Parse(sr.ReadLine());
            for (int n = 0; n < N; n++)
            {
                string[] s = sr.ReadLine().Split(' ');
                if (s.Length == 2)
                {
                    int b1 = int.Parse(s[0]);
                    int b2 = int.Parse(s[1]);
                    SW.WriteLine("Case #" + (n + 1).ToString() + ": " + a.Solve(b1, b2));
                    Console.WriteLine("Ok");
                }
                else if (s.Length == 3)
                {
                    int b1 = int.Parse(s[0]);
                    int b2 = int.Parse(s[1]);
                    int b3 = int.Parse(s[2]);
                    SW.WriteLine("Case #" + (n + 1).ToString() + ": " + a.Solve(b1, b2, b3));
                    Console.WriteLine("Ok");
                }

            }
            SW.Close();
            sr.Close();
        }
    }


    class A
    {
        public A()
        {
            //HappyNumbers=new int[11,10000];
            //IsHappyDB=new int[11,10000];
            HappyNumbers = new SortedList<int, int>[11];
            for (int i = 0; i < 11; i++)
            {
                HappyNumbers[i] = new SortedList<int, int>();
            }
        }
        public SortedList<int, int>[] HappyNumbers;
        //            public int[,] HappyNumbers;
        //            public int[,] IsHappyDB;
        //public int GetFirstHappyNumber(int Base)
        //{
        //    int x = 2;
        //    while (true)
        //    {
        //        //if (IsHappy(x,b))
        //        //    return x;
        //        x++;
        //    }
        //}
        public int Solve(int b1, int b2)
        {
            int x = 2;
            while (!(IsHappy(x, b1) && IsHappy(x, b2)))
                x++;
            return x;
        }
        public int Solve(int b1, int b2, int b3)
        {
            int x = 2;
            while (!(IsHappy(x, b1) && IsHappy(x, b2) && IsHappy(x, b3)))
                x++;
            return x;
        }
        public bool IsHappy(int x, int b)
        {
            List<int> q = new List<int>();
            while (true)
            {
                if (x == 1)

                {
                    foreach (int u in q)
                    {
                        HappyNumbers[b].Add(u, 1);
                        //IsHappyDB[b, u] = 1;
                        return true;
                    }
                }
                if (x == 0 || q.Contains(x))
                {
                    foreach (int u in q)
                    {
                        HappyNumbers[b].Add(u, -1);
                        //IsHappyDB[b, u] = -1;
                        return false;
                    }
                }
             if (HappyNumbers[b].ContainsKey(x))
            {
                if (HappyNumbers[b][x] == 1)
                    return true;
                else if (HappyNumbers[b][x] == -1)
                    return false;
            }
               q.Add(x);
                x = Get(x, b);
            }
        }
        public int Get(int x, int b)
        {
            int y = 0;
            while (1 <= x * b)
            {
                //f = f * b;
                int e = x - b * (x / b);
                y += e * e;
                x = (x - e) / b;
            }
            return y;
        }
    }


}
