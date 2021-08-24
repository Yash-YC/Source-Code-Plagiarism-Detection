using System;
using System.IO;
using System.Collections.Generic;
using System.Collections;
using System.Text;


namespace GTask02
{
    public class BaseConvert
    {
        private static readonly char[] IntAlpha;
        private static readonly char[] AlphaInt;

        static BaseConvert()
        {
            //Integers first then alpha
            IntAlpha = new char[] { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 
                               'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 
                               'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

            //Alpha first then integers
            AlphaInt = new char[] { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 
                               'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 
                               'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        }

        public static string BetweenBases(string Value, sbyte FromBase, sbyte ToBase)
        {
            return Encode(Decode(Value, FromBase, true), ToBase, true);
        }

        public static string BetweenBases(string Value, sbyte FromBase, sbyte ToBase, bool NumeralsFirst)
        {
            if (FromBase < 2 || FromBase > 36) { throw new ArgumentOutOfRangeException("FromBase", "Value must be between 2 and 36"); }
            if (ToBase < 2 || ToBase > 36) { throw new ArgumentOutOfRangeException("ToBase", "Value must be between 2 and 36"); }

            return Encode(Decode(Value, FromBase, NumeralsFirst), ToBase, NumeralsFirst);
        }

        public static string Encode(long Value, sbyte Base)
        {
            return Encode(Value, Base, true);
        }

        public static string Encode(long Value, sbyte Base, bool NumeralsFirst)
        {
            if (Base < 2 || Base > 36) { throw new ArgumentOutOfRangeException("Base", "Value must be between 2 and 36"); }

            string Encoded = "";
            char[] WorkingSet = NumeralsFirst ? IntAlpha : AlphaInt;

            if (Value == 0) return WorkingSet[0].ToString().ToUpper();

            while (Value != 0)
            {
                Encoded = WorkingSet[Value % Base] + Encoded;
                Value /= Base;
            }

            Encoded = Encoded.ToUpper();

            return Encoded;
        }

        public static long Decode(string Input, sbyte Base)
        {
            return Decode(Input, Base, true);
        }

        public static long Decode(string Input, sbyte Base, bool NumeralsFirst)
        {
            if (Base < 2 || Base > 36) { throw new ArgumentOutOfRangeException("Base", "Value must be between 2 and 36"); }

            char[] WorkingSet = NumeralsFirst ? IntAlpha : AlphaInt;

            Input = Input.Trim();
            Input = Input.ToLower();

            long Decoded = 0;

            char[] CharArray = Input.ToCharArray();

            Array.Reverse(CharArray);

            for (int i = 0; i < CharArray.Length; i++)
            {
                if (Array.IndexOf(WorkingSet, CharArray[i]) >= Base)
                {
                    throw new ArgumentOutOfRangeException("Input", "Input contains characters that are not in the base set");
                }

                // find the index in the array that the char resides
                int valueindex = Array.IndexOf(WorkingSet, CharArray[i]);

                // the actual value given by that is 
                // the index multiplied by the base number to the power of the index
                int temp = valueindex * Convert.ToInt32(Math.Pow(Base, i));

                // add this value to the counter until there are no more values
                Decoded += (long)temp;
            }
            // return the total result
            return Decoded;
        }
    }

    // http://en.wikipedia.org/wiki/Happy_number
    class Program
    {   
        static string sDir = @"C:\Algorithms\G-Task-HappyBase\";
        static string sFileName = sDir + "data_01_01.txt";
        static string sOutName = sDir + "out_01_01.txt";

        static StreamReader m_RE;
        static TextWriter m_TW;

        static int[] HAPPY_10 = new int[] {1, 7, 10, 13, 19, 23, 28, 31, 32, 44, 49, 68, 70, 79, 82, 86, 91, 94, 97, 100, 103, 109, 129, 130, 133, 139, 167, 176, 188, 190, 192, 193, 203, 208, 219, 226, 230, 236, 239, 262, 263, 280, 291, 293, 301, 302, 310, 313, 319, 320, 326, 329, 331, 338, 356, 362, 365, 367, 368, 376, 379, 383, 386, 391, 392, 397, 404, 409, 440, 446, 464, 469, 478, 487, 490, 496};


        static String ConvertBase(string s_value, sbyte toBase)
        {
            return BaseConvert.BetweenBases(s_value, (sbyte)10, toBase);
        }

        static bool TestNumber(String s_num, sbyte toBase)
        {
            //Print(String.Format("{0} , {1}", s_num, toBase));

            switch (toBase)
            {
                case 2:
                    return true;
                case 3:
                    if (s_num.Equals("2") || s_num.Equals("11") || s_num.Equals("12") || s_num.Equals("22"))
                    {
                        return false;
                    }
                    break;
                case 4:
                    return true;
                case 5:
                    if (s_num.Equals("4") || s_num.Equals("31") || s_num.Equals("20") || s_num.Equals("23") || s_num.Equals("33"))
                    {
                        return false;
                    }
                    break;
                case 6:
                    if (s_num.Equals("32") || s_num.Equals("21") || s_num.Equals("5") || s_num.Equals("41") || s_num.Equals("25") || s_num.Equals("45") || s_num.Equals("105") || s_num.Equals("42"))
                    {
                        return false;
                    }
                    break;
                case 7:
                    if (s_num.Equals("2") || s_num.Equals("4") || s_num.Equals("22") || s_num.Equals("11") || s_num.Equals("34") || s_num.Equals("13") || s_num.Equals("23") || s_num.Equals("16") || s_num.Equals("52") || s_num.Equals("41") || s_num.Equals("23") || s_num.Equals("63") || s_num.Equals("44"))
                    {
                        return false;
                    }
                    break;
                case 8:
                    if (s_num.Equals("4") || s_num.Equals("20") || s_num.Equals("5") || s_num.Equals("31") || s_num.Equals("12") || s_num.Equals("32") || s_num.Equals("15") || s_num.Equals("24") || s_num.Equals("64"))
                    {
                        return false;
                    }
                    break;
                case 9:
                    if (s_num.Equals("55") || s_num.Equals("58") || s_num.Equals("108") || s_num.Equals("72") || s_num.Equals("58") || s_num.Equals("45") || s_num.Equals("75") || s_num.Equals("82") || s_num.Equals("75"))
                    {
                        return false;
                    }
                    break;
                case 10:
                    int n = int.Parse(s_num);
                    for (int i = 0; i < HAPPY_10.Length; i++)
                    {
                        if (n == HAPPY_10[i])
                        {
                            return true;
                        }
                    }
                    if (n < 500)
                    {
                        return false;
                    }
                    break;
            }

            int sum = 0;
            for (int i = 0; i < s_num.Length; i++)
            {
                int k = int.Parse(s_num[i].ToString());
                sum += k * k;
            }
            
            String snext = ConvertBase(sum.ToString(), toBase);
            if (snext.Equals("1"))
            {
                return true;
            }
            else
            {
                return TestNumber(snext, toBase);
            }
        }


        static void LoadData()
        {
            Print("Open data file : " + sFileName);

            m_RE = File.OpenText(sFileName);
            m_TW = new StreamWriter(sOutName);

            Int32 iCases = Int32.Parse(m_RE.ReadLine());
            for (Int32 i = 0; i < iCases; i++)
            {
                String sLine = m_RE.ReadLine();
                String[] aBases = sLine.Split(new char[] { ' ' });
                
                int  hNum = 0;
                for (int m = 2; m < int.MaxValue; m++)
                {
                    bool bRes = true;
                    for (int j = 0; j < aBases.Length; j++)
                    {
                        sbyte toBase = sbyte.Parse(aBases[j]);
                        String s_num = ConvertBase(m.ToString(), toBase); ;
                        bRes = bRes && TestNumber(s_num, toBase);
                    }
                    if (bRes)
                    {
                        hNum = m;
                        break;
                    }
                }
                m_TW.WriteLine(String.Format("Case #{0}: {1}", i + 1, hNum));
            }

            m_RE.Close();
            m_TW.Close();
        }

        static void Main(string[] args)
        {
            LoadData();
        }

        static void Print(string msg)
        {
            System.Console.Out.WriteLine(msg);
            System.Diagnostics.Debug.WriteLine(msg);
        }


    }
}
