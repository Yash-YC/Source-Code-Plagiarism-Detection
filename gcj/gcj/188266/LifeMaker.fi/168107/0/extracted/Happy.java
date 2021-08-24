import java.io.*;
import java.util.*;

public class Happy 
{
	String[] bases;
	long[] happy;
	int[] basesInt;
	
	public long getHappy(long start, int base)
	{
		while(!isHappy(start, base))
			start++;
		
		return start;
	}
	
	public boolean isHappy(long number, int b)
	{
		Hashtable<String, Integer> ht = new Hashtable<String, Integer>();
		
		String num = convertBase(number, b);
		//while(num.length() > 1)
		while(! ht.containsKey(num))
		{
			ht.put(num, 0);
			num = calc(num, b);
		}
		if(num.trim().equals("1"))
			return true;
		else
			return false;
	}
	
	public String calc(String str, int b)
	{
		char ch;
		int i;
		long sum = 0;
		for(i = 0; i < str.length(); i++)
		{
			ch = str.charAt(i);
			sum += (ch - '0') * (ch - '0');
		}
		return convertBase(sum, b);
	}
	
	public String convertBase(long num, int b)
	{
		String conv = "";
		while(num > 0)
		{
			conv = (num % b) + conv;
			num /= b;
		}
		return conv;
	}
	
	public int getSmallest()
	{
		long min = happy[0];
		int index = 0;
		int dup = 0;
		
		for(int i = 0; i < happy.length; i++)
		{
			if(happy[i] < min)
			{
				min = happy[i];
				index = i;
			}
			else if(happy[i] == min)
			{
				dup++;
			}
		}
		if(dup == happy.length)
			return -1;
		else
			return index;
	}
	
	public long solve()
	{
		int i, ind;

		for(i = 0; i < bases.length; i++)
		{
			happy[i] = getHappy(2, basesInt[i]);
		}
		
		ind = getSmallest();
		
		while(ind != -1)
		{
			happy[ind] = getHappy(happy[ind] + 1, basesInt[ind]);
			ind = getSmallest();
		}
		
		return happy[0];
	}
	
	public void run()throws IOException
	{
		Scanner sc = new Scanner(new FileReader("A-small.in"));
		int n = sc.nextInt();
		sc.nextLine();
		int i;
		for(i = 1; i <= n; i++)
		{
			bases = sc.nextLine().split("[\\s]+");
			happy = new long[bases.length];
			basesInt = new int[bases.length];
			for(int j = 0; j < bases.length; j++)
			{
				basesInt[j] = Integer.parseInt(bases[j].trim());
			}
			System.out.println("Case #" + i + ": " + solve());
		}
	}
	
	public static void main(String[] args)throws IOException
	{
		new Happy().run();
	}
}
