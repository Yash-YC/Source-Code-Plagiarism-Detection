using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Cards {
    class Program {
        static void Main(string[] args) {
            //string res = processFile("..\\..\\A.in");
            //File.WriteAllLines("..\\..\\A.out", new string[] { res });
            string res = processFile("..\\..\\C-small-attempt0.in");
            File.WriteAllLines("..\\..\\C-small-attempt0.out", new string[] { res });
            //string res = processFile("..\\..\\A-large.in");
            //File.WriteAllLines("..\\..\\A-large.out", new string[] { res });
            //Console.Write(res);
            Console.WriteLine("Press any key...");
            Console.ReadKey();
        }

        public static string processFile(string filePath) {
            StringBuilder b = new StringBuilder();
            List<string> fileContent = getFileContent(filePath);
            string line = null;
            int T = int.Parse(fileContent[0]);
            for (int tt = 1;tt <= T;tt++) {
                line = fileContent[tt];
                decimal res = solveCase(line);
                b.AppendLine(string.Format("Case #{0}: {1:F7}", tt, res).Replace(",","."));
            }
            return b.ToString();
        }

        static decimal solveCase(string line) {
            string[] _bases = line.Split(' ');
            return (decimal.Parse(_bases[0]) + decimal.Parse(_bases[1])) / decimal.Parse(_bases[1]);
        }

        public static List<string> getFileContent(string filePath) {
            return new List<string>(System.IO.File.ReadAllLines(filePath));
        }
    }
}
