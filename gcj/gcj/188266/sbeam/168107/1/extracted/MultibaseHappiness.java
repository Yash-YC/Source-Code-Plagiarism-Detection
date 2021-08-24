package sbeam.Round1A;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class MultibaseHappiness {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		// io stuff
		FileInputStream file = null;
		FileWriter output = null;
		
		try {
			file = new FileInputStream("A-large.in");
			output = new FileWriter("A-large-out.txt");
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		Scanner in = new Scanner(file);
		
		int numCases = in.nextInt();
		in.nextLine();
		
		for(int i = 1; i <= numCases; i++)
		{
			// input stuff
			String line = in.nextLine();
			Scanner l = new Scanner(line);
			int[] bases = new int[10];
			Arrays.fill(bases, -1);
			int idx = 0;
			
			while(l.hasNext())
			{
				bases[idx++] = l.nextInt();
			}
			
			System.out.println(String.format("%d %d %d", bases[0], bases[1], bases[2]));
			
			int number = 2;
			
			while(true)
			{
				idx = 0;
				boolean happy = true;
				
				while(bases[idx] != -1)
				{
					if(isHappy(number, bases[idx]))
					{					
						idx++;
						continue;
					}
					
					happy = false;
					break;
				}
				
				if(happy)
				{
					break;
				}
				
				number++;
			}
			
			System.out.println(String.format("Case #%d: %d", i, number));
			output.write(String.format("Case #%d: %d\n", i, number));		
			
		}
		
		output.close();
	}
	
	
	public static boolean isHappy(int number, int base)
	{
		ArrayList<Integer> results = new ArrayList<Integer>();
		
		while(true)
		{
			int sum = 0;
			while(number != 0)
			{
				int dig = number % base;
				number = number / base;
				
				sum += dig * dig;
			}
			// System.out.println(sum);
			if(sum == 1)
			{
				return true;
			}
			
			if(results.contains(sum))
			{
				return false;
			}
			else
			{
				results.add(sum);
				number = sum;
			}
		}
	}
}

