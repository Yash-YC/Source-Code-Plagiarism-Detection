using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

//using Service;  // local

namespace GCJ
{
    class A_small
    {
        const string path = @"D:\usr\gcj\2009R1A";

        static void Main(string[] args)
        {

            new A_small(null, 0).Do(new int[] { 2,3});
            new A_small(null, 0).Do(new int[] {2,3,7});
            new A_small(null, 0).Do(new int[] { 9,10 });
           // return;


            string fileName = @"A-small-attempt0.in-1.txt";

            string rd_fileName = System.IO.Path.Combine(path, fileName);
            string wt_fileName = rd_fileName.Replace(".in", ".out");
            System.IO.StreamReader sr = new System.IO.StreamReader(rd_fileName);
            StreamWriter sw = new System.IO.StreamWriter(wt_fileName);

            //
            string line = sr.ReadLine();
            int N = int.Parse(line);
            for (int tc = 1; tc <= N; tc++)
            {
                string[] ss = sr.ReadLine().Split(' ');
                List<int> list = new List<int>();
                foreach (string s in ss)
                    list.Add(int.Parse(s));

                new A_small(sw, tc).Do(list.ToArray());
            }

            //
            sw.Close();
            sr.Close();
        }

        void Do(int[] bs)
        {
            for (int x = 2; ; x++)
            {
                bool h = true;
                foreach(int b in bs) 
                {
                    h = _happy(x, b);

                    //Logger.WriteLine(x, b, h);

                    if (!h)
                        break;
                }
                if (h)
                {
                    _Result((ulong)x);
                    return;
                }
            }
        }

        bool _happy(int x, int b)
        {
            List<int> a = new List<int>();

            for (; ; )
            {
                if (x == 1)
                {
                    return true;
                }
                var ds = _d(x, b);
                x = _sq(ds);
               
                if (a.Contains(x))
                    return false;
                a.Add(x);
            }
        }

        int  _sq(List<int> ds)
        {
            int sum = 0;
            foreach (var d in ds)
                sum += (d * d);
            return sum;
        }

        List<int> _d(int x, int b)
        {
            List<int> ds = new List<int>();
            for (; ; )
            {
                int d = x % b;
                x /= b;
                ds.Insert(0, d);

                if (x == 0)
                    break;
            }
            return ds;
        }


        A_small(StreamWriter sw, int tc)
        {
            _sw = sw;
            _tc = tc;
        }

        StreamWriter _sw = null;
        int _tc;

        void _Result(ulong ulongValue)
        {
            string line = String.Format("Case #{0}: {1}", _tc, ulongValue);
            if (_sw != null)
                _sw.WriteLine(line);

            System.Diagnostics.Trace.WriteLine(line);
        }
    }
}
