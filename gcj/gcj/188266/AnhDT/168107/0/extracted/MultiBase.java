
import java.io.*;
import java.util.*;

public class MultiBase
{
	static String file = "A-small-attempt0";
	
	public static void main(String [] args) throws IOException
	{
		BufferedReader input = new BufferedReader(new FileReader(file + ".in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(file + ".out")));
		
		int T = Integer.parseInt(input.readLine());
		for(int t = 1; t <= T; t++)
		{
			System.out.println("Running on testcase #" + t);
			String [] st = input.readLine().split(" ");
			int [] base = new int[st.length];
			for(int i = 0; i < st.length; i++) base[i] = Integer.parseInt(st[i]);
			
			boolean [] check;
			for(int i = 2;  ; i++)
			{
				//System.out.println(i);
				boolean ok = true;
				for(int j = 0; j < base.length; j++)
				{
					check = new boolean[1001];
					if(!good(Integer.toString(i,base[j]),base[j],check)) 
					{
						//System.out.println("FAIL " + i + " " + base[j]);
						ok = false;
						break;
					}					
				}
				if(ok) 
				{
					out.println("Case #" + t + ": " + i);
					break;
				}
			}
		}
		out.close();
	}
	
	public static boolean good(String s, int base, boolean [] check)
	{
		//System.out.println(s + " " + base);
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