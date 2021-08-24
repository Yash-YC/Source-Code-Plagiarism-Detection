import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;

public class Crossing {
	static int C, N, M;
	static int[][] S, W, T;

	static long nextEastCross(long currenttime, int n, int m) {
		long modtime = currenttime % (S[n][m] + W[n][m]);
		while (modtime < T[n][m])
			modtime += S[n][m] + W[n][m];
		if (modtime >= T[n][m] + S[n][m]) {
			return currenttime;
		} else {
			return currenttime - modtime + T[n][m] + S[n][m];
		}
	}

	static long nextNorthCross(long currenttime, int n, int m) {
		long modtime = currenttime % (S[n][m] + W[n][m]);
		while (modtime < T[n][m])
			modtime += S[n][m] + W[n][m];
		if (modtime < T[n][m] + S[n][m]) {
			return currenttime;
		} else {
			return currenttime - modtime + T[n][m] + S[n][m] + W[n][m];
		}
	}

	static long calc() {
		long[][] timemap = new long[2 * N][2 * M];
		timemap[0][0] = 0;
		for (int n = 0; n < N; n++) {
			if (n > 0)
				timemap[2 * n][0] = timemap[2 * n - 1][0] + 2;
			timemap[2 * n + 1][0] = nextNorthCross(timemap[2 * n][0], n, 0) + 1;
		}

		for (int m = 0; m < M; m++) {
			if (m > 0)
				timemap[0][2 * m] = timemap[0][2 * m - 1] + 2;
			timemap[0][2 * m + 1] = nextEastCross(timemap[0][2 * m], 0, m) + 1;
		}
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				if (n > 0 && m > 0) {
					timemap[2 * n][2 * m] = Math.min(timemap[2 * n][2 * m - 1],
							timemap[2 * n - 1][2 * m]) + 2;
				}
				if (n > 0) {
					timemap[2 * n][2 * m + 1] = Math.min(nextEastCross(
							timemap[2 * n][2 * m], n, m) + 1,
							timemap[2 * n - 1][2 * m + 1] + 2);
				}
				if (m > 0) {
					timemap[2 * n + 1][2 * m] = Math.min(nextNorthCross(
							timemap[2 * n][2 * m], n, m) + 1,
							timemap[2 * n + 1][2 * m - 1] + 2);
				}
				{
					timemap[2 * n + 1][2 * m + 1] = Math
							.min(
									nextEastCross(timemap[2 * n + 1][2 * m], n,
											m) + 1,
									nextNorthCross(timemap[2 * n][2 * m + 1],
											n, m) + 1);
				}
			}
		}
		return timemap[2 * N - 1][2 * M - 1];
	}

	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(
					"C:\\Documents and Settings\\Anqi Cui\\Desktop\\B-small-attempt0.in"));
			BufferedWriter bw = new BufferedWriter(
					new FileWriter(
							"C:\\Documents and Settings\\Anqi Cui\\Desktop\\output.txt"));

			String line = br.readLine();
			C = Integer.parseInt(line);

			for (int c = 0; c < C; c++) {
				line = br.readLine().trim();
				String[] temparr = line.split(" ");
				N = Integer.parseInt(temparr[0]);
				M = Integer.parseInt(temparr[1]);
				S = new int[N][M];
				W = new int[N][M];
				T = new int[N][M];
				for (int n = 0; n < N; n++) {
					line = br.readLine().trim();
					temparr = line.split(" ");
					for (int m = 0; m < M; m++) {
						S[n][m] = Integer.parseInt(temparr[m * 3]);
						W[n][m] = Integer.parseInt(temparr[m * 3 + 1]);
						T[n][m] = Integer.parseInt(temparr[m * 3 + 2]);
						T[n][m] = T[n][m] % (S[n][m] + W[n][m]);
					}
				}
				long time = calc();
				bw.write("Case #" + (c + 1) + ": " + time);
				bw.newLine();
			}
			br.close();
			bw.close();
		} catch (FileNotFoundException fnfe) {
			fnfe.printStackTrace();
		} catch (IOException ioe) {
			ioe.printStackTrace();
		}

	}

}
