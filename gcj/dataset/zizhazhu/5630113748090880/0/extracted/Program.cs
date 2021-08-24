using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace RankAndFile
{
    class Program
    {
        static void Main(string[] args)
        {
            //StreamReader input = new StreamReader(@"D:\codejam\input.txt");
            //StreamWriter output = new StreamWriter(@"D:\codejam\output.txt");
            StreamReader input = new StreamReader(@"D:\codejam\RankAndFile\B-small-attempt2.in");
            StreamWriter output = new StreamWriter(@"D:\codejam\RankAndFile\B-small-attempt2.out");

            string line;
            bool first = true;
            int numRow = 0;
            List<int[]>[] data = new List<int[]>[0];
            int count = 0;
            int c = 0;
            while ((line = input.ReadLine()) != null)
            {
                if (first)
                {
                    count = int.Parse(line);
                    data = new List<int[]>[count];
                    first = false;
                }
                else
                {
                    numRow = int.Parse(line);
                    List<int[]> curList = new List<int[]>();
                    for (int i = 0; i < numRow * 2 - 1; i++)
                    {
                        line = input.ReadLine();
                        string[] row = line.Split(' ');
                        int[] nums = new int[row.Length];
                        for(int j=0;j<nums.Length;j++)
                        {
                            nums[j] = int.Parse(row[j]);
                        }
                        curList.Add(nums);
                    }
                    data[c] = curList;
                    c++;
                }
            }
            input.Close();

            for (int i = 0; i < count; i++)
            {
                List<int[]> curList = data[i];
                int n = curList.First().Length;
                int[,] matrix = new int[n,n];
                int missing = -1;
                bool missingRow = false;

                for (int j = 0; j < n; j++)
                {
                    curList = curList.OrderBy(x => x[j]).ToList();

                    if (curList.Count==1||curList[0][j] != curList[1][j])
                    {
                        missing = j;
                        if (j == 0)
                        {
                            missingRow = false;
                            for (int k = 0; k < n; k++)
                            {
                                matrix[j, k] = curList[0][k];
                            }
                        }
                        else
                        {
                            bool rowValid = true;
                            for (int k = 0; k < j; k++)
                            {
                                if ((matrix[j, k] != curList[0][k] && matrix[j, k] != 0) || matrix[j, k]< matrix[j-1, k])
                                {
                                    rowValid = false;
                                    break;
                                }
                            }
                            for (int k = 0; k < n; k++)
                            {
                                if (curList[0][k] < matrix[j - 1, k])
                                {
                                    rowValid = false;
                                    break;
                                }
                            }
                            if (rowValid)
                            {
                                missingRow = false;
                                for (int k = 0; k < n; k++)
                                {
                                    matrix[j, k] = curList[0][k];
                                }
                            }
                            else
                            {
                                missingRow = true;
                                for (int k = 0; k < n; k++)
                                {
                                    matrix[k, j] = curList[0][k];
                                }
                            }
                        }
                        curList.RemoveAt(0);
                    }
                    else
                    {
                        bool rowValid = true;
                        for (int k = 0; k < j; k++)
                        {
                            if ((matrix[j, k] != curList[0][k] && matrix[j, k] != 0)|| matrix[j, k] < matrix[j - 1, k])
                            {
                                rowValid = false;
                                break;
                            }
                        }
                        if (j > 0)
                        {
                            for (int k = 0; k < n; k++)
                            {
                                if (curList[0][k] < matrix[j - 1, k])
                                {
                                    rowValid = false;
                                    break;
                                }
                            }
                        }
                        if (rowValid)
                        {
                            for (int k = 0; k < n; k++)
                            {
                                matrix[j, k] = curList[0][k];
                                matrix[k, j] = curList[1][k];
                            }
                        }
                        else
                        {
                            for (int k = 0; k < n; k++)
                            {
                                matrix[k, j] = curList[0][k];
                                matrix[j, k] = curList[1][k];
                            }
                        }
                        curList.RemoveAt(0);
                        curList.RemoveAt(0);
                    }
                    
                }
                int[] res = new int[n];
                for(int l=0;l< n;l++)
                {
                    if(missingRow)
                    {
                        res[l] = matrix[missing, l];
                    }
                    else
                    {
                        res[l] = matrix[l, missing];
                    }
                }
                output.WriteLine("Case #{0}: {1}", i + 1, string.Join(" ", res));
            }
            output.Close();
        }
    }
}
