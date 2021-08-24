using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication1
{
    class MBHappiness
    {
        public static void Main(String[] args)
        {
            MBHappiness.run();

        }
        static void run()
        {
            string line = System.Console.In.ReadLine();
            int t = int.Parse(line);

            MBHappiness a = new MBHappiness();

            for (int i = 0; i < t; i++)
            {
                string nextLine = System.Console.In.ReadLine();
                string[] strBases = nextLine.Split(new char[] { ' ' });

                int[] bases = new int[strBases.Length];
                for (int j = 0; j < strBases.Length; j++)
                {
                    bases[j] = int.Parse(strBases[j]);
                }

                System.Console.Out.WriteLine("Case #{0}: {1}", i+1, a.findHappy(bases));
            }
        }

        List<Dictionary<int, bool>> baseHappyDict;

        public MBHappiness()
        {
            baseHappyDict = new List<Dictionary<int, bool>>();
            for (int i = 0; i <= 10; i++)
            {

                baseHappyDict.Add(new Dictionary<int, bool>());
            }

        }

        public int findHappy(int[] bases)
        {
            for (int i = 2; ; i++)
            {
                bool found = true;

                foreach(int b in bases) {
                    if (!isHappy(i, b))
                    {
                        found = false;
                        break;
                    }
                }

                if(found)
                    return i;
            }
        }

        public bool isHappy(int num, int b)
        {
            string basedNum = toBase(num, b);

            return recurIsHappy(basedNum, b);
        }

        public bool recurIsHappy(string num, int b)
        {
            int parsedNum = int.Parse(num);
            //Check cache result
            if (baseHappyDict[b].ContainsKey(parsedNum))
                return baseHappyDict[b][parsedNum];

            //Base case
            if (parsedNum == 1)
            {
                baseHappyDict[b][parsedNum] = true;
                return true;
            }

            //Initialise to false, initially, so if we ever see it, then we will know its false
            baseHappyDict[b][parsedNum] = false;

            //Do squaring
            int nextNumd = 0;
            foreach (char a in num)
            {
                int ad = int.Parse(a.ToString());
                nextNumd += ad * ad;
            }


            //Recurse
            if (recurIsHappy(toBase(nextNumd, b), b))
            {
                //Add to dict
                baseHappyDict[b][parsedNum] = true;
                return true;
            }
            else
            {
                return false;

            }

        }

        public string toBase(int num, int b)
        {
            //Convert num to base
            string basedNum = "";
            while (num > 0)
            {
                basedNum = (num % b).ToString() + basedNum;
                num = num / b;
            }

            return basedNum;
        }
    }
}
