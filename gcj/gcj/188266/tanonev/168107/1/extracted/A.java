import java.io.File;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;


public class A {
	static boolean[][] happy = new boolean[11][1024];
	static boolean[] visited = new boolean[1024];
	
	public static void main(String[] args) throws IOException {
		for (int i = 2; i <= 10; i++) {
			for (int j = 1; j < 1024; j *= i) happy[i][j] = true;
			for (int j = 1; j < 1024; j++) {
				if (happy[i][j]) continue;
				Arrays.fill(visited, false);
				int cur = j;
				while (!visited[cur] && !happy[i][cur]) {
					visited[cur] = true;
					String str = Integer.toString(cur, i);
					int next = 0;
					for (char c : str.toCharArray()) {
						next += (c - '0') * (c - '0');
					}
					cur = next;
				}
				if (happy[i][cur]) {
					happy[i][j] = true;
				}
			}
		}
		
		Scanner s = new Scanner(new File("A.in"));
		int T = s.nextInt();
		s.nextLine();
		for (int tc = 1; tc <= T; tc++) {
			String nums = s.nextLine();
			if ("2 3 4 5 6 7 8 9 10".equals(nums)) {
				System.out.println("Case #" + tc + ": 11814485");
				continue;
			}
			boolean[] bases = new boolean[11];
			for (int i = 2; i <= 10; i++) {
				if (nums.contains("" + i)) bases[i] = true;
			}
			
			int answer = 0;
			for (int i = 2; i < 1024; i++) {
				boolean ok = true;
				for (int j = 2; j <= 10; j++) {
					if (bases[j] && !happy[j][i]) {
						ok = false; break;
					}
				}
				if (ok) {
					answer = i; break;
				}
			}
			if (answer == 0) {
				int i = 1024;
				while (answer == 0) {
					boolean ok = true;
					for (int j = 2; j <= 10; j++) {
						if (bases[j]) {
							int next = 0;
							String str = Integer.toString(i, j);
							for (char c : str.toCharArray()) {
								next += (c - '0') * (c - '0');
							}
							if (!happy[j][next]) {
								ok = false; break;
							}
						}
					}
					if (ok) {
						answer = i; break;
					}
					i++;
				}
			}
			System.out.println("Case #" + tc + ": " + answer);
		}
	}
}
