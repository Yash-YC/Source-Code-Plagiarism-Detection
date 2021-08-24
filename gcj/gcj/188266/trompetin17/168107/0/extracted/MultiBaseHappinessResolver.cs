using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace AlienLanguage
{
    public static class MultiBaseHappinessResolver
    {
        private static Dictionary<int, string> _decimales;
        public static void Resolve(StringReader reader, string outputFile)
        {
            _decimales = new Dictionary<int, string>();
            //primera linea la cantidad de casos
            var T = int.Parse(reader.ReadLine());
           for (var i = 0; i < T; i++)
            {
                var coincidencia = 0;
                var sBases = reader.ReadLine().Split(new[] { " " }, StringSplitOptions.RemoveEmptyEntries);
                var contador = 2;
                do
                {
                    coincidencia = 0;
                    foreach (var s in sBases)
                    {
                        var nBase = int.Parse(s);

                        var sNewBase = Conversor.ToNumBase(contador.ToString(), nBase);

                        if (!EsNumeroHappy(sNewBase, nBase, new List<int>()))
                        {
                            break;
                        }
                        coincidencia++;
                    }
                    if (coincidencia == sBases.Length)
                    {
                        //es numero happy
                        //aqui se escribe el resultado
                        File.AppendAllText(outputFile, string.Format("Case #{0}: {1}\r\n", i + 1, contador));
                        //lo agrego a la coleccion
                        //_decimales.Add(contador, "#" + string.Join("#", sBases) + "#");
                        break;
                    }
                    contador++;
                } while (true);
            }
        }

        private static bool EsNumeroHappy(string s, int conteo, List<int> evaluados)
        {


            if (evaluados.Contains(int.Parse(s)))
            {
                return false;
            }

            var datos = s.ToCharArray();

            var total = 0;

            foreach (var c in datos)
            {
                var numero = int.Parse(new string(c, 1));
                if (numero == 0) continue;
                total += numero*numero;
                
            }
            total = int.Parse(Conversor.ToNumBase(total.ToString(), conteo));
            if (total == 1)
            {
                //numero feliz
                return true;
            }
            evaluados.Add(int.Parse(s));

            return EsNumeroHappy(total.ToString(), conteo, evaluados);
        }
    }

}
