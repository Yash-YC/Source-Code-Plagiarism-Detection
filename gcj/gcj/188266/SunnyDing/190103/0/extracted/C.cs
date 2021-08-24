using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Round1A_C
{
    class C
    {
        const string _DatasetInput = "C-small-attempt0.in";
        const string _DatasetOutput = "C-small-attempt0.out";

        static void Main(string[] args)
        {
            try
            {
                C program = new C();
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
                    string[] str = reader.ReadLine().Split(' ');
                    int iC = int.Parse(str[0].ToString());
                    int iN = int.Parse(str[1].ToString());
                    string strOutput = "Case #" + i.ToString() + ": " + GetResultNumber(iC, iN);
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

        private string GetResultNumber(int iC, int iN)
        {
            decimal dC = iC;
            decimal dN = iN;

            decimal dResult = (dC - dN) + (dC / dN);

            return dResult.ToString("f7");
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
