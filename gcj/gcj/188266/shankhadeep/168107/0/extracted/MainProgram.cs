using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Round1
{
   public class MainProgram
    {
       public static void Main(string[] args)
       {
           if (args.Length <= 0)
           {
               Console.WriteLine("Invalid Input");
               return;
           }
           string value = Console.ReadLine();
           string path = args[0];
           if (!File.Exists(path))
           {
               Console.WriteLine("File mention does not exist");
           }
           using (StreamReader reader = new StreamReader(File.OpenRead(path)))
           {
               int caseCount = int.Parse(reader.ReadLine());
               

              string[] output ;//= MilkShakes.Execute(caseCount, reader);
              output = ProblemA.Execute(caseCount, reader);
              //output = ProblemB.Execute(caseCount, reader);
              //output = ProblemC.Execute(caseCount, reader);

              
               File.WriteAllLines(@"C:\googlecodejam2009\Round1A\ProblemA\output.txt", output);
               //File.WriteAllLines(@"C:\googlecodejam2009\Round1A\ProblemB\output.txt", output);
               //File.WriteAllLines(@"C:\googlecodejam2009\Round1A\ProblemC\output.txt", output);

           }
       }
    }
}

