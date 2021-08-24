//-----------------------------------------------------------------------------
// Clase Conversor                                                  (31/Oct/07)
// Para convertir valores decimales a cualquier otra base numérica
//
// ©Guillermo 'guille' Som, 2007
//-----------------------------------------------------------------------------
using System;

using System.Collections.Generic;
using System.Text;

namespace AlienLanguage
{


    /// <summary>
    /// Clase para convertir bases numéricas
    /// </summary>
    /// <remarks></remarks>
    public class Conversor
    {

        //
        // Funciones de conversión a otras bases
        //


        /// <summary>
        /// Convierte un número decimal en una base distinta
        /// Las bases permitadas son de 2 a 36
        /// </summary>
        /// <param name="num"></param>
        /// <param name="nBase">
        /// Base a la que se convertirá (de 2 a 36)
        /// (con los tipos de .NET ñla base 36 no es fiable)
        /// </param>
        /// <param name="conSeparador">
        /// Si se añade un separador cada 4 cifras
        /// </param>
        /// <param name="trimStart">
        /// Si se quitan los ceros a la izquierda
        /// </param>
        /// <returns></returns>
        /// <remarks></remarks>
        public static string ToNumBase(string num,
                                       int nBase,
                                       bool conSeparador,
                                       bool trimStart)
        {
            StringBuilder s = new StringBuilder();
            ulong n = Convert.ToUInt64(num);
            if (n == 0 && conSeparador == false && trimStart == false)
            {
                return "0";
            }

            // La base debe ser como máximo 36
            // (por las letras del alfabeto (26) + 10 dígitos)
            // F = 70 - 55 + 1 = 16
            // Z = 90 - 55 + 1 = 36
            if (nBase < 2 || nBase > 36)
            {
                throw new ArgumentOutOfRangeException("La base debe ser como máximo 36 y como mínimo 2");
            }

            int j = 0;
            double nu = n;

            while (nu > 0)
            {
                double k = (nu / nBase);
                nu = System.Math.Floor(k);
                int f = Convert.ToInt32((k - nu) * nBase);

                if (f > 9)// letras
                {
                    s.Append((char)(f + 55));
                }
                else // números
                {
                    s.Append((char)(f + 48));
                }
                if (conSeparador)
                {
                    j = j + 1;
                    if (j == 4)
                    {
                        j = 0;
                        s.Append(" ");
                    }
                }
            }

            // Hay que darle la vuelta a la cadena
            char[] ac = s.ToString().ToCharArray();
            Array.Reverse(ac);
            s = new StringBuilder();
            foreach (char c in ac)
                s.Append(c);


            if (trimStart)
            {
                return s.ToString().TrimStart(" 0".ToCharArray()).TrimEnd();
            }
            else
            {
                return s.ToString().TrimEnd();
            }
        }

        //
        // Sobrecargas
        //

        /// <summary>
        /// Convierte un número decimal en una base distinta
        /// Las bases permitadas son de 2 a 36
        /// No se muestran los ceros a la izquierda y
        /// no se separan los dígitos en grupos de 4
        /// </summary>
        /// <param name="num"></param>
        /// <param name="nBase"></param>
        /// <returns></returns>
        /// <remarks></remarks>
        public static string ToNumBase(string num, int nBase)
        {
            return ToNumBase(num, nBase, false, true);
        }

        /// <summary>
        /// Convierte un número decimal en una base distinta
        /// Las bases permitadas son de 2 a 36
        /// no se separan los dígitos en grupos de 4
        /// </summary>
        /// <param name="num"></param>
        /// <param name="nBase"></param>
        /// <param name="trimStart"></param>
        /// <returns></returns>
        /// <remarks></remarks>
        public static string ToNumBase(string num, int nBase, bool trimStart)
        {
            return ToNumBase(num, nBase, false, trimStart);
        }

        //
        // Funciones específicas
        //

        /// <summary>
        /// Convierte de Decimal a binario (base 2)
        /// </summary>
        /// <param name="num">
        /// El número a convertir en binario
        /// se convierte internamente a ULong como máximo
        /// </param>
        /// <param name="conSeparador"></param>
        /// <param name="trimStart"></param>
        /// <returns></returns>
        /// <remarks>
        /// v.0.11 29/Oct/07
        /// </remarks>
        public static string DecToBin(string num, bool conSeparador, bool trimStart)
        {
            return ToNumBase(num, 2, conSeparador, trimStart);
        }

        /// <summary>
        /// Convierte de Decimal a hexadecimal (base 16)
        /// </summary>
        /// <param name="num">
        /// El número a convertir en hexadecimal
        /// se convierte internamente a ULong como máximo
        /// </param>
        /// <param name="conSeparador"></param>
        /// <param name="trimStart"></param>
        /// <returns></returns>
        /// <remarks>
        /// </remarks>
        public static string DecToHex(string num, bool conSeparador, bool trimStart)
        {
            return ToNumBase(num, 16, conSeparador, trimStart);
        }

        /// <summary>
        /// Convierte de Decimal a octal (base 8)
        /// </summary>
        /// <param name="num">
        /// El número a convertir en binario
        /// se convierte internamente a ULong como máximo
        /// </param>
        /// <param name="conSeparador"></param>
        /// <param name="trimStart"></param>
        /// <returns></returns>
        /// <remarks>
        /// </remarks>
        public static string DecToOctal(string num, bool conSeparador, bool trimStart)
        {
            return ToNumBase(num, 8, conSeparador, trimStart);
        }



        /// <summary>
        /// Convierte de cualquier base a Double
        /// </summary>
        /// <param name="num">
        /// El número en formato de la base
        /// </param>
        /// <param name="base">
        /// La base del número a convertir
        /// </param>
        /// <returns></returns>
        /// <remarks>
        /// </remarks>
        public static ulong FromNumBase(string num, int nbase)
        {
            const int aMay = 'A' - 10;
            const int aMin = 'a' - 10;
            int i = 0;
            ulong n = 0;

            num = num.TrimStart("0".ToCharArray());

            for (int j = num.Length - 1; j >= 0; j--)
            {
                if (num[j] == '0')
                {
                    i += 1;
                }
                else if (num[j] == ' ')
                {
                    // nada
                }
                else if (num[j] >= '1' && num[j] <= '9')
                {
                    int k = num[j] - 48;
                    if (k - nbase >= 0)
                        continue;
                    n = (ulong)(n + k * System.Math.Pow(nbase, i));
                    i += 1;
                }
                else if (num[j] >= 'A' && num[j] <= 'Z')
                {
                    int k = num[j] - aMay;
                    if (k - nbase >= 0)
                        continue;
                    n = (ulong)(n + k * System.Math.Pow(nbase, i));
                    i += 1;
                }
                else if (num[j] >= 'a' && num[j] <= 'z')
                {
                    int k = num[j] - aMin;
                    if (k - nbase >= 0)
                        continue;
                    n = (ulong)(n + k * System.Math.Pow(nbase, i));
                    i += 1;
                }
            }

            return n;
        }


        /// <summary>
        /// Convierte de Hexadecimal a Double
        /// </summary>
        /// <param name="num"></param>
        /// <returns></returns>
        /// <remarks>
        /// </remarks>
        public static double FromHex(string num)
        {
            return FromNumBase(num, 16);
        }

        /// <summary>
        /// Convierte de Octal a Double
        /// </summary>
        /// <param name="num"></param>
        /// <returns></returns>
        /// <remarks>
        /// </remarks>
        public static double FromOct(string num)
        {
            return FromNumBase(num, 8);
        }


        /// <summary>
        /// Convierte de Binario a Double
        /// </summary>
        /// <param name="num"></param>
        /// <returns></returns>
        /// <remarks>
        /// </remarks>
        public static double FromBin(string num)
        {
            return FromNumBase(num, 2);
        }
    }
}
