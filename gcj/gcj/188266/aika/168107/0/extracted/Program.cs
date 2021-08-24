using System;
using System.Collections.Generic;
using System.Text;

namespace CA1A
{
    class Program
    {
        static void Main(string[] args)
        {
            int _N = int.Parse(Console.ReadLine());
            for (int _index = 1; _index <= _N; _index++)
            {
                List<int> bases = new List<int>(10); ;
                string temp = Console.ReadLine();
                string[] split = temp.Split(' ');
                for (int i = 0; i < split.Length; i++)
                    bases.Add(int.Parse(split[i]));
                int number = 0;
                for (int i = 2; ; i++)
                {
                    bool found=true;
                    for (int j = 0; j < bases.Count; j++)
                    {
                        if (!isHappy(i, bases[j]))
                        {
                            found = false;
                            break;
                        }
                    }
                    if (found)
                    {
                        number = i;
                        break;
                    }
                }

                string _output = string.Format("Case #{0}: {1}", _index, number);
                Console.WriteLine(_output);
            }
        }

        static bool isHappy(int num, int bas)
        {
            List<int> ls = new List<int>(100);
            while (true)
            {
                if (num == 1)
                    return true;
                if (ls.IndexOf(num) != -1)
                    return false;
                ls.Add(num);

                int newnum = 0;
                while (num > 0)
                {
                    int s = num % bas;
                    newnum += s * s;
                    num = num / bas;
                }
                num = newnum;
            }
        }
    }
}
