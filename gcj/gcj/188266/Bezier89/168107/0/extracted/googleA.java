import java.util.*;
import java.io.*;

public class googleA
{
	public static void main(String[] args) throws IOException
	{
		//long startT = System.nanoTime();
		
		Scanner in = new Scanner(new File("test.in"));
		
		int numCases = in.nextInt();
		in.nextLine();
		
		for (int i = 1; i <= numCases; i++)
		{
			Scanner current = new Scanner(in.nextLine());
			int largest = 0;
			ArrayList<Integer> bases = new ArrayList<Integer>();

			while(current.hasNextInt())
				bases.add(current.nextInt());
			
			for (int happyNum = 2; ; happyNum++)
			{
				boolean allHappy = true;
				for (int base : bases)
				{
					int test = happyNum;
					boolean happy = false;
					for (int loop = 0; loop < 1000; loop++)
					{
						test = nextNum(test, base);
						if (test == 1)
						{
							happy = true;
							break;
						}
					}
					if (!happy)
					{
						allHappy = false;
						break;
					}
				}
				if (allHappy)
				{
					System.out.format("Case #%d: %d\n", i, happyNum);
					break;
				}
			}
		}
		
		//System.out.println((System.nanoTime()-startT)/1000000000.0 + " seconds");
	}
	
	public static int nextNum(int val, int base)
	{
		int place = 0;
		while ((Math.pow(base, place)+0.5) < val)
			place++;
		
		int sum = 0;
		
		while (place >= 0)
		{
			int num = val / (int)(Math.pow(base, place)+0.5);
			sum += num*num;
			val -= num * (int)(Math.pow(base, place)+0.5);
			place--;
		}
		
		return sum;
	}
}
