/*This code is writen by using c#.*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Welcome_to_Code_Jam
{
    class Program
    {
        static int testcaseNumber;
        static List<int>[] bases;
        static Dictionary<int, List<int>> happyNumbers;//key:base;value:numbers
        static Dictionary<int, List<int>> unhappyNumbers;//key:base;value:numbers
        static int[] smallesthappy;

        static void Main()
        {
            string inputFile = @"E:\Documents\Google Code Jam\02.Round 1\Round 1 A\A-small-attempt0.in";
            string outputFile = @"E:\Documents\Google Code Jam\02.Round 1\Round 1 A\A-small-attempt0.out";
            Initialization(inputFile);
            Process();
            Output(outputFile);
        }

        private static void Initialization(string inputFile)
        {
            StreamReader reader = new StreamReader(inputFile);
            testcaseNumber = int.Parse(reader.ReadLine());
            bases = new List<int>[testcaseNumber];
            happyNumbers = new Dictionary<int, List<int>>();
            unhappyNumbers = new Dictionary<int, List<int>>();
            smallesthappy = new int[testcaseNumber];

            for (int i = 0; i < testcaseNumber; i++)
            {
                bases[i] = new List<int>();
                string[] temp = reader.ReadLine().Split(' ');
                for (int j = 0; j < temp.Length; j++)
                {
                    bases[i].Add(int.Parse(temp[j]));
                }
            }
            reader.Close();
        }

        private static void Process()
        {
            for (int test = 0; test < testcaseNumber; test++)
            {
                //every test 
                int number = 2;
                while (true)
                {
                    int happycount = 0;
                    foreach (int basenumber in bases[test])
                    {
                        //every base
                        if (happyNumbers.ContainsKey(basenumber) && happyNumbers[basenumber].Contains(number))
                        {
                            //it's a happynumber
                            happycount++;
                            if (happycount == bases[test].Count)
                            {
                                break;
                            }
                            continue;
                        }
                        if (unhappyNumbers.ContainsKey(basenumber) && unhappyNumbers[basenumber].Contains(number))
                        {
                            break;
                        }
                        //compute
                        if (ComputeHappy(basenumber, number))
                        {
                            happycount++;
                            if (happycount == bases[test].Count)
                            {
                                break;
                            }
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    if (happycount == bases[test].Count)
                    {
                        //smallest happy!!
                        smallesthappy[test] = number;
                        break;
                    }
                    number++;
                }
            }
        }

        private static bool ComputeHappy(int basenumber, int number)
        {
            List<int> trace = new List<int>();
            trace.Add(number);
            int sum = 0;
            while (true)
            {
                if (number == 0)
                {
                    number = sum;
                    if (number == 1)
                    {
                        //happy
                        if (!happyNumbers.ContainsKey(basenumber))
                        {
                            happyNumbers.Add(basenumber, new List<int>());
                        }
                        foreach (int uh in trace)
                        {
                            if (!happyNumbers[basenumber].Contains(uh))
                            {
                                happyNumbers[basenumber].Add(uh);
                            }
                        }
                        return true;
                    }
                    else
                    {
                        if ((unhappyNumbers.ContainsKey(basenumber) && unhappyNumbers[basenumber].Contains(number))
                            || (trace.Contains(number)))
                        {
                            //unhappy
                            if (!unhappyNumbers.ContainsKey(basenumber))
                            {
                                unhappyNumbers.Add(basenumber, new List<int>());
                            }
                            foreach (int uh in trace)
                            {
                                if (!unhappyNumbers[basenumber].Contains(uh))
                                {
                                    unhappyNumbers[basenumber].Add(uh);
                                }
                            }
                            return false;
                        }
                        else
                        {
                            trace.Add(number);
                            sum = 0;
                            continue;
                        }
                    }
                }
                else
                {
                    int mod = number % basenumber;
                    sum += mod * mod;
                    number = number / basenumber;
                }
            }
        }

        private static void Output(string outputFile)
        {
            StreamWriter writer = new StreamWriter(outputFile);
            for (int i = 0; i < testcaseNumber; i++)
            {
                writer.WriteLine("Case #{0}: {1}", i + 1, smallesthappy[i]);
            }
            writer.Close();
        }

    }
}