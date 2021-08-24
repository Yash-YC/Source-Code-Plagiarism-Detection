import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class HappyNumbers {
	final static int MAX = 1000000; 
	private int base;
	private boolean computed[] = new boolean[MAX];
	private boolean happy[] = new boolean[MAX];
	public HappyNumbers(int base) {
		this.base = base;
		computed[1] = true;
		happy[1] = true;
	}
	public boolean isHappy(int n) {
		//System.err.println("isHappy(" + n + ") in base " + base);
		if (computed[n]) {
			return happy[n];
		} else {
			int rem = n;
			int sum = 0;
			while (rem != 0) {
				sum += (rem % base) * (rem % base);
				rem /= base;
			}
			computed[n] = true; // if loops, number is unhappy
			boolean ret = isHappy(sum);
			happy[n] = ret;
			return ret;
		}
	}
}

class Solver {
	static HappyNumbers[] happyNumbers = new HappyNumbers[11];
	{
		for (int i = 0; i < happyNumbers.length; i++) {
			happyNumbers[i] = new HappyNumbers(i);
		}
	}
	
	public Solver() {
	}

	public String solve(int[] bases) {
		for (int n = 2; ; n++) {
			boolean allHappy = true;
			for (int base : bases) {
				if (!happyNumbers[base].isHappy(n)) {
					allHappy = false;
					break;
				}
			}
			if (allHappy) {
				return Integer.toString(n);
			}
		}
	}

}

public class Main {

	private final static String FILE_NAME_BASE = "A-small-attempt0";

	public static void main(String[] args)
	throws IOException {
		String inputFileName = FILE_NAME_BASE + ".in";
		BufferedReader in = new BufferedReader(new FileReader(inputFileName));
		Scanner s = new Scanner(in);

		String outputFileName = FILE_NAME_BASE + ".out";
		BufferedWriter out = new BufferedWriter(new FileWriter(outputFileName));

		int numCases = s.nextInt(); s.nextLine();

		for (int cas = 0; cas < numCases; cas++) {
			List<String> basesStr = new ArrayList<String>();
			while (true) {
				String baseStr = s.findInLine("\\d+");
				if (baseStr == null) break;
				basesStr.add(baseStr);
			}
			s.nextLine();
			int[] bases = new int[basesStr.size()];
			for (int i = 0; i < bases.length; i++) {
				bases[i] = Integer.parseInt(basesStr.get(i));
			}
			String result = new Solver().solve(bases);
			out.write("Case #" + (cas + 1) + ": " + result + "\n");
		}
		
		out.close();
		in.close();
	}

}
