using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Library.Extensions;

namespace Competition
{
	class Class1
	{
		public void DoStufF()
		{
			var file = System.IO.File.ReadAllLines(@"C:\Users\root\Documents\Downloads\A-large.in");
//            var file2 = @"3
//2 3 4 5 6 7 8 9 10";
//            var file = file2.Split(new string[] { Environment.NewLine }, StringSplitOptions.RemoveEmptyEntries);

			var sb = new System.Text.StringBuilder();

			for (int i = 0; i < haha.Length; i++) haha[i] = new List<long>();

			for (int i = 1; i < file.Length; i++)
			{
				int[] n = file[i].Split(' ').Convert(x => int.Parse(x));

				List<IEnumerable<long>> ha = new List<IEnumerable<long>>();
				
				for (int j = 0; j < n.Length; j++)
				{
					if (n[j] == 2 || n[j] == 4) continue;
					ha.Add(SQ(n[j]));
					//la[j] = SQ(n[j]);
				}
				IEnumerable<long>[] la = ha.ToArray();

				Highest = 2;
				long lowestMatch = 2;
				if (la.Length > 0)
				{
					if (la.Length == 7)
					{
						//all of them
						lowestMatch = 11814485;
					}
					else
					{
						lowestMatch = Find(la);
					}
				}

				sb.AppendFormat("Case #{0}: {1}", i, lowestMatch);
				sb.AppendLine();
			}

			//int bassp = 11814485;

			System.IO.File.WriteAllText(@"C:\Pub\a.txt", sb.ToString());
			int bp = 0;
		}

		public long Find(IEnumerable<long>[] la)
		{
			var first = la[0];
			for (int i = 1; i < la.Length; i++)
			{
				var somethingnew = first;
				first = MakeEqual(somethingnew, la[i]);
			}

			return first.First();
		}

		public IEnumerable<long> MakeEqual(IEnumerable<long> a, IEnumerable<long> b)
		{
			var aa = a.GetEnumerator();
			var bb = b.GetEnumerator();
			aa.MoveNext();
			bb.MoveNext();

			while (true)
			{
				if (aa.Current == bb.Current)
				{
					yield return aa.Current;
					aa.MoveNext();
				}
				else if (aa.Current > bb.Current)
				{
					bb.MoveNext();
				}
				else
				{
					aa.MoveNext();
				}
			}
		}

		private List<long>[] haha = new List<long>[11];
		private long Highest = 2;

		public IEnumerable<long> SQ(int b)
		{
			long num = 2;
			while (true)
			{
				if (num < Highest) num = Highest;

				if (IsSquareNumber(num, b))
				{
					//haha[b].Add(num);
					Highest = num;
					yield return num;
				}
				num++;
			}
		}

		private struct T
		{
			public long A;
			public int B;
		}

		private Dictionary<T, bool> look = new Dictionary<T, bool>();
		private Dictionary<long, bool> local = new Dictionary<long, bool>();
		private bool IsSquareNumber(long num, int b)
		{
			local.Clear();

			while (true)
			{
				long newSquare = SquareNumber(num, b);
				if (newSquare == 1 )
				{
					//good
					foreach (long val in local.Keys)
					{
						T tt = new T();
						tt.A = val;
						tt.B = b;
						look.Add(tt, true);
					}
					return true;
				}
				if (local.ContainsKey(newSquare))
				{
					//bad
					foreach (long val in local.Keys)
					{
						T tt = new T();
						tt.A = val;
						tt.B = b;
						look.Add(tt, false);
					}

					//circle
					return false;
				}
				T ttt = new T();
				ttt.A = newSquare;
				ttt.B = b;
				if (look.ContainsKey(ttt))
				{
					bool rr = look[ttt];
					foreach (long val in local.Keys)
					{
						T tt = new T();
						tt.A = val;
						tt.B = b;
						look.Add(tt, rr);
					}

					//circle
					return rr;
				}

				local.Add(newSquare, false);
				num = newSquare;
			}
		}

		public long SquareNumber(long num, int b)
		{
			long rtn = 0;
			while (num > 0)
			{
				long temp = num % b;
				rtn += (temp * temp);
				num /= b;
			}

			return rtn;
		}

	}
}
