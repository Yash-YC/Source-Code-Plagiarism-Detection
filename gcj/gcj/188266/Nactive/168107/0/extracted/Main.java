import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.ArrayList;

import sun.print.resources.serviceui;


public class Main {
	
	static boolean opl [] [] = new boolean [11] [2000000];
	static boolean know [] [] = new boolean [11] [2000000];
	/**
	 * @param args
	 */	
	public static void main(String[] args) {

		
		ArrayList<String> s = readInput("small.in");
		//String o[] = new String [s.length];
		ArrayList<String> o = new ArrayList<String>();

		int casec = 0;
		while (s.size() != 0) {
			String ss = s.get(0);
			s.remove(0);
			casec++;
			
			int [] bases = ConvertStringToInt(ss.split(" "));
			
			boolean no = true;
			int a = 1;
			while (no) {
				a++;
				boolean b = true;
				for (int i = 0; i < bases.length; i++) {
					if (crackHapyNumber(a, bases[i]) == false) {
						i = bases.length + 1;
						b = false;
					}
				}
				if (b == true) {
					no = false;
				}
			}
			
			
			//System.out.println("Match " + a);
			
			o.add("Case #" + casec + ": " + a);
			System.out.println(o.get(o.size() - 1));
		}
		
		writeOutput("small.out", o);
		System.out.println("Finished!");
	}
	
	
	static private boolean crackHapyNumber(int number, int base) {
		if (know [base] [number] == true) return opl [base] [number];
		int a = convert(number, base);
		know [base] [number] = true;
		if (a == 1) {
			//System.out.println("Boeka");
			opl [base] [number] = true;
		} else {
			opl [base] [number] = crackHapyNumber(a, base);
		}
		return opl [base] [number];
	}
	
	
	static private int convert(int number, int base) {
		double high = 0;
		int counter = -1;
		while (high < (double) number) {
			counter++;
			high = Math.pow(base, counter);
		}
		int [] returnn = new int[counter + 1];
		int over = number;
		for (int i = counter; i > -1; i--) {
			int current = dubbleToInt(Math.pow(base, i));
			if (current <= over) {
				if (over % current == 0) returnn [i] = (over / current);
				else {
					returnn [i] = dubbleToInt(Math.ceil((double) over / (double) current)) - 1;
				}
				over -= returnn [i] * current;
			} else {
				returnn [i] = 0;
			}
		}
		int tot = 0;
		for (int i = 0; i < returnn.length; i++ ){
			tot += returnn [i] * returnn [i];
		}
		return tot;
	}

	

	
	

	private static int dubbleToInt(double a) {
		return Integer.parseInt(String.valueOf(Math.round(a)));
	}
	
	private static int getMax(int [] a) {
		int max = 0;
		for (int i = 0; i < a.length; i++) if (a[max] < a[i]) max = i;
		return max;
	}
	
	private static int abs(int a) {
		if (a > -1) return a;
		else return a * -1;
	}

	private static String [] setString(String [] s, String set) {
		for (int i = 0; i < s.length; i++) s [i] = set;
		//for (int i = 0; i < s.length; i++) for (int j = 0; j < s [i].length; j++) s [i] [j] = set;
		//for (int i = 0; i < s.length; i++) for (int j = 0; j < s [i].length; j++) for (int k = 0; k < s[i][j].length; k++) s [i] [j] [k] = set;
		
		return s;
	}
	
	private static int [] setInt(int [] s, int set) {
		for (int i = 0; i < s.length; i++) s [i] = set;
		//for (int i = 0; i < s.length; i++) for (int j = 0; j < s [i].length; j++) s [i] [j] = set;
		
		return s;
	}
	
	private static int [][] setIntt(int [][] s, int set) {
		//for (int i = 0; i < s.length; i++) s [i] = set;
		for (int i = 0; i < s.length; i++) for (int j = 0; j < s [i].length; j++) s [i] [j] = set;
		return s;
	}
	private static int [][][] setInttt(int [][][] s, int set) {
		//for (int i = 0; i < s.length; i++) s [i] = set;
		//for (int i = 0; i < s.length; i++) for (int j = 0; j < s [i].length; j++) s [i] [j] = set;
		for (int i = 0; i < s.length; i++) for (int j = 0; j < s [i].length; j++) for (int k = 0; k < s[i][j].length; k++) s [i] [j] [k] = set;
		
		return s;
	}
	private static long [] [] setLong(long [][] s, long set) {
		//for (int i = 0; i < s.length; i++) s [i] = set;
		for (int i = 0; i < s.length; i++) for (int j = 0; j < s [i].length; j++) s [i] [j] = set;
		//for (int i = 0; i < s.length; i++) for (int j = 0; j < s [i].length; j++) for (int k = 0; k < s[i][j].length; k++) s [i] [j] [k] = set;
		return s;
	}

	private static double [] setDouble(double [] s, double set) {
		for (int i = 0; i < s.length; i++) s [i] = set;
		//for (int i = 0; i < s.length; i++) for (int j = 0; j < s [i].length; j++) s [i] [j] = set;
		//for (int i = 0; i < s.length; i++) for (int j = 0; j < s [i].length; j++) for (int k = 0; k < s[i][j].length; k++) s [i] [j] [k] = set;
		
		return s;
	}
	
	private static ArrayList<String> readInput(String fname) {
		ArrayList<String> in = new ArrayList<String>();
		try {
			FileReader fr = new FileReader(fname);
			BufferedReader br = new BufferedReader(fr);
			br.readLine();
			String s;
			while((s=br.readLine()) !=null) {
				in.add(s);
			}
			fr.close();
		} catch (Exception e) {
			System.out.println(e);
		}
		System.out.println("Input is " + in.size() + " lines long.");
		return in;
	}

	private static void writeOutput(String fname, ArrayList<String> o) {
		try {
		    OutputStream out = new FileOutputStream(fname);
		    PrintStream p = new PrintStream( out );
		    
		    for (int i = 0; i < o.size(); i++) {
		    	p.println(o.get(i));
		    }
		    
		    out.close();
		} catch (Exception e) {
			System.out.println(e);
	    }
	}
	
	private static int [] ConvertStringToInt(String [] s) {
		int [] terug = new int[s.length];
		for (int i = 0; i < s.length; i++) {
			terug [i] = Integer.parseInt(s[i]);
		}
		return terug;
	}
	
	private static String [] splitAtEveryChar(String s) {
		String [] t = s.split("");
		String [] p = new String [t.length - 1];
		for (int i = 1; i < t.length; i++) {
			p[i - 1] = t [i];
		}
		return p;
	}
}
