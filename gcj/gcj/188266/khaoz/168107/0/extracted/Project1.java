import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Project1 {

	static Map<Integer, Integer> smallestForBase = new HashMap<Integer, Integer>();

	static Map<Integer, Map<Integer, Boolean>> isNumberHappy = new HashMap<Integer, Map<Integer, Boolean>>();

	static Map<Integer, Integer> smallestNum = new HashMap<Integer, Integer>();
	int smallest;

	public Project1(int[] bases) {
		smallest = 2;

		while (true) {
			TRY_NUM: {
				for (int i = 0; i < bases.length; i++) {
					if (!isNumHappy(smallest, bases[i])) {
						break TRY_NUM;
					}
				}
				return;
			}

			smallest++;
		}

	}

	public boolean isNumHappy(int numBase10, int base) {

		if (!isNumberHappy.containsKey(base)) {
			isNumberHappy.put(base, new HashMap<Integer, Boolean>());
		}

		if (isNumberHappy.get(base).containsKey(numBase10)) {
			return isNumberHappy.get(base).get(numBase10);
		}


		int squareSum = 0;
		int temp = numBase10;
		while (temp > 0) {
			int mod = temp % base;
			squareSum += mod*mod;
			temp = temp / base;
		}

		if (squareSum == 1) {
			isNumberHappy.get(base).put(numBase10, true);
			return true;
		} else {
			isNumberHappy.get(base).put(numBase10, false);

			boolean result = isNumHappy(squareSum, base);

			isNumberHappy.get(base).put(numBase10, result);
			return result;
		}

	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int n = scanner.nextInt();
		scanner.nextLine();

		for (int i = 0; i < n; i++) {
			String line = scanner.nextLine();
			String[] strBases = line.split(" ");
			int[] bases = new int[strBases.length];

			for (int j = 0; j < strBases.length; j++) {
				bases[j] = Integer.parseInt(strBases[j]);
			}
			Project1 solution = new Project1(bases);
			System.out.printf("Case #%d: %d\n", i + 1, solution.smallest);
		}

	}
}
