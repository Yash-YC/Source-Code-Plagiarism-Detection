using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleJam.Round1A
{
    class ProblemA
    {
        static void Main(string[] args)
        {
            using (System.IO.StreamReader reader = File.OpenText("A-small-attempt0.in"))
            {
                int count = int.Parse(reader.ReadLine());

                using (StreamWriter writer = File.CreateText("A-small-attempt0.out"))
                {

                    for (int i = 0; i < count; i++)
                    {
                        string[] numbers = reader.ReadLine().Split(' ');
                        int lastNumber = 1;
                        int baseNumber = int.Parse(numbers[numbers.Length - 1]);
                        bool doMore = true;


                        while (doMore)
                        {
                            do
                            {
                                lastNumber++;
                            } while (!isHappyNumber(baseNumber, lastNumber));

                            for (int j = numbers.Length - 2; j >= 0; j--)
                            {
                                int bNumber = int.Parse(numbers[j]);
                                if (!isHappyNumber(bNumber, lastNumber))
                                {
                                    doMore = true;
                                    break;
                                }

                                doMore = false;
                            }
                        }

                        Console.WriteLine("Case #{0}: {1}", i + 1, lastNumber);
                        writer.WriteLine("Case #{0}: {1}", i + 1, lastNumber);
                    }
                }
            }
            Console.Read();
        }

        static bool isHappyNumber(int numberBase, int number)
        {
            List<int> pastValues = new List<int>();
            number = NaturalToBase(numberBase, number);

            do
            {
                number = aLoop(numberBase, number);
                if (pastValues.Contains(number))
                {
                    return false;
                }
                pastValues.Add(number);
            } while (number != 1 && number != 0);

            return true;
        }

        static int multiplication(int numberBase, int number)
        {
            int n = BaseToNatural(numberBase, number);
            return NaturalToBase(numberBase, n * n);
        }

        static int addition(int numberBase, int numberA, int numberB)
        {
            int a = BaseToNatural(numberBase, numberA) + BaseToNatural(numberBase, numberB);
            return NaturalToBase(numberBase, a);
        }


        static int aLoop(int numberBase, int number)
        {
            int a = 0;

            char[] split = number.ToString().ToCharArray();

            for (int i = 0; i < split.Length; i++)
            {
                int m = multiplication(numberBase, int.Parse(split[i].ToString()));
                a = addition(numberBase, a,  m);
            }

            return a;
        }

        static int BaseToNatural(int baseNumber, int number)
        {
            if (number < baseNumber)
                return number;

            int a = 0;

            char[] split = number.ToString().ToCharArray();

            for (int i = 0; i < split.Length; i++)
            {
                a += int.Parse(split[i].ToString()) * (int) (Math.Pow(baseNumber, (double)(split.Length -1 - i)));
            }

            return a;
        }

        static int NaturalToBase(int baseNumber, int number)
        {
            int a = 0;
            string num = string.Empty;


            int reminder = 0;
            if (number < baseNumber)
                return number;
            do
            {
                reminder = number % baseNumber;
                number = number / baseNumber;
                num = reminder.ToString() + num;

            } while (number != 0);

            return int.Parse(num);
        }

    }

}
