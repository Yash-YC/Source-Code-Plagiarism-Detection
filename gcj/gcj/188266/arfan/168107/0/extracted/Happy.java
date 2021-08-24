import java.util.*;
import java.io.*;

public class Happy
{
	static BitSet visited = new BitSet();
	
	public static void main(String args[]) throws IOException
	{
		//Scanner scan = new Scanner(System.in);
		BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(buff.readLine());
		
		for(int i=0;i<n;i++)
		{
			StringTokenizer token = new StringTokenizer(buff.readLine());
			int len = token.countTokens();
			
			int array[] =  new int[len];
			int index=0;
			while(token.hasMoreTokens())
			{
				array[index++]=Integer.parseInt(token.nextToken());
			}
			
			System.out.println("Case #"+(i+1)+": "+findSmallest(array));
		}
		//System.out.println(happyOperate(10, 82));
		//isHappy(2, "10");
		//System.out.println(findSmallest(7));
		//System.out.println(isHappy(3, "82"));
		//int array[] = {9, 10};
		
		//System.out.println(findSmallest(array));
	}
	
	public static int happyOperate(int base, int num)
	{
		String a = Integer.toString(num, base);
		//System.out.println(a);
		int total = 0;
		
		int len = a.length();
		for(int i=0;i<len;i++)
		{
			int dig = (a.charAt(i)-'0');
			//System.out.println(dig);
			total+= dig*dig;
		}
		
		return total;
	}
	
	public static boolean isHappy(int base, String num)
	{
		visited.clear();
		int n = Integer.parseInt(num);
		
		int curr = n;
		
		while(curr!=1 && !visited.get(curr))
		{
			visited.set(curr);
			curr = happyOperate(base, curr);
		}
		
		//System.out.println(curr);
		if(curr==1)
			return true;
		
		return false;
	}
	
	//~ public static int findSmallest(int base)
	//~ {
		//~ int curr = 2;
		//~ while(!isHappy(base, Integer.toString(curr)))
		//~ {
			//~ curr++;
		//~ }
		
		//~ return curr;
	//~ }
	
	public static int findSmallest(int[] bases)
	{
		int curr = 2;
	
		while(true)
		{
			boolean alltrue = true;
			for(int i: bases)
			{
				if(!isHappy(i, Integer.toString(curr)))
				{
					alltrue = false;
					break;
				}
			}
			if(alltrue)
				break;
			
			curr++;
		}
		
		return curr;
	}
}


