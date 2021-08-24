using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A_The_Last_Word
{
    class Program
    {
        static void Main(string[] args)
        {
            var file = "A-large";
            var input = File.OpenText($@"{file}.in");

            StringBuilder sb = new StringBuilder();
            int T = int.Parse(input.ReadLine());
            for (int t = 1; t <= T; ++t)
            {

                var last = "";
                string word = input.ReadLine();

                foreach (var letter in word)
                {
                    if (last == "" || letter >= last[0])
                    {
                        last = letter + last;
                    }
                    else
                    {
                        last = last + letter;
                    }
                }
                sb.AppendLine(string.Format($"Case #{t}: {last}"));
            }
            File.WriteAllText($@"{file}.out", sb.ToString());
        }
    }
}
