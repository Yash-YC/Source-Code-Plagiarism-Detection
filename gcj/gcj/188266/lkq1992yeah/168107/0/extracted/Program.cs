using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int t, j;
            int check1, check2, n;
            bool find = false;
            int[] b;
            int[] record;
            string info;
            string[] split;
            StreamReader sr = new StreamReader("c:\\temp3.in", Encoding.GetEncoding("gb2312"));
            StreamWriter sw = new StreamWriter("c:\\out.txt", true, Encoding.GetEncoding("gb2312"));
            t = Convert.ToInt32(sr.ReadLine());
            for (int i = 0; i < t; i++)
            {
                b = new int[3];
                split = new string[3];
                record = new int[50];
                info = sr.ReadLine();
                split = info.Split(' ');
                j = 0;
                foreach (string str in split)
                {
                    b[j] = Convert.ToInt32(str);
                    j++;
                }
                for (n = 2; ; n++)
                {
                    for (int k = 0; k <= 2&&b[k]!=0; k++)
                    {
                        record = new int[50];
                        check1 = n;
                        find = false;
                        while (check1 != 1)
                        {
                            check2 = Toit(check1, b[k]);
                            check1 = Cal(check2);
                            for (j = 0; record[j] != 0; j++)
                            {
                                if (check1 == record[j])
                                {
                                    find = true;        //死循环
                                    break;
                                }

                            }
                            if (find == true)
                                break;
                            else
                                record[j] = check1;
                        }
                        if (find == true)
                            break;

                    }
                    if (find == false)
                    {
                        sw.WriteLine("Case #{0}: {1}", i + 1, n);
                        break;
                    }
                }
            }
            sw.Close();
        }
        static int Toit(int num, int b)
        {
            int re = 0, temp = 0, n;
            n = num;
            while (n > 0)
            {
                re += (n % b) * Convert.ToInt32(Math.Pow(10, temp));
                n /= b;
                temp++;
            }
            return re;
        }

        static int Cal(int num)
        {
            int re = 0, n;
            n = num;
            while (n > 0)
            {
                re += (n % 10) * (n % 10);
                n /= 10;
            }
            return re;
        }
    }
}
