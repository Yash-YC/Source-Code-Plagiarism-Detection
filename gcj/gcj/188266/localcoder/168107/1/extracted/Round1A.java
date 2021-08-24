// Matthew Gatland aka Localcoder
//		find the smallest int that is happy in all given bases.
//		input bases can be 2 through to 10
//		we can have up to 3 bases per test - or 9 in the big dataset
//		500 tests.
//OK, so: since there are only 10 possible bases, can I precompute? er, probably not, for all possible integers...
//but as we reduce numbers they will become numbers that we have seen before.
//we'll need a memory.
//Ok, the first problem is actually finding happy numbers in interesting bases.

//ok, spent too long on this. the small dataset was easy, my large randomly generated dataset runs slow but fast enough.
//looks like it'll take 5 minutes...
//I should do better than that.

//OK, for each base I'll have a cache.
//a cache of 'this number leads to happiness'
//and 'this number leads to 'sadness'
//it will have to be a hashmap :o
//any number that ends up being happy - I will add all of its part numbers

//er, although it already may run fast enough. Is it work the extra dev time?

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

import javax.swing.Timer;

public class Round1A {

	private static final boolean debug = false;
	private static final Object bad = new Object();
	private static final Object good = new Object();

	private static  HashMap<Integer, Object>[] cache;
	
	public static void main(String[] args) {
		start();
		//test();
	}

	private static void start() {
		long startTime = System.currentTimeMillis();
		cache = new HashMap[11];
		for (int i=0; i < 11; i++) {
			cache[i] = new HashMap<Integer, Object>();
		}
		
		Scanner scanner = new Scanner(System.in);
		int numberOfCases = scanner.nextInt();
		scanner.nextLine();

		for (int caseNumber=0;caseNumber<numberOfCases;caseNumber++) {
			int[] bases = getBasesFromLine(scanner.nextLine());
			int numberToTest = 2;
			boolean happy = false;
			while (!isHappy(numberToTest, bases)) {
				numberToTest++;
			}
			System.out.println("Case #" + (caseNumber+1) + ": " + numberToTest);
		}
		long timePassed = System.currentTimeMillis() - startTime;
		int secs = (int)(timePassed / 1000);
		int mins = secs/60;
		//if (debug) {
	//		System.out.println(mins);
		//}
		
	}

	private static boolean isHappy(int numberToTest, int[] bases) {
		for (int i=0; i < bases.length; i++) {
			if (!isHappy(numberToTest, bases[i])) {
				if (debug) {
					System.out.println("" + i + " is not happy");
				}
				return false;
			}
		}
		return true;
	}

/*
 8*8 + 2*2       = 64 + 4    = 68,  repeat:
6*6 + 8*8       = 36 + 64   = 100, repeat:
1*1 + 0*0 + 0*0 = 1 + 0 + 0 = 1 (happy! :)
 */
	
	private static boolean isHappy(int numberToTest, int base) {
		int newVal = numberToTest;
		ArrayList<Integer> oldVals = new ArrayList<Integer>();
		oldVals.add(new Integer(numberToTest));
		
		while (newVal > 1) {
			newVal = sumOfSquares(newVal, base);
			Integer newValObject = new Integer(newVal);
			
//			if (cache[base].containsKey(newValObject)) {
//				if (cache[base].get(newValObject) == bad) {
//					sadCache(oldVals, base);
//					return false;
//				} else {
//					happyCache(oldVals, base);
//					return true;
//				}
//			}
			
			if (oldVals.contains(newValObject)) {
				sadCache(oldVals, base);
				return false;
			}
			oldVals.add(newVal);
		}
		happyCache(oldVals, base);
		return true;
	}

	private static void happyCache(ArrayList<Integer> oldVals, int base) {
//		for (Integer i: oldVals) {
//			cache[base].put(i, good);
//		}
	}

	private static void sadCache(ArrayList<Integer> oldVals, int base) {
//		for (Integer i: oldVals) {
//			cache[base].put(i, bad);
//		}	
}
	
	
	//looked at http://barnyard.syr.edu/quickies/happy.c
	
	private static int sumOfSquares(int number, int base) {
		int sum = 0;
		while(number>0){
			int digit = number % base; //get the last digit.
			number = number / base; //
			sum += digit*digit;
		}
		if (debug) {
			System.out.println("sum " + sum);
		}
		return sum;
	}
	
	private static int[] getBasesFromLine(String nextLine) {
		Scanner scanner = new Scanner(nextLine);
		ArrayList<Integer> ints = new ArrayList<Integer>();
		while (scanner.hasNextInt()) {
			ints.add(scanner.nextInt());
		}
		int[] out = new int[ints.size()];
		for (int i=0;i<ints.size();i++) {
			out[i] = ints.get(i);
		}
		if (debug) {
			System.out.println(out);
		}
		return out;
	}
}
