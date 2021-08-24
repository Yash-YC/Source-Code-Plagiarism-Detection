// Name:     Yoel Grodentzik
// UserID:   Lordxguy@aol.com
// Language: C#

using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Collections;

namespace MultiBaseHappiness
{
    class MultiBaseHappiness
    {
        static void Main(string[] args)
        {
            string inputFile = @"C:\a-small.in";
            string outputFile = @"C:\a-small.out";

            StreamReader sr;
            StreamWriter sw;

            sr = new StreamReader(inputFile);
            sw = new StreamWriter(outputFile);

            int numCases = Convert.ToInt32(sr.ReadLine());
            Hashtable bases = new Hashtable();

            for (int i = 2; i <= 10; i++)
            {
                Hashtable htbl = new Hashtable();
                htbl.Add(1.0, 1);
                bases.Add(i, htbl);
            }
            for (int i = 0; i < numCases; i++)
            {
            
                string line = sr.ReadLine();
                string[] str = line.Split(' ');
                

                List<int> theBases = new List<int>();
                //List<Hashtable> tbls = new List<Hashtable>();
                for (int j = 0; j < str.Length; j++)
                {
                    theBases.Add(Convert.ToInt32(str[j]));
                }

                double num = 2;
                bool stillHappy = false;

                while (!stillHappy)
                {
                    stillHappy = true;
                    foreach (int k in theBases)
                    {
                        //int k = Convert.ToInt32(key);
                        Hashtable tempTbl = new Hashtable();
                        
                        double convNum = conv(num, 10, k);

                        while (!tempTbl.ContainsKey(convNum) && !((Hashtable)bases[k]).ContainsKey(convNum))
                        {
                            tempTbl.Add(convNum, 1);
                            convNum = sumDigits(convNum, k);
                        }

                        if (tempTbl.ContainsKey(convNum) || ( ((Hashtable)bases[k]).ContainsKey(convNum) && ((int)((Hashtable)bases[k])[convNum]) == 0))
                            stillHappy = false;

                        foreach (object key2 in tempTbl.Keys)
                        {
                            double d = Convert.ToDouble(key2);
                            if (stillHappy)
                                ((Hashtable)bases[k]).Add(d, 1);
                            else
                                ((Hashtable)bases[k]).Add(d, 0);
                        }
                        tempTbl.Clear();
                        tempTbl = null;
                        
                        if (!stillHappy)
                            break;

                    }

                    if (stillHappy)
                        break;
                    else
                        num++;
                    
                }
                           
                string outString = "Case #" + (i + 1) + ": " + num;
                sw.WriteLine(outString);

                theBases = null;
            }

            sr.Close();
            sw.Close();

            sr = null;
            sw = null;
        }

        static double conv(double x, int b1, int b2)
        {

            if (x == 0)
                return 0;
            string xStr = x.ToString();
            double xT = 0;
            
            
            for (int i = xStr.Length - 1; i >= 0; i--)
                xT += (xStr[i] - 48) * Math.Pow(b1, xStr.Length - 1 - i);

            int numDigits = Convert.ToInt32(Math.Ceiling(Math.Log(xT + 1, b2)));
            string ans = "";
            for(int i = numDigits - 1; i >= 0; i--)
            {
                ans += Math.Floor(xT / Math.Pow(b2, i));
                xT -= Math.Floor(xT/Math.Pow(b2, i)) * Math.Pow( b2, i);
            }

            return Convert.ToDouble(ans);
        }

        static double add(double x, double y, int b)
        {
            return conv(conv(x, b, 10) + conv(y, b, 10), 10, b);
        }

        static double sqr(double x, int b)
        {
            return conv(conv(x, b, 10) * conv(x, b, 10), 10, b);
        }

        static double sumDigits(double x, int b)
        {
            string xStr = x.ToString();
            double tot = sqr(xStr[0] - 48, b);
            for (int i = 1; i < xStr.Length; i++)
            {
                tot = add(tot, sqr(xStr[i] - 48,b) , b);
            }
            return tot;
        }

        /* static double add(int x, int y, int b)
         {
             string xStr = x.ToString();
             string yStr = y.ToString();

             double xT = 0;
             double yT = 0;

             double sum = 0;
             for (int i = xStr.Length - 1; i >= 0; i--)
             {
                 xT += xStr[i] * Math.Pow(b, xStr.Length - 1 - i);
             }

             for (int i = xStr.Length - 1; i >= 0; i--)
             {
                 yT += xStr[i] * Math.Pow(b, yStr.Length - 1 - i);
             }

            
         }*/


    }
}
