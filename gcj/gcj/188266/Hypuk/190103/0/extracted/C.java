import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class C implements Runnable{
	
	public static void main(String[] ar){
		new C().run();
	}

	BufferedReader in;
	int num = 1000;
	double[][] a;
	int[] cnt;
	int[][] concat;
    double[][] result = new double[11][11];
	
	double solve(int C, int N){
		a = new double[num+1][(1<<C)];
		a[0][0] = 1;
	
		cnt = new int[(1<<C)];
		int cnk = 0;
		for (int mask=0;mask<(1<<C);mask++){
			int c = 0;
			for (int i=0;i<C;i++)
				if ((mask & (1 << i)) > 0) c++;
			cnt[mask] = c;
			if (c == N) cnk++;
		}

		for (int i=0;i<num;i++)
			for (int mask=0;mask<(1<<C)-1;mask++)
				if (a[i][mask] > 0){
					double prob = a[i][mask] / cnk;
					for (int j = 0;j<(1<<C);j++)
						if (cnt[j] == N)
							a[i+1][mask|j] += prob; 
				}
		
		double res = 0;
		for (int i=0;i<=num;i++)
			res += i*a[i][(1 << C) - 1];
		
		return res;
	}
	
	@Override
	public void run() {
		try{
			in = new BufferedReader(new FileReader("C-small.in"));
			PrintWriter out = new PrintWriter(new File("c.out"));
			
			
			for (int C=1;C<=10;C++)
				for (int N=1;N<=C;N++)
					result[C][N] = solve(C,N);
			
			int T = Integer.parseInt(in.readLine());
			for (int ttt = 1;ttt<=T;ttt++){
				out.write("Case #" + String.valueOf(ttt) + ": ");
				String[] temp = in.readLine().split(" ");
				int C = Integer.parseInt(temp[0]);
				int N = Integer.parseInt(temp[1]);
				
				out.printf("%.6f\n", result[C][N]);
			}
			
			out.flush();
		}catch(Exception ex){
			ex.printStackTrace();
		}
	}
}