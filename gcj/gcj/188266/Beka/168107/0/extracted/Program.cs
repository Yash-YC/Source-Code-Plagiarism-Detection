using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Practice
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader input = new StreamReader("input.txt");
            StreamWriter output = new StreamWriter("output.txt");

            int n = int.Parse(input.ReadLine());

            for (int i = 0; i < n; ++i)
            {
                int ans = 1;
                string[] arg = input.ReadLine().Split(' ');
                int [] a=new int[arg.Length];
                
                for (int j = 0; j < a.Length; ++j)
                {
                    a[j] = int.Parse(arg[j]);
                }

                bool ok = false;
                
                while (!ok)
                {
                    ++ans;
                    ok = true;
                    for (int j = 0; j < a.Length; ++j)
                    {
                        if (!happy(a[j],ans))
                        {
                            ok = false;
                            break;
                        }
                    }
                }
                
                output.WriteLine("Case #{0}: {1}", i + 1, ans);
            }
             
            input.Close();
            output.Close();
        }

        static bool happy(int b,int x)
        {
            List<int> used = new List<int>();

            while (x>1)
            {
                int t = x;
                x = 0;
                while (t > 0)
                {
                    x += (t % b) * (t % b);
                    t /= b;
                }
                if (used.Contains(x)) break;
                else
                    used.Add(x);
            }

            return (x == 1);
        }
    }
}
