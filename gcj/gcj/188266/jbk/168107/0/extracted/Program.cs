/*
 * Created by SharpDevelop.
 * User: jbk
 * Date: 2009-09-12
 * Time: 02:59
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace round1A
{
	class Program
	{
		static long casesT;
		
		public static string ReverseString(string input)
		{
			char[] arr = input.ToCharArray();
		    Array.Reverse(arr);
		    return new string(arr);
		}
		
		public static List<long> SplitDecimToIntList(long decim)
		{
			List<long> result = new List<long>();
			foreach (var currentChar in decim.ToString())
			{
				result.Add(long.Parse(currentChar.ToString()));
			}
			return result;
		}
		
		public static string DecimToOtherBaseString(long decim, long otherBase)
		{
            if (decim == 0)
            {
                return "0";
            }

			string result = string.Empty;
			long currentResult = decim;
			while (currentResult!=0)
			{
				result += (currentResult % otherBase).ToString();
				currentResult = currentResult / otherBase;
			}
			
			return ReverseString(result);
		}
		
		public static long OtherBaseStringToDecim(string stringNumber, long otherBase)
		{
			long intResult = 0;
			string workOnString = ReverseString(stringNumber);
			for (int i=0; i<workOnString.Length; ++i)
			{
				intResult += Convert.ToInt64(workOnString[i].ToString()) * Convert.ToInt64(Math.Pow(otherBase,i));
			}
			
			return intResult;
		}
		
		public static bool CheckIsHappy(long a, List<long> bases)
		{
			List<long> list = SplitDecimToIntList(a);
		
			foreach (long currentBase in bases)
			{
                long b = Convert.ToInt64(DecimToOtherBaseString(a, currentBase));
				List<long> wasNumbers = new List<long>();
				while (SplitDecimToIntList(b).Count>1 ||
				       SplitDecimToIntList(b).Count==1 &&
				       SplitDecimToIntList(b)[0]!=1)
				{
                    long c = 0;
					foreach (long digit in SplitDecimToIntList(b))
					{
						c+=digit*digit;
					}

                    if (wasNumbers.Contains(c))
					{
						return false;
					}
					else
					{
                        wasNumbers.Add(c);
					}
                    b = Convert.ToInt64(DecimToOtherBaseString(c, currentBase));
				}		
			}

			return true;
		}
		
		public static void Main(string[] args)
		{
            TextWriter streamWriter = new StreamWriter("d:\\out.out");
			using (StreamReader streamReader = new StreamReader(/*args[0]*/"d:\\a.in"))
            {
				casesT = long.Parse(streamReader.ReadLine());
				
                int linenumber = 0;
				List<long> bases;
				while (!streamReader.EndOfStream)
				{
                    linenumber++;
					bases = new List<long>();
					string[] numbers = streamReader.ReadLine().Split(' ');
					foreach (var currentStr in numbers)
					{
						bases.Add(Convert.ToInt64(currentStr));
					}
					
					
					for (long i = 2; i<100000; ++i)
					{	
						if (CheckIsHappy(i, bases))
						{
							Console.WriteLine("HAPPY: "+i.ToString());
                            streamWriter.WriteLine(String.Format("Case #{0}: {1}",linenumber, i));

                            break;
						}
					}
							
					
					
				}
            }
			
			streamWriter.Close();
			
			Console.Write("Press any key to continue . . . ");
			Console.ReadKey(true);
		}
	}
}