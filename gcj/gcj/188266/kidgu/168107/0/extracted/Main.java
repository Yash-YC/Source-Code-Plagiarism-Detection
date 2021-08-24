import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	public static BufferedReader cin = new BufferedReader(
			new InputStreamReader(System.in));
	public static StringTokenizer tok = null;

	public static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(cin.readLine());
		}
		return tok.nextToken();
	}

	public static int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(next());
	}

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		FileInputStream fstream = new FileInputStream("A-small-attempt0.in");
		BufferedReader br = new BufferedReader(new InputStreamReader(fstream));

		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			StringTokenizer testCaseTok = new StringTokenizer(br.readLine());
			List<Integer> l = new ArrayList<Integer>();
			while (testCaseTok.hasMoreTokens()) {
				l.add(Integer.parseInt(testCaseTok.nextToken()));
			}
			for (int j = 2;; j++) {
				int numFound = 0;
				for (int j2 = 0; j2 < l.size(); j2++) {
					if (isHappy(j, l.get(j2))) {
						if (j2 == l.size() - 1) {
							numFound = j;
							System.out.println("Case #" + (i + 1) + ": "
									+ numFound);
						}
					} else {
						break;
					}
				}
				if (numFound != 0)
					break;
			}
		}
	}

	public static int changeFactor(int Num, int factor) {
		String temp = "";
		String temp1 = "";
		int num = Num;
		while ((num) >= 1) {
			temp += (num % factor);
			num = num / factor;
		}

		for (int i = temp.length() - 1; i >= 0; i--) {
			temp1 += temp.charAt(i);
		}

		return Integer.parseInt(temp1);
	}

	public static boolean isHappy(int num, int factor) {
		num = changeFactor(num, factor);
		String numString = num + "";
		int result = 0;
		boolean isHappy = false;
		for (int j = 0; j < 10; j++) {
			for (int i = 0; i < numString.length(); i++) {
				int numI = Integer.parseInt(numString.charAt(i) + "");
				result += numI * numI;
			}
			result = changeFactor(result, factor);
			if (result == 1) {
				isHappy = true;
				break;
			} else {
				numString = result + "";
				result = 0;
			}
		}
		return isHappy;
	}
}
