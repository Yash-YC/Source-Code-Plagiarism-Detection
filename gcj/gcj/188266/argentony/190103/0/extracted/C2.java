import java.io.*;
import java.util.*;
import java.math.*;

public class C2 implements Runnable {
    public static void main(String[] args) {
	new Thread(new C2()).start();
    }

    @Override
    public void run() {
	try {
	    Locale.setDefault(Locale.US);
	    br = new BufferedReader(new FileReader(FNAME + ".in"));
	    out = new PrintWriter(FNAME + ".out");
	    solve();
	    out.close();
	} catch (Throwable e) {
	    e.printStackTrace();
	    System.exit(-1);
	}
    }

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;
    boolean eof = false;

    String cnv(String a) {
	return a.equals("") ? "0" : a;
    }

    String nextToken() {
	while (st == null || !st.hasMoreElements()) {
	    try {
		st = new StringTokenizer(br.readLine());
	    } catch (Exception e) {
		eof = true;
		return "";
	    }
	}
	return st.nextToken();
    }

    int nextInt() {
	return Integer.parseInt(cnv(nextToken()));
    }

    double nextDouble() {
	return Double.parseDouble(cnv(nextToken()));
    }

//    String FNAME = "prb";
//    String FNAME = "C-small-attempt0";
    
    String FNAME = "C-small-attempt1";
    
    int MC = 51;
    
    private void solve() throws IOException {
	BigInteger[][] cnk = new BigInteger[MC][MC];
	for (int i = 0; i < cnk.length; ++i) {
	    Arrays.fill(cnk[i], BigInteger.ZERO);
	}
	for (int i = 0; i < MC; ++i) {
	    cnk[i][0] = BigInteger.ONE;
	}
	for (int i = 1; i < MC; ++i) {
	    for (int j = 1; j < MC; ++j) {
		cnk[i][j] = cnk[i - 1][j - 1].add(cnk[i - 1][j]);
	    }
	}
	
	
	int t = nextInt();
	for (int tn = 1; tn <= t; ++tn) {
	    int c = nextInt();
	    int n = nextInt();
	    double[] e = new double[c + 1];
	    double[] p = new double[c + 1];
	    p[0] = 1;
	    for (int i = 0; i <= c; ++i) {
		double q = cnk[i][n].doubleValue() / cnk[c][n].doubleValue();
		double iq = cnk[c][n].subtract(cnk[i][n]).doubleValue() / cnk[c][n].doubleValue(); 
		for (int j = i + 1; j <= c && j <= i + n; ++j) {
		    double w = cnk[c - i][j - i].doubleValue() * cnk[i][n - j + i].doubleValue() / cnk[c][n].doubleValue();
		    if (cnk[c - i][j - i].equals(BigInteger.ZERO) || cnk[i][n - j + i].equals(BigInteger.ZERO)) continue;
		    double d = q / w + 1;
		    e[j] += p[i] * w / (1 - q) * (e[i] + d);
		    p[j] += p[i] * w / iq; 
		}
	    }
//	    System.out.println(Arrays.toString(e));
//	    System.out.println(Arrays.toString(p));
//	    System.out.println("---------");
	    for (int i = 0; i <= c; ++i) {
		if (Double.isNaN(e[i]) || Double.isNaN(p[i])) {
		    System.err.println("BOTVA " + i);
		}
	    }
//	    out.println("Case #" + tn + ": " + e[c]);
	    out.printf("Case #%d: %.7f\n", tn, e[c]);
	}
    }

}
