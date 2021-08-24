using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ_2009___Round_1A___P1
{
    class Program
    {
        static StreamReader reader;
        static StreamWriter writer;

        static void Main(string[] args)
        {
            Console.WriteLine("Enter file name: ");
            String fileName = Console.ReadLine();
            reader = new StreamReader(fileName);
            writer = new StreamWriter(fileName.Replace(".in", ".out"));
            int cases = Convert.ToInt32(reader.ReadLine());
            for (int i = 1; i <= cases; i++)
                ProcessCase(i);
            writer.Flush();
            writer.Close();
        }

        static void ProcessCase(int caseNumber)
        {
            String[] numbers = reader.ReadLine().Split(new char[] { ' ' });
            List<int> temp = new List<int>();
            for (int k = 0; k < numbers.Length; k++)
                temp.Add(Convert.ToInt32(numbers[k]));
            temp.Remove(2);
            temp.Remove(4);
            int[] bases = temp.ToArray();
            bool happy;
            for (int n = 2; n < 2000000; n++)
            {
                happy = true;
                for (int k = 0; k < bases.Length; k++)
                {
                    if (!IsHappy(n, bases[k]))
                    {
                        happy = false;
                        break;
                    }
                }
                if (happy)
                {
                    writer.WriteLine("Case #{0}: {1}", caseNumber, n);
                    return;
                }
            }
            writer.WriteLine("Case #{0}: {1}", caseNumber, "NOT FOUND");
        }

        static bool IsHappy(int n, int b)
        {
            int[] digits;
            int m = n;
            List<int> list = new List<int>();
            while (true)
            {
                if (list.Contains(m))
                    break;
                list.Add(m);
                digits = ConvertToDigits(m, b);
                m = 0;
                for (int k = 0; k < digits.Length; k++)
                    m += digits[k] * digits[k];
                if (m == 1)
                    return true;
            }
            return false;
        }

        static int[] ConvertToDigits(int number, int b)
        {
            int quotient;
            int remainder = number;
            int digits = Convert.ToInt32(Math.Floor(Math.Log(number, b))) + 1;
            int[] result = new int[digits];
            int c = Convert.ToInt32(Math.Pow(b, digits - 1));
            for (int k = digits - 1; 0 <= k; k--)
            {
                quotient = remainder / c;
                remainder -= quotient * c;
                result[k] = quotient;
                c /= b;
            }
            return result;
        }
    }
}
