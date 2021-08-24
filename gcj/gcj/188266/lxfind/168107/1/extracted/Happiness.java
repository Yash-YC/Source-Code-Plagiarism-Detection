import java.io.*;

public class Happiness {
	static int n;
	static int[] bases;
	
	static boolean isDead(int num, int base)
	{
		switch (base)
		{
			case 3: return (num==2);
			case 5: return (num==4);
			case 6: return (num==5);
			case 7: return (num==2 || num==17);
			case 8: return (num==4 || num==5 || num==26);
			case 9: return (num==53 || num==68);
			case 10: return (num==4);
		}
		return false;
	}
	
	static boolean isHappy(int num, int base)
	{
		if (base == 2 || base == 4)
		{
			return true;
		}
		else
		{
			int j;
			int x;
			while (num!=1 && !isDead(num,base))
			{
				String s = Integer.toString(num, base);
				x = 0;
				for (j=0;j<s.length();j++)
				{
					x += (s.charAt(j)-48)*(s.charAt(j)-48);
				}
				if (x==num)
				{
					return false;
				}
				num = x;
			}
			if (num==1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	
	static int solve()
	{
		int i = 2;
		int j;
		while (true)
		{
			for (j=0;j<bases.length;j++)
			{
				if (!isHappy(i,bases[j]))
				{
					break;
				}
			}
			if (j==bases.length)
			{
				break;
			}
			i++;
		}
		return i;
	}
	
	public static void main(String args[])
	{
		try {
			BufferedReader reader = new BufferedReader(new FileReader("src/Round1/A-large.in"));
			BufferedWriter writer = new BufferedWriter(new FileWriter("output"));
			int i,j,result;
			n = Integer.parseInt(reader.readLine());
			for (i=0;i<n;i++)
			{
				String line = reader.readLine();
				String[] nums = line.split(" ");
				bases = new int[nums.length];
				for (j=0;j<nums.length;j++)
				{
					bases[j] = Integer.parseInt(nums[j]);
				}
				result = solve();
				writer.write("Case #"+(i+1)+": "+result);
				writer.newLine();
			}
			reader.close();
			writer.close();
		}
		catch (Exception ex)
		{
			ex.printStackTrace();
		}
	}
}
