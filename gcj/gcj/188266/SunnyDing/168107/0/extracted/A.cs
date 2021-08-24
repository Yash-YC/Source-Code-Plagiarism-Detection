using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Round1A_A
{
    class A
    {
        const string _DatasetInput = "A-small-attempt0.in";
        const string _DatasetOutput = "A-small-attempt0.out";

        static void Main(string[] args)
        {
            try
            {
                A program = new A();
                Console.WriteLine("Process Beginning...");
                program.Process(_DatasetInput, _DatasetOutput);
                Console.WriteLine("Process End.");
            }
            catch (System.Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                Console.WriteLine();
                Console.WriteLine("Press Any Key to Exit the Program...");
                Console.ReadKey();
            }

        }

        public void Process(string in_file_path, string out_file_path)
        {
            try
            {

                StreamReader reader = new StreamReader(in_file_path, Encoding.Default);

                if (File.Exists(out_file_path))
                {
                    File.Delete(out_file_path);
                }

                int iMax = int.Parse(reader.ReadLine().ToString());
                int i = 1;

                while (i <= iMax && (!reader.EndOfStream))
                {
                    string strBaseList = reader.ReadLine();
                    string strOutput = "Case #" + i.ToString() + ": " + GetResultNumber(strBaseList);
                    WriteOutput(out_file_path, strOutput);
                    i += 1;
                }

                reader.Dispose();
            }
            catch (System.Exception ex)
            {
                throw ex;
            }
        }

        private string GetResultNumber(string strBaseList)
        {
            string[] strList = strBaseList.Split(' ');
            int[] iBaseList = new int[strList.Length];
            for (int i = 0; i < strList.Length; i++)
            {
                iBaseList[i] = int.Parse(strList[i].ToString());
            }

            Int64 iResult = 0;
            bool bFlag = false;

            for (Int64 i = 2; !bFlag; i++)
            {
                for (int j = 0; j < iBaseList.Length; j++)
                {
                    bFlag = IsHappyNum(ConvBaseNumString(i, iBaseList[j]), iBaseList[j], string.Empty);
                    if (!bFlag)
                    {
                        break;
                    }
                }
                if (bFlag)
                {
                    iResult = i;
                }
            }


            return iResult.ToString();
        }

        private string ConvBaseNumString(Int64 iNum, int iBase)
        {
            string strResult = string.Empty;

            for (Int64 i = iNum; i > 0; i /= iBase)
            {
                strResult = (i % iBase).ToString() + strResult;
            }

            return strResult;
        }

        private bool IsHappyNum(string strNum, int iBase, string strHistory)
        {
            char[] cInt = strNum.ToCharArray();
            Int64 iNum = 0;
            for (int i = 0; i < cInt.Length; i++)
            {
                iNum += Int64.Parse(cInt[i].ToString()) * Int64.Parse(cInt[i].ToString());
            }

            if (iNum == 1)
            {
                return true;
            }
            else
            {
                string strNewNum = ConvBaseNumString(iNum, iBase);
                if (strHistory.IndexOf("^" + strNewNum + "^") != -1)
                {
                    return false;
                }
                else
                {
                    string strNewHistory = strHistory + "^" + strNewNum + "^";
                    return IsHappyNum(strNewNum, iBase,strNewHistory);
                }
            }
        }

        private void WriteOutput(string file_path, string content)
        {

            StreamWriter writer = new StreamWriter(file_path, true, Encoding.Default);

            writer.WriteLine(content);
            writer.Flush();
            writer.Close();
            writer.Dispose();

        }

    }
}
