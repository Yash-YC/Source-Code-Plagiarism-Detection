using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ACode_A
{
    class Program
    {
        static void Main(string[] args)
        {
            /*
            Console.WriteLine(DecimalToBase(3, 2));
            Console.WriteLine(DecimalToBase(3, 3));

            int n = SumSubSet(DecimalToBase(3, 2));
            Console.WriteLine("{0}", n);
            n = SumSubSet(DecimalToBase(3, 3));
            Console.WriteLine("{0}", n);
            */

            ArrayList lineGroups = ProcessInputFile.LoadFile(args[0], 0, 0);

            foreach (ArrayList group in lineGroups)
            {
                int count = 0;
                foreach (string line in group)
                {
                    string[] bases = line.Split(' ');

                    int num = 2;

                    count++;
                    while(true)
                    {
                        int trueCount = 0;

                        foreach(string sBase in bases)
                        {
                            trueCount += Foo(num, Convert.ToInt32(sBase)) == true ? 1 : 0;
                        }

                        if (trueCount == bases.Length)
                        {
                            Console.WriteLine("Case #{0}: {1}", count, num);
                            break;
                        }
                        num++;
                    }
                }
            }

            
        }

        static void ConvertToBase(int n, int nBase)
        {
            
        }

        static bool Foo(int n, int nBase)
        {
            int nCurrentNum = n;

            ArrayList nums = new ArrayList();
            
            while (!nums.Contains(nCurrentNum))
            {
                nums.Add(nCurrentNum);

                nCurrentNum = SumSubSet(DecimalToBase(nCurrentNum, nBase));
                if (nCurrentNum == 1)
                {
                    return true;
                }
            }

            return false;
        }

        static int SumSubSet(string numString)
        {
            int sum = 0;
            for(int i = 0 ; i < numString.Length ; i++)
            {
                int nPos = numString[i] - '0';
                sum += nPos*nPos;
            }

            return sum;
        }

        // Convert any base below 10 (binary, octal, etc) to decimal (base 10)
        static double changeToBaseTen(double number, int fromBase)
        {
            double baseTenValue = 0;
            double[] buffer = new double[Convert.ToString(number).Length];

            for (int power = 0; power < Convert.ToString(number).Length; power++)
            {

                string digit = Convert.ToString(number).Substring(power, 1);

                buffer[power] = Convert.ToInt16(digit);

            }

            // The digits are in reverse order, so just reverse them here
            Array.Reverse(buffer);

            for (int i = 0; i < Convert.ToString(number).Length; i++)
            {

                baseTenValue += (buffer[i] * Math.Pow(Convert.ToDouble(fromBase), Convert.ToDouble(i)));

            }

            return baseTenValue;

        }

        public static int BaseToDecimal(string input, int nBase)
        {
            string characters = "0123456789";
            if (nBase < 2 || nBase > characters.Length)
            {
                throw new ArgumentOutOfRangeException("nBase", nBase, "Range: 2.." + characters.Length);
            }
            int result = 0;
            bool negative = false;
            if (input.StartsWith("-"))
            {
                negative = true;
                input = input.Substring(1);
            }
            for (int i = 0; i < input.Length; i++)
            {
                int value = characters.IndexOf(input[i]);
                if (value >= nBase || value < 0)
                {
                    throw new ArgumentOutOfRangeException("input[" + i + "]", input[i], "This character is not valid for base " + nBase);
                }
                result += value * (int)Math.Pow(nBase, input.Length - i - 1);
            }
            if (negative)
            {
                result *= -1;
            }
            return result;
        }

        public static string DecimalToBase(int input, int nBase)
        {
            string characters = "0123456789";
            if (nBase < 2 || nBase > characters.Length)
            {
                throw new ArgumentOutOfRangeException("nBase", nBase, "Range: 2.." + characters.Length);
            }
            if (input == 0)
            {
                return characters[0].ToString();
            }
            bool negative = false;
            if (input < 0)
            {
                negative = true;
                input *= -1;
            }
            StringBuilder sb = new StringBuilder();
            while (input != 0)
            {
                sb.Insert(0, (characters[input % nBase]));
                input /= nBase;
            }
            if (negative)
            {
                sb.Insert(0, "-");
            }
            return sb.ToString();
        }

    }
}
