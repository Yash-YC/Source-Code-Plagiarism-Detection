import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Oppa implements Runnable {
	public static void main(String[] args) throws IOException {
		new Thread(new Oppa()).start();
	}

	public void run() {
		try {
			run1();
		} catch (IOException e) {

		}
	}

	boolean[][] was;
	boolean[][] res;

	boolean ook(int a, int b, int j) {
		if(was[j][a]) return res[j][a];
		if (a == 1)
			return true;
		was[j][a] = true;
		int tmp = a;
		int tmp1 = 0;
		while (tmp > 0) {
			tmp1 += (tmp % b) * (tmp % b);
			tmp /= b;
		}
		if(ook(tmp1, b, j)) {
			res[j][a] = true;
			return true;
		}
		return false;
	}

	private void run1() throws IOException {
		Scanner sc = new Scanner(new FileReader("bonus.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("bonus.out"));
		int T = sc.nextInt();
		sc.nextLine();
		for (int tn = 1; tn <= T; tn++) {
			String[] s = sc.nextLine().split(" ");
			int[] b = new int[s.length];
			int n = s.length;
			for (int i = 0; i < b.length; i++) {
				b[i] = Integer.parseInt(s[i]);
			}
			int max = 100000;
			was = new boolean[n][max];
			res = new boolean[n][max];
			for (int i = 2; i < max; i++) {
				boolean ok = true;
				for (int j = 0; j < n; j++) {
					ok &= ook(i, b[j], j);
				}
				if (ok) {
					pw.printf("Case #%d: %d", tn, i);
					pw.println();
					break;
				}
			}
		}
		pw.close();
	}

	private int[] get(int[] cur, int[][][] next) {
		if (next[cur[0]][cur[1]][0] == cur[0]
				&& next[cur[0]][cur[1]][1] == cur[1]) {
			return cur;
		}
		return next[cur[0]][cur[1]] = get(next[cur[0]][cur[1]], next);
	}
}
