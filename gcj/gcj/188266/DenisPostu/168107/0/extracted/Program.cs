using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ.Round1A.A
{
    class Program
    {
        static int nCases;
        static string line;
        static int small = 1;

        static string iFN = (small == 1) ? "D:/GCJ/In/A.in" : "D:/GCJ/In/ALarge.in";
        static string oFN = (small == 1) ? "D:/GCJ/Out/A.txt" : "D:/GCJ/In/ALarge.txt";

        static string Convert(int Num, int Base)
        {
            string c = "";
            while (Num > 0)
            {
                c = (Num % Base).ToString() + c;
                Num /= Base;
            }
            return c;
        }

        static int sum(string Num)
        {
            int s = 0;
            for (int i = 0; i < Num.Length; i++)
            {
                s += int.Parse(Num[i].ToString()) * int.Parse(Num[i].ToString());
            }
            return s;
        }

        static bool Lucky(int Num, int Base)
        {
            int i = 50;
            string NumBase = Convert(Num, Base);
            string NumSum = Convert(sum(NumBase), Base);
            while (i-- > 0)
            {
                NumSum = Convert(sum(NumSum), Base);
                if (NumSum == "1") return true;
            }
            return false;
        }

        static bool Good(int Num, List<int> bases)
        {
            for (int i = 0; i < bases.Count; i++)
            {
                if (!Lucky(Num, bases[i])) return false;
            }
            return true;
        }

        static void Main(string[] args)
        {
            try
            {
                FileStream ifs = File.OpenRead(iFN);
                FileStream ofs = File.Create(oFN);

                StreamReader reader = new StreamReader(ifs);
                StreamWriter writer = new StreamWriter(ofs);

                nCases = int.Parse(reader.ReadLine());
                for (int Case = 1; Case <= nCases; Case++)
                {
                    List<int> bases = new List<int>();
                    line = reader.ReadLine();
                    string[] parts = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    for (int i = 0; i < parts.Length; i++) bases.Add(int.Parse(parts[i]));

                    int Num = 2;
                    while (!Good(Num, bases)) Num++;

                    writer.WriteLine("Case #{0}: {1}", Case, Num);

                }

                writer.Close();
                reader.Close();
                ofs.Close();
                ifs.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                Console.ReadKey();
            }
        }
    }
}
