using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ.Round1A.C
{
    class Program
    {
        static int nCases;
        static int C, N;
        static int small = 1;

        static string iFN = (small == 1) ? "D:/GCJ/In/C.in" : "D:/GCJ/In/CLarge.in";
        static string oFN = (small == 1) ? "D:/GCJ/Out/C.txt" : "D:/GCJ/In/CLarge.txt";

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
                    string[] parts = reader.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    C = int.Parse(parts[0]);
                    N = int.Parse(parts[1]);

                    double step = 1.0 * C / N;
                    double probability = 1.0 * N / C;
                    double decks = 1;

                    if(N < C)
                        while(probability * decks < 1.5)
                        {
                            decks += step;
                        }

                    writer.WriteLine("Case #{0}: {1,-10:F8}", Case, decks);
                    Console.WriteLine("Case #{0}: {1,-10:F8}", Case, decks);
                }
                Console.WriteLine();
                Console.WriteLine("Execution done. ");
                Console.ReadLine();

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
