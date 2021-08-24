package com.gzroger.codejam2009.round1a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;

public class MultiBaseHappiness {
	
	ArrayList<Integer> lBases = new ArrayList<Integer>();
	
	public MultiBaseHappiness(ArrayList<Integer> pBases) {
		this.lBases = pBases;
	}
	
	public int findSmallestHappy() {
		int result = 2;
		while (true) {
			boolean bHappyInAll = true;
			for (int base: lBases) {
				bHappyInAll = bHappyInAll && isHappyInBase(result, base);
			}
			if (bHappyInAll) {
				return result;
			}
			result++;
		}
	}

	private static boolean isHappyInBase(int result, int base) {
		HashSet<Integer> wasInCycle = new HashSet<Integer>(); 
		while (true) {
			wasInCycle.add(result);
			ArrayList<Integer> lDigits = getDigitsInBase(result, base);
			int sum = 0;
			for (int digit:lDigits) {
				sum += digit*digit;
			}
			if (wasInCycle.contains(sum)) break;
			result = sum;
		}
		return result == 1;
	}

	private static ArrayList<Integer> getDigitsInBase(int result, int base) {
		ArrayList<Integer> lDigits = new ArrayList<Integer>();
		while (result>0) {
			lDigits.add(result%base);
			result = result / base;
		}
		return lDigits;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		/*
		System.out.println(getDigitsInBase(123, 10));
		System.out.println(getDigitsInBase(15, 2));
		System.out.println(getDigitsInBase(27, 3));
		System.out.println(getDigitsInBase(1545378698, 10));

		System.out.println(isHappyInBase(3, 2));
		System.out.println(isHappyInBase(3, 3));
		System.out.println(isHappyInBase(11, 3));
		System.out.println(isHappyInBase(143, 2));
		System.out.println(isHappyInBase(143, 3));
		System.out.println(isHappyInBase(143, 7));
		System.out.println(isHappyInBase(91, 7));
		System.out.println(isHappyInBase(91, 9));
		System.out.println(isHappyInBase(91, 10));
		System.out.println(isHappyInBase(82, 10));
		System.out.println(isHappyInBase(82, 3));
		*/
		ArrayList<Integer> bases;
		MultiBaseHappiness mbh;

/*		bases = new ArrayList<Integer>();
		bases.add(2); bases.add(3);
		mbh = new MultiBaseHappiness(bases);
		System.out.println(mbh.findSmallestHappy());

		bases = new ArrayList<Integer>();
		bases.add(2); bases.add(3); bases.add(7);
		mbh = new MultiBaseHappiness(bases);
		System.out.println(mbh.findSmallestHappy());
	
		bases = new ArrayList<Integer>();
		bases.add(9); bases.add(10); 
		mbh = new MultiBaseHappiness(bases);
		System.out.println(mbh.findSmallestHappy());*/
		///projects/codejam2009/src/com/gzroger/codejam2009/round1a/
		try {
			BufferedReader br = new BufferedReader(new FileReader(args[0]));
			
			PrintStream ps;
			if (args.length>1) {
				ps = new PrintStream(args[1]);
			} else {
				ps = System.out;
			}
			int T;
			String firstLine = br.readLine();
			T = Integer.parseInt(firstLine);
			for (int i=0;i<T;i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				bases = new ArrayList<Integer>();
				while (st.hasMoreTokens()) {
					bases.add(Integer.parseInt(st.nextToken()));
				}
				mbh = new MultiBaseHappiness(bases);
				ps.println( "Case #"+ (i+1) + ": " + mbh.findSmallestHappy() );
			}

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}

}
