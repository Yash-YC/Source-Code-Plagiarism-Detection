using System;
using System.Collections.Generic;
using System.Text;

namespace Google_Code_Jam
{
    class Program
    {
        static void Main(string[] args)
        {
            string arquivo = "../../file.in";
            System.IO.StreamReader sr = new System.IO.StreamReader(arquivo);
            System.IO.StreamWriter sro = new System.IO.StreamWriter(arquivo+".out");
            int n = int.Parse(sr.ReadLine());

            for (int i = 0; i < n; i++)
            {
                string[] str  = sr.ReadLine().Split(' ');
                int[] bases = new int[str.Length];
                for (int j = 0; j < bases.Length; j++)
                {
                    bases[j] = int.Parse(str[j]);
                }
                Dictionary<int, Dictionary<int, bool>> testados = new Dictionary<int, Dictionary<int, bool>>();
                int happy = 2;

                while (true)
                {
                    bool testado = true;
                    for (int j = 0; j < bases.Length; j++)
                    {
                        testado = testado && IsHappy(happy, bases[j], testados);
                    }
                    if (testado)
                    {
                        break;
                    }
                    happy++;
                }
                sro.WriteLine(string.Format("Case #{0}: {1}", i + 1,happy));

            }
            
            sro.Flush();
            sro.Close();
            sr.Close();
        }

        //private static  string ConverteDaBase10(int numero, int Nbase)
        //{
        //    //www.devbrasil.net
        //    string resultado = "";
        //    int auxResult;
        //    string seq = "0123456789";
        //    auxResult = Convert.ToInt32(numero / Nbase);
        //    int resto = numero % Nbase;
        //    while (resto > 0)
        //    {
        //        resultado = seq.Substring(resto + 1, 1) + resultado;
        //        resto = auxResult % Nbase;
        //        auxResult = Convert.ToInt32(auxResult / Nbase);
        //    }
        //    return resultado;
        //}

        private static bool IsHappy(int numero, int Nbase, Dictionary<int, Dictionary<int, bool>> testados)
        {
            if (!testados.ContainsKey(Nbase) )
            {
                testados[Nbase] = new Dictionary<int, bool>();
            }
            if (testados[Nbase].ContainsKey(numero))
            {
                return testados[Nbase][numero];
            }
            string s = Convert(10, Nbase,numero.ToString());
            int retorno = 0;
            foreach (char c in s)
            {
                int x = int.Parse("" + c);
                retorno += (x * x);
            }
            
            if (retorno == 1)
            {
                testados[Nbase][numero] = true;
                return true;
            }
            else
            {
                testados[Nbase][numero] = false;
                bool r = IsHappy(retorno, Nbase, testados);
                testados[Nbase][numero] = r;
                return r;
            }
        }

            //Copyright Andrew Jonkers 2006-
    //convert a positive integer in base:from  to another base (allowable bases from 2 to 36)
    //the number can be any number of digits long
    //input and output in string format (e.g. digits in base 2="0-1", base 16="0-F", base 20="0-J" etc
        //Convert number in string representation from base:from to base:to. Return result as a string
        public static String Convert(int from, int to,string s)
        {

            //Return error if input is empty
            if (String.IsNullOrEmpty(s))
            {
                return ("Error: Nothing in Input String");
            }
            //only allow uppercase input characters in string
            s = s.ToUpper();
                        //only do base 2 to base 36 (digit represented by charecaters 0-Z)"
            if (from < 2 || from > 36 || to < 2 || to > 36) { return ("Base requested outside range"); }
                        //convert string to an array of integer digits representing number in base:from
            int il = s.Length;
            int[] fs = new int[il];
            int k = 0;
            for (int i = s.Length - 1; i >= 0; i--)
            {
                if (s[i] >= '0' && s[i] <= '9') { fs[k++] = (int)(s[i] - '0'); }
                else
                {
                    if (s[i] >= 'A' && s[i] <= 'Z') { fs[k++] = 10 + (int)(s[i] - 'A'); }
                    else
                    { return ("Error: Input string must only contain any of 0-9 or A-Z"); } //only allow 0-9 A-Z characters
                }
            }            //check the input for digits that exceed the allowable for base:from
            foreach(int i in fs)
            {
                if (i >= from) { return ("Error: Not a valid number for this input base"); }
            }            //find how many digits the output needs
            int ol = il * (from / to+1);
            int[] ts = new int[ol+10]; //assign accumulation array
            int[] cums = new int[ol+10]; //assign the result array
            ts[0] = 1; //initialise array with number 1             //check the input for digits that exceed the allowable for base:from
                        //evaluate the output
            for (int i = 0; i < il; i++) //for each input digit
            {
                for (int j = 0; j < ol; j++) //add the input digit times (base:to from^i) to the output cumulator
                {
                    cums[j] += ts[j] * fs[i];
                    int temp = cums[j];
                    int rem = 0;
                    int ip = j;
                    do // fix up any remainders in base:to
                    {
                        rem = temp / to;
                        cums[ip] = temp-rem*to; ip++;
                        cums[ip] += rem;
                        temp = cums[ip];
                    }
                    while (temp >=to);
                }
                                //calculate the next power from^i) in base:to format
                for (int j = 0; j < ol; j++)
                {
                    ts[j] = ts[j] * from;
                } 
                for(int j=0;j<ol;j++) //check for any remainders
                {
                    int temp = ts[j];
                    int rem = 0;
                    int ip = j;
                    do  //fix up any remainders
                    {
                        rem = temp / to;
                        ts[ip] = temp - rem * to; ip++;
                        ts[ip] += rem;
                        temp = ts[ip];
                    }
                    while (temp >= to);
                }
            }            //convert the output to string format (digits 0,to-1 converted to 0-Z characters) 
            String sout = String.Empty; //initialise output string
            bool first = false; //leading zero flag
            for (int i = ol; i >= 0; i--)
            {
                if (cums[i] != 0) { first = true; }
                if (!first) { continue; }
                if (cums[i] < 10) { sout += (char)(cums[i] + '0'); }
                else { sout += (char)(cums[i] + 'A' - 10); }
            }
            if (String.IsNullOrEmpty(sout)) { return "0"; } //input was zero, return 0
            //return the converted string
            return sout;
        }
    }

}
