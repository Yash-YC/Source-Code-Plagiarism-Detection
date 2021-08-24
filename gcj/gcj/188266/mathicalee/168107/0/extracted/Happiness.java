package round1;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;

public class Happiness {
	
	private static int HAPPY = 1;
	private static int NOTHAPPY = 2;
	
	private int T;
	private int[] bases;
	
	private int[][] isHappy; // 0: not calculated, 1: happy, 2: not happy
	private Vector<Integer> v = new Vector<Integer>();
	
	private int caseNum = 1;
	
	private Scanner s;
	private PrintWriter pw;
	
	public Happiness() throws IOException {
		s = new Scanner(new File("input1.txt"));
		pw = new PrintWriter(new File("output1.txt"));
		
		T = s.nextInt();
		s.nextLine();
		
		for(int caseT = 1; caseT <= T; caseT++) {
			StringTokenizer st = new StringTokenizer(s.nextLine());
			bases = new int[st.countTokens()];
			for(int i = 0; i < bases.length; i++ ) {
				bases[i] = Integer.parseInt(st.nextToken());
			}
			
			isHappy = new int[bases.length][1000000];
			
			int num = 2;
			while(true) {
				boolean b = true;
				for(int i = 0; i < bases.length; i++) {
					v.clear();
					if(!checkIsHappy(i, num)) {
						b = false;
						continue;
					}
				}
				
				if(b) {
					print(num);
					break;
				}
				
				num++;
				
			}
		}
		
		s.close();
		pw.close();
	}
	
	public boolean checkIsHappy(int base, int num) {
		
//		System.out.println("["+ bases[base] +"]["+ num +"]");
		
		if(isHappy[base][num] == HAPPY) {
			mark(base, HAPPY);
			System.out.println("["+ bases[base] +"]["+ num +"] : " + "HAPPY");
			return true;
		} else if(isHappy[base][num] == NOTHAPPY) {
			mark(base, NOTHAPPY);
			System.out.println("["+ bases[base] +"]["+ num +"] : " + "NOTHAPPY");
			return false;
		}
		
		if(v.contains(num)) {
			mark(base, NOTHAPPY);
			return false;
		} else {
			v.add(num);
			int sum = 0;
			String str = Integer.toString(num, bases[base]);
			for(int i = 0; i < str.length(); i++) {
				sum += (str.charAt(i)-'0')*(str.charAt(i)-'0');
			}
			
			if(sum != 1) {
				
				return checkIsHappy(base, sum);
			} else {
				mark(base, HAPPY);
				return true;
			}
		}
	}
	
	public void mark(int base, int h) {
		for(int a : v) {
			isHappy[base][a] = h;
			System.out.println("["+ bases[base] +"]["+ a +"] : " + (h == HAPPY ? "HAPPY" : "NOTHAPPY"));
		}
	}
	
	public void print(int num) {
		System.out.println("Case #"+ caseNum + ": "  + num);
		pw.println("Case #"+ caseNum + ": "  + num);
		caseNum++;
	}
	
	public static void main(String[] args) throws IOException {
		new Happiness();
	}
}
