using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        public static object MulBase(int n, ArrayList OtherBase)
        {
            int b = OtherBase.Count;
            Stack Digits = new Stack();
            do
            {
                Digits.Push(n % b);
                n /= b;
            } while (n != 0);
            string temp = "";
            while (Digits.Count > 0)
            {
                temp += OtherBase[(int)Digits.Pop()].ToString();
            }
            return temp;
        }

        static void Main(string[] args)
        {
            TextReader tr = new StreamReader("C:\\Documents and Settings\\avparate\\Desktop\\input.txt");
            TextWriter tw = new StreamWriter("C:\\Documents and Settings\\avparate\\Desktop\\output.txt");

            int csno, output;
            csno = int.Parse(tr.ReadLine());

            string input = null;
                        
            for (int caseno = 1; caseno <= csno; caseno++)
            {
                input = tr.ReadLine();
                string[] first_line = input.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                ArrayList[] array = new ArrayList[first_line.Length]; //seperate individual lists to be added in main list.
                for (int i = 0; i < array.Length; i++)
                {
                    array[i] = new ArrayList();
                }
                for (int i = 0; i < first_line.Length; i++)
                {
                    for (int j = 0; j < int.Parse(first_line[i]); j++)
                    {
                        array[i].Add(j);	// 1st list
                    }
                }

                bool condition = true;
                int K = 2;
                while (condition)
                {
                    int count =0;
                    int xx = 0;

                        for (int mm = 0; mm < first_line.Length; mm++)
                        {
                            ArrayList abc = new ArrayList();
                            object result = MulBase(K, array[mm]);
                            string KK = Convert.ToString(result);
                            xx = 0;
                            while (xx != 1)
                            {
                                xx = 0;
                                for (int ii = 0; ii < KK.Length; ii++)
                                {
                                    xx += int.Parse(KK[ii].ToString()) * int.Parse(KK[ii].ToString());

                                }
                                if (!abc.Contains(xx))
                                    abc.Add(xx);
                                else
                                    break;
                                result = MulBase(xx, array[mm]);
                                KK = Convert.ToString(result);
                                if (xx == 1)
                                    count++;
                                if (count == first_line.Length)
                                {
                                    output = K;
                                    condition = false;
                                }
                            }

                        }
                        K++;

                }

                
                
                
                
                // Print output line
                tw.WriteLine("Case #{0}: {1}", caseno,--K); 
            }

            tr.Close();
            tw.Close();
        }
    }
}