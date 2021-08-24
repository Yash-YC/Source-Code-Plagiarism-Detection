using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

namespace Multibase
{
	class Program
	{
		static void Main(string[] args)
		{
			var T = int.Parse(Console.In.ReadLine());
			for (int X = 0; X < T; X++)
			{
				var bases = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();

				for (int i = 2; i <= int.MaxValue /* ?? */; i++)
				{
					bool sad = false;
					foreach (var b in bases)
					{
						if (!IsHappy(i, b))
						{
							sad = true;
							break;
						}
					}
					if (!sad)
					{
						Console.WriteLine("Case #{0}: {1}", X + 1, i);
						break;
					}
				}
			}
		}

		static int[] BaseNDigits(int value, int radix)
		{
			Stack<int> digits = new Stack<int>();
			do
			{
				int digit;
				value = Math.DivRem(value, radix, out digit);
				digits.Push(digit);
			} while (value > 0);
			return digits.ToArray();
		}

		static int BaseNInt(int[] digits, int radix)
		{
			int result = 0;
			for (int i = 0; i < digits.Length; i++)
			{
				var p = (int)Math.Round(Math.Pow(radix, i));
				result += digits[digits.Length - i - 1] * p;
			}
			return result;
		}

		static bool IsHappy(int value, int radix)
		{
			var valuesTested = new List<int>();

			for (; ; )
			{
				var digits = BaseNDigits(value, radix);
				var processed = digits.Select(d => d * d).Sum();
	
				if (processed == 1) return true;
				if (valuesTested.Contains(processed)) return false;
				else
				{
					valuesTested.Add(processed);
					value = processed;
				}
			}
		}
	}
}
