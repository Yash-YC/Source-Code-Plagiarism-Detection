import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {
    public static void main(String[] args) {
	new Thread(new A()).start();
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

//    String FNAME = "A-small-attempt0";
    String FNAME = "sample";

    int MB = 11;
    int MA = 100000000;

    int[] lu;
    int[] c;
    private void solve() throws IOException {
	lu = new int[MA];
	c = new int[MA];
	for (int i = 2; i < MB; ++i) {
	    lu[1] |= (1 << i);
	    c[1] |= (1 << i);
	    for (int j = 2; j < lu.length; ++j) {
//		if (j % 100 == 0) {
//		    System.out.println(i + " " + j);
//		}
		search(i, j);
	    }
	}
	System.out.println((lu[82] & (1 << 10)) != 0);

	int[] ans = new int[1 << MB];
	
	for (int q = 2; q < MA; ++q) {
	    int mask = 0;
	    for (int i = 2; i < MB; ++i) {
		if (!get(lu, i, q)) continue;
		mask |= (1 << i);
	    }
	    count(ans, mask, q);
	}
	
	for (int i = 1; i < ans.length; ++i) {
	    if (i % 4 == 0 && ans[i] == 0) {
		System.out.println(Integer.toBinaryString(i));
	    }
	}
	PrintWriter ff = new PrintWriter("dump");
	for (int i = 0; i < ans.length; ++i) {
	    ff.println(i + " " + ans[i]);
	}
	ff.close();
	
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

    private void count(int[] ans, int mask, int q) {
	for (int i = 0; i < (1 << MB); ++i) {
	    if ((i & mask) == i && ans[i] == 0) {
		ans[i] = q;
	    }
	}
    }
    
    boolean get(int[] lu, int i, int j) {
	return (lu[j] & (1 << i)) != 0;
    }
    
    boolean search(int i, int j) {
	if (j >= MA) return false;
	if (i == 3 && j == 2) {
	    i += 0;
	}
	if (get(c, i, j)) return get(lu, i, j);
	int k = j;
	int q = 0;
	while (k > 0) {
	    q += (k % i) * (k % i);
	    k /= i;
	}
	c[j] |= (1 << i);
	boolean z = search(i, q);
	if (z) lu[j] |= (1 << i);
	return z;
    }
    
}
