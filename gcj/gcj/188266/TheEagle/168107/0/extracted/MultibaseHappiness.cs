using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam2009
{
    public class MultibaseHappiness : BaseClass
    {
        public const int base10 = 10;
        char[] cHexa = new char[] { 'A', 'B', 'C', 'D', 'E', 'F' };
        int[] iHexaNumeric = new int[] { 10, 11, 12, 13, 14, 15 };
        int[] iHexaIndices = new int[] { 0, 1, 2, 3, 4, 5 };
        const int asciiDiff = 48;

        private class NonHappyNumber
        {
            private long _baseNumber;
            private List<long> _numbers;
            

            public NonHappyNumber()
            {
                _numbers = new List<long>();
            }

            public long BaseNumber
            {
                get
                {
                    return _baseNumber;
                }
                set
                {
                    _baseNumber = value;
                }
            }

            public List<long> Numbers
            {
                get
                {
                    return _numbers;
                }
                set
                {
                    _numbers = value;
                }
            }
        }
        private List<NonHappyNumber> nonHappyNumbers = new List<NonHappyNumber>();

        public string Run(string inputFile)
        {
            int nbCases = base.GetInput(inputFile);
            StringBuilder output = new StringBuilder();

            for (int i = 0; i < nbCases; i++)
            {
                output.Append("Case #" + (i + 1).ToString() + ": " + GetMinNumber() + Environment.NewLine);
            }

            StreamWriter writer = new StreamWriter(inputFile.Replace(".in", ".out"));
            writer.Write(output.ToString());
            writer.Close();
            return inputFile.Replace(".in", ".out");
        }

        private string GetMinNumber()
        {
            string[] bases = Lines[Cursor++].Split(' ');
            long startIndex = 2;

            for (int i = 0; i < bases.Length; i++ )
            {
                List<long> allNumbers = new List<long>();
                if (IsHappyNumber(startIndex, int.Parse(bases[i]), ref allNumbers))
                {
                    continue;
                }
                else
                {
                    startIndex = GetMinNumberByBase(int.Parse(bases[i]), startIndex);
                    i = -1;
                }
            }

            return startIndex.ToString();
        }

        private long GetMinNumberByBase(int baseNumber, long startIndex)
        {
            for (long i = startIndex; true; i++)
            {
                List<long> allNumber = new List<long>();
                if (IsHappyNumber(i, baseNumber, ref allNumber))
                {
                    return i;
                }
            }
        }

        private bool IsHappyNumber(long initialNumber, int baseNumber, ref List<long> allNumbers)
        {
            allNumbers.Add(initialNumber);
            string nInBase;
            if (initialNumber < baseNumber)
            {
                nInBase = initialNumber.ToString();
            }
            else
            {
                nInBase = DecimalToBase((int)initialNumber, baseNumber);
            }
            long sum = 0;
            long n = 0;

            for (int j = 0; j < nInBase.Length; j++)
            {
                n = long.Parse(nInBase[j].ToString());
                sum += n * n;
            }

            if (sum.Equals(1))
            {
                return true;
            }
            else if (nonHappyNumbers.Count(x => (x.BaseNumber.Equals(baseNumber) && x.Numbers.Contains(sum))) > 0)
            {
                return false;
            }
            else if (allNumbers.Contains(sum))
            {
                NonHappyNumber nonHappyBaseNumber = (from x in nonHappyNumbers
                                                     where x.BaseNumber.Equals(baseNumber)
                                                     select x).FirstOrDefault();
                if (nonHappyBaseNumber != null)
                {
                    nonHappyBaseNumber.Numbers.Add(sum);
                    nonHappyBaseNumber.Numbers.Add(n);
                }
                else
                {
                    NonHappyNumber newNonHappyNumber = new NonHappyNumber();
                    newNonHappyNumber.BaseNumber = baseNumber;
                    newNonHappyNumber.Numbers.Add(sum);
                    newNonHappyNumber.Numbers.Add(n);
                    nonHappyNumbers.Add(newNonHappyNumber);
                }

                return false;
            }
            else
            {
                return IsHappyNumber(sum, baseNumber, ref allNumbers);
            }
        }

        private string DecimalToBase(int iDec, int numbase)
{
	string strBin = "";
	int[] result = new int[32];
	int MaxBit = 32;
	for(; iDec > 0; iDec/=numbase)
	{
		int rem = iDec % numbase;
		result[--MaxBit] = rem;
	} 
	for (int i=0;i<result.Length;i++)
		if ((int)result.GetValue(i) >= 10)
		strBin += cHexa[(int)result.GetValue(i)%10];
		else
			strBin += result.GetValue(i);
		strBin = strBin.TrimStart(new char[] {'0'});
	return strBin;
        }

    }
}
