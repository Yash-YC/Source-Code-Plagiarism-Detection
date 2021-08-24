using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GJ
{
    class CodeJam
    {
        static void Main(string[] args)
        {
            new Cards().Run("in.in", "out.out");
        }

        public static void WriteCase(StreamWriter output, int caseNum, string content)
        {
            Console.WriteLine("Case #" + caseNum.ToString() + ": " + content);
            output.WriteLine("Case #" + caseNum.ToString() + ": " + content);
        }
    }
}
