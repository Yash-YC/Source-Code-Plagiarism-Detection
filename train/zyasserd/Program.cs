using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using static System.Console;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = @"C:\Users\Zezo\Desktop\A-small-attempt3";
            using (StreamWriter StW = new StreamWriter(path + ".out"))
            using (StreamReader StR = new StreamReader(path + ".in"))
            {
                StR.ReadLine();
                int LC = 0;

                string line;
                while ((line = StR.ReadLine()) != null)
                {
                    int subLen = line.Length - 1;
                    List<string> P = new List<string>();
                    #region
                    for (int i = (1 << subLen) - 1; i >= 0; i--)
                    {
                        P.Add(line[0].ToString());
                        for (int j = 1; j <= subLen; j++)
                        {
                            if ((i & (1 << subLen - j)) == 0)
                                //P[P.Count - 1].Insert(0, line[j].ToString());
                                P[P.Count - 1] = line[j] + P[P.Count - 1];
                            else
                                //P[P.Count - 1].Add(line[j].ToString());
                                P[P.Count - 1] = P[P.Count - 1] + line[j];
                        }
                    }
                    #endregion
                    #region
                    //int index = 0, max = 0;
                    //foreach (string item in P)
                    //{
                    //    int count = 0;
                    //    int temp = 0;
                    //    //for (int i = item.Count - 2; i >= 0; i--)
                    //    //{
                    //    //    if (item[i] <= item[i + 1])
                    //    //        count++;
                    //    //    else
                    //    //        break;
                    //    //}
                    //    //for (int i = 0; i < item.Length - 1; i++)
                    //    //{
                    //    //    if (i == 0)
                    //    //        temp = string.Compare(item[i].ToString(), item[i + 1].ToString());
                    //    //    if (string.Compare(item[i].ToString(), item[i + 1].ToString()) == temp)
                    //    //        count++;
                    //    //    else
                    //    //        break;
                    //    //}
                    //    for (int i = item.Length - 1; i > 0; i--)
                    //    {
                    //        if (i == item.Length - 1)
                    //            temp = string.Compare(item[i].ToString(), item[i - 1].ToString());
                    //        if (string.Compare(item[i].ToString(), item[i - 1].ToString()) == temp)
                    //            count++;
                    //        else
                    //            break;
                    //    }
                    //    if (count > max)
                    //    {
                    //        max = count;
                    //        index = P.IndexOf(item);
                    //    }
                    //}
                    #endregion

                    //StW.WriteLine($"Case #{++LC}: {string.Concat(P[index].Select(x => (char)(x ^ '@')))}");
                    P.Sort();
                    StW.WriteLine($"Case #{++LC}: {P[P.Count-1]}");
                }
            }
        }
    }
}
