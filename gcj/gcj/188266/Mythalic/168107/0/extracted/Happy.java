import java.io.*;
import java.util.*;

public class Happy
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("A-small-attempt0.out")));
		
		int T = Integer.parseInt(br.readLine());
		
		String line;
		String[] bases;
		boolean happy;
		long smallest;
		boolean happyperbase;
		
		for (int i=0; i<T; i++)
		{
			line = br.readLine();
			bases = line.split(" ");
			
			happy = false;
			smallest = 2;
			while (!happy)
			{
				happyperbase = true;
				for (int j=0; j<bases.length; j++)
				{
					if (!isHappy(convert(smallest, Integer.parseInt(bases[j])), Integer.parseInt(bases[j])))
					{
						happyperbase = false;
						break;
					}
				}
				happy = happyperbase;
				if (!happy)
				{
					smallest++;
				}
			}
			pw.println("Case #"+(i+1)+": "+smallest);
		}
		pw.close();
	}
	
	public static String convert(long nr, int base)
	{
		String result = "";
		
		if (base == 10)
		{
			return ""+nr;
		}
		
		while(nr>0)
		{
			result = Long.toString(nr%base)+result;
			nr = nr/base;
		}
		return result;
	}
	
	public static boolean isHappy(String n, int base)
	{
		long sum, aux;
		boolean repeatError;
		ArrayList<String> memory = new ArrayList<String>();
		while (true)
		{
			sum = 0;
			aux = 0;
			for (int i=0; i<n.length(); i++)
			{
				aux = Long.parseLong(""+n.charAt(i))*Long.parseLong(""+n.charAt(i)); //square
				sum += aux;
			}
			n = ""+convert(sum, base);
			repeatError = false;
			for (int j=0; j<memory.size(); j++)
			{
				if (n.equals(memory.get(j)))
				{
					repeatError = true;
					break;
				}
			}
			if (repeatError)
			{
				break;
			}
			memory.add(n);
		}
		
		if (n.equals("1"))
		{
			return true;
		}
		return false;
	}
}