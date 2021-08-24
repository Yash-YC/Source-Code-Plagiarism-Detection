import java.io.File;
import java.io.FileWriter;
import java.util.PriorityQueue;
import java.util.Scanner;

public class B {

	static int[][] S;
	static int[][] W;
	static int[][] T;

	public static void main(String[] args) throws Exception {
//				String fileName = args.length > 0 ? args[0] : "bin\\B.txt";
		String fileName = args.length > 0 ? args[0] : "bin\\B-small-attempt0";
		Scanner sc;
		sc = new Scanner(new File(fileName + ".in"));
		FileWriter writer = new FileWriter(new File(fileName + ".out"));
		int C = sc.nextInt();
		for (int i = 0; i < C; ++i) {
			int N = sc.nextInt();
			int M = sc.nextInt();
			S = new int[N][M];
			W = new int[N][M];
			T = new int[N][M];
			for (int j = 0; j < N; ++j) {
				for (int k = 0; k < M; ++k) {
					S[j][k] = sc.nextInt();
					W[j][k] = sc.nextInt();
					T[j][k] = sc.nextInt() % (S[j][k]+ W[j][k]);
				}
			}
			int result = 0;
			boolean[][] visited = new boolean[2 * N][2 * M];
			PriorityQueue<State> q = new PriorityQueue<State>();
			q.add(new State(2 * N - 1, 0, 0));
			while (true) {
				State cur = q.poll();
				if (cur.r == 0 && cur.c == 2 * M - 1) {
					result = cur.t;
					break;
				}
				if (visited[cur.r][cur.c]) {
					continue;
				}
				visited[cur.r][cur.c] = true;
				if (cur.r % 2 == 0 && cur.r > 0 && !visited[cur.r - 1][cur.c]) {
					q.add(new State(cur.r - 1, cur.c, cur.t + 2));
				}
				if (cur.r % 2 == 1 && !visited[cur.r - 1][cur.c]) {
					q.add(new State(cur.r - 1, cur.c, nextNorth(cur)));
				}
				if (cur.c % 2 == 1 && cur.c < 2 * M - 1 && !visited[cur.r][cur.c + 1]) {
					q.add(new State(cur.r, cur.c + 1, cur.t + 2));
				}
				if (cur.c % 2 == 0 && !visited[cur.r][cur.c + 1]) {
					q.add(new State(cur.r, cur.c + 1, nextEast(cur)));
				}
			}
			writer.write("Case #" + (i + 1) + ": " + result + "\n");
		}
		writer.close();
	}

	static int nextNorth(State st) {
		int r = st.r / 2;
		int c = st.c / 2;
		int proc = (st.t + (S[r][c] + W[r][c]) - T[r][c]) % (S[r][c] + W[r][c]);
		if (proc < S[r][c]) {
			return st.t + 1;
		} else {
			return st.t + (S[r][c] + W[r][c] - proc) + 1;
		}
	}

	static int nextEast(State st) {
		int r = st.r / 2;
		int c = st.c / 2;
		int proc = (st.t + (S[r][c] + W[r][c]) - T[r][c]) % (S[r][c] + W[r][c]);
		if (proc >= S[r][c]) {
			return st.t + 1;
		} else {
			return st.t + (S[r][c] - proc) + 1;
		}

	}

	static class State implements Comparable<State> {
		int r;
		int c;
		int t;

		State(int r, int c, int t) {
			this.r = r;
			this.c = c;
			this.t = t;
		}

		public int compareTo(State o) {
			return this.t - o.t;
		}

	}

}
