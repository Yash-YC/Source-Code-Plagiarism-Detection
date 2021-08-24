import java.io.*;
import java.util.*;

public class GA1
{
	
	static int[] ansList = new int[101];
	static boolean[][] clist = new boolean[9][30000];
	
	public static void main(String[] args) throws Exception
	{
		Scanner scanner = new Scanner(new FileInputStream("A-small-attempt1.in"));
		int qcount = scanner.nextInt();
		scanner.nextLine();
		
		for(int qnum=1;qnum<=qcount;qnum++)
		{
			String next = scanner.nextLine();
			int out = answer(next);
			
			System.out.print("Case #");
			System.out.print(qnum);
			System.out.print(": ");
			System.out.println(Integer.toString(out));
			
		}
	}
	
	public static boolean isHappy(int num, int base)
	{
		try
		{
			if(clist[base-2].length>num && clist[base-2][num])
			{
				return true;
			}
		}
		catch(Exception e)
		{
			System.out.println(num);
			System.exit(0);
		}
			
		
		boolean[] ced = new boolean[1001];
		int num2 = num;
		
		while(true)
		{
			int sum = 0;
			while(num>0)
			{
				int a = num%base;
				sum+=(a*a);
				num-=a;
				num/=base;
			}
			
			if(sum==1)
			{
				if(clist[base-2].length>num2)
					clist[base-2][num2] = true;
				return true;
			}
				
			
			if(ced[sum])
				return false;
			
			if(ced.length>sum)
				ced[sum] = true;
			
			num = sum;
		}
	}
	
	public static int answer(String s) throws Exception
	{
		int[] nums = split(s);
		
		int ans = 2;
		while(true)
		{
			boolean b = true;
			for(int i=0;i<nums.length;i++)
			{
				boolean bb = isHappy(ans, nums[i]);
			//	System.out.println(ans+" "+nums[i]+" "+bb);
				if(!bb)
				{
					b = false;
					break;
				}
			}
			if(b) return ans;
			ans++;
		}
	}
	
	public static int[] split(String s) throws Exception
	{
		StringTokenizer st = new StringTokenizer(s, " ");
		int[] ret = new int[st.countTokens()];
		
		for(int i=0;i<ret.length;i++)
			ret[i] = Integer.parseInt(st.nextToken());
		
		return ret;
	}
}
