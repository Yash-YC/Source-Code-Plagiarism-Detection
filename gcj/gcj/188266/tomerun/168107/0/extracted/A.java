import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class A {

	static int size = 1000000;
	static int[][] t = new int[9][size];

	public static void main(String[] args) throws Exception {
		String fileName = args.length > 0 ? args[0] : "bin\\A-small-attempt1";
		Scanner sc;
		sc = new Scanner(new File(fileName + ".in"));
		FileWriter writer = new FileWriter(new File(fileName + ".out"));

		for (int i = 2; i <= 10; ++i) {
			for (int j = 2; j < size; ++j) {
				t[i - 2][j] = happy(j, i);
			}
		}

		int n = sc.nextInt();
		sc.nextLine();
		for (int i = 0; i < n; ++i) {
			String[] bases = sc.nextLine().split(" ");
			int[] base = new int[bases.length];
			for (int j = 0; j < base.length; ++j) {
				base[j] = Integer.valueOf(bases[j]);
			}
			int result = 2;
			for (; result < size; ++result) {
				boolean found = true;
				for (int b : base) {
					if (t[b - 2][result] != 1) {
						found = false;
						break;
					}
				}
				if (found) {
					break;
				}
			}

			writer.write("Case #" + (i + 1) + ": " + result + "\n");
		}
		writer.close();
	}

	static int happy(int i, int base) {
		if (t[base - 2][i] != 0) {
			return t[base - 2][i];
		}
		t[base - 2][i] = -1;
		String str = Integer.toString(i, base);
		int result = 0;
		for (char c : str.toCharArray()) {
			result += (c - '0') * (c - '0');
		}
		if (result == 1) {
			t[base - 2][i] = 1;
			return 1;
		}
		t[base - 2][i] = happy(result, base);
		return t[base - 2][i];
		//		if (result <= start) {
		//			return t[base - 2][result];
		//		}
		//		return happy(result, base, start);
	}
}
