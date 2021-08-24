using System;
using System.Collections.Generic;
using System.Text;
using System.IO;


namespace Round1A
{
    class Program
    {
        static void Main(string[] args)
        {
            string inputFile = @"E:\Projects\GoogleCodeJam\Round1A\A-small-attempt0.in";
            string outputFile = @"E:\Projects\GoogleCodeJam\Round1A\A-large-practice.out";

            File.Delete(outputFile);

            StreamReader reader = File.OpenText(inputFile);
            string line = reader.ReadLine().Trim(); // first line
            int caseCount = int.Parse(line);

            List<int>[] happyNumbers = new List<int>[11];
            //happyNumbers[2] = 1;
            for (int i = 2; i <= 10; i++)
            {
                happyNumbers[i] = HappyNumbers(i);
            }

            for (int i = 0; i < caseCount; i++)
            {
                line = reader.ReadLine().Trim();

                string[] strArray = line.Split(' ');
                int minHappyNumber = int.MaxValue;

                List<int> tmpList = happyNumbers[int.Parse(strArray[0])];
                int nominator=0;
                for (int k = 0; k < tmpList.Count; k++)
                {
                    nominator = tmpList[k];
                    bool success = true;

                    for (int j = 1; j < strArray.Length; j++)
                    {
                        int nbase = int.Parse(strArray[j]);
                        if (happyNumbers[nbase].BinarySearch(nominator) < 0)
                        {
                            success = false;
                            break;
                        }
                    }
                    if (success)
                    {
                        break;
                    }
                }
                File.AppendAllText(outputFile, string.Format("Case #{0}: {1}\n", i + 1, nominator));
            }
        }

        public static List<int> HappyNumbers(int nbase)
        {
            List<int> hNumbers = new List<int>();

            for (int i = nbase; i < 10000; i++)
            {
                previousSeeds.Clear();
                if (IsHappyNumber(i, nbase))
                {
                    hNumbers.Add(i);
                }
            }
            return hNumbers;
        }

        public static List<int> previousSeeds = new List<int>();
        public static bool IsHappyNumber(int number, int nbase)
        {
            if (number < 3)
            {
                return false;
            }
            string str = ToBaseString(number, nbase);
            int sum = 0;
            for (int i = 0; i < str.Length; i++)
            {
                int tmp = int.Parse(str.Substring(i, 1));
                sum += tmp * tmp;
            }
            if (sum == 1)
            {
                return true;
            }
            else
            {
                int idx = previousSeeds.BinarySearch(sum);
                if (idx >= 0)
                {
                    return false;
                }
                else
                {
                    previousSeeds.Insert(~idx, sum);
                    return IsHappyNumber(sum, nbase);
                }
            }
        }

        public static string ToBaseString(int number, int nbase)
        {
            int remainder = 0;
            string output = "";
            while (number > 0)
            {
                remainder = number % nbase;
                output = remainder.ToString() + output;

                number = number / nbase;
            }
            return output;
        }
    }
}
