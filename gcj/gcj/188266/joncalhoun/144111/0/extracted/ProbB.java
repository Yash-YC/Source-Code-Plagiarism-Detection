//Jon Calhoun
//joncalhoun@gmail.com

import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.io.*;

public class ProbB {
	int N;
	int R;
	int C;
	int S[][];
	int W[][];
	int T[][];
	int v[][];
	int memo[][];
	int MOD[][];
	int oo = 987654321;
	public void va() throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("ProbB.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("ProbB.out")));
		String split[] = in.readLine().split("[ ]+");


		N = Integer.parseInt(split[0]);

		for(int n = 1; n <= N; n++) {
			split = in.readLine().split("[ ]+");
			R = Integer.parseInt(split[0]);
			C = Integer.parseInt(split[1]);
			System.out.println(R + " " + C);
			S = new int[R][C];
			W = new int[R][C];
			T = new int[R][C];
			v = new int[R*2][C*2];
			memo = new int[R*2][C*2];
			MOD = new int[R][C];

			for(int i = 0; i < R*2; i++) {
				Arrays.fill(v[i], -1);
				Arrays.fill(memo[i], -1);
			}

			for(int i = 0; i < R; i++) {
				split = in.readLine().split("[ ]+");

				for(int j = 0; j < C; j++) {
					S[i][j] = Integer.parseInt(split[j*3]);
					W[i][j] = Integer.parseInt(split[j*3+1]);
					T[i][j] = Integer.parseInt(split[j*3+2]);
					//System.out.println(T[i][j]);
					MOD[i][j] = S[i][j] + W[i][j];
					T[i][j] = (T[i][j] % MOD[i][j]);
					//System.out.println(S[i][j] + " " + W[i][j] + " " + T[i][j] + " " + MOD[i][j]);
				}
			}
			//System.out.println(dfs(R*2-1, 0, 0));

			out.println("Case #" + n + ": " + dfs(R*2-1, 0, 0));
		}
		out.close();
	}
	public int dfs(int r, int c, int time) {
		//System.out.println(r + " " + c + " " + time);
		if(r == 0 && c == ((C*2)-1)) return 0;
		//System.out.println("TERST");
		if(r < 0 || r >= R*2 || c < 0 || c >= C*2) return oo;
		//System.out.println("TERST");
		if(v[r][c] != -1 && v[r][c] < time) return oo;
		//System.out.println("TERST");
		if(v[r][c] == time) return memo[r][c];
		memo[r][c] = oo;
		//System.out.println("TERST");
		v[r][c] = time;
		int rr = r/2;
		int cc = c/2;
		int wait = 0;
		int tt;

		//try going right
		boolean even = false;
		if(c%2 == 0) even = true;
		if(even) {
			tt = time%MOD[rr][cc];
			if(tt < T[rr][cc] || (tt >= (T[rr][cc] + S[rr][cc]) && tt < (T[rr][cc] + MOD[rr][cc]))) {
				wait = 0;
			} else {
				wait = T[rr][cc]+S[rr][cc] - tt;
			}
			memo[r][c] = Math.min(wait + 1 + dfs(r, c+1, time+wait+1), memo[r][c]);
		} else {
			memo[r][c] = Math.min(2 + dfs(r, c+1, time+2), memo[r][c]);
		}

		//try going left
		if(!even) {
			if(cc-1 >= 0) {
				cc--;
				tt = time%MOD[rr][cc];
				if(tt < T[rr][cc] || tt >= (T[rr][cc] + S[rr][cc])) {
					wait = 0;
				} else {
					wait = T[rr][cc] - tt + S[rr][cc];
				}
				memo[r][c] = Math.min(wait + 1 + dfs(r, c-1, time+wait+1), memo[r][c]);
				cc++;
			}
		}else {
			memo[r][c] = Math.min(2 + dfs(r, c-1, time+2), memo[r][c]);
		}

		even = false;
		if(r%2 == 0) even = true;
		//try going up
		if(even) {
			memo[r][c] = Math.min(2 + dfs(r-1, c, time+2), memo[r][c]);
		} else {
			wait = 0;
			if(rr >= 0) {
				//rr--;
				tt = time%MOD[rr][cc];
				if(tt >= T[rr][cc] && tt < (T[rr][cc] + S[rr][cc])) {
					wait = 0;
				} else {
					if(tt < T[rr][cc]) {
						wait = T[rr][cc] - tt;
					} else {
						wait = MOD[rr][cc] - tt + T[rr][cc];
					}
				}
				memo[r][c] = Math.min(wait + 1 + dfs(r-1, c, time + wait + 1), memo[r][c]);
				//rr++;
			}
		}

		//try going down
		if(!even) {
			memo[r][c] = Math.min(2 + dfs(r+1, c, time+2), memo[r][c]);
		} else {
			tt = time%MOD[rr][cc];
			if(tt >= T[rr][cc] && tt < (T[rr][cc] + S[rr][cc])) {
				wait = 0;
			} else {
				if(tt < T[rr][cc]) {
					wait = T[rr][cc] - tt;
				} else {
					wait = MOD[rr][cc] - tt + T[rr][cc];
				}
			}
			memo[r][c] = Math.min(wait + 1 + dfs(r+1, c, time + wait + 1), memo[r][c]);
		}
		//System.out.println(r + " " + c + " returning " + memo[r][c]);
		return memo[r][c];
	}

	public static void main(String[] argv) throws IOException {
		new ProbB().va();
	}
}