
import java.io.*;
import java.util.*;

public class MultiBaseFast
{
	static String file = "A-large";
	static int MAX = 11814485;
	
	public static void main(String [] args) throws IOException
	{
		BufferedReader input = new BufferedReader(new FileReader(file + ".in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(file + "_1.out")));
		
		int [] bits = new int[1<<11];
		Arrays.fill(bits, -1);
		boolean [] check;
		
		for(int i = 2; i <= MAX; i++)
		{
			int state = 0;
			for(int base = 2; base <= 10; base++)
			{
				check = new boolean[1000];
				if(good(Integer.toString(i,base),base,check))
				{
					state |= (1 << base);
				}
			}
			
			if(bits[state] == -1) bits[state] = i;
		}
		
		int T = Integer.parseInt(input.readLine());
		for(int t = 1; t <= T; t++)
		{
			System.out.println("Running on testcase #" + t);
			String [] st = input.readLine().split(" ");
			
			int cur = 0;
			for(int i = 0; i < st.length; i++)
			  	cur |= (1 << Integer.parseInt(st[i]));
			
			int res = Integer.MAX_VALUE;
			for(int i = 0; i < (1 << 11); i++)
				if(bits[i] != -1 && (cur & i) == cur)
					res = Math.min(res, bits[i]);
				
			
			out.println("Case #" + t + ": " + res);
		}
		
		out.close();
	}
	
	public static boolean good(String s, int base, boolean [] check)
	{
		char [] c = s.toCharArray();
		int L = c.length;
		int sum = 0;
		for(int i = 0; i < L; i++) sum += (c[i] - '0') * (c[i] - '0');
		
		if(sum == 1) return true;
		if(check[sum]) return false;
		check[sum] = true;
		
		return good(Integer.toString(sum,base), base, check);
	}
}