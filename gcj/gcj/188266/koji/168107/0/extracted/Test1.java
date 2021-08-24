import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class Test1 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new FileReader("in.txt"));

		int line = Integer.parseInt(br.readLine());

		for (int i = 1; i <= line; ++i) {
			String temp = br.readLine();
			solve(i, temp.split(" "));
		}

	}

	private static void solve(int index, String[] split) {
		int number = 2;

		while (true) {
			boolean flag = true;
			for (int i = 0; i < split.length; i++) {
				String radixStr = BigInteger.valueOf(number).toString(Integer.parseInt(split[i]));
				boolean ok = innerResolve(radixStr, Integer.parseInt(split[i]));
				if (!ok) {
					flag = false;
					break;
				}
			}
			if (flag) {
				System.out.println("Case #"+index+": "+number);
				break;
			}
			number++;
		}

	}

	private static boolean innerResolve(String radixStr, int parseInt) {
		List<Long> cache = new ArrayList<Long>();
		while (true) {
			long sum = 0;
			for (int i = 0; i < radixStr.length(); ++i) {
				char temp = radixStr.charAt(i);
				int temp_i = temp - 48;
				sum = sum+temp_i * temp_i;
			}
			if (sum != 1) {
				if (cache.contains(sum)) {
					return false;
				} else {
					cache.add(sum);
					radixStr = BigInteger.valueOf(sum).toString(parseInt);
				}
			} else {
				return true;
			}
		}
	}

}
