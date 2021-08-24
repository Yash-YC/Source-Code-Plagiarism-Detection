public class C{
	static double [] dp;
	static int C,N;
	static double cN;
	public static void main (String [] arg)throws Throwable{
		int T = nextInt();
		for (int z = 1; z<=T; ++z) {
			C = nextInt();
			N = nextInt();
			cN = choose(C,N);
			dp = new double [C+1];
			java.util.Arrays.fill(dp,-1);
			double ans = 1+solve(C-N);
			System.out.println("Case #"+z+": " + ans);
		}
	
	}
	public static double solve (int L) {
		if (L <= 0) return 0;
		if (dp[L] > 0) return dp[L];
		double ans = 0.0;
		//REPEATS
		
		for (int i = 1; i<=L; ++i) {
			ans += choose(L,i) * choose(C-L,N-i) / cN * (1+solve(L-i));
		}
		//System.err.println("A : " + ans);
		double P = choose(C-L,N) / cN;
		ans = (ans+P)/(1-P);
		
		dp[L] = ans;
		//System.err.println("" + "@ " + L + " = " + (ans));
		return dp[L];
	}
	public static double choose (int A, int B) {
		double ans = 1.0;
		for (int i=B+1; i<=A; ++i) ans = (ans*i)/(i-B);
		return ans;
	}

public static int nextInt() throws Throwable {
		int i = 0;
		boolean negative = false;
		while (i < 44) i = System.in.read();
		if (i == 45) {
			negative = true; i = 0;
		} else {
			 i = i - 48;
		}
		int j = System.in.read();
		while (j > 47) {i*=10;i+=j-48;j = System.in.read();}
		return (negative) ? -i : i;
}

public static String nextLine() throws Throwable {
		StringBuilder b = new StringBuilder(7);
		int j = System.in.read();
		while (j < 32) j = System.in.read();
		while (j != 10) {
			b=b.append((char)j);
			j=System.in.read();
		}
		//System.err.println("Input : " + b);
		return b.toString();
	}}