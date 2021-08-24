import java.io.*;
import java.util.*;
import java.math.*;
import java.awt.geom.*;

public class Solution {
	
	static String TASK = "XXX";
    static Scanner in;
	static PrintWriter out;
    
    static class Pair implements Comparable<Pair> {
    	public int x, y;
    	public Pair(int xx, int yy) {
    		x = xx; y = yy;
    	}
    	public int compareTo(Pair p) {
    		if (x != p.x) {return x-p.x;}
    		return y-p.y;
    	}
    }

    static int conv(int x, int b) {
    	int res = 0;
    	while (x > 0) {
    		res += (x % b)*(x % b);
    		x /= b;
    	}
    	return res;
    }

    static boolean test(int x, int b) {
    	HashSet<Integer> use = new HashSet<Integer>();
    	int y = x;
    	while (true) {
    		if (y == 1) {return true;}
    		if (use.contains(y)) {return false;}
    		use.add(y);
    		y = conv(y, b);
    	}
    }
               
	public static void main(String[] args) throws Exception {
		in = new Scanner(new File(TASK+".in"));
		out = new PrintWriter(new File(TASK+".out"));

		int cas = in.nextInt();
		in.nextLine();
		for (int casn=1; casn<=cas; casn++) {
			
			Scanner in2 = new Scanner(in.nextLine());	

			int[] a = new int[20];
			int n = 0;
			while (in2.hasNextInt()) {
				a[n++] = in2.nextInt();
			}

			int ans;
			for (ans = 2; ans < Integer.MAX_VALUE; ans++) {
				boolean shit = false;
				for (int i=0; i<n; i++) {
					if (!test(ans, a[i])) {
						shit = true;
						break;
					} 
				}
				if (!shit) {break;}
			}

			out.println("Case #"+casn+": "+ans);
		}

		out.flush();
	}	
}
