using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;

namespace GCJ2008
{
	class Numbers
	{
		static void go(int r, int c, int N, int M, int m, int t, int[, ,] times, SortedList<int, List<KeyValuePair<KeyValuePair<int, int>, int>>> q)
		{
			if (r >= 0 && r < N && c >= 0 && c < M && times[r, c, m] >= t)
			{
				KeyValuePair<KeyValuePair<int, int>, int> kvp = new KeyValuePair<KeyValuePair<int, int>, int>(new KeyValuePair<int, int>(r, c), m);
				List<KeyValuePair<KeyValuePair<int, int>, int>> list;
				if(!q.TryGetValue(t, out list))
				{
					list = new List<KeyValuePair<KeyValuePair<int,int>,int>>();
					q[t] = list;
				}
				list.Add(kvp);
				times[r, c, m] = t;
			}
		}
		static int nexth(int time, int r, int c, int[,] S, int[,] W, int[,] T)
		{
			int s = S[r, c];
			int w = W[r, c];
			int t = T[r, c];
			int period = s + w;
			int diff = t - time;
			if (diff > 0)
			{
				int amt = (int)Math.Ceiling((double)diff / period);
				t -= amt * period;
			}
			else
			{
				int amt = -diff / period;
				t += amt * period;
			}
			while (t > time)
			{
				t -= period;
			}
			while (t + period <= time)
			{
				t += period;
			}
			if (time < t + s)
			{
				return t + s;
			}
			else
			{
				return time;
			}
		}
		static int nextv(int time, int r, int c, int[,] S, int[,] W, int[,] T)
		{
			int s = S[r, c];
			int w = W[r, c];
			int t = T[r, c];
			int period = s + w;
			int diff = t - time;
			if (diff > 0)
			{
				int amt = (int)Math.Ceiling((double)diff / period);
				t -= amt * period;
			}
			else
			{
				int amt = -diff / period;
				t += amt * period;
			}
			while (t > time)
			{
				t -= period;
			} 
			while (t + period <= time)
			{
				t += period;
			}
			if (time >= t + s)
			{
				return t + period;
			}
			else
			{
				return time;
			}
		}
		static void Main(string[] args)
		{
			string[] lines = File.ReadAllLines("B-small-attempt4.in");
			int lineAt = 0;
			string output = "";

			int cases = int.Parse(lines[lineAt++]);
			for (int i = 0; i < cases; i++)
			{
				string[] size = lines[lineAt++].Split(' ');
				int N = int.Parse(size[0]);
				int M = int.Parse(size[1]);
				int[,] S = new int[N, M];
				int[,] W = new int[N, M];
				int[,] T = new int[N, M];
				for (int j = 0; j < N; j++)
				{
					string[] num = lines[lineAt++].Split(' ');
				
					for (int k = 0; k < 3 * M; k+=3)
					{
						S[j, k / 3] = int.Parse(num[k]);
						W[j, k / 3] = int.Parse(num[k+1]);
						T[j, k / 3] = int.Parse(num[k+2]);
					}
				}
				int[,,] times = new int[N, M, 4];
				for (int j = N - 1; j >= 0; j--)
				{
					for (int k = M - 1; k >= 0; k--)
					{
						for (int m = 3; m >= 0; m--)
						{
							times[j, k, m] = int.MaxValue;
						}
					}
				}
				times[N-1,0,0] = 0;
				KeyValuePair<KeyValuePair<int,int>,int> t = new KeyValuePair<KeyValuePair<int,int>,int>(new KeyValuePair<int, int>(N-1, 0), 0);
				SortedList<int, List<KeyValuePair<KeyValuePair<int,int>,int>>> q = new SortedList<int,List<KeyValuePair<KeyValuePair<int,int>,int>>>();
				List<KeyValuePair<KeyValuePair<int, int>, int>> lame = new List<KeyValuePair<KeyValuePair<int, int>, int>>();
				lame.Add(t);
				q.Add(0, lame);
				int result = 0;
				while(q.Count > 0)
				{
					List<KeyValuePair<KeyValuePair<int, int>, int>> lameo = q.Values[0];
					KeyValuePair<KeyValuePair<int, int>, int> next = lameo[0];

					int r = next.Key.Key;
					int c = next.Key.Value;
					int m = next.Value;
					
					int time = q.Keys[0];
					
					if (lameo.Count == 1)
					{
						q.RemoveAt(0);
					}
					else
					{
						lameo.RemoveAt(0);
					}
					if (r == 0 && c == M - 1 && m == 3)
					{
						result = time;
						break;
					}
					int nv = nextv(time, r, c, S, W, T);
					if(nv < time)
					{
						Console.WriteLine("arrgg");
					}
					int nh = nexth(time, r, c, S, W, T);
					if(nh < time)
					{
						Console.WriteLine("arggg");
					}
					if (times[r, c, m] < time)
					{
						continue;
					}
					switch (m)
					{
						/* 
						 1 3
						 0 2
						 */
						case 0:
							
								go(r - 1, c, N, M, 1, time + 2, times, q);
								go(r, c - 1, N, M, 2, time + 2, times, q);
							
							
							go(r, c, N, M, 1, nextv(time, r, c, S, W, T) + 1, times, q);
							go(r, c, N, M, 2, nexth(time, r, c, S, W, T) + 1, times, q);
							
							break;
						case 1:
							
								go(r + 1, c, N, M, 0, time + 2, times, q);
								go(r, c - 1, N, M, 3, time + 2, times, q);
							

							go(r, c, N, M, 0, nextv(time, r, c, S, W, T) + 1, times, q);
							go(r, c, N, M, 3, nexth(time, r, c, S, W, T) + 1, times, q);
							break;
						case 2:
							
								go(r - 1, c, N, M, 3, time + 2, times, q);
								go(r, c + 1, N, M, 0, time + 2, times, q);
							

							go(r, c, N, M, 3, nextv(time, r, c, S, W, T) + 1, times, q);
							go(r, c, N, M, 0, nexth(time, r, c, S, W, T) + 1, times, q);
							break;
						case 3:
							
								go(r + 1, c, N, M, 2, time + 2, times, q);
								go(r, c + 1, N, M, 1, time + 2, times, q);
							
							go(r, c, N, M, 2, nextv(time, r, c, S, W, T) + 1, times, q);
							go(r, c, N, M, 1, nexth(time, r, c, S, W, T) + 1, times, q);
							break;
					}
				}

				output += "Case #" + (i + 1) + ": " + result;
				output += Environment.NewLine;
				
			}
			Console.WriteLine(output);
			File.WriteAllText("output.txt", output);
		}
	}
}
