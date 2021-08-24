using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Google2_1
{
   
    class Program
    {
        static void Main(string[] args)
        {
            string outputStr = "";
            int inputSize = int.Parse(Console.ReadLine());
            for (int i = 0; i < inputSize; i++)
            {
                List<int> input = new List<int>();
                foreach (string s in Console.ReadLine().Split(' '))
                {
                    input.Add(int.Parse(s));
                }
                List<int> output = checkList(input);
                outputStr += string.Format("Case #{0}: {1}", i + 1, output[1]) + Environment.NewLine;
            }
            Console.Write(outputStr);
        }

        static List<int> checkList(List<int> input)
        {
            Find4BaseM baseX = new Find4BaseM(input[0]);
            baseX.CheckUntil(100000);
            List<int> lastList = baseX.output();
            input.RemoveAt(0);
            foreach (int i in input)
            {
                Find4BaseM basem = new Find4BaseM(i);
                basem.CheckUntil(100000);
                List<int> output = basem.output();
                lastList = new List<int>(lastList.Intersect(output));
            }
            return lastList;
        }
    }



    class Find4BaseM
    {
        const int searchcacheSize = 100001;
        int _base;
        List<byte> searchcache;
        List<int> temp;
        int count;
        int lastoutput;
        List<int> outputCache;

        public Find4BaseM(int basenum)
        {
            _base = basenum;
            searchcache = new List<byte>(searchcacheSize);
            for (int i = 0; i < searchcacheSize; i++)
                searchcache.Add(0);
            temp = new List<int>();
            count = 0;
            lastoutput = 0;
            outputCache = new List<int>();
        }

        public byte Check(int n)
        {
            if (searchcache[n] == 0)
            {
                int last = n;
                temp.Add(n);
                while (true)
                {
                    int checktemp = last;
                    last = 0;
                    while (checktemp > 0)
                    {
                        int yu = (checktemp % _base);
                        last += yu * yu;
                        checktemp /= _base;
                    }

                    if (last == 1)
                    {
                        searchcache[n] = 1;//a happy number
                        break;
                    }

                    if (searchcache[last] == 2 || temp.Contains(last))
                    {
                        searchcache[n] = 2;
                        break;
                    }
                    temp.Add(last);
                }
                if (searchcache[n] == 2)
                {
                    foreach (int i in temp)
                        searchcache[i] = 2;
                }
                else if (searchcache[n] == 1)
                {
                    foreach (int i in temp)
                        searchcache[i] = 1;
                }
                temp.Clear();
            }
            return searchcache[n];
        }

        public void CheckUntil(int n)
        {
            for (int i = count; i <= n; i++)
                Check(i);
            count = n;
        }

        public List<int> output()
        {
            for (int i = lastoutput+1; i <= count; i++)
            {
                if (searchcache[i] == 1)
                    outputCache.Add(i);
            }
            return outputCache;
        }
    }
}
