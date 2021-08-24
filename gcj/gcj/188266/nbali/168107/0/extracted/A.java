package google.code.jam.round1.subrounda;

import google.code.jam.Env;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;

/**
 * @author NB4L1
 */
@SuppressWarnings("unchecked")
public final class A
{
	private static final Map<Integer, Boolean>[] IS_HAPPY = new Map[11];
	
	static
	{
		for (int i = 0; i < IS_HAPPY.length; i++)
		{
			IS_HAPPY[i] = new HashMap<Integer, Boolean>();
			IS_HAPPY[i].put(1, true);
		}
	}
	
	public static void main(String[] args) throws ClassNotFoundException, IOException
	{
		@SuppressWarnings("unused")
		BufferedReader br = Env.init(true);
		
		/**
		 * number of maps
		 */
		final int T;
		
		T = Integer.parseInt(br.readLine());
		
		for (int t = 0; t < T; t++)
		{
			final String line = br.readLine();
			
			StringTokenizer st = new StringTokenizer(line);
			
			final int[] bases = new int[st.countTokens()];
			
			for (int i = 0; i < bases.length; i++)
				bases[i] = Integer.parseInt(st.nextToken());
			
			final Set<Integer> visited = new HashSet<Integer>();
			
			number: for (int i = 2;; i++)
			{
				for (int base : bases)
				{
					visited.clear();
					
					if (!isHappy(i, base, visited))
						continue number;
				}
				
				System.out.println("Case #" + (t + 1) + ": " + i);
				break number;
			}
		}
	}
	
	private static boolean isHappy(final int i, int base, Set<Integer> visited)
	{
		Boolean isHappy = IS_HAPPY[base].get(i);
		
		if (isHappy != null)
			return isHappy.booleanValue();
		
		final int sum = getSumOfSquares(i, base);
		
		if (!visited.add(sum))
			return false;
		
		isHappy = isHappy(sum, base, visited);
		
		IS_HAPPY[base].put(i, isHappy);
		
		return isHappy;
	}
	
	private static int getSumOfSquares(int i, int base)
	{
		int sum = 0;
		
		while (i > 0)
		{
			int div = i % base;
			
			sum += div * div;
			
			i /= base;
		}
		
		return sum;
	}
}
