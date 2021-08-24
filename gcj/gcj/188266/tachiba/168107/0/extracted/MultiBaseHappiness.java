package round1a;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Set;

public class MultiBaseHappiness {

	public MultiBaseHappiness() throws FileNotFoundException{
		FileInputStream fis = new FileInputStream("src/round1a/A-small-attempt0.in");
		System.setOut(new PrintStream("src/round1a/A-small-attempt0.out"));
		Scanner sc = new Scanner(fis);
		
		int T = sc.nextInt();
		sc.nextLine();
		for (int i = 0; i < T; i++) {
			// bases
			String line = sc.nextLine();
//			System.out.println(line);
			Scanner isc = new Scanner(line);
			LinkedList<Integer> bases = new LinkedList<Integer>();
			while (isc.hasNext()) bases.add(isc.nextInt());
			
			// init
			boolean[][] h = new boolean[11][1000000];
			
			// calc
			// 2karadeyoi?
			for (int j = 2; ; j++) {
//				System.out.println("bases=" + bases);
				for (Iterator<Integer> iterator = bases.iterator(); iterator.hasNext();) {
					int base = iterator.next();
					
					// change base
					int n = j;
					StringBuilder number = new StringBuilder();
					while (true) {
						if (n < base) {
							// 条件必要かも？
							number.append(n);
							break;
						}
						number.append(n % base);
						n /= base;
					}
//					System.out.println("j=" + j + "base=" + base + "number=" + number.reverse().toString());
					char[] c = number.reverse().toString().toCharArray();
					
					// are you happy?
					// ここらへんから順番関係ない
					Set<String> s = new HashSet();
					while (true) {
						int sum = 0;
						for (int k = 0; k < c.length; k++) {
							sum += (c[k] - '0') * (c[k] - '0');
						}
						if (sum == 1) {
							h[base][j] = true;
							break;
						}
						
//						System.out.println(sum);
						c = base(sum, base);
						if (s.contains(new String(c))) {
							break;
						}
						s.add(new String(c));
//						System.out.println(new String(c));
					}
				}
				
				boolean isHappy = true;
				for (Iterator<Integer> iterator = bases.iterator(); iterator.hasNext();) {
					int base = iterator.next();
					if (!h[base][j]) isHappy = false;
				}
				
				if (isHappy) {
					System.out.println("Case #" +( i + 1) + ": " + j);
					break;
				}
			}
//			System.exit(1);
		}
	}
	
	public char[] base(int input, int base) {
		StringBuilder t = new StringBuilder();
		while (true) {
			if (input < base) {
				// 条件必要かも？
				t.append(input);
				break;
			}
			t.append(input % base);
			input /= base;
		}
		return t.toString().toCharArray();
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		new MultiBaseHappiness();
	}

}
