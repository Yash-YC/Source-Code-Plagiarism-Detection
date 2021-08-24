using System;
using System.Collections;
using System.Text;
using System.IO;

namespace ConsoleApplication5
{
    class Program
    {
        static void Main(string[] args)
        {
            Class2 c = new Class2();

            //Console.WriteLine(c.FindSmallest(7));
            ////Console.WriteLine(c.isHappy(143, 7));
            //Console.ReadLine();

            string path1 = "A-small-attempt0.in";
            string path2 = "o.out";
            FileStream fs = File.OpenRead(path1);

            StreamReader sr = new StreamReader(fs);
            StreamWriter sw = new StreamWriter(path2, false);
            int N = int.Parse(sr.ReadLine());
            for (int i = 0; i < N; i++)
            {
                string l = sr.ReadLine();
                string[] jinzhi = l.Split(' ');
                int[] intJInzhi = new int[jinzhi.Length];
                for (int j = 0; j < jinzhi.Length; j++)
                    intJInzhi[j] = int.Parse(jinzhi[j]);

                int retN = c.AllJinzhi(intJInzhi);
                sw.WriteLine(string.Format("Case #{0}: {1}", (i + 1), retN));
            }
            sr.Close();
            fs.Close();
            sw.Close();

        }
 
      
    }
}
