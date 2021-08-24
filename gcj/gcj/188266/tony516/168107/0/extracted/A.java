import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;


public class A extends CodeJamProblem {

	public static void main(String[] args) {
		new A().main_(args);
	}

	@Override
	protected TestCase parseTestCase(Scanner s) {
		String line = s.nextLine();
		if (line.length() == 0)
			line = s.nextLine();
		String[] baseStrings = line.split(" ");
		int[] baseInts = new int[baseStrings.length];
		for (int i = 0; i < baseStrings.length; ++i)
			baseInts[i] = Integer.parseInt(baseStrings[i]);
		return new Bases(baseInts);
	}
	
	static class Bases implements TestCase {

		private int[] bases;
		
		public Bases(int[] bases) {
			this.bases = bases;
		}
		
		@Override
		public String solve() {
			for (int i = 2;;++i) {
				boolean happy = true;
				for (int base : bases) {
					if (!isHappyNumber(i, base)) {
						happy = false;
						break;
					}
				}
				if (happy)
					return i + "";
			}
		}
		
	}
	
	static List<Integer> convertToBase(int base10Int, int base) {
		assert base <= 10;
		LinkedList<Integer> remainders = new LinkedList<Integer>();
		while (true) {
			int quotient = base10Int / base;
			int remainder = base10Int % base;
			remainders.add(remainder);
			if (quotient == 0)
				break;
			base10Int = quotient;
		}
		List<Integer> result = new ArrayList<Integer>(remainders.size());
		for (Iterator<Integer> itr = remainders.descendingIterator(); itr.hasNext();)
			result.add(itr.next());
		return result;
	}
	
	static int addSumSquareDigits(List<Integer> digits) {
		int result = 0;
		for (int digit : digits)
			result += digit * digit;
		return result;
	}
	
	static boolean isHappyNumber(int x, int base) {
		List<Integer> digits = convertToBase(x, base);
		Set<String> seen = new HashSet<String>();
		return isHappyNumber_(digits, base, seen);
	}
	
	static boolean isHappyNumber_(List<Integer> digits, int base, Set<String> seen) {
		String toString = digits.toString();
		if (seen.contains(toString))
			return false;
		seen.add(toString);
		int sumSq = addSumSquareDigits(digits);
		if (sumSq == 1)
			return true;
		return isHappyNumber_(convertToBase(sumSq, base), base, seen);
	}

}
