package r1sA;

import java.io.File;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

public class AR1A {

	private static int NUMBERS = 5000000;
	static boolean visited[] = new boolean[NUMBERS+1];
//	static int flow[] = new int[NUMBERS+1];
	static int finish[] = new int[NUMBERS+1];
	static BigInteger n10 = new BigInteger("10");
	
	public static boolean happy(int x, int b){
//		int sum = 0;
		int n = 0;
		BigInteger N = new BigInteger(new BigInteger(""+x).toString(b));
//		System.out.println(b + ":" + n + ":");
		while(N.compareTo(BigInteger.ZERO)>0)
		{
			int v = N.mod(n10).intValue(); 
			n += v*v;
			N = N.divide(n10);
		}
		if(n==1) return true;
//		else if(finish[n]==0) return false;
//		else if(finish[n]==1) return true;
		else if(!visited[n])
			{
			visited[n] = true;
			boolean v = happy(n, b);
			visited[n] = false;
			return v;
//			if(v==true) { finish[n]=1; return true; }
//			else if(v==false) { finish[n]=0; return false; } 
			}
		return false;
	}
	
	/**
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception {		
		for (int i = 2; i <= NUMBERS; i++) { visited[i] = false; }
				
		Scanner s = new Scanner(new File("src/A-small.in"));
		System.setOut(new PrintStream(new File("src/A-small.out")));
		int bases[] = new int[10], sz;
		int T = Integer.parseInt(s.nextLine());
		for (int i = 1; i <= T; i++) {
			String[] ins = s.nextLine().split(" ");
			sz = ins.length;
			for (int j = 0; j < sz; j++) {
				bases[j] = Integer.parseInt(ins[j]);
			}
			boolean yes = false;
			for (int j = 2; (j < NUMBERS) && (!yes); j++) {
				yes = true;
				for (int k = 0; k < sz; k++) {
					if(happy(j, bases[k]) == false) yes = false;
				}
				if(yes) System.out.println("Case #" + i + ": " + j);
			}
		}
	}

}
