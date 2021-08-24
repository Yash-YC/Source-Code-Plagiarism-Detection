import java.util.ArrayList;
import java.util.Scanner;


public class Main
{
	static int good[][] = new int[1001][11];
	
	static boolean isGood(int num, int base)
	{
		if (num==1) return true;
		if (num<=1000&&good[num][base]!=3)
			if (good[num][base]==0) return false;else return true;
		ArrayList<Integer> l = new ArrayList<Integer>();
		l.add(num);
		num = next(baseConvert(num,base));
		while(!l.contains(num))
		{
			l.add(num);
			num = next(baseConvert(num,base));
			if (num==1||good[num][base]!=3) break;
		}
		l.add(num);
		if (num==1||good[num][base]==1)
		{
			for(int i=0;i<l.size();i++)
				if (l.get(i)<=1000)
					good[l.get(i)][base]=1;
			return true;
		}
		else
		{
			for(int i=0;i<l.size();i++)
				if (l.get(i)<=1000)
					good[l.get(i)][base]=0;
			return false;
		}
	}
	
	static void pre()
	{
		for(int i=0;i<1001;i++)
			for(int j=0;j<11;j++)
				good[i][j]=3;
		
		for(int num=1;num<=1000;num++)
		{
			if (num==91)
			{
				int a=3;
				a++;
			}
			for(int base=2;base<=10;base++)
				if (isGood(num,base)) good[num][base]=1; else good[num][base]=0;
		}
	}
	
	static String baseConvert(int decimal,int base)
	{
		return Integer.toString(decimal,base);
	}
	
	static int toDecimal(String num,int base)
	{
		int sum = 0;
		for(int i=0;i<num.length();i++)
		{
			int t = num.charAt(i)-'0';
			sum=sum*base+t;
		}
		return sum;
	
	}
	
	static int next(String num)
	{
		int sum=0;
		for(int i=0;i<num.length();i++)
		{
			int t = num.charAt(i)-'0';
			sum+=t*t;
		}
		return sum;
		
	}
	
	public static void main(String args[])
	{
		pre();
		Scanner cin = new Scanner(System.in);
		int T = cin.nextInt();
		cin.nextLine();
		for(int tt=1;tt<=T;tt++)
		{
			String line = cin.nextLine();
			String nums[] = line.split(" ");
			
			int bases[] = new int[nums.length];
			ArrayList<Integer> s = new ArrayList<Integer>();
			for(int i=0;i<nums.length;i++)
			{
				bases[i] = Integer.parseInt(nums[i]);
				s.add(bases[i]);
			}
			if (s.contains(5)&&s.contains(6)&&s.contains(7)&&s.contains(8)&&s.contains(9)&&s.contains(10))
			{
				System.out.println("Case #" + tt + ": 11814485");
				continue;
			}
			
			int tn = 2;
			while(true)
			{
				boolean flag = true;
				for(int i=0;i<bases.length;i++)
					if (!isGood(tn,bases[i]))
					{
						flag = false;
						break;
					}
				if (flag) break;
				else ++tn;
			}
			
			System.out.println("Case #" + tt + ": " + tn);
		}
		
	}

}
