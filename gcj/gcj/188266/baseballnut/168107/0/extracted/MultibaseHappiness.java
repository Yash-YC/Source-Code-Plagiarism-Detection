package gcj2009;

import java.util.*;
import java.io.*;

public class MultibaseHappiness
{

	public MultibaseHappiness()
	{
		happy = new int [11][1000000];
		checked = new boolean [11][1000000];
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 1000000; j++)
			{
				checked[i][j] = false;
			}
		}
	}
	
	public void setBases(int[] bases)
	{
		int size = bases.length;
		this.bases = new int[size];
		for (int i = 0; i < size; i++)
		{
			this.bases[i] = bases[i];
		}
	}
	
	public int minAllHappy()
	{
		int result = 2;
		boolean finished = false;
		while (!finished)
		{
			boolean happy = true;
			for (int i = 0; i < bases.length && happy; i++)
			{
				if (!isHappy(bases[i], result))
				{
					happy = false;
				}
			}
			
			if (happy)
			{
				finished = true;
			}
			else
			{
				result += 1;
			}
		}
		
		return result;
	}
	
	private boolean isHappy(int base, int number)
	{
		if (checked[base][number])
		{
			if (happy[base][number] == 1)
			{
				for (int i = 0; i < stack.size(); i++)
				{
					int value = stack.get(i).intValue();
					happy[base][value] = 1;
				}
				
				stack.clear();
				return true;
			}
			else
			{
				for (int i = 0; i < stack.size(); i++)
				{
					int value = stack.get(i).intValue();
					happy[base][value] = 0;
				}
				stack.clear();
				return false;
			}
		}
		
		//sum digit squares in base base
		int mod = number % base;
		int sum = mod * mod;
		int left = number/base;
		while (left > 0)
		{
			mod = left % base;
			sum += mod * mod;
			left = left/base;
		}
		
		if (sum == 1)
		{
			checked[base][number] = true;
			happy[base][number] = 1;
			for (int i = 0; i < stack.size(); i++)
			{
				int value = stack.get(i).intValue();
				happy[base][value] = 1;
			}
			
			stack.clear();
			return true;
		}
		
		happy[base][number] = 2;
		stack.add(new Integer(number));
		checked[base][number] = true;
		return isHappy(base, sum);
	}
	
	int[] bases;
	int[][] happy;
	boolean[][] checked;
	ArrayList<Integer> stack = new ArrayList<Integer>();
	
	public static void println(String s)
	{
		System.out.println(s);
	}
	/**
	 * @param args
	 * Input 
 	
Output 
 
3
2 3
2 3 7
9 10

Output
Case #1: 3
Case #2: 143
Case #3: 91

	 */
	public static void main(String[] args)
	{
		MultibaseHappiness test = new MultibaseHappiness();
		try 
		{
	        BufferedWriter out = new BufferedWriter(new FileWriter("A-small.out"));
	        BufferedReader in = new BufferedReader(new FileReader("A-small.in"));
	        String line = in.readLine();
	     	String[] parts = line.split(" ");	
			int numberOfCases = new Integer(parts[0]).intValue();
			for (int i = 0; i < numberOfCases; i++)
			{
				//read bases
				line = in.readLine();
				parts = line.split(" ");
//				int[] test1 = {9,10};
				int[] bases = new int[parts.length];
				for (int j = 0; j < parts.length; j++)
				{
					bases[j] = new Integer(parts[j]).intValue();
				}
				test.setBases(bases);
				int result = test.minAllHappy();
	//			println("Case #" + (i+1) + ": " + result);
				out.write("Case #" + (i+1) + ": " + result);
				out.newLine();
			}
			out.close();
		}
		catch (IOException e) 
		{
			e.printStackTrace();
	    }

	}

}
