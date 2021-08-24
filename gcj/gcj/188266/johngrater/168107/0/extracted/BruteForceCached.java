package codejam.round1a.multibasehappiness;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Stack;

public class BruteForceCached {

	final static Integer ZERO = new Integer(0);
	final static Integer ONE = new Integer(1);

	enum Happiness {
		HAPPY, UNHAPPY, DECIDING
	};

	static class Base {
		final int _radix;
		final Map<Integer, Happiness> _cache;

		Base(int radix) {
			_radix = radix;
			_cache = new HashMap<Integer, Happiness>();
			_cache.put(ZERO, Happiness.UNHAPPY);
			_cache.put(ONE, Happiness.HAPPY);
		}

		int calc(int i) {
			final String s = Integer.toString(i, _radix);
			int next = 0;
			for (int j = 0; j < s.length(); j++) {
				char c = s.charAt(j);
				int x = Integer.parseInt("" + c);
				next += x * x;
			}
			return next;
		}

		boolean test(final int i) {
			Happiness result = _cache.get(i);
			if (result == Happiness.DECIDING) {
				// Infinite loop
				debug("Bailing out of infinite loop");
				return false;
			}
			if (result == null) {
				_cache.put(i, Happiness.DECIDING);
				debug(Integer.toString(i, _radix) + "}" + i);
				final boolean answer = test(calc(i));
				result = (answer ? Happiness.HAPPY : Happiness.UNHAPPY);
				final Happiness check = _cache.put(i, result);
				assert check == Happiness.DECIDING;
			} else {
				debug("HIT " + i + "=" + result);
			}
			return (result == Happiness.HAPPY);
		}

		@Override
		public String toString() {
			return "" + _radix;
		}
	}

	static void debug(final String s) {
		// System.out.println(s);
	}

	static Map<Integer, List<Integer>> _cache = new HashMap<Integer, List<Integer>>();

	static int find(final Stack<Base> st) {
		if (st.isEmpty()) {
			return -1;
		}
		final Base top = st.pop();
		int i = 1;
		while (true) {
			debug("Starting from base " + top);
			do {
				i++;
				debug("Checking " + i + " in base " + top);
			} while (!top.test(i));
			final Stack<Base> descent = new Stack<Base>();
			descent.addAll(st);
			boolean isHappy = false;
			do {
				final Base b = descent.pop();
				debug("Operating on base " + b);
				isHappy = b.test(i);
			} while (isHappy && !descent.isEmpty());
			if (isHappy && descent.isEmpty())
				return i;
		}
	}

	public static void main(String[] args) throws IOException {
		// initialise from file
		// bases.push(new Base(2));
		// bases.push(new Base(3));
		// bases.push(new Base(7));
		// bases.push(new Base(9));
		// bases.push(new Base(10));

		BufferedReader r = new BufferedReader(
				new FileReader(
						new File(
						// "src/codejam/round1a/multibasehappiness/A-sample-in.txt")));
								"src/codejam/round1a/multibasehappiness/A-small-attempt0.in.txt")));

		final String N = r.readLine();
		int n = 1;
		while (r.ready()) {
			String l = r.readLine();
			final Stack<Base> bases = new Stack<Base>();
			String[] from = l.split(" ");
			for (String s : from) {
				bases.push(new Base(Integer.parseInt(s)));
			}
			System.out.println("Case #" + n++ + ": " + find(bases));
		}
		assert Integer.valueOf(N) == n - 1;
		r.close();
	}
}
