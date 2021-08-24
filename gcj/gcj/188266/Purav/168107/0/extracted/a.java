import java.math.*;
import java.util.*;
import java.io.*;

public class a 
{
	static int b[] = new int[15], p;
	public static void main(String args[])throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int t, zz = 1, vis[] = new int[2000000], id = 1;
		t = Integer.parseInt(in.readLine());
		while(t-- > 0)
		{
			StringTokenizer st = new StringTokenizer(in.readLine());
			p = 0;
			while(st.hasMoreTokens()) b[p++] = Integer.parseInt(st.nextToken());
			for(int i = 2; i < 20000000; i++)
			{
				//System.out.println("No : " + i);
				BigInteger x = new BigInteger("" + i);
				boolean happy = true;
				
				outer : for(int j = 0; j < p; j++)
				{
					id++;
					if(b[j] == 2 || b[j] == 4) continue;
					//System.out.println("base " + b[j]);
					String s = x.toString(b[j]);
					int sum = 0;
					while(sum != 1)
					{
						sum = 0;
						for(int k = 0; k < s.length(); k++) sum += (s.charAt(k) - '0') * (s.charAt(k) - '0');
						if(vis[sum] == id) {happy = false; break outer;}
						vis[sum] = id;
						s = new BigInteger("" + sum).toString(b[j]);
						//System.out.print(s + " ");
					}
					//System.out.println();
				}
				if(happy) {System.out.println("Case #" + zz++ + ": " + i); break;}
			}
		}
	}
}