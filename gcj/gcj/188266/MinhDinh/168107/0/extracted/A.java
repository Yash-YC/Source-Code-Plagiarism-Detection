package a;
import java.util.*;import java.text.*;import java.math.*;import java.util.regex.*;import java.awt.geom.*;import java.io.*;import static java.lang.Math.*;import static java.lang.Character.*;import static java.lang.Integer.*;import static java.lang.Double.*;import static java.lang.Long.*;import static java.lang.System.*;import static java.util.Arrays.*; 

class Solver {
//	public static final String FILE_NAME = "A"; 
	public static final String FILE_NAME = "A-small-attempt0"; 
//	public static final String FILE_NAME = "A-large"; 
	
	public static final String FOLDER_NAME = "E:\\Minh\\topcoder\\topcoders workspace\\GCJ\\src\\a\\";
	public static final String INPUT_FILE_NAME = FOLDER_NAME + FILE_NAME + ".in";
	public static final String OUTPUT_FILE_NAME = FOLDER_NAME + FILE_NAME + ".out";
	
	final int INF = Integer.MAX_VALUE/10;
	int m;
	int n;
	int[] a;
	
	static HashSet<Long> map = new HashSet<Long>();
	
	
	public boolean isHappy (long x, int radix) {
		if (x==1) {
			map.clear();
			return true;
		}
		long xx = x*10+radix;
		if (map.contains(xx)) {
			map.clear();
			return false;
		}
		map.add(xx);
		String s = Long.toString(x, radix);
		long t = new Long(s), k = 0;
		while (t!=0) {
			k += (t%10) * (t%10);
			t/=10;
		}
		return isHappy(k, radix);
	}
	
	public void input() throws Exception{
		a = parseArrInt(in.readLine());
	}
	
	private String outputString () {
		return "Case #"+(A.CURRENT_TEST+1)+": ";
	}
	public void output() throws IOException {
		out.write(outputString() + ret +"\n");
		System.out.print(outputString() + ret +"\n");
		// write what you need here
	}

	long ret= 0;
	public void process() throws Exception{
		long x = 2;
		while(true) {
			boolean ok = true;
			
			for (int i = 0; i < a.length; i++) {
				if (! isHappy(x, a[i])) {
					ok = false;
					break;
				}
			}
			
			if (ok) break;
			x++;
		}
		ret = x;
	}

	BufferedReader in;
	BufferedWriter out;
	
	public Solver(BufferedReader in, BufferedWriter out ){
		this.in = in;
		this.out = out;
	}
	
	int[] parseArrInt (String s) {
		s = s.trim();
		ArrayList<Integer> list = new ArrayList<Integer> ();
		String[] ss = s.split("[ ]+");
		for(String x:ss) list.add(new Integer(x));
		int[] ret = new int[list.size()];
		for (int i = 0; i < ret.length; i++) {
			ret[i] = list.get(i);
		}
		return ret;
	}
	
	// Bit Operators
	int SET(int mask, int u) { return mask | (1 << u);}
	boolean CHECK(int mask, int u) {return (mask & (1 << u)) != 0;}
	int FLIP(int mask, int u) {return mask ^ (1 << u);}
	int CLEAR(int mask, int u) {if (CHECK(mask, u)) return FLIP(mask, u);return mask;}
	long SET(long mask, long u) { return mask | (1L << u);}
	boolean CHECK(long mask, long u) {return (mask & (1L << u)) != 0;}
	long FLIP(long mask, long u) {return mask ^ (1L << u);}
	long CLEAR(long mask, long u) {if (CHECK(mask, u)) return FLIP(mask, u);return mask;}
}

public class A {
	static BufferedReader in;
	static BufferedWriter out;
	static int NUMBER_OF_TEST, CURRENT_TEST;
	static int[] p2;
	static {
		p2 = new int[10];
		for (int i = 0; i < 10; i++) {
			p2[i] = i*i;
		}
	}
	

	public static void main(String[] args) throws java.lang.Exception {
		in =  new BufferedReader(new FileReader(new File (Solver.INPUT_FILE_NAME)));
		out = new BufferedWriter(new FileWriter(new File (Solver.OUTPUT_FILE_NAME)));
		Solver solver = new Solver(in, out);
		
//		int[] temp = solver.parseArrInt(in.readLine());
//		// code here
//		NUMBER_OF_TEST = temp[0];
//		solver.input();
//		for(CURRENT_TEST = 0;CURRENT_TEST<NUMBER_OF_TEST;CURRENT_TEST++) {
//			solver.process();
//			solver.output();
//		}
//		
		
		NUMBER_OF_TEST = new Integer(in.readLine());
		for(CURRENT_TEST = 0;CURRENT_TEST<NUMBER_OF_TEST;CURRENT_TEST++) {
			solver.input();
			solver.process();
			solver.output();
		}
		
		in.close();
		out.close();
	}
}

