using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

class RankAndFile
{
    const string PROB = "B-small-attempt0";
    static string NAME_IN = String.Format("data\\{0}.in", PROB);
    static string NAME_OUT = String.Format("data\\{0}.out", PROB);

    static void Main(string[] args)
    {
        using (CodeJamProblem prob = new CodeJamProblem(NAME_IN))
        {
            int nt = prob.ReadLineInt16();

            for (int t = 0; t < nt; t++)
            {
                int N = prob.ReadLineInt32();
                int[][] RC = new int[2 * N - 1][];
                int[] H = new int[2501];

                for (int i = 0; i < 2 * N - 1; i++)
                {
                    RC[i] = prob.ReadInt32Array();
                    for (int j = 0; j < RC[i].Length; j++)
                    {
                        H[RC[i][j]]++;
                    }
                }
                int[] M = new int[N];
                int idx=0;
                for (int i = 0; i < 2501; i++)
                {
                    if (H[i] % 2 == 1)
                    {
                        //Missing
                        M[idx++] = i;
                    }
                }
                Array.Sort(M);
                string ans = "";
                for (int i = 0; i < N; i++)
                {
                    ans += " " + M[i].ToString();
                }
                prob.OutputCase(ans.Substring(1));
            }
        }
    }
}