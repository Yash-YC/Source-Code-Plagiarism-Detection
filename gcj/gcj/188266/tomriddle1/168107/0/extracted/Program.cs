using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;


namespace GoogleCodeJam
{
    class Program
    {
        const int base10 = 10;
        static char[] cHexa = new char[]{'A','B','C','D','E','F'};
        static int[] iHexaNumeric = new int[] {10,11,12,13,14,15};
        static int[] iHexaIndices = new int[] {0,1,2,3,4,5};
        static int asciiDiff = 48;

        static HashSet<string> happyNumbers = new HashSet<string>();

        static void Main(string[] args)
        {
            string input = @"c:\input\A-small-attempt1.in";
            string output = @"c:\output\A-small-attempt1.out";
            
            /*
            string input = @"c:\input\A-large.in";
            string output = @"c:\output\A-large.out";
             // */ 

            StreamReader reader = new StreamReader(input);
            StreamWriter writer = new StreamWriter(output);

            
            int numOfTestCases = Int32.Parse(reader.ReadLine());
            
            for (int i = 0; i < numOfTestCases; i++)
            {
                string[] bases = reader.ReadLine().Split(new char[] { ' ' });
                int[] intBases = new int[bases.Length];
                for (int j = 0; j < bases.Length; j++)
                {
                    intBases[j] = Int32.Parse(bases[j]);
                }

                int? num = findHappyInAllBases(intBases);

                if (num.HasValue)
                writer.WriteLine("Case #"+(i+1)+": "+num);            
            }
            reader.Close();
            writer.Close();
         }

        static int? findHappyInAllBases(int[] bases)
        {
            for (int i = 2; i < Int32.MaxValue; i++)
            {
                bool f = true;
                foreach (int b in bases)
                {
                    f = f && isHappy(i, b);
                    if (!f) break;    
                }

                if (f)
                    return i;
            }
            return null;
        }

        static bool isHappy(int x, int numbase)
        {
            string num = DecimalToBase(x, numbase);
            if (happyNumbers.Contains(num+"z"+numbase)) 
                return true;
            char[] digits = num.ToCharArray();
            string sum = "0";
            HashSet<string> sums = new HashSet<string>();

            while (sum != "1")
            {
                sum = "0";
                foreach (char c in digits)
                {
                    string squareOfDigit = square(c.ToString(), numbase);
                    sum = add(sum, squareOfDigit, numbase);
                }

                if (sums.Contains(sum))
                    break;

                sums.Add(sum);

                digits = sum.ToCharArray();
            }

            if (sum == "1")
            {
                // Happy number add it to the list of happy numbers
                happyNumbers.Add(num+"z"+numbase);

                //Also add each of the sums
                foreach (string s in sums)
                {
                    if (!happyNumbers.Contains(s+"z"+numbase))
                    happyNumbers.Add(s+"z"+numbase);
                }

                return true;
            }

            return false;
        }

        static string DecimalToBase(int iDec, int numbase)
        {
            string strBin = "";
            int[] result = new int[32];
            int MaxBit = 32;
            for (; iDec > 0; iDec /= numbase)
            {
                int rem = iDec % numbase;
                result[--MaxBit] = rem;
            }
            for (int i = 0; i < result.Length; i++)
                if ((int)result.GetValue(i) >= base10)
                    strBin += cHexa[(int)result.GetValue(i) % base10];
                else
                    strBin += result.GetValue(i);
            strBin = strBin.TrimStart(new char[] { '0' });
            return strBin;
        }

        static int BaseToDecimal(string sBase, int numbase)
        {
            int dec = 0;
            int b;
            int iProduct = 1;
            string sHexa = "";
            if (numbase > base10)
                for (int i = 0; i < cHexa.Length; i++)
                    sHexa += cHexa.GetValue(i).ToString();
            for (int i = sBase.Length - 1; i >= 0; i--, iProduct *= numbase)
            {
                string sValue = sBase[i].ToString();
                if (sValue.IndexOfAny(cHexa) >= 0)
                    b = iHexaNumeric[sHexa.IndexOf(sBase[i])];
                else
                    b = (int)sBase[i] - asciiDiff;
                dec += (b * iProduct);
            }
            return dec;
        }

        static string square(string digit, int numbase)
        {
            int dec = BaseToDecimal(digit, numbase);
            int x = dec * dec;
            return DecimalToBase(x, numbase);
        }

        static string add(string x, string y, int numbase)
        {
            int x1 = BaseToDecimal(x, numbase);
            int x2 = BaseToDecimal(y, numbase);

            int sum = x1 + x2;
            return DecimalToBase(sum, numbase);
        }        
    }
}

