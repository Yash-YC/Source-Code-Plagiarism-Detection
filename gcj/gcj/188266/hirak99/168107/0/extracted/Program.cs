using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ2009R1AA {
    class Program {
        int sum2base(int n, int b) {
            int sum = 0;
            while (n > 0) {
                int m = n % b;
                sum += m * m;
                n /= b;
            }
            return sum;
        }
        Dictionary<int, int>[] Cases = new Dictionary<int, int>[11];
        int reorient(int n, int b) {
            List<int> digits = new List<int>();
            while (n > 0) {
                int m = n % b;
                if (m>0) digits.Add(m);
                n /= b;
            }
            digits.Sort();
            int result = 0;
            foreach (int d in digits)
                result = (result * b) + d;
            return result;
        }
        int repeatedSum(int n, int b) {
            if (Cases[b] == null)
                Cases[b] = new Dictionary<int, int>();
            if (Cases[b].ContainsKey(n)) return Cases[b][n];
            Dictionary<int, bool> seen = new Dictionary<int, bool>();
            while (!seen.ContainsKey(n)) {
                if (n == 1) break;
                seen.Add(n, true);
                n = sum2base(n, b);
            }
            foreach (int key in seen.Keys)
                Cases[b][key] = n;
            return n;
        }
        Dictionary<int[], int> results = new Dictionary<int[], int>();
        public Program() {
            int ncases = int.Parse(Console.ReadLine());
            for (int i = 0; i < ncases; ++i) {
                int startat = 2;
                int[] bases = Console.ReadLine().Split().Select(n=>int.Parse(n)).ToArray();
                foreach (var x in results) {
                    int[] knowncase = x.Key;
                    bool IsSuperset = true;
                    foreach (int a in knowncase) {
                        if (!bases.Contains(a)) { IsSuperset = false; break; }
                    }
                    if (IsSuperset) {
                        if (startat < x.Value) startat = x.Value;
                    }
                }
                int j;
                for (j = startat; ; ++j) {
                    bool IsHappy = true;
                    foreach (int b in bases) {
                        if (repeatedSum(j, b) != 1) { IsHappy = false; break; }
                    }
                    if (IsHappy) break;
                }
                results[bases] = j;
                Console.WriteLine("Case #{0}: {1}", i + 1, j);
            }
        }
        static void Main(string[] args) {
            new Program();
        }
    }
}
