package current;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import ca.missine.utils.Problem;
import ca.missine.utils.Reader;

public class HappyTime extends Problem {
	public HappyTime() throws Exception {
		super();
	}
	
	public static void main(String args[]) throws Exception {
//		System.out.println(getDigits(81, 2));
		new HappyTime().solve();
	}

	Set<Integer> cache = new HashSet<Integer>();
	protected String next() throws Exception {
		String a[] = Reader.getLine().split("\\s+");
		int bases[] = new int[a.length];
		for(int i = 0; i < bases.length; i++) bases[i] = Integer.parseInt(a[i]);
		for(int i = 2; i < 10000000; i++) {
			if(isHappy(i, bases)) return "" + i;
		}
		throw new IllegalStateException("No solution");
	}

	private boolean isHappy(int i, int[] bases) {
		for(int base : bases) {
			cache.clear();
			if(!isHappy(i, base)) 
				return false;
		}
		return true;
	}

	private boolean isHappy(int i, int base) {
		if(cache.contains(i)) return false;
		cache.add(i);
		if(i == 1) return true;
		return isHappy(op(i, base), base);
	}

	private int op(int i, int base) {
		List<Integer> digits = getDigits(i, base);
		int r = 0;
		for(int d : digits) r += d*d;
		return r;
	}

	private static List<Integer> getDigits(int i, int base) {
		List<Integer> r = new ArrayList<Integer>();
		int power = 1;
		while(power < i) power *= base;
		while(power >= 1) {
			int x = i / power;
			r.add(x);
			i = i % power;
			power /= base;
		}
		if(r.get(i) == 0) r.remove(0);
		return r;
	}
}
