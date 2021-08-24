import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Locale;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.TreeSet;

@SuppressWarnings("unchecked")
public class Main implements Runnable {
	private static final String TASKNAME = "a";

	private static int getSumOfSquares(int n, final int base) {
		int sum = 0;
		while (n > 0) {
			int rem = n % base;
			n /= base;
			sum += rem * rem;
		}
		return sum;
	}

	private void solve() throws Exception {
		final int testN = nextInt();
		final HashMap<HashSet<Integer>, Integer> map = new HashMap<HashSet<Integer>, Integer>();
		
		final HashSet<Integer> full = new HashSet<Integer>();
		for (int i = 2; i <= 10; ++i) {
			full.add(i);
		}
		map.put(full, 11814485);
		
		for (int test = 1; test <= testN; ++test) {
			String s = reader.readLine();
			Scanner scanner = new Scanner(s);
			boolean[] need = new boolean[11];
			HashSet<Integer> bases = new HashSet<Integer>();
			while (scanner.hasNextInt()) {
				int x =scanner.nextInt(); 
				need[x] = true;
				bases.add(x);
			}
			
			printf("Case #%d: ", test);
			if (map.containsKey(bases)) {
				println(map.get(bases));
				continue;
			}
			
			int answer = -1;
			for (int n = 2; ;++n) {
				boolean allMatches = true;
				for (int base = 2; base <= 10; ++ base) {
					if (need[base]) {
						HashSet<Integer> set = new HashSet<Integer>();
						int x = n;
						while (!set.contains(x)) {
							set.add(x);
							x = getSumOfSquares(x, base);
						}
						if (x != 1) {
							allMatches = false;
							break;
						}
					}
				}
				if (allMatches) {
					answer = n;
					break;
				}
			}
			map.put(bases, answer);
			println(answer);
		}
	}

	public void run() {
		try {
			reader = new BufferedReader(new FileReader(TASKNAME + ".in"));
			writer = new PrintWriter(new BufferedWriter(new FileWriter(
					new File(TASKNAME + ".out"))));

			solve();

			reader.close();
			writer.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(13);
		}
	}

	private void print(Object o) {
		writer.print(o);
	}

	private void println(Object o) {
		writer.println(o);
	}

	private void printf(String format, Object... o) {
		writer.printf(format, o);
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	public static void main(String[] args) throws InterruptedException {
		final long startTime = System.currentTimeMillis();
		Locale.setDefault(Locale.US);
		final Thread thread = new Thread(new Main());
		thread.start();
		thread.join();
		System.err.printf("%.3f\n",
				(System.currentTimeMillis() - startTime) * 0.001);
	}

	private BufferedReader reader;
	private PrintWriter writer;
	private StringTokenizer tokenizer;
}
