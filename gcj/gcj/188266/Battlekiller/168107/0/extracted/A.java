import java.io.File;
import java.util.HashSet;
import java.util.Scanner;


public class A {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(new File("A-small-attempt0.in"));
		/*
		boolean[][] isHappy = new boolean[10][1000000];
		for (int i = 3; i <= 9; i++)
		{
			for (int j = 1; j < isHappy[i].length; j++)
			{
				isHappy[i][j] = isHappy(j, i);
			}
			System.out.println(Debug.CREATE_ARRAY(isHappy[i]));
		}
		*/
		
		
		
		int N = in.nextInt();
		in.nextLine();		
		for (int i = 0; i < N; i++)
		{
			String line = in.nextLine();
			String[] split = line.split(" ");
			for (int k = 2; k < 100000; k++)
			{
				
				boolean fail = false;
				for (int j = 0; j < split.length; j++)
				{
					int base = Integer.parseInt(split[j]);
					if(!isHappy(k, base))
					{
						fail = true;
						break;
					}
				}
				if(!fail)
				{
					System.out.println("Case #" + (i+1)+ ": " + k);
					break;
				}
			}
		}
		
	}
	
	public static boolean isHappy(Integer num, int base)
	{
		//System.out.println(num + " " + base);
		String snum = Integer.toString(num, base);
		HashSet<Integer> nums = new HashSet<Integer>();
		while(true)
		{
			int total = 0;
			for (int i = 0; i < snum.length(); i++)
			{
				int t = (snum.charAt(i) - '0');
				total += t*t;
			}
			total = Integer.parseInt(Integer.toString(total, base));
			if(total == 1)
				return true;
			if(nums.contains(total))
			{
				return false;
			}
			nums.add(total);
			snum = total+"";
		}
	}
	
}
