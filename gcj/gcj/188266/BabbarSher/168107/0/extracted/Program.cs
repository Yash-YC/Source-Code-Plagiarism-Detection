using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Problem1
{
    class OneBase
    {
        public int baseNumber;
        public List<long> occurred ;

        public OneBase(int baseN)
        {
            baseNumber = baseN;
            occurred = new List<long>();
        }

        private int[] digits(long number)
        {
            List<int> r = new List<int>();
            for (int k =0; number > 0; number = number / 10,k++)
            {
                r.Add(Convert.ToInt32(number % 10));               
            }

            return r.ToArray();
        }

        private long CovertToBase(long num)
        {
            int[] numberArray;
            int rem = 0;
            List<int> b= new List<int>();
            for (int k = 0; num > 0; k++, num = num / baseNumber)
            {
                rem = Convert.ToInt32(num % baseNumber);
                b.Add(rem);               
            }
            numberArray = Reverse(b.ToArray());
            StringBuilder s = new StringBuilder();
            foreach (int x in numberArray)
            {
                s.Append(Convert.ToString(x));
            }
            return Convert.ToInt64(s.ToString());
        }

        private int[] Reverse(int[] ar)
        {
            
            int[] rev = new int[ar.Length];
            int i = 0;
            for (int k = ar.Length - 1; k >= 0; k--,i++)
            {
                rev[i] = ar[k] ;
            }
            return rev;
        }

        public int RecursiveSquareSum(long number)
        {
            if (number == 1)
            {
                return -1;
            }
            long n = CovertToBase(number); 
            int[] ar = digits(n);
            long nextNum = 0;
            for (int k = 0; k < ar.Length ; k++)
            {
                nextNum += Convert.ToInt64(Math.Pow(ar[k], 2));
            }
            occurred.Add(number);
            if (occurred.Contains(nextNum))
            {
                return 2;
            }

            return RecursiveSquareSum(nextNum);
        }

        public bool CheckForHappy(int m)
        {
                       
            if (RecursiveSquareSum(m) == -1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public int FindMinHappyNum(int min)
        {
            int a = min + 1;
            for (;true ; a++)
            {
                if (RecursiveSquareSum(a) == -1)
                {
                    break;
                }
            }
            return a;
        }

    }


    class TestCase
    {
        public List<int> bases;

        public TestCase(List<int> l)
        {
            bases = l;
        }

        private bool CheckForRest(int x)
        {
            bool res = true; ;
            for (int k = 1; k < bases.Count; k++)
            {
                OneBase obj = new OneBase(bases[k]);
                res = obj.CheckForHappy(x);
                if (res == false)
                {
                    break;
                }
            }
            return res;
        }

        public int Solve(int starting)
        {
            OneBase obj = new OneBase(bases[0]);
            int x = obj.FindMinHappyNum(starting);
            if (CheckForRest(x))
            {
                return x;
            }
            else
            {
                return Solve(x);
            }
        }
    }

    class Program
    {
        private static int N;
        private static List<TestCase> testCases = new List<TestCase>();
        private static void Read(string filename)
        {
            StreamReader sr = new StreamReader(filename);
            N = Convert.ToInt32(sr.ReadLine());
            int i = 0;
            string[] arr;
            while (!sr.EndOfStream && i <= N)
            {
                arr = sr.ReadLine().Split(' ');
                List<int> bases = new List<int>();
                for (int k = 0; k < arr.Length; k++)
                {
                    bases.Add(Convert.ToInt32(arr[k]));
                }
                TestCase obj = new TestCase(bases);
                testCases.Add(obj);
                i++;
            }
            sr.Close();
        }

        static void Main(string[] args)
        {
            Read("C:\\Code Jam Round1\\Problem1\\Input.txt");
            StringBuilder str = new StringBuilder();
            for(int i =0;i<testCases.Count;i++)
            {
                TestCase obj = testCases[i];
                str.Append("Case #"+(i+1)+": "+obj.Solve(1)+"\n");
            }
            Write(str.ToString());
        }

        private static void Write(string outputText)
        {
            File.AppendAllText("C:\\Code Jam Round1\\Problem1\\Output.txt", outputText);
        }
    }
}
