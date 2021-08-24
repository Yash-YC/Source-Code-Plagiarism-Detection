import java.util.*;
public class foo1
{
//	public static List<Integer>[] dp = new List[11];
//	public static int counter = 0;
	public static int[][] b = new int[11][11814485+10];
	public static void main(String args[])
	{
//		
//		for(int i = 0; i < dp.length; i++)
//		{
//			dp[i] = new ArrayList<Integer>();
//		}
		//11814485+10
		for(int i = 2; i < 	11814485+10; i++)
		{
			for(int j = 2; j <= 10; j++)
			{
				if(happy(i, j))
				{
					b[j][i]=1;
				}
				else
					b[j][i]=-1;
			}
			if(i%10000==0)
				System.out.println(i);
			
		}
		System.out.println("ready");
		Scanner scn = new Scanner(System.in);
		int t = scn.nextInt();
		scn.nextLine();
		for(int i = 0; true; i++)
		{
			String[] st = scn.nextLine().split(" ");
//			System.out.println(Arrays.toString(st));
			int[] it = new int[st.length];
			for(int j = 0; j < st.length; j++)
			{
				it[j] = Integer.parseInt(st[j]);
			}
			//indexes
			int curr = 2;
			int[] it2 = new int[it.length];
//			System.out.println(Arrays.toString(it));
//			System.out.println(Arrays.toString(it2));
//			System.out.println(dp[2]);
//			System.out.println(dp[3]);
//			System.out.println(Arrays.toString(b[7]));
//			for(int k = 0; i < b[10].length; k++)
//			{
//				if(b[10][k]==1)
//					System.out.println(k);
//			}
//			System.out.println(dp[10]);
//			
//			System.out.println(b[2][2] + " " + b[3][2] + " " + b[7][2]);
			for(int z = 0; z < b[0].length; z++)
			{
				boolean found = true;
				for(int c = 0; c < it.length; c++)
				{
					if(b[it[c]][z]!=1)
					{
						found = false;
						break;
					}
				}
				if(found)
				{
					curr = z;
					break;
				}
					
			}
//			try{
//			while(true)
//			{
//				int min =b[it[0]][it2[0]];
//				int minindex = 0;
//				boolean found = true;
//				
//				for(int q = 1; q < it.length; q++)
//				{
//					int minq = b[it[q]][it2[q]];
////					System.out.println(minq);
//					if(minq<min)
//					{
//						found = false;
//						min = minq;
//						minindex = q;
//					}
//					if(minq>min)
//						found=false;
//				
//				}
//				if(found)
//				{
//					curr = min;
//					break;
//				}
//				it2[minindex] = it2[minindex]+1;
//				
//			}
//			}
//			catch(Exception e)
//			{
//				e.printStackTrace();
//			}
			//int curr = 2;
			System.out.println("Case #" + (i+1) + ": " + curr);
			
			/*while(true)
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
					break;
				}
				curr++;
			}*/
		}
	}
	public static boolean happy(int x, int base)
	{
		List<Integer> l = new LinkedList<Integer>();
		while(true)
		{
			
			x = calc(x, base);
			if(b[base][x]==1)
				return true;
			if(b[base][x]==-1)
				return false;
			if(x==1)
			{
				for(int s : l)
				{
					b[base][s]=1;
				}
				return true;
			}
			
//			if(dp[base].size()!=0 && x < counter )
//			{
////				if(base==7)
////				{
////					System.out.println("count: " + counter);
////					System.out.println("check " + x);
////					System.out.println("base " + base);
////					
////				}
//				return Collections.binarySearch(dp[base], x) >= 0;
//			}
			
			if(l.contains(x))
			{
				for(int s : l)
					b[base][s]=-1;
				return false;
			}
			l.add(x);
		}
	}
	public static int calc(int x, int base)
	{
//		if(base==7)
//			System.out.println("calcing " + x);
		String s = Integer.toString(x, base);
		int next = 0;
		for(char c : s.toCharArray())
		{
			next += (c-'0')*(c-'0');
		}
		//System.out.println(next);
//		if(base==7 && x == 125)System.out.println("returning " + next);
		return next;
	}
}
