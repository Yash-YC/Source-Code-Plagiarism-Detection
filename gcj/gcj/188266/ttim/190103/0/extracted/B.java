import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {
	int c,n;
	
	public int cnk(int n, int k) {
		if ((k < 0) || (n < k)) return 0;
		
		int res = 1;
		for (int i = k+1; i <= n; i++) res *= i;
		for (int i = 1; i <= n-k; i++) res /= i;
		
		return res;
	}
	
	public double prob(int i, int j) {
		return (cnk(c-i, j-i)*cnk(i, n-(j-i))*1.0)/cnk(c, n);
	}
	
	public void run() throws FileNotFoundException {
		Scanner input = new Scanner(new File("input.txt"));
		PrintWriter output = new PrintWriter(new File("output.txt"));
				
		int t = input.nextInt();
		
		for (int tt = 0; tt < t; tt++) {
			c = input.nextInt();
			n = input.nextInt();
			
			double[] v = new double[c+1];
			v[0] = 1;
			int step = 0;
			double ans = 0;
			
			while (true) {
				// produce step
				step++;
				
				double[] nv = new double[c+1];
				
				//for (int i = 0; i <= c; i++) System.out.print(v[i]+" ");
				//System.out.println();
				
				for (int i = 0; i <= c; i++)
					for (int j = i; j <= c; j++) {
						// ne popalo j-i
						// popalo n-(j-i)
						nv[j] += v[i]*prob(i, j);
					}
				
				// add to ans
				ans += step*(nv[c]-v[c]);
				if ((1-v[c])*step*2 < 0.000001) break;
				
				v = nv;
			}
			
			output.println("Case #"+(tt+1)+": "+ans);
		}
		
		
		input.close(); output.close();	
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		(new B()).run();
	}

}