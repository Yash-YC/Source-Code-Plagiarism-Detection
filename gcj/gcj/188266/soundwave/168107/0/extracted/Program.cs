using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Multibase
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader rd = new StreamReader("Input.txt");
            StreamWriter wt = new StreamWriter("output.txt", false);
            String line = rd.ReadLine();
            Dictionary<Int32,Dictionary<Int32,Boolean>> _happyNum = new Dictionary<int,Dictionary<int,bool>>();

            Int32 T = Convert.ToInt32(line);
            for (Int32 i = 1; i <= T; i++)
            {
                line = rd.ReadLine();
                String[] param = line.Split(' ');
                Int32[] bases = param.Select(x => Convert.ToInt32(x)).ToArray();

                Int32 index = 2;
                while (true)
                {
                    bool result = true;
                    foreach (Int32 baseNum in bases)
                    {
                        if (!_happyNum.ContainsKey(index))
                            _happyNum.Add(index, new Dictionary<int, bool>());

                        if (!_happyNum[index].ContainsKey(baseNum))
                            _happyNum[index].Add(baseNum, beHappy(index, baseNum));

                        if (!_happyNum[index][baseNum])
                        {
                            result = false;
                            break;
                        }
                    }

                    if (result == true)
                    {
                        wt.WriteLine("Case #{0}: {1}", i, index);
                        Console.WriteLine("Case #{0}: {1}", i, index);
                        break;
                    }
                    index++;
                }
            }



            wt.Close();
        }

        static private bool beHappy(Int32 number, Int32 baseNum)
        {
            Int32 sum = 0;
            Int32 oldNum = -1;
            HashSet<Int32> cal = new HashSet<int>();

            while (oldNum != number && number!=1 && !cal.Contains(number))
            {
                sum = 0;
                oldNum = number;
                cal.Add(oldNum);
                while (number != 0)
                {
                    Int32 digi = number % baseNum;
                    sum += digi * digi;
                    number = number / baseNum;
                }
                number = sum;
            }

            if (number == 1)
                return true;
            else
                return false;
        }
    }
}
