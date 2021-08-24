using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Problem_A {
	class Program {
		static void Main(string[] args) {
			StreamReader reader = new StreamReader("input.in");
			StreamWriter writer = new StreamWriter("output.out", false);
			int numCases = int.Parse(reader.ReadLine());
			for (int i = 0; i < numCases; i++) {
				int[] bases = Array.ConvertAll<string, int>(reader.ReadLine().Split(' '), new Converter<string, int>(System.Convert.ToInt32));
				bool found = false;
				int j = 2;
				while (!found) {
					bool happy = true;
					foreach (int k in bases) {
						if (happy) {
							HashSet<int> cycledetect = new HashSet<int>();
							int temp = j;
							int sumSquares = 0;
							while (sumSquares != 1) {
								sumSquares = 0;
								while (temp > 0) {
									int digit;
									temp = Math.DivRem(temp, k, out digit);
									sumSquares += digit * digit;
								}
								if (!cycledetect.Add(sumSquares)) {
									happy = false;
									break;
								}
								temp = sumSquares;
							}
						} else {
							break;
						}
					}
					if (happy) {
						writer.WriteLine("Case #{0}: {1}", i + 1, j);
						break;
					}
					j++;
				}
			}
			reader.Close();
			writer.Close();
		}
	}
}
