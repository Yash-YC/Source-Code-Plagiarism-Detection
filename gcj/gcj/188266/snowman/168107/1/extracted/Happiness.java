package round1a;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Happiness {

	final static String RESULT		= "test/round1a/A-output.txt";
	final static String INPUT		= "test/round1a/A-large.in"; 
	final static String OUTPUT		= "test/round1a/A-large.out";
	
	String toBase(int n, int b) {
		StringBuffer sb = new StringBuffer();
		while (n>0) {
			sb.append(n%b);
			n/=b;
		}
		return sb.toString();
	}
	
	int sumOfSquares(String s) {
		int t = 0;
		for (int i=0; i<s.length(); i++) {
			int d = s.charAt(i) - '0';
			t += d*d; 
		}
		return t;
	}
	
	boolean isHappy(int n, int b) {
		boolean[] marked = new boolean[10000];
		Arrays.fill(marked, false);
		String s = toBase(n, b);
		while (true) {
			int ss = sumOfSquares(s);
			if (ss==1) break;
			if (marked[ss]) return false;
			marked[ss] = true;
			String s2 = toBase(ss, b);
			s = s2;
		}
		return true;
	}

	boolean isHappy(int n, int[] bs) {
		for (int i=0; i<bs.length; i++)
			if (!isHappy(n, bs[i])) return false;
		return true;
	}
	
	int find(int[] bs) {
		return find(bs, 2);
	}
	
	int find(int[] bs, int startFrom) {
		int n = startFrom;
		while (n<100000000) {
			if (isHappy(n, bs)) return n;
			n++;
		}
		return -1;
	}
	
	boolean isSubset(int u, int i) {
		for (int j=0; j<9; j++) {
			if ((u>>j&1)==1&&(i>>j&1)==0) return false;
		}
		return true;
	}
	
	void generateAll() {
		int[] cache = new int[1<<9];
		for (int i=1; i<1<<9; i++) {
			int nb = 0;
			for (int j=0; j<9; j++)
				if ((i>>j&1)==1) nb++;
			int[] bs = new int[nb];
			nb = 0;
			for (int j=0; j<9; j++)
				if ((i>>j&1)==1) bs[nb++] = j+2;
			System.out.println(i);
			for (int j=0; j<nb; j++) System.out.print(bs[j]+" "); System.out.println();
			int startFrom = 2;
			for (int u=1; u<i; u++)
				if (isSubset(u, i)) {
					startFrom = Math.max(startFrom, cache[u]);
				}
			cache[i] = find(bs, startFrom);
			System.out.println(cache[i]);
		}		
	}

	int[] res;
	
	void readResults() throws Exception {
		res = new int[1<<9];
		BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(RESULT)));
		for (int i=1; i<1<<9; i++) {
			br.readLine();
			br.readLine();
			res[i] = Integer.parseInt(br.readLine());
		}
	}
	
	void solveProblem() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(INPUT)));		
		PrintWriter out = new PrintWriter(OUTPUT);
		int t = Integer.parseInt(br.readLine());
		for (int i=0; i<t; i++) {
			int[] bs = Utils.toInts(br.readLine());
			int si = 0;
			for (int j=0; j<bs.length; j++) si |= 1<<(bs[j]-2);
			out.println("Case #"+(i+1)+": "+res[si]);
		}
		out.close();
	}
	
	public Happiness() throws Exception {
		readResults();
		solveProblem();
	}
	
	public static void main(String[] args) throws Exception {
		new Happiness();
		System.out.println("Done!");
	}
	
}

class Utils {

	public static String[] toStrings(String s, String delim) {
		StringTokenizer st = new StringTokenizer(s, delim);
		ArrayList <String> r = new ArrayList <String>();
		while (st.hasMoreTokens()) {
			r.add(st.nextToken());
		}
		String[] res = new String[r.size()];
		for (int i=0; i<r.size(); i++) res[i] = r.get(i);
		return res;
	}

	public static String[] toStrings(String s) {
		return toStrings(s, " ");
	}

	public static int[] toInts(String s, String delim) {
		String[] ss = toStrings(s, delim);
		int[] r = new int[ss.length];
		for (int i=0; i<r.length; i++) r[i] = Integer.parseInt(ss[i]);
		return r;
	}
	
	public static int[] toInts(String s) {
		return toInts(s, " ");
	}
	
}
