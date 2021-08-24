using System;
using System.Collections.Generic;
using System.IO;

namespace HappyNumbers
{
    class Program
    {
        static void Main()
        {
            string basePath = @"D:\DamoData\projects\GoogleCodeJam\2009R1A\";
            var infile = new StreamReader(basePath + "smalla.txt");
            var outfile = new StreamWriter(basePath + "output.txt");

            int testCases = Int32.Parse(infile.ReadLine());
            for (int caseNo = 1; caseNo <= testCases; caseNo++) // note this is 1-based
            {
                // read in the input data
                string[] data = (infile.ReadLine()).Split(new [] { ' ' }, StringSplitOptions.None);
                var bases = new int[data.Length];
                for(int i=0; i < data.Length; i++)
                    bases[i] = Int32.Parse(data[i]);

                int smallestHappyNo=2;
                while (true)
                {
                    bool exit = false;
                    foreach (var b in bases)
                    {
                        if (!isHappy(smallestHappyNo, b, new List<int>()))
                        {
                            exit = true;
                            break;
                        }
                    }
                    if (exit)
                        smallestHappyNo++;
                    else
                        break;
                }
                
                // write out the results
                outfile.WriteLine(String.Format("Case #{0}: {1}", caseNo, smallestHappyNo));
            }
            infile.Close();
            outfile.Close();
        }

        static bool isHappy(int base10number, int baseTo, List<int> previous)
        {
            if (base10number == 1)
                return true;

            if (base10number == 0 || previous.Contains(base10number))
                return false;

            int current = base10number;
            checked
            {
                int sumDigits = 0;
                double index = Math.Floor(Math.Log(base10number, baseTo)); // the leftmost index
                while (index >= 0 && base10number>0)
                {
                    int digit = (int) (Math.Floor(base10number/Math.Pow(baseTo, index)));
                    sumDigits += digit*digit;
                    base10number = base10number - (int) (digit*Math.Pow(baseTo, index));
                    index--;
                }
                previous.Add(current);
                return isHappy(sumDigits,baseTo, previous);
            }
        }
    }
}