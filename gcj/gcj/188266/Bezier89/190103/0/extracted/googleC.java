import java.util.*;
import java.io.*;

public class googleC
{
	public static int numCards;
	public static int perPack;
	public static int possibleHands;
	public static int index;
	public static boolean[][] hands;
	public static double factor;
	
	public static void main(String[] args) throws IOException
	{
		//long startT = System.nanoTime();
		
		Scanner in = new Scanner(new File("test.in"));
		long[] fact = new long[11];
		fact[0] = 1;
		for (int i = 1; i <= 10; i++)
			fact[i] = fact[i-1] * i;
		
		int numCases = in.nextInt();
		
		for (int i = 1; i <= numCases; i++)
		{
			numCards = in.nextInt();
			perPack = in.nextInt();
			
			possibleHands = (int)(fact[numCards] / (fact[perPack] * fact[numCards-perPack]));
			factor = (1.0 / possibleHands);
			index = 0;
			hands = new boolean[possibleHands][numCards];
			
			boolean[] used = new boolean[numCards];
			comb(used, numCards-1, perPack);
			
			boolean[] cards = new boolean[numCards];
			
			System.out.format("Case #%d: %f\n", i, getProb(1, cards, 0));
		}
		
		//System.out.println((System.nanoTime()-startT)/1000000000.0 + " seconds");
	}
	
	public static double getProb(double weight, boolean[] cards, int packs)
	{
		if (weight < 5e-6)
			return (weight*packs);
			
		boolean allTrue = true;
		for (boolean x : cards)
			if (!x)
			{
				allTrue = false;
				break;
			}
		
		if (allTrue)
			return (weight*packs);
		
		double sum = 0;
		
		for (int i = 0; i < possibleHands; i++)
		{
			boolean[] orig = new boolean[numCards];
			for (int j = 0; j < numCards; j++)
				orig[j] = cards[j];
			
			for (int j = 0; j < numCards; j++)
				if (hands[i][j])
					cards[j] = true;
			
			sum += getProb(weight * factor, cards, packs+1);
			
			for (int j = 0; j < numCards; j++)
				cards[j] = orig[j];
		}
		
		return sum;
	}
	
	public static void comb(boolean[] used, int n, int r)
	{
		if (r == 0)
		{
			for (int i = 0; i < used.length; i++)
				hands[index][i] = used[i];
			
			index++;
			return;
		}
		
		if (n >= 0)
		{
			used[n] = true;
			comb(used, n-1, r-1);
			used[n] = false;
			comb(used, n-1, r);
		}
	}
}