using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _1A
{
    class Program
    {
        static System.IO.StreamReader SR;
        static System.IO.StreamWriter SW;

        static void Main(string[] args)
        {
            SR = new System.IO.StreamReader("test.in");
            SW = new System.IO.StreamWriter("test.out");
            int C = int.Parse(SR.ReadLine());
            for (int i = 0; i < C; i++)
                SW.WriteLine("Case #" + (i + 1) + ": " + Solve());
            SW.Close();
            SR.Close();
        }

        static int Solve()
        {
            int[] Bases = Array.ConvertAll(SR.ReadLine().Split(new char[] { ' ' }), new Converter<string, int>(int.Parse));
            for (int n = 2; ; n++)
            {
                bool success = true;
                for (int i = 0; i < Bases.Length; i++)
                    success = success && Number.isHappy(new Number(Bases[i], n));
                if (success)
                    return n;
            }
        }

        public class Number
        {
            int Base;
            int[] values;
            public Number(int Base, int Decimal)
            {
                this.Base = Base;
                int topPlace;
                for (topPlace = 0; Math.Pow(Base, topPlace) <= Decimal; topPlace++) ;
                values = new int[topPlace];
                for (int place = topPlace-1; place >= 0 && Decimal > 0; place--)
                {
                    int inc = (int)Math.Pow(Base, place);
                    for (values[place] = 0; values[place] < Base && Decimal >= inc; values[place]++)
                        Decimal -= inc;
                }
            }

            public void AddNumber(Number other)
            {
                int [] R = new int[(values.Length < other.values.Length ? other.values.Length : values.Length)+1];
                int carry;
                for (int i = 0; i < R.Length; i++)
                {
                    int sum = (i < values.Length ? values[i] : 0) + (i < other.values.Length ? other.values[i] : 0);
                    if ((carry = sum - Base) > 0)
                    {
                        R[i] = sum - carry;
                        R[i + 1] = carry;
                    }
                    else
                        R[i] = sum;
                }
            }

            public int decimalEquiv()
            {
                int R = 0;
                for (int p = 0; p < values.Length; p++)
                    R += values[p] * ((int)Math.Pow(Base, p));
                return R;
            }

            public Number squareAndAdd()
            {
                int R = 0;
                for (int p = 0; p < values.Length; p++)
                    R += new Number(Base, values[p] * values[p]).decimalEquiv();
                return new Number(Base, R);
            }

            public static bool isHappy(Number R)
            {
                for (int i = 0; i < 20; i++)
                    if (R.decimalEquiv() != 1)
                        R = R.squareAndAdd();
                    else
                        return true;
                return false;
            }
        }
    }
}
