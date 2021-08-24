using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace cj1a
{
	class Program
	{
		//const string fin = "test.txt";
		const string fin = "A-small-attempt0.in";
		//const string fin = "A-large.in";
		const string OUT_STR = "Case #{0}: {1}";

		static void Main(string[] args)
		{
			StreamReader sr; StreamWriter sw;
			GcjParser.CreateIO(fin, out sr, out sw);

			// Header
			var tks = sr.InputsOnLine().Parse<int>();
			int T = tks[0];

			for (int i = 0; i < T; i++)
			{
				var bases = sr.InputsOnLine().Parse<int>();
				var result = Help(bases);
				sw.WriteLine(OUT_STR, i + 1, result);
			}

			sr.Close();
			sw.Close();
		}

		private static int Help(int[] bases)
		{
			Dictionary<int, bool>[] di = new Dictionary<int, bool>[bases.Length];
			for (int i = 0; i < di.Length; i++)
			{
				di[i] = new Dictionary<int, bool>();
			}
			var notFound = true;
			int maxNew = 10;
			int maxLast = 2;
			while (notFound)
			{
				for (int i = 0; i < di.Length; i++)
				{
					for (int j = maxLast; j < maxNew; j++)
					{
						if (!di[i].ContainsKey(j))
						{
							di[i].Add(j, isHappy(j, di[i], bases[i], new LinkedList<int>()));
						}
					}
				}

				for (int j = maxLast; j < maxNew; j++)
				{
					var ok = true;
					for (int i = 0; i < di.Length; i++)
					{
						ok &= isHappy(j, di[i], bases[i], null);
					}
					if (ok)
					{
						notFound = false;
						return j;
					}
				}

				maxLast = maxNew;
				maxNew *= 2;
			}
			throw new Exception();
		}

		private static bool isHappy(int i, Dictionary<int, bool> d, int p, LinkedList<int> tried)
		{
			if (i == 0)
			{
				return false;
			}
			if (i == 1)
			{
				return true;
			}
			if (d.ContainsKey(i))
			{
				return d[i];
			}
			tried.AddFirst(i);
			List<int> l = new List<int>();
			while (i != 0)
			{
				var ta = i % p;
				l.Add(ta);
				i /= p;
			}
			var newNum = 0;
			foreach (var item in l)
			{
				newNum += item * item;
			}
			if (tried.Contains(newNum))
			{
				return false;
			}
			return isHappy(newNum, d, p, tried);
		}
	}

	#region Input Parsing
	public static class GcjParser
	{
		public static string[] InputsOnLine(this StreamReader sr)
		{
			var x = sr.ReadLine();
			return x.Split(' ');
		}

		public static T[] Parse<T>(this string[] s) where T : struct
		{
			T[] ii = new T[s.Length];
			if (typeof(T).Equals(typeof(int)))
			{
				for (int i = 0; i < s.Length; i++)
				{
					object o = int.Parse(s[i]);
					ii[i] = (T)o;
				}
			}
			if (typeof(T).Equals(typeof(double)))
			{
				for (int i = 0; i < s.Length; i++)
				{
					object o = double.Parse(s[i]);
					ii[i] = (T)o;
				}
			}
			return ii;
		}

		public static void CreateIO(string s, out StreamReader sr, out StreamWriter sw)
		{
			var path = GetPath(s);
			sr = File.OpenText(Path.Combine(path, s));
			string sOut = null;
			if (s.Contains(".in"))
			{
				sOut = s.Replace(".in", ".out");
			}
			else
			{
				sOut = s.Replace(".txt", ".out");
			}
			sw = File.CreateText(Path.Combine(path, sOut));
		}

		private static string GetPath(string s)
		{
			string[] srcDirs = new string[]
			{
				Environment.GetFolderPath(Environment.SpecialFolder.Desktop),
				Directory.GetCurrentDirectory()
			};
			foreach (var item in srcDirs)
			{
				if (File.Exists(Path.Combine(item, s)))
				{
					return item;
				}
			}
			throw new Exception("File Not Found");
		}
	}
	#endregion
}
