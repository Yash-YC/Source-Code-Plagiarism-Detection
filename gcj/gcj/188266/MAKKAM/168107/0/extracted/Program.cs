using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;


namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sm = new StreamReader("input.txt");
            StreamWriter sw = new StreamWriter("output.txt");
            int t = Int32.Parse(sm.ReadLine());
            //sw.WriteLine("T: " + t);
            //sw.Flush();
            bool[,] dyn = new bool[1000000, 11];
            for (int j = 2; j <11; j++)
            {
                /*
                           sw.WriteLine("Analysing: " + j+" "+mas[j]);
                           sw.Flush();
                 * */
                dyn[1, j] = true;
                for (int k = 2; k < 1000000; k++)
                {
                    ArrayList list = new ArrayList();
                    if (j == -1)
                    {
                        sw.WriteLine("Number: " + k);
                        sw.Flush();
                    }
                    list.Add(k);
                    int a = k;
                    int sum = 0;
                    while (true)
                    {
                        int temp = a;
                        while (temp > 0)
                        {
                            if (j == -1)
                            {
                                sw.WriteLine("Evaluating sum: " + sum);
                                sw.WriteLine("Adding square of: " + temp % j);
                                sw.Flush();
                            }
                            sum += (temp %j) * (temp % j);
                            temp /= j;
                        }
                        if (j == -1)
                        {
                            sw.WriteLine("Final sum: " + sum);
                            sw.Flush();
                        }
                        if (sum == a) break;
                        if (sum >= 1000000)
                        {
                            a = sum;
                            continue;
                        }
                        if (dyn[sum, j])
                        {
                            dyn[k, j] = true;
                            break;
                        }
                        if (sum < k) break;
                        if (list.Contains(sum)) break;
                        a = sum;
                        sum = 0;
                        list.Add(a);
                    }
                }
            }

	    	for(int i=0; i<t; i++)
		        {
		        String line = sm.ReadLine();
              //  sw.WriteLine("Get line: " + line);
             //   sw.Flush();
                String[] sp = line.Split(' ');
		        int[] mas = new int[sp.Length];
		        for(int j=0; j<sp.Length; j++)
			        {
                       // sw.WriteLine("Part: " + sp[j]);
			        mas[j] = Int32.Parse(sp[j]);
					}
		        
        		
		    for(int j=2; j<1000000; j++)
		    for(int k=0; k<sp.Length; k++)
			    if(!dyn[j,mas[k]]) break;
			        else if(k==sp.Length-1) 
			    	{
				    sw.WriteLine("Case #"+(i+1)+": "+j);
                    sw.Flush();
                      goto A;
				    }
        A: ;
		    }
        }
    }
}
