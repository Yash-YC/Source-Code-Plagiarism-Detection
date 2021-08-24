import java.util.*;
import java.io.*;

public class c {
    
    public static void main(String[] args) throws Exception {
	BufferedReader in = new BufferedReader(new FileReader("333.in"));
	//BufferedReader in = new BufferedReader(new FileReader("c2.txt"));
	int cases = Integer.parseInt(in.readLine());
	for (int u = 1; u <= cases; u++) {
	    System.out.print("Case #" + u + ": ");
	    String[] sa = in.readLine().split(" ");
	    int n = Integer.parseInt(sa[0]);
	    int k = Integer.parseInt(sa[1]);
	    double[] ans = new double[n];
	    for (int i = 0; i < k-1; i++)
		ans[i] = (double)(i+1)/k;
	    ans[k-1] = 1;
	    for (int i= k; i < n; i++) {
		double a = choose(n,k);
		double b = choose(i,k);
		double denom = a-b;
		double thing = b/denom;
		for (int j = 1; j <= k; j++) {
			thing += choose(i,k-j)/denom*choose(n-i,j)*(ans[i-j]+1);
		}
	
		ans[i] = thing;
	    }
	    System.out.println(ans[ans.length-1]);
	}
    }
    
    public static double choose(int n, int k) {
	double ans = 1;
	for (int i = 1; i <= k; i++)
	    ans *= (double)(n+1-i)/i;
	return ans;
    }
	
}
