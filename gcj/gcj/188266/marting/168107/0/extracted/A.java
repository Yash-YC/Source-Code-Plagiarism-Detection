import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;


public class A {	
	static int calc(int [] bases) {
		int res = 2;
		final boolean B[] = new boolean[5000];
		for (; ; res++) {
			boolean ok = true;
			for (int b : bases) {
				Arrays.fill(B, false);
				int r = res;
				for (;;) {
					int r1 = 0;
					for (; r > 0; r /= b)
						r1 += (r % b)*(r % b);
					if (r1 == 1 || B[r1] || r1 == res) {
						r = r1;
						break;
					}
					B[r1] = true;
					r = r1;
				}
				if (r != 1) {
					ok = false;
					break;
				}
			}
			if (ok)
				return res;
		}
	}

	public static void main(String[] args) throws Exception {
		/*List<Integer> R[] = new List[11];
		for (int b=2; b<=10; b++) {
			R[b] = new ArrayList<Integer>();
			boolean B[] = new boolean[5000];
			for (int res = 2; res < 10000; res++) {
				Arrays.fill(B, false);
				int r = res;
				for (;;) {
					int r1 = 0;
					for (; r > 0; r /= b)
						r1 += (r % b)*(r % b);
					if (r1 == 1) {
						System.out.println(res);
						break;
					}
					if (B[r1] || r1 == res) break;
					B[r1] = true;
					r = r1;
				}
			}
		}*/
		
		Scanner cin = new Scanner(new File("a.in"));
		PrintWriter cout = new PrintWriter(new File("a.out"));
		int T = cin.nextInt();
		cin.nextLine();
		int bases[] = new int[10];
		for (int I=0; I<T; I++) {
			String s = cin.nextLine();
			StringTokenizer st = new StringTokenizer(s);
			int n = 0;
			while (st.hasMoreElements()) {
				bases[n++] = Integer.valueOf( st.nextToken() );
			}
			int res = calc(Arrays.copyOf(bases, n));
			cout.format("Case #%d: %d\n", I+1, res);
		}
		
		cout.close();
	}
}
