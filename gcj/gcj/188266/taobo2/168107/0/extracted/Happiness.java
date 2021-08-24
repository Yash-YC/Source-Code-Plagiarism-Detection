import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Happiness {
	static int[] bases;

	static boolean isHappy(long n, int b) {
		Set<Long> set = new HashSet<Long>();
		do {
			int ret = 0;
			while (n > 0) {
				long t = n % b;
				ret += t * t;
				n /= b;
			}
			if (ret == 1)
				return true;
			if (set.contains(Integer.valueOf(ret).longValue()))
				return false;
			set.add(Integer.valueOf(ret).longValue());
			n = ret;
		} while (true);
	}

	static boolean allHappy(long n) {
		boolean ret = true;
		for (int base : bases) {
			ret &= isHappy(n, base);
		}
		return ret;
	}

	static long min() {
		long i = 2;
		for (; !allHappy(i); i++)
			;
		return i;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		String input = "G:/chrome_download/A-small-attempt0.in";
		Scanner scan = new Scanner(new BufferedReader(new FileReader(input)));

		String output = "D:/temp/out1.txt";
		 PrintWriter out=new PrintWriter(new BufferedWriter(new
		 FileWriter(output)));
//		PrintWriter out = new PrintWriter(System.out);

		int T = scan.nextInt();
		for (int i = 1; i <= T;) {
			String line = scan.nextLine().trim();
			if ("".equals(line))
				continue;
			String[] tb = line.split(" ");
			bases = new int[tb.length];
			for (int j = 0; j < tb.length; j++) {
				bases[j] = Integer.parseInt(tb[j]);
			}
			long ret = min();
			out.println("Case #" + i + ": " + ret);
			i++;
		}

		scan.close();
		out.close();
	}

}
