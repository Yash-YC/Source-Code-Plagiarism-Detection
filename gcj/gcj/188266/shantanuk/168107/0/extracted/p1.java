package probs;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.HashMap;
import java.util.HashSet;

public class HappyNumbers {
	
	
	public static void main(String [] args) throws Exception
	{
		FileReader reader = new FileReader("C:\\GCJ\\in.txt");
		BufferedReader br = new BufferedReader(reader);
		int N = Integer.parseInt(br.readLine());
		
		
		
		
		
	

		for (int i = 0; i < N; i++) {
			String currentCase = br.readLine();
			String [] basesStr = currentCase.split(" ");
			boolean isValid = true;
			for(int j=2;;j++)
			{
				if(j==49)
				{
				 j= 49;	
				}
				isValid = true;
				for(int k=0;k<basesStr.length;k++)
				{
					if(!isValid)
						break;
					if(!isHappy(new Integer(Integer.toString(j, new Integer(basesStr[k]))), new Integer(basesStr[k]), new HashSet<String>()))
						isValid = false;
				}
				if(isValid)
				{
					System.out.println("Case #" + (i + 1) + ": " + j);
					break;
				}
			}
		

			
		

		}

		

		br.close();
		reader.close();

	}
	
	public static boolean isHappy(int num, int base, HashSet<String> numbersOccured)
	{
		if(num==49)
		{
			//System.out.println("y");
		}
		String inGivenBase = Integer.toString(num);
		if(numbersOccured.contains(inGivenBase))
			return false;
		else
			numbersOccured.add(inGivenBase);
		
		int sum =0;
		for(int i=0;i<inGivenBase.length();i++)
		{
			int currChar = Integer.valueOf(new Character(inGivenBase.charAt(i)).toString());
			
			int sq = (int) Math.pow(currChar, 2);
			//Integer.to
			//int inBs = Integer.parseInt(Integer.toString(sq, base));
			sum = sum + sq;
			
			//System.out.println(sum + ":" + base);
			//sum = Integer.parseInt(Integer.toString(sum, base));
			//int lim = new Integer(Integer.toString(1000,base));
			//if(sum>lim)
				//return false;
		}

			sum = new Integer(Integer.toString(sum, base));
			//Integer.parseInt(new Integer(sum).toString(), base);
		
		
		if(sum == 1)
			return true;
		else
			return isHappy(sum, base, numbersOccured);
		
	}

}
