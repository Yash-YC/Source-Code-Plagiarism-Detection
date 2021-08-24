import java.util.*;
public class foo1
{
	public static void main(String args[])
	{
		
		Scanner scn = new Scanner(System.in);
		int t = scn.nextInt();
		scn.nextLine();
		for(int i = 0; i < t; i++)
		{
			String[] st = scn.nextLine().split(" ");
			//System.out.println(Arrays.toString(st));
			int[] it = new int[st.length];
			for(int j = 0; j < st.length; j++)
			{
				it[j] = Integer.parseInt(st[j]);
			}
			int curr = 2;
			while(true)
			{
				boolean found = true;
				for(int b : it)
				{
					if(!happy(curr, b))
					{
						found = false;
						break;
					}
				}
				if(found)
				{
					System.out.println("Case #" + (i+1) + ": " + curr);
					break;
				}
				curr++;
			}
		}
	}
	public static boolean happy(int x, int base)
	{
		List<Integer> l = new LinkedList<Integer>();
		while(true)
		{
			x = calc(x, base);
			if(x==1)
				return true;
			if(l.contains(x))
				return false;
			l.add(x);
		}
	}
	public static int calc(int x, int base)
	{
		String s = Integer.toString(x, base);
		int next = 0;
		for(char c : s.toCharArray())
		{
			next += (c-'0')*(c-'0');
		}
		//System.out.println(next);
		return next;
	}
}
