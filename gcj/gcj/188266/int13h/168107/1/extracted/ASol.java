import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Date;

import com.sun.swing.internal.plaf.basic.resources.basic;


public class ASol {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		//569669
		//11814485
		
		solveA("A-large.in", "A-large.out");		
		
		


		/*
		System.out.println("start");
		Date d1 = new Date();
		boolean baseMap [][] = new boolean[11][];
		for (int i = 2; i <= 10; i++) {
			baseMap[i] = findInBase2(1, i);
		}
		Date d2 = new Date();
		System.out.println("end");
		System.out.println(d2.getTime()-d1.getTime());
		
		
		Date d21 = new Date();
		int rez = solveSlow(new int []{2,3,4,5,6,7,8,9,10}, baseMap);
		Date d22 = new Date();
		System.out.println(d22.getTime()-d21.getTime());
		System.out.println("rez: " + rez);
		/*
		
		int rez  = solveSlow(new int []{2,3,4,5,6,7,8,9,10});
		
		
		*/
	}

	private static int solveSlow(int[] bases) {
		int n = 2;
		int lastN = n;
		while (true) {
			for (int i = 0; i < bases.length; i++) {
				
				n = findInBase(n, bases[i]);
			}
			//System.out.println(n);
			if (lastN == n) {
				break;
			}
			
			lastN = n;
		}
		return n;
	}
	
	private static int solveSlow(int[] bases, boolean baseMap [][]) {
		int n = 2;
		int lastN = n;
		while (true) {
			for (int i = 0; i < bases.length; i++) {
				
				while ((baseMap[bases[i]].length > n) && !baseMap[bases[i]][n] ) n++;
				//System.out.println(n + " " + baseMap[bases[i]][n]);
				//
				if (baseMap[bases[i]].length > n) {
					System.out.println("*");
					n = findInBase(n, bases[i]);
				}
			}
			//System.out.println(n);
			if (lastN == n) {
				break;
			}
			
			lastN = n;
		}
		return n;
	}
	
	private static boolean[] findInBase2(int n, int base) {
		int mm [] = new int[11814485+1];
		boolean mb [] = new boolean[mm.length];
		for (int i = n; i < mm.length; i++) {
			ArrayList<String> parts = new ArrayList<String>();
			if (mm[i] == 0) {
				boolean rez = solve(i, base, parts);
				if (rez) {
					for (int j = 0; j < parts.size(); j++) {
						int sk = Integer.parseInt(parts.get(j));
						mm[sk] = 1;
						mb[sk] = true;
					}
				} else {
					for (int j = 0; j < parts.size(); j++) {
						int sk = Integer.parseInt(parts.get(j));
						mm[sk] = -1;
						mb[sk] = false;
					}
				}
			}
		}
		return mb;
	}
	
	
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
		//System.out.println("solve: " + n + " " + base);
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
			
			System.out.println("start");
			Date d1 = new Date();
			boolean baseMap [][] = new boolean[11][];
			for (int i = 2; i <= 10; i++) {
				baseMap[i] = findInBase2(1, i);
			}
			Date d2 = new Date();
			System.out.println("end");
			System.out.println(d2.getTime()-d1.getTime());
			
			
			int t = Integer.parseInt(dis.readLine());
			for (int i = 0; i < t; i++) {
				String e = dis.readLine();
				String ee[] = e.split(" ");
				int bases [] = new int[ee.length];
				for (int j = 0; j < bases.length; j++) {
					bases[j] = Integer.parseInt(ee[j]);
				}
				int rez = solveSlow(bases, baseMap);
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
