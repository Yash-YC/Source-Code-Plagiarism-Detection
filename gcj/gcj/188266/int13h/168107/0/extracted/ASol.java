import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;


public class ASol {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		solveA("A-small-attempt0.in", "A-small-attempt0.out");		

	}

	private static int solveSlow(int[] bases) {
		int n = 2;
		int lastN = n;
		while (true) {
			for (int i = 0; i < bases.length; i++) {
				n = findInBase(n, bases[i]);
			}	
			if (lastN == n) {
				break;
			}
			lastN = n;
		}
		return n;
	}
	
	/*
	private static int findInBase2(int n, int base) {
		boolean mm [] = new boolean[569669];
		
		ArrayList<String> good = new ArrayList<String>();
		ArrayList<String> bad = new ArrayList<String>();
		for (int i = 0; i < mm.length; i++) {
			ArrayList<String> parts = new ArrayList<String>(); 
			boolean rez = solve(n, base, parts);
			if (rez) {
				good.addAll(parts);
				for (int j = 0; j < parts.size(); j++) {
					
				}
			} else {
				bad.addAll(parts);
			}
			System.out.println(n + " " + base +  " " + rez + " " + parts.size());
			if (rez) {
				return n;
			}
			n++;
		}
	}
	*/
	
	private static int findInBase(int n, int base) {

		ArrayList<String> good = new ArrayList<String>();
		ArrayList<String> bad = new ArrayList<String>();
		while (true) {  
			ArrayList<String> parts = new ArrayList<String>(); 
			boolean rez = solve(n, base, parts);
			/*
			if (rez) {
				good.addAll(parts);
			} else {
				bad.addAll(parts);
			}
			*/
			//System.out.println(n + " " + base +  " " + rez + " " + parts.size());
			if (rez) {
				return n;
			}
			n++;
		}
	}
	private static boolean solve(int n, int base, ArrayList<String> sums) {
		int nn = n;
		boolean rez = true;
		while (true) {
			String d = Integer.toString(nn, base);
			nn = digitSquareSum(d);
			//System.out.println(nn + " " + base);
			if (sums.contains("" + nn)) {
				rez = false;
				break;
			} else {
				sums.add("" + nn);
			}
			if (nn == 1)
				break;
		}
		
		return rez;
		
	}
	private static int digitSquareSum(String a) {
		int sum = 0;
		for (int i = 0; i < a.length(); i++) {
			int d = a.charAt(i) - '0';
			sum += d*d;
		}
		return sum;
	}
	
	private static void solveA(String in, String out) {
		try {
			FileReader fis = new FileReader(in);
			BufferedReader  dis = new BufferedReader (fis);
			
			FileWriter fw = new FileWriter(out);
			BufferedWriter bw = new BufferedWriter(fw);
			
			int t = Integer.parseInt(dis.readLine());
			for (int i = 0; i < t; i++) {
				String e = dis.readLine();
				String ee[] = e.split(" ");
				int bases [] = new int[ee.length];
				for (int j = 0; j < bases.length; j++) {
					bases[j] = Integer.parseInt(ee[j]);
				}
				int rez = solveSlow(bases);
				bw.write("Case #" + (i+1) + ": " + rez + "\n");
			}
			
			
			bw.flush();
			bw.close();
			fw.close();
			dis.close();
			fis.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			
		}
	}

}
