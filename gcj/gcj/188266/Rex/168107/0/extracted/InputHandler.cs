using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ.MultiBase
{
    public class InputHandler
    {
        private string FilePath { get; set; }
        public List<List<int>> Bases { get; set; }

        public InputHandler(string path)
        {
            FilePath = path;
            Bases = new List<List<int>>();
            Process();
        }

        void Process()
        {
            string[] rows = File.ReadAllLines(FilePath);
            int totalInputs = Int32.Parse(rows[0].Trim());
            int currentRow = 1;
            for (int i = 0; i < totalInputs; i++)
            {
                string[] data = rows[currentRow++].Split(' ');
                int []op=Array.ConvertAll<string, int>(data, a => Int32.Parse(a));
                List<int> bases = new List<int>();
                bases.AddRange(op);
                Bases.Add(bases);
            }
        }
    }
}
