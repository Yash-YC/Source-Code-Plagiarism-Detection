package pku;

import java.io.FileInputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class Happiness {

	static final int MAX = 500000;

	static int makeHappy(int i, int base) {
		int result = 0;
		while (i > 0) {
			int temp = (i % base);
			result += temp * temp;
			i /= base;
		}
		return result;
	}

	boolean isHappy(int i, int base) {
		HashSet<Integer> history = new HashSet<Integer>();
		while (true) {
			if (i == 1)
				return true;
			if (allSet[base].contains(i))
				return true;
			int j = makeHappy(i, base);
			if (history.contains(j))
				return false;
			if (j == i)
				return false;
			else
				i = j;
			history.add(i);
		}
	}

	HashSet<Integer>[] allSet = new HashSet[11];

	public Happiness() {
		for (int i = 2; i < 11; i++) {
			allSet[i] = new HashSet<Integer>();
			for (int j = 2; j < MAX; j++) {
				if (isHappy(j, i))
					allSet[i].add(j);
			}
			// System.out.print(i + "\t:");
			// System.out.println(allSet[i]);
		}
	}

	int getMin(ArrayList<Integer> bases) {
		for (int i = 2; i < MAX; i++) {
			boolean flag = true;
			for (int j = 0; j < bases.size(); j++) {
				int b = bases.get(j);
				if (!allSet[b].contains(i)) {
					flag = false;
					break;
				}
			}
			if (flag)
				return i;
		}
		return 0;
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		// System.out.println(makeHappy(82, 10));
		// System.out.println(isHappy(82, 10));
		// System.out.println(isHappy(82, 3));

		Happiness h = new Happiness();

		FileInputStream fis = new FileInputStream("A-large.in");
		PrintWriter pw = new PrintWriter("A-large.out");
		Scanner s = new Scanner(fis);
		int kk = s.nextInt();
		s.nextLine();
		for (int i = 0; i < kk; i++) {
			Scanner ss = new Scanner(s.nextLine());
			ArrayList<Integer> arrayInt = new ArrayList<Integer>();
			try {
				while (true)
					arrayInt.add(ss.nextInt());
			} catch (Exception ex) {

			}
			System.out.println(arrayInt);
			int result = h.getMin(arrayInt);
			System.out.println(result);
			pw.print("Case #" + (i + 1) + ": ");
			pw.println(result);
			pw.flush();
		}

//		System.out.println(Integer.toString(2753, 9));
		pw.close();
	}

}
