import java.io.*;
import java.util.*;

public class CodeJamA
{
	// Not used
   public static int changeBase(int number, int base)
   {
	   String newNumber ="";
	   while (number > 0)
	   {
		   newNumber = String.valueOf(number % base) + newNumber;
		   number /= base;
	   }
	   return Integer.parseInt(newNumber);
		   
   }
	
   public static boolean isHappy(int number, int base)
	{
	   Set < Integer> used = new HashSet<Integer>();
	while (number > 0)
	{
		int next = number;
		int sumOfSquares = 0;
		while (next > 0)
		{
			int digit = next %base;
			sumOfSquares += digit * digit;
			next /= base;
		}
		if (sumOfSquares ==1 )
		{
			return true;
		}
		if (used.contains(sumOfSquares ))
			return false;
		used.add(sumOfSquares);
		number = sumOfSquares;
	//	number = changeBase(sumOfSquares,base);
	//	System.out.println(number + " "+ base);
	}
	return false;
		 
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException
	{
		String fileName = "A-small0";
		Scanner in = new Scanner(new File(fileName+ ".in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				fileName + ".out")));

		// Keep track of time for efficiency
		long startTime = System.currentTimeMillis();
		
		// Process each of the test cases
		int N = in.nextInt();
		in.nextLine();
		
		for (int caseNo = 1; caseNo <= N; caseNo++)
		{
			int [] bases = new int [10];
			int noOfBases = 0;
			Scanner baseStr = new Scanner(in.nextLine());
			while (baseStr.hasNextInt())
				bases[noOfBases++] = baseStr.nextInt();
			
			for (int i = 0; i < noOfBases; i++)
				System.out.print(bases[i] + " ");
			System.out.println();
            int number = 2;
            boolean allHappy = false;
            while (!allHappy)
            {
            	allHappy = true;
            	for (int i = 0; i < noOfBases && allHappy; i++)
            		if (!isHappy(number,bases[i]))
            			allHappy = false;
            	if (allHappy == false)
            	number ++;
            }
			
			// Find the happy numbers
			
			// Output the results
			System.out.println("Case #" + caseNo + ": " + number );
			out.println("Case #" + caseNo + ": " + number);
		}
		
		System.out.println("Done");
		long stopTime = System.currentTimeMillis();
		System.out.println("Time: " + (stopTime - startTime)/1000.0);
		
		// Close the files
		in.close();
		out.close();
	}

}
