import java.io.*;
import java.util.*;
import java.math.*;

public class A2 implements Runnable {
    public static void main(String[] args) {
	new Thread(new A2()).start();
    }

    @Override
    public void run() {
	try {
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

//    String FNAME = "sample";
//    String FNAME = "A-small-attempt0";
    String FNAME = "A-large";
    
    
    int MB = 11;
    
    private void solve() throws IOException {
	Scanner in  = new Scanner(new File("dump"));
	int[] ans = new int[1 << 11];
	while (in.hasNext()) {
	    ans[in.nextInt()] = in.nextInt();
	}
	for (int i = 0; i < ans.length; ++i) {
	    if (i % 4 == 0 && ans[i] == 0) {
		System.out.println(i);
	    }
	}
	
	int t = nextInt();
	for (int tn = 1; tn <= t; ++tn) {
	    String s = br.readLine();
	    StringTokenizer st = new StringTokenizer(s);
	    int mask = 0;
	    while (st.hasMoreElements()) {
		int q = Integer.parseInt(st.nextToken());
		mask |= (1 << q);
	    }
	    out.println("Case #" + tn + ": " + ans[mask]);
	}
    }

}
