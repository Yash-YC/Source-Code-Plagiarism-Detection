using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace GCJR1
{
    class P1
    {
        public static int[] squareTable = new int[0];
        public static Dictionary<KeyValuePair<int, int>, bool> dpTable = new Dictionary<KeyValuePair<int, int>, bool>();

        // Usage: Set the project's startup object to P1, set first argument to input filename, set second argument to output filename
        public static void Main(string[] args)
        {
            using (var reader = new StreamReader(File.OpenRead(args[0])))
            {
                using (var writer = new StreamWriter(File.OpenWrite(args[1])))
                {
                    int numCases = int.Parse(reader.ReadLine());

                    for (int i = 0; i < numCases; i++)
                    {
                        writer.WriteLine("Case #{0}: {1}", i + 1, Search(reader.ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => int.Parse(x)).ToArray()));
                    }
                }
            }
        }

        public static int Search(int[] bases)
        {
            var maxBase = bases.Last();

            if (maxBase > squareTable.Length)
            {
                squareTable = new int[maxBase];

                for (int i = 0; i < squareTable.Length; i++)
                    squareTable[i] = i * i;

                for (int i = 0; i <= maxBase; i++)
                    dpTable[new KeyValuePair<int, int>(1, i)] = true;
            }

            for (int currVal = 2; true; currVal++)
            {
                if (IsHappy(currVal, bases))
                    return currVal;
            }
        }

        public static bool IsHappy(int currVal, int[] bases)
        {
            foreach (var currBase in bases)
            {
                var result = IsHappy(currVal, currBase);

                foreach (var val in result.Value)
                    dpTable[new KeyValuePair<int, int>(val, currBase)] = result.Key;

                if (!result.Key)
                    return false;
            }

            return true;
        }

        public static KeyValuePair<bool, List<int>> IsHappy(int currVal, int currBase)
        {
            var currTable = new List<int>();

            while (true)
            {
                if (dpTable.ContainsKey(new KeyValuePair<int, int>(currVal, currBase)))
                {
                    return new KeyValuePair<bool, List<int>>(dpTable[new KeyValuePair<int, int>(currVal, currBase)], currTable);
                }
                else if (currTable.Contains(currVal))
                {
                    return new KeyValuePair<bool, List<int>>(false, currTable);
                }
                else
                {
                    currTable.Add(currVal);

                    var newVal = 0;

                    while (currVal > 0)
                    {
                        newVal += squareTable[currVal % currBase];
                        currVal /= currBase;
                    }

                    currVal = newVal;
                }
            }
        }
    }
}
