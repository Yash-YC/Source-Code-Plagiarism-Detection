package q1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Set;
import java.util.TreeSet;

public class MultibaseHappiness {

	boolean isHappy(int n, int radix, Set<Integer> set) {
		int sum = n;
		set = new TreeSet<Integer>();
		while (!set.contains(sum)) {
			set.add(sum);
			String s = Integer.toString(sum, radix);
			sum = 0;
			for (char ch : s.toCharArray()) {
				int i = ch - '0';
				sum += i * i;
			}
		}
		if (sum == 1)
			return true;
		return false;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		MultibaseHappiness m = new MultibaseHappiness();

		try {
			
			BufferedReader reader = new BufferedReader(new FileReader(args[0]));
			String line = null;
			line = reader.readLine();
			int testCount = Integer.parseInt(line);
			
			for (int i=1; i<=testCount; i++) {
				line = reader.readLine();
				String[] radixStrs = line.split(" ");
				int[] radixes = new int[radixStrs.length];
				for (int j=0; j<radixes.length; j++) {
					radixes[j] = Integer.parseInt(radixStrs[j]);
				}
				
				for (int j=2; j<1000000; j++) {
					boolean happy = true;
					for (int k=0; k<radixes.length; k++) {
						if (!m.isHappy(j, radixes[k], null)) {
							happy = false;
							break;
						}
					}
					if (happy) {
						System.out.print("Case #");
						System.out.print(i);
						System.out.print(": ");
						System.out.println(j);
						break;
					}
				}
			}
			reader.close();
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

}
