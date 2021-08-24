using System;
using System.Collections.Generic;
using System.Text;
using System.Collections.ObjectModel;
using System.Text.RegularExpressions;

namespace GoogleCodeJam.RoundOne
{
    public class MultiBaseProblemSolver
    {

        private Collection<Collection<int>> testCases = new Collection<Collection<int>>();
        private const string InputPath = "A-small-attempt0_1.in";
        private const string OutputPath = "Test.out";

        Collection<ulong> handled = new Collection<ulong>();
        private void LoadData()
        {
            Collection<string> rawData = InputAndOutPut.ReadData(InputPath);
            int caseCount = 0;
            caseCount = Convert.ToInt32(rawData[0]);

            //Loads test cases
            for (int i = 0; i < caseCount; i++)
            {
                string[] subCases = rawData[i + 1].Split(' ');

                Collection<int> temValues = new Collection<int>();
                foreach (string str in subCases)
                {
                    temValues.Add(Convert.ToInt32(str));
                }
                testCases.Add(temValues);
            }
        }

        private bool IsHappyNum(ulong value ,ulong baseN )
        {
            ulong sum = 0;
            ulong temValue = value;
            ulong tem = temValue % 10;
            while (temValue != 0)
            {
                sum = sum + (ulong)(tem * tem);
                temValue = temValue / 10;
                tem = temValue % 10;
            }
            if (sum == 1)
            {
                return true;
            }
            sum = ConvertNumber(sum, baseN);
            if (handled.Contains(sum))
            {
                return false;
            }
            if (sum != 1)
            {
                handled.Add(sum);
                return IsHappyNum(sum, baseN);
            }
            return true;
        }

        private ulong ConvertNumber(ulong number, ulong numberBase)
        {
            ulong result = 0;
            ulong tem;
            ulong tem2;
            tem = number / numberBase;
            tem2 = number % numberBase;
            int index = 0;
            while (tem != 0)
            {
                result = result + tem2 * GetNunber(index);
                tem2 = tem % numberBase;
                tem = tem / numberBase;
                index++;
            }
            result = result + tem2 * GetNunber(index);
            return result;
        }
        private ulong GetNunber(int count)
        {
            ulong result = 1;
            for (int i = 0; i < count; i++)
            {
                result = result * 10;
            }
            return result;
        }

        private ulong GetSmallest(Collection<int> numberBases)
        {
            ulong tem = 2;
            while (true)
            {
                bool success = false;
                foreach (int baseN in numberBases)
                {
                    ulong conversed = ConvertNumber((ulong)tem,(ulong) baseN);
                    handled.Clear();
                    success = IsHappyNum(conversed, (ulong)baseN);
                    if (!success)
                    {
                        break;
                    }
                }
                if (success)
                {
                    return tem;
                }
                tem++;
            }
        }

        private Collection<string> GetResult()
        {
            Collection<string> result = new Collection<string>();

            const string OutFormat = "Case #{0}: {1}";
            for (int i = 0; i < testCases.Count; i++)
            {
                Collection<int> currentCase = testCases[i];
                ulong smallest = GetSmallest(currentCase);
                result.Add(string.Format(OutFormat, i + 1, smallest));
            }

            return result;
        }

        public void Solve()
        {
            LoadData();
            Collection<string> result = GetResult();
            InputAndOutPut.WriteResult(OutputPath, result);
        }
    }
}
