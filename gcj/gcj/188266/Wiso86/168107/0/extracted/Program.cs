using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace R1A___Multi_base_Hapiness
{
    class Program
    {

        static bool[,] sol = new bool[12, 10000000];
        static int MAX = 100000;

        static ulong cambioDeDecimalABase(ulong numero, ulong a_base)
        {
            String aux = "";
            String res = "";

            aux += numero % a_base;

            while (numero / a_base >= a_base)
            {
                numero /= a_base;
                aux += numero % a_base;                
            }
            aux += numero / a_base;

            for (int i = aux.Length - 1; i >= 0; i--)
            {
                res += aux[i];
            }
            return Convert.ToUInt64(res);
        }

        static ulong cambioADecimalDeBase(ulong numero, ulong de_base)
        {
            String num = numero.ToString();
            ulong res = 0;

            for (int i = 0; i < num.Length; i++)
            {
                res += power(Convert.ToUInt64(num[i])- 48, num.Length - 1 - i);
            }
            return res;
        }

        private static ulong power(ulong p, int p_2)
        {
            ulong res = 1;
            for (int i = 0; i < p_2; i++)
            {
                res *= p;
            }
            return res;
        }



        static void Main(string[] args)
        {

            TextReader input = new StreamReader("..\\..\\A-small-attempt0.in");
            TextWriter output = new StreamWriter("..\\..\\outputSmall.txt");


            for (int i = 2; i <= 10; i++)
            {
                for (int j = 2; j < MAX; j++)
                {
                    comprobarFelicidad((ulong)j, (ulong)i);
                }
            }


            int casos = Convert.ToInt32(input.ReadLine());

            for (int i = 0; i < casos; i++)
            {
                String[] linea = input.ReadLine().Split();

                int[] bases = new int[15];
                int j = 0;
                int tam;
                while (true)
                {
                    try
                    {
                        bases[j] = Convert.ToInt32(linea[j]);
                    }
                    catch (System.IndexOutOfRangeException e)
                    {
                        tam = j;
                        break;
                    }
                    j++;
                }

                for(j = 2; j < MAX; j++){
                    bool es = true;
                    for(int k = 0; k < tam; k++){
                        if(sol[bases[k], j] != true){
                            es = false;
                            break;
                        }
                    }
                    if(es){
                        output.WriteLine("Case #" + (i+1).ToString() + ": " + j.ToString());
                        break;
                    }
                }
            }


            output.Close();

        }

        private static void comprobarFelicidad(ulong numero, ulong _base)
        {
            ulong orig = numero;
            int pasos = 0;
            while (numero != 1UL && pasos < 100)
            {
                if (sol[_base, numero] == true)
                {
                    sol[_base, orig] = true;
                    return;
                }
                ulong aux = cambioDeDecimalABase(numero, _base);
                aux = powerear(aux);
                if (aux == numero)
                    return;
                numero = aux;
                pasos++;
            }
            if (pasos != 100)
                sol[_base, orig] = true;

        }

        private static ulong powerear(ulong aux)
        {
            String str = aux.ToString();
            ulong res = 0UL;
            for (int i = 0; i < str.Length; i++)
            {
                int auxi = Convert.ToInt32(str[i]) - 48;
                res += (ulong)(auxi * auxi);
            }
            return res;
        }


    }
}
