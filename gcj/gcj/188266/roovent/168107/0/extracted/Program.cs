using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace QualificationRound_2
{
	class Program
	{
		static string inPath = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.Desktop), "A-small-attempt0.in");
		static string outPath = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.Desktop), "a-small.out");

		static List<int> list = new List<int>();

		static void Main(string[] args)
		{
			StreamReader sr = new StreamReader(inPath);
			StreamWriter sw = new StreamWriter(outPath);

			int c = int.Parse(sr.ReadLine());

			for (int i = 0; i < c; ++i)
			{
				string[] B = sr.ReadLine().Split(' ');
				int[] b = new int[B.Length];
				for (int j = 0; j < b.Length; ++j)
				{
					b[j] = int.Parse(B[j]);
				}

				int o = 1;

				xxx:++o;
				for (int j = 0; j < b.Length; ++j)
				{
					list.Clear();
					if (!isHappyNumer(b[j], o))
					{
						goto xxx;
					}
				}
				sw.WriteLine("Case #{0}: {1}", (i + 1).ToString(), o.ToString());
			}

			sr.Close();
			sw.Close();
		}

		static bool isHappyNumer(int b, int N)
		{
			list.Add(N);
			List<int> l = new List<int>();
			int n = N;
			while (n > 0)
			{
				l.Add(n % b);
				n = n / b;
			}

			int sum = 0;
			foreach (int x in l)
			{
				sum += x * x;
			}

			if (sum * sum >= b && !list.Contains(sum))
			{
				return isHappyNumer(b, sum);
			}
			else if (sum == 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}
