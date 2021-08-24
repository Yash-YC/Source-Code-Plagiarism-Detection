using System;
using System.Collections.Generic;
using System.Text;
using System.Collections.ObjectModel;
using System.IO;
using GoogleCodeJam.RoundOne;

namespace GoogleCodeJam
{
    public class InputAndOutPut
    {
        public static Collection<string> ReadData(string filePath)
        {
            Collection<string> data = new Collection<string>();
            FileStream fileStream = new FileStream(filePath, FileMode.Open, FileAccess.Read);
            StreamReader reader = new StreamReader(fileStream);
            while (!reader.EndOfStream)
            {
                data.Add(reader.ReadLine());
            }

            reader.Close();
            fileStream.Close();
            return data;
        }

        public static void WriteResult(string filePath,Collection<string> data)
        {
            FileStream fileStream = new FileStream(filePath, FileMode.Create, FileAccess.Write);
            StreamWriter writer = new StreamWriter(fileStream);
            foreach (string str in data)
            {
                writer.WriteLine(str);
            }
            writer.Close();
            fileStream.Close();
        }
    }
    public class Program
    {
        static void Main(string[] args)
        {
            //GoogleCodeJam.AlienLanguage.ProblemSolver solver = new GoogleCodeJam.AlienLanguage.ProblemSolver();
            //solver.Solve();
            //GoogleCodeJam.WelcometCodeJam.ProblemSolver solver = new GoogleCodeJam.WelcometCodeJam.ProblemSolver();
            //solver.Solve();
            MultiBaseProblemSolver t = new MultiBaseProblemSolver();
            t.Solve();
        }
    }
}
