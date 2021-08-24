using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication3
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());
            string[] cases = new string[n];
            for (int i = 0; i < n; i++)
            {
                cases[i] = Console.ReadLine();
            }

            for (int i = 0; i < cases.Length; i++)
            {
                string ans = "";
                string word = cases[i];
                int[] ascii = new int[word.Length];
                int pos = 0;
                for(int j=0;j<word.Length;j++)
                {
                    ascii[j] = Convert.ToInt32(word[j]);
                }

                ans = ans + word[0];
                pos = Convert.ToInt32(word[0]);
                if(word.Length>1) { 
                    for (int j = 1; j < word.Length; j++)
                    {
                        if (Convert.ToInt32(word[j]) >= pos)
                        {
                            pos = Convert.ToInt32(word[j]);
                            ans = word[j] + ans;
                        }
                        else
                        {
                            ans = ans + word[j];
                        }
                    }
                }
                Console.WriteLine("Case #{0}: {1}", i + 1, ans);
            }
        }
    }
}
