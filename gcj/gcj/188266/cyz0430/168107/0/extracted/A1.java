import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class A1 {

	public static void main(String[] args) throws Exception {
		reader = new BufferedReader(new InputStreamReader(System.in));
		st = new StringTokenizer(reader.readLine());
		int t = Integer.parseInt(st.nextToken()), c = 1;
		int a[] = new int[100], b[] = new int[100], cnt, sum;
		boolean valid, used[] = new boolean[100000];
		while (t-- > 0) {
			st = new StringTokenizer(reader.readLine());
			cnt = 0;
			while (st.hasMoreTokens()) {
				a[cnt++] = Integer.parseInt(st.nextToken());
			}
			for (int i = 2;; i++) {
				valid = true;
				for (int j = 0; j < cnt; j++) {
					int tmp = i;
					sum = i;
					Arrays.fill(used, false);
					used[i] = true;
					while (sum != 1) {
						tmp = sum;
						sum = 0;
						int k = 0;
						while (tmp > 0) {
							b[k] = tmp % a[j];
							b[k] *= b[k];
							sum += b[k];
							k++;
							tmp /= a[j];
						}
						if (used[sum]) {
							valid = false;
							break;
						}
						used[sum] = true;
					}
					if (!valid)
						break;
				}
				if (valid) {
					System.out.println("Case #" + c++ + ": " + i);
					break;
				}
			}
		}

	}

	static StringTokenizer st;
	static BufferedReader reader;
	static String line;
	static double eps = 1e-9;
	static double PI = Math.atan2(0, -1.0);

}
