import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Happy {
	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(System.in);

		int T = scanner.nextInt();
		scanner.nextLine();
		for (int i = 1; i <= T; i++) {
			String line = scanner.nextLine();
			Scanner bs = new Scanner(line);
			List<Integer> bases = new ArrayList<Integer>();
			while (bs.hasNext()) {
				bases.add(bs.nextInt());
			}

			int curr = 2;

			while (true) {
				boolean found = true;

				for (int base : bases) {
					if (!isHappy(curr, base)) {
						found = false;
						break;
					}
				}

				if (found) {
					System.out.printf("Case #%d: %d\n", i, curr);
					break;
				}
				curr++;
			}
		}
	}

	private static boolean isHappy(int number, int base) {
		if (base == 2)
			return true;
		Set<Integer> cycle = new HashSet<Integer>();
		while (number != 1 && !cycle.contains(number)) {
			cycle.add(number);
			int m = 0;
			while (number > 0) {
				int digit = (number % base);
				m += digit * digit;
				number /= base;
			}
			number = m;
		}
		return number == 1;
	}
}
