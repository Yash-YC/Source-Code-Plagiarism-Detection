using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;


namespace ConsoleApplication4
{
    class Program
    {
        static int[] IntToArray(int x, int basis)
        {
            List<int> result = new List<int>();
            while (x != 0)
            {
                result.Add(x % basis);
                x = x - (x % basis);
                x /= basis;
            }
            result.Reverse(0, result.Count);
            return result.ToArray<int>();
        }
        static int ArrayToInt(int[] array, int basis)
        {
            int result=0;
            int[] reverse = array.Reverse<int>().ToArray<int>();
            for (int i = 0; i < reverse.Length; i++)
                result += reverse[i] * (int) Math.Pow(basis, i);
            return result;
        }
        static int SumSquares(int[] array)
        {
            int total = 0;
            foreach (int i in array)
                total += i*i;
            return total;
        }
        static bool IsHappy(int[] x, int basis)
        {
            List<int> history = new List<int>();
            bool result = true;
            while (SumSquares(x) != 1)
            {
                if (history.Contains(SumSquares(x)))
                {
                    result = false;
                    break;
                }
                else
                {
                    history.Add(SumSquares(x));
                    x = IntToArray(SumSquares(x), basis);
                }
            }
            return result;
        }
        static void Main(string[] args)
        {
            StreamReader input = new StreamReader(@"C:\Users\zzy\Desktop\A-small-attempt0 (1).in");
            StreamWriter output = new StreamWriter(@"C:\Users\zzy\Desktop\outt.txt");
            bool happy=true;
            int cases = Int32.Parse(input.ReadLine());
            for (int i = 0; i < cases; i++)
            {
                int[] bases=Array.ConvertAll<string,int>(input.ReadLine().Split(' '),new Converter<string,int>(System.Convert.ToInt32));
                int j;
     
                for(j=2;;j++)
                {
                    happy = true;
                    foreach(int k in bases)
                        happy&=IsHappy(IntToArray(j,k),k);
                    if (happy)
                        break;
                }
                output.WriteLine("Case #{0}: {1}",i+1,j);
            }
            input.Close();
            output.Close();
        }
                
            

        }
    }

