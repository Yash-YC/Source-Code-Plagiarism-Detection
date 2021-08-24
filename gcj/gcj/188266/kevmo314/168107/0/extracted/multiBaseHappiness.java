import java.io.*;
import java.util.*;
import java.math.*;

public class multiBaseHappiness {
	public static void main(String[] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new FileReader("multiBaseHappiness.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("multiBaseHappiness.out")));
		
		int numTestCases = Integer.parseInt(in.readLine());
		for(int i = 0; i < numTestCases; i++)
		{
			System.out.println(i);
			StringTokenizer token = new StringTokenizer(in.readLine());
			int j = 0;
			Arrays.fill(bases, 0);
			while(token.hasMoreTokens())
			{
				bases[j++] = Integer.parseInt(token.nextToken());
			}
			out.println("Case #"+(i+1)+": "+minHappyValue(j-1));
		}
		
		out.close(); // close the output file
		System.exit(0); // don't omit this!
	}
	public static int minHappyValue(int baseCt)
	{
		int i = 1;
		while(true)
		{
			i++;
			boolean validSolution = true;
			for(int j = 0; j <= baseCt; j++)
			{
				Arrays.fill(visited, false);
				if(!numIsHappy(String.valueOf(i), bases[j]))
				{
					validSolution = false;
					break;
				}
			}
			if(validSolution == true)
				return i;
		}
	}
	static int[] bases = new int[3];
	static boolean[] visited = new boolean[100000];
	public static boolean numIsHappy(String val, int base)
	{
		if(Integer.parseInt(val) == 1)
			return true;
		else if(visited[Integer.parseInt(val)])
			return false;
		else
		{
			visited[Integer.parseInt(val)] = true;
			return numIsHappy(iterate(val, base), base);
		}
	}
	public static String iterate(String val, int base)
	{
		val = Integer.toString(Integer.parseInt(val), base);
		int sum = 0;	// in base 10;
		for(int i = val.length()-1; i >= 0; i--)
		{
			int digit = Integer.parseInt(String.valueOf(val.charAt(i)));
			digit *= digit;
			sum += digit;

		}
		return String.valueOf(sum);
	}
}
