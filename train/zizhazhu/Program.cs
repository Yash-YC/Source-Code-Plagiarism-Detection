using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace TheLastWord
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader input = new StreamReader(@"D:\codejam\TheLastWord\A-large.in");
            StreamWriter output = new StreamWriter(@"D:\codejam\TheLastWord\A-large.out");

            string line;
            bool first = true;
            string[] data = new string[1];
            int count = 0;
            int c = 0;
            while((line=input.ReadLine())!=null)
            {
                if(first)
                {
                    count = int.Parse(line);
                    data = new string[count];
                    first = false;
                }
                else
                {
                    data[c++] = line;
                }
            }
            input.Close();

            
            for(int i=0;i< count;i++)
            {
                LinkedList<char> charList = new LinkedList<char>();
                string s = data[i];
                char max = (char)('A' - 1);
                for (int j = 0; j < s.Length; j++)
                {
                    if(!charList.Any())
                    {
                        charList.AddFirst(s[j]);
                    }
                    else
                    {
                        if(s[j]>= charList.First())
                        {
                            charList.AddFirst(s[j]);
                        }
                        else
                        {
                            charList.AddLast(s[j]);
                        }
                    }
                }
                string res = new string(charList.ToArray());
                output.WriteLine("Case #{0}: {1}", i + 1, res);
            }
            output.Close();
        }
    }
}
