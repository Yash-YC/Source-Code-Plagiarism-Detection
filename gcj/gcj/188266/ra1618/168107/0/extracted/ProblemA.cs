using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

/// <summary>
/// ProblemA
/// </summary>
public class ProblemA
{
    static void Main()
    {
        //TextReader sr = new StreamReader(@"c:\_temp\A.in");
        //TextWriter sw = new StreamWriter(@"c:\_temp\A.out");

        TextReader sr = new StreamReader(@"c:\_temp\A-small-attempt0.in");
        TextWriter sw = new StreamWriter(@"c:\_temp\A-small-attempt0.out");

        //TextReader sr = new StreamReader(@"c:\_temp\A-large.in");
        //TextWriter sw = new StreamWriter(@"c:\_temp\A-large.out");

        //TextReader sr = Console.In;
        //TextWriter sw = Console.Out;

        string[] split = sr.ReadLine().Split(' ');
        T = int.Parse(split[0]);

        for (int caseNo = 1; caseNo <= T; caseNo++)
        {
            DateTime now = DateTime.Now;
            sw.Write("Case #" + caseNo + ": ");
            solve(sr, sw);
            Console.WriteLine("done " + caseNo + "; Elapsed ms:" + (DateTime.Now - now).TotalMilliseconds);
        }
        sw.Close();
        Console.WriteLine("Press any key to continue...");
        Console.ReadKey();
    }

    private static int T;
    private static readonly Dictionary<int, bool> _cache = new Dictionary<int, bool>(1000000);
    private static readonly Dictionary<int, bool> _cycleCache = new Dictionary<int, bool>(1000000);
    static int[] digits = new int[100];
    //private static int[,] map;
    //private static char[,] cmap;

    private static void solve(TextReader sr, TextWriter sw)
    {
        int result;

        string[] split = sr.ReadLine().Split(' ');
        int[] bases = new int[split.Length];
        int i = 0;
        foreach (string s in split)
        {
            bases[i] = int.Parse(s);
            i++;            
        }

        int num = 1;
        while (true)
        {
            num++;
            bool isOK = true;
            foreach (int b in bases)
            {
                if (!calc(num, b))
                {
                    isOK = false;
                    break;
                }
            }
            if (isOK)
            {
                result = num;
                break;
            }
        }
        sw.WriteLine(result);
    }

    // If the num is "happy" in base b.
    private static bool calc(int num, int b)
    {
        if (num == 0)
        {
            return false;
        }
        if (num == 1)
        {
            return true;
        }

        // Try to use _cache.
        int key = b + num * 16;
        bool res;
        if (_cache.TryGetValue(key, out res))
        {
            return res;
        }
        if (_cycleCache.TryGetValue(key, out res))
        {
            if (res)
            {
                return false; // Cycle detected
            }
        }
        _cycleCache[key] = true;

        // Parse into digits.
        int rem = num;
        int len = -1;
        while (rem >= 1)
        {
            len++;
            int digit = rem%b;
            digits[len] = digit;
            rem = rem/b;
        }

        // Check each digit.
        bool isOK = true;
        long newNum = 0;
        for (int i = 0; i <= len; i++)
        {
            newNum += digits[i] * digits[i];
        }
        if (newNum > int.MaxValue)
        {
            isOK = false;
        }
        else if (!calc((int)newNum, b))
        {
            isOK = false;
        }            

        _cache[key] = isOK;
        return isOK;
    }
}
