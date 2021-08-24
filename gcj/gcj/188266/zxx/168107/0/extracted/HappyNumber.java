package round1a;

import static java.lang.Integer.parseInt;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

public class HappyNumber {
	private static ArrayList<HashMap<Integer, Boolean>> mem;
	static {
		mem = new ArrayList<HashMap<Integer, Boolean>>();
		for (int base = 2; base <= 10; base++) {
			HashMap<Integer, Boolean> res = new HashMap<Integer, Boolean>();
			res.put(1, true);
			for (int i = 2; i < 100000; i++) {
				int num = i;
				int iter = 0;
				for (iter = 0; iter < 20; iter++) {
					String next = calc(num, base);
					int nn = parseInt(next, base);
					if (res.containsKey(nn) == false) {
						num = Integer.parseInt(next, base);
					} else {
						res.put(num, res.get(nn));
						break;
					}
				}
				if (iter == 20) {
					res.put(i, false);
				}
			}
			mem.add(res);
		}
	}

	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader("A-small-attempt1.in"));
			int n = parseInt(br.readLine());
			BufferedWriter bw = new BufferedWriter(new FileWriter("A-small-attempt1.out"));
			for (int i = 1; i <= n; i++) {
				String tmp[] = br.readLine().split(" ");
				int[] bases = new int[tmp.length];
				for (int j = 0; j < tmp.length; j++) {
					bases[j] = parseInt(tmp[j]);
				}
				for (int num = 2; num < 100000; num++) {
					boolean flag = true;
					for (int j = 0; j < tmp.length; j++) {
						int base = bases[j];
						if (isHappy(num, base) == false) {
							flag = false;
							break;
						}
					}
					if (flag) {
						bw.write("Case #" + i + ": " + num);
						if (i != n) {
							bw.write("\n");
						}
						break;
					}
				}

			}
			bw.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (NumberFormatException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static boolean isHappy(int num, int base) {
		try {
			return mem.get(base - 2).get(num);
		} catch (Exception e) {
			return false;
		}

	}

	private static String calc(int num, int base) {
		String s = Integer.toString(num, base);
		int res = 0;
		for (int i = 0; i < s.length(); i++) {
			int d = s.charAt(i) - '0';
			res += d * d;
		}
		return Integer.toString(res, base);
	}
}
