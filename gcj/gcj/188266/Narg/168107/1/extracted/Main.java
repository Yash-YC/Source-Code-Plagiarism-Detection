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
		
		for (int[] a : VALUES) {
			HashSet<Integer> bases = new HashSet<Integer>();
			for (int j = 0; j < a.length - 1; ++j) {
				bases.add(a[j]);
			}
			map.put(bases, a[a.length - 1]);
		}
		
//		for (int i = 0; i < (1 << 8); ++i) {
//			boolean[] b = new boolean[11];
//			HashSet<Integer> set = new HashSet<Integer>();
//			b[10] = true;
//			set.add(10);
//			print("{");
//			for (int j = 2; j < 10; ++j) {
//				if (((i >> (j - 2)) & 1) != 0) {
//					b[j] = true;
//					set.add(j);
//				}
//			}
//			for (int j = 0; j <= 10; ++j) {
//				if (b[j]) {
//					print(j + ", ");
//				}
//			}
//			writer.flush();
//			if (map.containsKey(set)) {
//				println(map.get(set) + "}, ");
//				continue;
//			}
//			processSet(map, b, set);
//		}
		
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
			processSet(map, need, bases);
		}
	}

	private void processSet(final HashMap<HashSet<Integer>, Integer> map,
			boolean[] need, HashSet<Integer> bases) {
		int answer = -1;
		for (int n = 2; ;++n) {
//			n = 11814485;
			if (n % 1000000 == 0) {
				System.err.println(bases + " " + n);
			}
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
		writer.flush();
	}
	
	private int[][] VALUES = new int[][] {{10, 7}, 
			{2, 10, 7}, 
			{3, 10, 13}, 
			{2, 3, 10, 13}, 
			{4, 10, 7}, 
			{2, 4, 10, 7}, 
			{3, 4, 10, 13}, 
			{2, 3, 4, 10, 13}, 
			{5, 10, 7}, 
			{2, 5, 10, 7}, 
			{3, 5, 10, 23}, 
			{2, 3, 5, 10, 23}, 
			{4, 5, 10, 7}, 
			{2, 4, 5, 10, 7}, 
			{3, 4, 5, 10, 23}, 
			{2, 3, 4, 5, 10, 23}, 
			{6, 10, 44}, 
			{2, 6, 10, 44}, 
			{3, 6, 10, 79}, 
			{2, 3, 6, 10, 79}, 
			{4, 6, 10, 44}, 
			{2, 4, 6, 10, 44}, 
			{3, 4, 6, 10, 79}, 
			{2, 3, 4, 6, 10, 79}, 
			{5, 6, 10, 49}, 
			{2, 5, 6, 10, 49}, 
			{3, 5, 6, 10, 79}, 
			{2, 3, 5, 6, 10, 79}, 
			{4, 5, 6, 10, 49}, 
			{2, 4, 5, 6, 10, 49}, 
			{3, 4, 5, 6, 10, 79}, 
			{2, 3, 4, 5, 6, 10, 79}, 
			{7, 10, 7}, 
			{2, 7, 10, 7}, 
			{3, 7, 10, 167}, 
			{2, 3, 7, 10, 167}, 
			{4, 7, 10, 7}, 
			{2, 4, 7, 10, 7}, 
			{3, 4, 7, 10, 167}, 
			{2, 3, 4, 7, 10, 167}, 
			{5, 7, 10, 7}, 
			{2, 5, 7, 10, 7}, 
			{3, 5, 7, 10, 7895}, 
			{2, 3, 5, 7, 10, 7895}, 
			{4, 5, 7, 10, 7}, 
			{2, 4, 5, 7, 10, 7}, 
			{3, 4, 5, 7, 10, 7895}, 
			{2, 3, 4, 5, 7, 10, 7895}, 
			{6, 7, 10, 49}, 
			{2, 6, 7, 10, 49}, 
			{3, 6, 7, 10, 6307}, 
			{2, 3, 6, 7, 10, 6307}, 
			{4, 6, 7, 10, 49}, 
			{2, 4, 6, 7, 10, 49}, 
			{3, 4, 6, 7, 10, 6307}, 
			{2, 3, 4, 6, 7, 10, 6307}, 
			{5, 6, 7, 10, 49}, 
			{2, 5, 6, 7, 10, 49}, 
			{3, 5, 6, 7, 10, 7895}, 
			{2, 3, 5, 6, 7, 10, 7895}, 
			{4, 5, 6, 7, 10, 49}, 
			{2, 4, 5, 6, 7, 10, 49}, 
			{3, 4, 5, 6, 7, 10, 7895}, 
			{2, 3, 4, 5, 6, 7, 10, 7895}, 
			{8, 10, 97}, 
			{2, 8, 10, 97}, 
			{3, 8, 10, 219}, 
			{2, 3, 8, 10, 219}, 
			{4, 8, 10, 97}, 
			{2, 4, 8, 10, 97}, 
			{3, 4, 8, 10, 219}, 
			{2, 3, 4, 8, 10, 219}, 
			{5, 8, 10, 219}, 
			{2, 5, 8, 10, 219}, 
			{3, 5, 8, 10, 219}, 
			{2, 3, 5, 8, 10, 219}, 
			{4, 5, 8, 10, 219}, 
			{2, 4, 5, 8, 10, 219}, 
			{3, 4, 5, 8, 10, 219}, 
			{2, 3, 4, 5, 8, 10, 219}, 
			{6, 8, 10, 608}, 
			{2, 6, 8, 10, 608}, 
			{3, 6, 8, 10, 3879}, 
			{2, 3, 6, 8, 10, 3879}, 
			{4, 6, 8, 10, 608}, 
			{2, 4, 6, 8, 10, 608}, 
			{3, 4, 6, 8, 10, 3879}, 
			{2, 3, 4, 6, 8, 10, 3879}, 
			{5, 6, 8, 10, 3879}, 
			{2, 5, 6, 8, 10, 3879}, 
			{3, 5, 6, 8, 10, 3879}, 
			{2, 3, 5, 6, 8, 10, 3879}, 
			{4, 5, 6, 8, 10, 3879}, 
			{2, 4, 5, 6, 8, 10, 3879}, 
			{3, 4, 5, 6, 8, 10, 3879}, 
			{2, 3, 4, 5, 6, 8, 10, 3879}, 
			{7, 8, 10, 34527}, 
			{2, 7, 8, 10, 34527}, 
			{3, 7, 8, 10, 48041}, 
			{2, 3, 7, 8, 10, 48041}, 
			{4, 7, 8, 10, 34527}, 
			{2, 4, 7, 8, 10, 34527}, 
			{3, 4, 7, 8, 10, 48041}, 
			{2, 3, 4, 7, 8, 10, 48041}, 
			{5, 7, 8, 10, 34527}, 
			{2, 5, 7, 8, 10, 34527}, 
			{3, 5, 7, 8, 10, 120407}, 
			{2, 3, 5, 7, 8, 10, 120407}, 
			{4, 5, 7, 8, 10, 34527}, 
			{2, 4, 5, 7, 8, 10, 34527}, 
			{3, 4, 5, 7, 8, 10, 120407}, 
			{2, 3, 4, 5, 7, 8, 10, 120407}, 
			{6, 7, 8, 10, 245035}, 
			{2, 6, 7, 8, 10, 245035}, 
			{3, 6, 7, 8, 10, 697563}, 
			{2, 3, 6, 7, 8, 10, 697563}, 
			{4, 6, 7, 8, 10, 245035}, 
			{2, 4, 6, 7, 8, 10, 245035}, 
			{3, 4, 6, 7, 8, 10, 697563}, 
			{2, 3, 4, 6, 7, 8, 10, 697563}, 
			{5, 6, 7, 8, 10, 245035}, 
			{2, 5, 6, 7, 8, 10, 245035}, 
			{3, 5, 6, 7, 8, 10, 2688153}, 
			{2, 3, 5, 6, 7, 8, 10, 2688153}, 
			{4, 5, 6, 7, 8, 10, 245035}, 
			{2, 4, 5, 6, 7, 8, 10, 245035}, 
			{3, 4, 5, 6, 7, 8, 10, 2688153}, 
			{2, 3, 4, 5, 6, 7, 8, 10, 2688153}, 
			{9, 10, 91}, 
			{2, 9, 10, 91}, 
			{3, 9, 10, 91}, 
			{2, 3, 9, 10, 91}, 
			{4, 9, 10, 91}, 
			{2, 4, 9, 10, 91}, 
			{3, 4, 9, 10, 91}, 
			{2, 3, 4, 9, 10, 91}, 
			{5, 9, 10, 91}, 
			{2, 5, 9, 10, 91}, 
			{3, 5, 9, 10, 91}, 
			{2, 3, 5, 9, 10, 91}, 
			{4, 5, 9, 10, 91}, 
			{2, 4, 5, 9, 10, 91}, 
			{3, 4, 5, 9, 10, 91}, 
			{2, 3, 4, 5, 9, 10, 91}, 
			{6, 9, 10, 1033}, 
			{2, 6, 9, 10, 1033}, 
			{3, 6, 9, 10, 6073}, 
			{2, 3, 6, 9, 10, 6073}, 
			{4, 6, 9, 10, 1033}, 
			{2, 4, 6, 9, 10, 1033}, 
			{3, 4, 6, 9, 10, 6073}, 
			{2, 3, 4, 6, 9, 10, 6073}, 
			{5, 6, 9, 10, 4577}, 
			{2, 5, 6, 9, 10, 4577}, 
			{3, 5, 6, 9, 10, 6073}, 
			{2, 3, 5, 6, 9, 10, 6073}, 
			{4, 5, 6, 9, 10, 4577}, 
			{2, 4, 5, 6, 9, 10, 4577}, 
			{3, 4, 5, 6, 9, 10, 6073}, 
			{2, 3, 4, 5, 6, 9, 10, 6073}, 
			{7, 9, 10, 1337}, 
			{2, 7, 9, 10, 1337}, 
			{3, 7, 9, 10, 1337}, 
			{2, 3, 7, 9, 10, 1337}, 
			{4, 7, 9, 10, 1337}, 
			{2, 4, 7, 9, 10, 1337}, 
			{3, 4, 7, 9, 10, 1337}, 
			{2, 3, 4, 7, 9, 10, 1337}, 
			{5, 7, 9, 10, 29913}, 
			{2, 5, 7, 9, 10, 29913}, 
			{3, 5, 7, 9, 10, 120149}, 
			{2, 3, 5, 7, 9, 10, 120149}, 
			{4, 5, 7, 9, 10, 29913}, 
			{2, 4, 5, 7, 9, 10, 29913}, 
			{3, 4, 5, 7, 9, 10, 120149}, 
			{2, 3, 4, 5, 7, 9, 10, 120149}, 
			{6, 7, 9, 10, 71735}, 
			{2, 6, 7, 9, 10, 71735}, 
			{3, 6, 7, 9, 10, 613479}, 
			{2, 3, 6, 7, 9, 10, 613479}, 
			{4, 6, 7, 9, 10, 71735}, 
			{2, 4, 6, 7, 9, 10, 71735}, 
			{3, 4, 6, 7, 9, 10, 613479}, 
			{2, 3, 4, 6, 7, 9, 10, 613479}, 
			{5, 6, 7, 9, 10, 218301}, 
			{2, 5, 6, 7, 9, 10, 218301}, 
			{3, 5, 6, 7, 9, 10, 711725}, 
			{2, 3, 5, 6, 7, 9, 10, 711725}, 
			{4, 5, 6, 7, 9, 10, 218301}, 
			{2, 4, 5, 6, 7, 9, 10, 218301}, 
			{3, 4, 5, 6, 7, 9, 10, 711725}, 
			{2, 3, 4, 5, 6, 7, 9, 10, 711725}, 
			{8, 9, 10, 1177}, 
			{2, 8, 9, 10, 1177}, 
			{3, 8, 9, 10, 1177}, 
			{2, 3, 8, 9, 10, 1177}, 
			{4, 8, 9, 10, 1177}, 
			{2, 4, 8, 9, 10, 1177}, 
			{3, 4, 8, 9, 10, 1177}, 
			{2, 3, 4, 8, 9, 10, 1177}, 
			{5, 8, 9, 10, 1177}, 
			{2, 5, 8, 9, 10, 1177}, 
			{3, 5, 8, 9, 10, 1177}, 
			{2, 3, 5, 8, 9, 10, 1177}, 
			{4, 5, 8, 9, 10, 1177}, 
			{2, 4, 5, 8, 9, 10, 1177}, 
			{3, 4, 5, 8, 9, 10, 1177}, 
			{2, 3, 4, 5, 8, 9, 10, 1177}, 
			{6, 8, 9, 10, 9867}, 
			{2, 6, 8, 9, 10, 9867}, 
			{3, 6, 8, 9, 10, 28099}, 
			{2, 3, 6, 8, 9, 10, 28099}, 
			{4, 6, 8, 9, 10, 9867}, 
			{2, 4, 6, 8, 9, 10, 9867}, 
			{3, 4, 6, 8, 9, 10, 28099}, 
			{2, 3, 4, 6, 8, 9, 10, 28099}, 
			{5, 6, 8, 9, 10, 28099}, 
			{2, 5, 6, 8, 9, 10, 28099}, 
			{3, 5, 6, 8, 9, 10, 28099}, 
			{2, 3, 5, 6, 8, 9, 10, 28099}, 
			{4, 5, 6, 8, 9, 10, 28099}, 
			{2, 4, 5, 6, 8, 9, 10, 28099}, 
			{3, 4, 5, 6, 8, 9, 10, 28099}, 
			{2, 3, 4, 5, 6, 8, 9, 10, 28099}, 
			{7, 8, 9, 10, 48041}, 
			{2, 7, 8, 9, 10, 48041}, 
			{3, 7, 8, 9, 10, 48041}, 
			{2, 3, 7, 8, 9, 10, 48041}, 
			{4, 7, 8, 9, 10, 48041}, 
			{2, 4, 7, 8, 9, 10, 48041}, 
			{3, 4, 7, 8, 9, 10, 48041}, 
			{2, 3, 4, 7, 8, 9, 10, 48041}, 
			{5, 7, 8, 9, 10, 246297}, 
			{2, 5, 7, 8, 9, 10, 246297}, 
			{3, 5, 7, 8, 9, 10, 346719}, 
			{2, 3, 5, 7, 8, 9, 10, 346719}, 
			{4, 5, 7, 8, 9, 10, 246297}, 
			{2, 4, 5, 7, 8, 9, 10, 246297}, 
			{3, 4, 5, 7, 8, 9, 10, 346719}, 
			{2, 3, 4, 5, 7, 8, 9, 10, 346719}, 
			{6, 7, 8, 9, 10, 2662657}, 
			{2, 6, 7, 8, 9, 10, 2662657}, 
			{3, 6, 7, 8, 9, 10, 4817803}, 
			{2, 3, 6, 7, 8, 9, 10, 4817803}, 
			{4, 6, 7, 8, 9, 10, 2662657}, 
			{2, 4, 6, 7, 8, 9, 10, 2662657}, 
			{3, 4, 6, 7, 8, 9, 10, 4817803}, 
			{2, 3, 4, 6, 7, 8, 9, 10, 4817803}, 
			{5, 6, 7, 8, 9, 10, 11814485}, 
			{2, 5, 6, 7, 8, 9, 10, 11814485}, 
			{3, 5, 6, 7, 8, 9, 10, 11814485}, 
			{2, 3, 5, 6, 7, 8, 9, 10, 11814485}, 
			{4, 5, 6, 7, 8, 9, 10, 11814485}, 
			{2, 4, 5, 6, 7, 8, 9, 10, 11814485}, 
			{3, 4, 5, 6, 7, 8, 9, 10, 11814485}, 
			{2, 3, 4, 5, 6, 7, 8, 9, 10, 11814485}};

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
