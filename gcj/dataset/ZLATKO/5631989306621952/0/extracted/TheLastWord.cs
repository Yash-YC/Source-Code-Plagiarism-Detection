using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

class TheLastWord
{
    const string PROB = "A-small-attempt0";
    static string NAME_IN = String.Format("data\\{0}.in", PROB);
    static string NAME_OUT = String.Format("data\\{0}.out", PROB);

    static void Main(string[] args)
    {
        using (CodeJamProblem prob = new CodeJamProblem(NAME_IN))
        {
            int nt = prob.ReadLineInt16();

            for (int t = 0; t < nt; t++)
            {
                string s = prob.ReadLine();

                char ch = s[0];
                string ans = ch.ToString();
                for (int i = 1; i < s.Length; i++)
                {
                    char ch1 = s[i];
                    if (ch1 >= ch)
                    {
                        ans = ch1.ToString() + ans;
                        ch = ch1;
                    }
                    else
                    {
                        ans += ch1.ToString();
                    }
                }

                prob.OutputCase(ans.ToString());
            }
        }
    }
}