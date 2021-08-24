using System;
using System.Collections.Generic;
using System.Text;

namespace Codejam1
{    
    public class Pair : IComparable
    {
        int a, b;
        public Pair( int A, int B ) { a = A; b = B; }        
        public int CompareTo( Object BB ) {
            Pair B = (Pair)BB;
            if (a != B.a) return a - B.a;
            return b - B.b;
        }
    }


    class Program
    {

        public Dictionary<Pair, bool> memo;

        Program()
        {
            memo = new Dictionary<Pair, bool>();
        }

        public bool Happy( int x, int B ) {
            
            for (int iter = 0; iter < 30; ++iter)
            {
                int y = 0;
                while (x > 0)
                {
                    int digit = x % B;
                    x /= B;
                    y += digit * digit;
                }
                x = y;
            }
            return (x == 1);
        }

        static void Main(string[] args)
        {
            Program solution = new Program();
            
            int T = Int32.Parse(Console.ReadLine());
            for (int tt = 1; tt <= T; ++tt)
            {
                string[] numbers = Console.ReadLine().Split(' ');
                int[] a = new int[numbers.Length];
                for( int i = 0; i < numbers.Length; ++i  ) a[i] = Int32.Parse(numbers[i]);

                Array.Sort(a);
                Array.Reverse(a);

                int cnt = 0;
                int ret = 2;
                bool ok = false;
                while (!ok)
                {
                    ok = true;
                    foreach (int Base in a)
                    {
                        if (!solution.Happy(ret, Base)) ok = false;
                        if (!ok) break;
                        ++cnt;
                    }
                    if (ok) break;
                    ++ret;
                }
                Console.WriteLine("Case #{0}: {1}", tt, ret);                
            }
        }
    }
}
