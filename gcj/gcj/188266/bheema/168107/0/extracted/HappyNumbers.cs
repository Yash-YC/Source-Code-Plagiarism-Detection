using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace CodeJam
{
    public class HappyNumbers
    {
        private static int GetNextNumber(int number, int bays)
        {
            int result = 0;
            while (number != 0)
            {
                int digit = number % bays;
                result += (digit * digit);
                number = number / bays;
            }
            return result;
        }

        private bool IsHappyInBase(int number, int bays)
        {
            hashset.Clear();
            hashset.Add(number);
            while (true)
            {
                number = GetNextNumber(number, bays);
                if (number == 1)
                    return true;
                else if (hashset.Contains(number))
                    return false;
                hashset.Add(number);
            }
        }

        int T;
        int[] results;
        StreamReader reader;
        HashSet<int> hashset;


        public HappyNumbers(string inputFile)
        {
            FileStream fs = new FileStream(inputFile, FileMode.Open);
            reader = new StreamReader(fs);
            string line = reader.ReadLine();
            line = line.Trim();
            T = Int32.Parse(line);
            results = new int[T];
            hashset = new HashSet<int>();
        }

        private int ProcessTestCase(int[] bases)
        {
            int result = 2;
            while(true)
            {
                bool done = true;
                for(int i = bases.Length - 1; i >= 0;i--)
                {
                    if(!IsHappyInBase(result,bases[i]))
                    {
                        result++;
                        done = false;
                        break;
                    }
                }
                if(done)
                    break;
            }
            return result;
        }

        public void ComputeResults()
        {
            for(int i = 0;i < T;i++)
            {
                string line = reader.ReadLine();
                string[] str = line.Split(null);
                int[] bases = new int[str.Length];
                for(int j = 0;j < bases.Length;j++)
                    bases[j] = Int32.Parse(str[j]);
                results[i] = ProcessTestCase(bases);
            }
            reader.Close();
        }

        public void WriteResults(string outFile)
        {
            FileStream fs = new FileStream(outFile, FileMode.Create);
            StreamWriter writer = new StreamWriter(fs);
            for (int i = 0; i < T; i++)
            {
                string output = String.Format("Case #{0}: {1}", i + 1, results[i]);
                writer.WriteLine(output);
            }
            writer.Close();
        }
        
        public static void Main(string[] args)
        {
            //args[0] = input, args[1] = output
            HappyNumbers hn = new HappyNumbers(args[0]);
            hn.ComputeResults();
            hn.WriteResults(args[1]);
        }
    }
}
