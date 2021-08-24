import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class A {
	public static void main(String[] args) {
		new A().run();
	}
	int N = 100000;
	void run() {
		ok = new int[11][N];
		for (int i = 2; i <= 10; i++) {
			fill(ok[i], -1);
			ok[i][1] = 1;
			for (int j = 2; j < N; j++) {
				ok(j, i);
			}
		}
		Scanner sc = new Scanner(System.in);
		int on = sc.nextInt();
		sc.nextLine();
		for (int o = 1; o <= on; o++) {
			System.out.printf("Case #%d: ", o);
			String[] ss = sc.nextLine().split(" ");
			int n = ss.length;
			int[] is = new int[n];
			for (int i = 0; i < n; i++) is[i] = Integer.parseInt(ss[i]);
			int i = 2;
			loop : for (;;i++) {
				for (int j = 0; j < n; j++) if (ok[is[j]][i] == 0) continue loop;
				break;
			}
			System.out.println(i);
		}
	}
	int[][] ok;
	int ok(int a, int d) {
		if (ok[d][a] >= 0) return ok[d][a];
		if (ok[d][a] == -2) return ok[d][a] = 0;
		ok[d][a] = -2;
		return ok[d][a] = ok(f(a, d), d);
	}
	int f(int a, int d) {
		int r = 0;
		for (char c : Integer.toString(a, d).toCharArray()) {
			r += (c - '0') * (c - '0');
		}
		return r;
	}
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
}
