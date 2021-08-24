import java.io.*;
import java.util.*;

public class cards {

	public static long[][] Ch;
	public static double[][] memo;
	
	public static void main(String[] args) throws Exception{
		
		Scanner In = new Scanner(new File("input.in"));
		System.setOut(new PrintStream(new File("output.out")));
		int numCases = In.nextInt();
		
		for(int currCase = 1;currCase <= numCases;currCase++){
			
			int C = In.nextInt(), N = In.nextInt();
			if(C <= N) System.out.printf("Case #%d: %.5f%n", currCase, 1.0);
			else{
				Ch = new long[C+1][C+1];
				preCalculateChoose(C);
				memo = new double[11][11];
				for(int i = 0;i < 11;i++)
					Arrays.fill(memo[i], -1.0);
				doMemo(C, N, 0);
				System.out.printf("Case #%d: %.5f%n", currCase, memo[C][0]);
			}
		}
		
	}
	
	public static void preCalculateChoose(int C){
		
		Ch[0][0] = 1;
		
		for(int i = 1;i <= C;i++){
			Ch[i][0] = 1;
			for(int j = 1;j <= i;j++)
				Ch[i][j] = Ch[i-1][j-1]+Ch[i-1][j];
		}
		
	}
	
	public static double doMemo(int C, int N, int U){
		
		if(C <= 0) return 0;
		if(memo[C][U] > -1) return memo[C][U];
		
		double prob = 0, expected = 0;
		for(int i = 1;i <= N;i++){
			double temp = 1.0*Chose(C, i)*Chose(U, N-i)/Chose(C+U, N);
			prob += temp;
			
			expected += doMemo(C-i, N, U+i)*temp;
		}

		return memo[C][U] = expected + 1/prob;
		
	}
	
	public static long Chose(int n, int k){
	
		if(k > n) return 0;
		if(n == k) return 1;
		return Ch[n][k];
	
	}
	
}
