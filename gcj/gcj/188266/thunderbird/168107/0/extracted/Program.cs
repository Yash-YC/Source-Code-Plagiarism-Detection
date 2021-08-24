using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace aliennumber
{
    class Program
    {

        static string JAM = "Welcome to Code Jam";
        static int L = JAM.Length;
        
        static void Main(string[] args)
        {


            StreamReader sr = new StreamReader(AppDomain.CurrentDomain.BaseDirectory + @"\\A.in");
            StreamWriter sw = new StreamWriter(AppDomain.CurrentDomain.BaseDirectory + @"\\A.out");

            string tmp = sr.ReadLine();
            int count = Convert.ToInt32(tmp);

            for (int i = 0; i < count; i++)
            {
                string[] template = sr.ReadLine().Split(' ');
                int[] bases = new int[template.Length];
                for (int j = 0; j < template.Length;j++)
                    bases[j] = Convert.ToInt32(template[j]);

                sw.WriteLine("Case #" + Convert.ToString(i + 1) + ": " + Convert.ToString(ProblemA(bases, bases.Length)));
            }

            sr.Close();
            sw.Close();
        }

        static int ProblemA(int[] bases, int count)
        {
            int ret = 0;
            int[] mark =new int[100];
            

            for (int i = 2; ; i++)
            {
                
                
                int j = 0;
                for (j = 0; j < count; j++)
                {
                    for (int k = 0; k < 100; k++)
                        mark[k] = 0;
                    if (!IsHappyNumber(i, bases[j], mark))
                        break;
                }
                if (j == count)
                {
                    ret = i;
                    break;
                }
            }

            return ret;
        }

        static bool IsHappyNumber(int number, int bases , int[] mark)
        {
            bool ret = false;

            string sn = convert(number, bases);
            int total = 0;
            for (int i = 0; i < sn.Length; i++)
                total += Convert.ToInt32(sn[i].ToString()) * Convert.ToInt32(sn[i].ToString());
            if (total == 1)
                return true;
            else
                if (total < 100)
                {
                    if (mark[total] == 1)
                        return false;
                    else
                    {
                        mark[total] = 1;
                        if (IsHappyNumber(total, bases, mark))
                            return true;
                        else
                            return false;
                    }
                }
                else
                {
                    if (IsHappyNumber(total, bases, mark))
                        return true;
                    else
                        return false;
                }
            return ret;
        }

        static string convert(int number, int bases)
        {
            string ret = "";
            int tmp;
            do
            {
                tmp = number % bases;
                ret = tmp+ret;
                number = (number - tmp) / bases;
            } while (number > 0);
            return ret;
        }

        static int ProblemB(string template, string jam)
        {
            int ret = 0;

            int length = template.Length;


            for (int i = 0; i <= length - L; i++)
            {
                if (template.Substring(i, 1) != jam.Substring(0, 1))
                    continue;
                else
                {
                    ret = 1;

                }
            }



            return ret;
        }



    }
}
