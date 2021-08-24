import java.util.Arrays;
import java.util.Scanner;

public class HappyNum {
	private static int[][] visited = new int[11][12000000];

	static int isHappy(int num, int base) {

		if (visited[base][num] != 0)
			return visited[base][num];
		int total = 0;
		int temp = num;
		while (temp > 0) {
			total += (temp % base) * (temp % base);
			temp = temp / base;
		}
		if (total == 1) {
			return visited[base][num] = 1;
		}
		visited[base][num] = -1;
		return visited[base][num] = isHappy(total, base);

	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		in.nextLine();
		for (int casenum = 1; casenum <= T; casenum++) {
			String[] bases = in.nextLine().split(" ");
			int[] base = new int[bases.length];
			for (int i = 0; i < bases.length; i++)
				base[i] = Integer.parseInt(bases[i]);
			int num = 2;
			for (int i = 0; i < 10; i++)
				Arrays.fill(visited[i], 0);
			while (true) {
				int res = 1;
				for (int i = 0; res > 0 && i < base.length; i++)
					res = isHappy(num, base[i]);
				if (res > 0) {
					System.out.printf("Case #%d: %d\n", casenum, num);
					break;
				}
				num++;
			}
		}
	}
}
