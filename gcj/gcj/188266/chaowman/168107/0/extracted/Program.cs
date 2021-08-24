using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Google {
    static class Program {
        const string inputFile = @"C:\Google\A-small-attempt0.in";
        const string outputFile = @"C:\Google\result\__result.out";

        static void Main(string[] args) {
            //read input from file
            string input;
            using (var reader = File.OpenText(inputFile)) {
                input = reader.ReadToEnd();
            }

            //write output to file
            using (var writer = File.CreateText(outputFile)) {
                foreach (var result in Solve(input))
                    writer.WriteLine(result);
            }
        }
        static IEnumerable<string> Solve(string input) {
            //split cases
            string[] cases = input.Split(new[] { "\r\n", "\n" },StringSplitOptions.None);
            int caseCount = int.Parse(cases[0]);

            //enumerate cases
            for (int j = 1; j <= caseCount; j++) {
                string result = SolveMultiBaseHapiness(cases[j].Split(' ').Select(s => int.Parse(s)).OrderByDescending(i => i).ToArray());
                yield return string.Format("Case #{0}: {1}", j, result);
            }
        }
        public static Func<T, TResult> Memoize<T, TResult>(this Func<T, TResult> func) {
            var dict = new Dictionary<T, TResult>();
            return arg => {
                TResult value;
                if (!dict.TryGetValue(arg, out value)) {
                    value = func(arg);
                    dict.Add(arg, value);
                }
                return value;
            };
        }
        public static Func<T1, T2, TResult> Memoize<T1, T2, TResult>(this Func<T1, T2, TResult> func) {
            var curried = Memoize<T1, Func<T2, TResult>>(arg1 =>
                              Memoize<T2, TResult>(arg2 => func(arg1, arg2)));
            return (arg1, arg2) => curried(arg1)(arg2);
        }
        static Func<long, int, bool> isHappy = new Func<long, int, bool>(IsHappy).Memoize();
        static string SolveMultiBaseHapiness(int[] bases) {
            for (long i = 2; ; i++) {
                if (bases.All(b => isHappy(i, b)))
                    return i.ToString();
            }
        }
        static bool IsHappy(long i, int b) {
            HashSet<long> set = new HashSet<long>();
            long x = i.ToBaseString(b);
            set.Add(i);
            while (!set.Contains(x)) {
                if (x == 1)
                    return true;
                set.Add(x);
                x = x.ToBaseString(b);
            }
            return false;
        }
        static long ToBaseString(this long i, int b) {
            long r;
            long sum = 0;
            while (i >= b) {
                i = Math.DivRem(i, b, out r);
                sum += r * r;
            }
            sum += i * i;
            return sum;
        }
    }
}
