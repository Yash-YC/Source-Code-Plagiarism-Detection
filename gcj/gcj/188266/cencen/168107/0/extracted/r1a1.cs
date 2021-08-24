using System;
using System.Collections;
using System.IO;
using System.Text;

class BooleanTree
{
    public static bool is_happy(string s, int b, ArrayList c)
    {
        //if (s.Length == 1 && int.Parse(s) > 1)
        //    return false;
        //else 
        if (s.Length == 1 && int.Parse(s) == 1)
            return true;
        else
        {
            int sum = 0;
            for (int i = 0; i < s.Length; i++)
                sum += int.Parse(s[i].ToString()) * int.Parse(s[i].ToString());
            if (c.Contains(sum))
                return false;
            else
            {
                c.Add(sum);
                return is_happy(tobase(sum, b), b,c);
            }
        }
    }

    public static string tobase(int num, int b)
    {
        System.Text.StringBuilder sb = new System.Text.StringBuilder();
        int n = num;
        while (n > 0)
        {
            sb.Append((n % b).ToString());
            n = n / b;
        }
        return sb.ToString();
    }
    
   

    public static void Main()
    {
        StreamReader SR;
        SR = File.OpenText("A-small-attempt0.in");
        StreamWriter SW;
        SW = File.CreateText("A.out");

        int T = int.Parse(SR.ReadLine());
        for (int l = 0; l < T; l++)
        {
            //codes here
            String s = SR.ReadLine();
            string[] wo = s.Split(' ');
            
            int num=2;
            //Console.WriteLine(is_happy("11110001",2));
                for (num=2; num <=1000000; num++)
                {
                   
                    int i=0;
                    for (i = 0; i < wo.Length; i++)
                    {
                        //if (int.Parse(wo[i]) == 2)
                        //    continue;
                        int b = int.Parse(wo[i]);
                        ArrayList c = new ArrayList();
                        if (!is_happy(tobase(num,b),b,c))
                        {
                           //Console.WriteLine(num);
                           // a[i] = true;
                            break;
                        }
                    }
                    if (i == wo.Length)
                        break;
                }
                //Console.WriteLine(num);
            //while (num < 10000)
            //{
            //    for (int i = 0; i < wo.Length; i++)
            //    {
            //        int b = int.Parse(wo[i].ToString());
            //        System.Text.StringBuilder sb = new System.Text.StringBuilder();
            //        while (num > 0)
            //        {
            //            sb.Append((num % b).ToString());
            //            num = num / b;

            //        }
            //        Console.WriteLine(sb);
            //        string s2 = sb.ToString();
            //        if (!is_happy(s2))
            //            num++;
            //        else break;
            //    }
            //}

            Console.WriteLine("Case #" + (l + 1) + ": " + num);
            SW.WriteLine("Case #" + (l + 1) + ": " + num);
        }

        SR.Close();
        SW.Close();
    }

}