using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace MultiBaseHappiness
{
    class Program
    {
        static void Main(string[] args)
        {
            //int p = 0;
            //Console.WriteLine(IsHappy(7, 4, ref p));
            //return;

            StreamReader sr = null;
            StreamWriter sw = null;
            try
            {
                sw = File.CreateText("../../../Inputs/MultiBaseHappiness_s.out");
                sr = File.OpenText("../../../Inputs/MultiBaseHappiness_s.in");
                sr.ReadLine();
                string line;
                int index = 0;
                while ((line = sr.ReadLine()) != null)
                {
                    string nl = string.Format("Case #{0}: {1}", ++index, GetResult(line));
                    Console.WriteLine(nl);
                    sw.WriteLine(nl);
                }
            }
            finally
            {
                if (sr != null)
                    sr.Close();
                if (sw != null)
                    sw.Close();
            }
        }
        static int GetResult(string line)
        {
            List<int> bases = new List<int>();
            foreach (string s in line.Split(' '))
                bases.Add(int.Parse(s));
            int res = 2;
            while (true)
            {
                bool ok = true;
                foreach (int b in bases)
                {
                    int pokus = 0;
                    if (!IsHappy(b, res, ref pokus))
                    {
                        ok = false;
                        res++;
                        break;
                    }
                }
                if (ok)
                    break;
            }
            return res;
        }
        private static bool IsHappy(int b, int res, ref int pokus)
        {
            pokus++;
            if (pokus > 100)
                return false;
            if (res == 1)
                return true;
            CiselnaSoustava cs = new CiselnaSoustava(b, null);
            CiselnaSoustavaCislo c = cs.Preved((ulong)res, 0);
            int sum = 0;
            foreach (int cif in c.Cifry)
                sum += cif * cif;
            return IsHappy(b, sum, ref pokus);
        }
    }
    public class CiselnaSoustava
    {
        int Zaklad;
        string Symboly;
        public CiselnaSoustava(int zaklad, string symboly)
        {
            Zaklad = zaklad;
            Symboly = symboly;
        }
        public CiselnaSoustavaCislo Preved(ulong cislo, int pocetCifer)
        {
            ulong ci = cislo;
            List<int> cifry = new List<int>();
            int rad = 0;
            while (cislo > Math.Pow(Zaklad, rad))
                rad++;
            if (Math.Pow(Zaklad, rad) > cislo)
                rad--;
            while (rad >= 0)
            {
                ulong mocnina = (ulong)Math.Pow(Zaklad, rad);
                cifry.Add((int)(ci / mocnina));
                ci = ci - ((ci / mocnina) * mocnina);
                rad--;
            }
            string symboly = string.Empty;
            if (cislo == 0)
                cifry.Add(0);
            if (pocetCifer > 0)
            {
                while (pocetCifer > cifry.Count)
                    cifry.Insert(0, 0);
            }
            if (Symboly != null)
                foreach (int cifra in cifry)
                    symboly += Symboly[cifra];
            CiselnaSoustavaCislo res = new CiselnaSoustavaCislo(cislo, cifry, symboly);
            return res;
        }
    }
    public class CiselnaSoustavaCislo
    {
        public ulong Hodnota;
        public List<int> Cifry;
        public string Symboly;
        public CiselnaSoustavaCislo(ulong hodnota, List<int> cifry, string symboly)
        {
            Hodnota = hodnota;
            Cifry = cifry;
            Symboly = symboly;
        }
    }
    public class Znak
    {
        public char Z;
        public int Index;
        public Znak(char z, int index)
        {
            Index = index;
            Z = z;
        }
    }
}
