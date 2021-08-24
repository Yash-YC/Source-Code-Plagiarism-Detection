import java.io.*;
import java.util.*;
public class CollectingCards
{
	static int maxK = 1000;

	
	public static int countBit(int N) 
	{
		int cnt = 0;
		while (N>0) 
		{
			cnt += N&1;
			N = N >> 1;
		}
		return cnt;
	}

	public static double cal(int N, int C)
	{
		int cnt = 0;
		int maxM = 1<<C;
		boolean[] c = new boolean[maxM];
		for (int i=0;i<maxM;i++)
			if (countBit(i)==N) {
				c[i] = true;
				cnt++;
			}
	
		double[][] f = new double[maxK][1<<C];
		
		double t = 1.0/cnt;
		
		for (int i=0;i<maxM;i++) 
			if (c[i]) f[0][i] = 1.0/cnt;
			
		for (int i=1;i<maxK;i++) {
			for (int j=0;j<maxM-1;j++)
				if (f[i-1][j]>0)
					for (int k=0;k<maxM;k++)
						if (c[k]) f[i][j|k] += f[i-1][j]*t;
		}
			
		double res = 0;
		for (int i=0;i<maxK;i++) res+=f[i][maxM-1]*(i+1);
			
		
		return res;


	}
	
	public static void main(String[] args) throws Exception
	{
		Scanner sc = new Scanner(new File("CollectingCards.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("CollectingCards.out"));
		
		int t = sc.nextInt();
		for (int test=1;test<=t;test++){
			int C = sc.nextInt();
			int N = sc.nextInt();						
			out.write("Case #"+test+": "+cal(N,C)+"\n");
		}		
		sc.close();
		out.close();
	}
}