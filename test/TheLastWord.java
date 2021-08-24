// 2016 Google Code Jam - Round 1: A - The Last Word
// Mpumelelo Mthethwa (Leleau)
// 16 April 2016

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

class TheLastWord
{
	public static void main (String args[])
	{		
		Scanner input = new Scanner (new BufferedReader (new InputStreamReader(System.in)));
		int N = Integer.parseInt(input.nextLine());
		
		for (int i=1; i<=N; i++)
			System.out.printf("Case #%d: %s\n",i,theLastWord(input.nextLine()));
		
		input.close();
	}
	
	private static String theLastWord (String S)
	{
		String result = S.substring(0,1);
		String temp1, temp2;
		
		for (int i=1; i<S.length(); i++)
		{
			temp1 = S.substring(i,i+1) + result;
			temp2 = result + S.substring(i,i+1);
			
			result = (temp1.compareTo(temp2) > 0)?temp1:temp2;
		}
		
		return result;
	}
}
