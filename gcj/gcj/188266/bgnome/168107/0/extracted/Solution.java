import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Solution {

	public void process(Scanner scan) {
		int T, i;
		ArrayList<Integer> list;
		String line;
		StringTokenizer tokenizer;
		MultiBaseHappiness solver = new MultiBaseHappiness();
		PrintWriter writer = null;

		try {
			writer = new PrintWriter(new FileOutputStream(
					new File("output.txt")));
			T = scan.nextInt();
			scan.nextLine();
			for (i = 0; i < T; ++i) {
				line = scan.nextLine();
				list = new ArrayList<Integer>();
				tokenizer = new StringTokenizer(line);
				while (tokenizer.hasMoreTokens()) {
					list.add(Integer.parseInt(tokenizer.nextToken()));
				}
				writer.format("Case #%d: %d\n", i + 1, solver
						.getMinimalHappyNumber(list));
				writer.flush();
			}
			writer.flush();
			writer.close();
		}
		catch (NumberFormatException e) {
		}
		catch (FileNotFoundException e) {
		}

	}

	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		Solution solution = new Solution();
		solution.process(scan);
		scan.close();
	}
}

class MultiBaseHappiness {

	private int nextHappy(int number, int base) {
		int result, tmp, digit;

		result = 0;
		while (number >= 1) {
			tmp = number / base;
			digit = number - tmp * base;
			result += digit * digit;
			number = tmp;
		}
		return result;
	}

	public int getMinimalHappyNumber(ArrayList<Integer> baseList) {
		int i, j, max, size;
		char[] color;
		int next, cur;
		Set<Integer> tmpSet = new TreeSet<Integer>();
		size = baseList.size();
		max = 100000;
		color = new char[max];
		color[1] = 1;
		for (i = 2; i < max; ++i) {
			tmpSet.clear();
			tmpSet.add(i);
			cur = i;
			while (true) {
				tmpSet.add(cur);
				next = nextHappy(cur, baseList.get(size - 1));
				if (tmpSet.contains(next)) {
					break;
				}
				cur = next;
			}
			if (tmpSet.contains(1)) {
				for (Integer iter : tmpSet) {
					color[iter] = 1;
				}
			}
		}
		for (i = 2; i < max; ++i) {
			if (color[i] == 1) {
				for (j = 0; j < size - 1; ++j) {
					cur = i;
					tmpSet.clear();
					tmpSet.add(cur);
					while (true) {
						tmpSet.add(cur);
						next = nextHappy(cur, baseList.get(j));
						if (tmpSet.contains(next)) {
							break;
						}
						cur = next;
					}
					if (!tmpSet.contains(1)) {
						break;
					}
				}
				if (j == size - 1) {
					return i;
				}
			}
		}

		return 0;
	}
}