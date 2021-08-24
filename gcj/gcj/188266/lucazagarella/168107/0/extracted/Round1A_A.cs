using System;
using System.IO;
using System.Collections.Generic;

namespace GCJ2009 {
    public class Round1A_A {

        public static void Solve(String inputFile, String outputFile) {

            StreamReader reader = new StreamReader(inputFile);
            TextWriter tw = new StreamWriter(outputFile);

            string line = "";

            line = reader.ReadLine();

            int T=int.Parse(line);

            int count=0;
            string output = "";

            for (int i = 0; i < T; i++) {
                Console.WriteLine("Case " + (i + 1).ToString("00") + "/" + T);
                line = reader.ReadLine();
                String[] basix=line.Split(' ');
                List<int> basi=new List<int>();
                foreach (var s in basix) {
                    int k = int.Parse(s);
                    basi.Add(k);
                }



                int minVal=getSmallValue(basi);
                String Case="Case #" + (++count).ToString() + ": ";
                output = Case + minVal.ToString();
                tw.WriteLine(output);
            }

            tw.Close();
            reader.Close();

        }

        #region private methods



        private static int getSmallValue(IList<int> basi) {
            
            int v=2;
            for (int i = 0; i < basi.Count; i++) {
                if (!isHappy(v,basi[i]))
                {
                    v++;
                    i=-1;
                    continue;
                }
            }
            
            return v;
        }
        private static Dictionary<int,List<int>> badValues=new Dictionary<int, List<int>>();
        private static Dictionary<int,List<int>> goodValues=new Dictionary<int, List<int>>();

        private static bool isHappy(int xdec, int bs) {
            if (badValues.ContainsKey(bs)) {
             if (badValues[bs].Contains(xdec))
                return false;
            }
            else badValues.Add(bs, new List<int>());
            

            if (goodValues.ContainsKey(bs)) {
                if (goodValues[bs].Contains(xdec))
                return true;
            }
            else goodValues.Add(bs, new List<int>());
           
            

            List<int> catena = new List<int> {};
            while (xdec != 1 && !catena.Contains(xdec)) {
                catena.Add(xdec);
                xdec = nextVal(xdec, bs);
                
            }
            if (xdec == 1) {
                
                goodValues[bs].AddRange(catena);
            }
            else {
                
                badValues[bs].AddRange(catena);
            }
            
            return xdec == 1;
        }

        private static int nextVal(int xdec, int bs) {
            List<int> cifre = new List<int>();
            int residuo = xdec;
            int sumdec=0;
            while (residuo > 0) {
                int resto = residuo % bs;
                cifre.Add(resto);
                sumdec += resto * resto;
                residuo = (residuo - resto) / bs;
            }



            return sumdec;

        }

        #endregion
    }
}