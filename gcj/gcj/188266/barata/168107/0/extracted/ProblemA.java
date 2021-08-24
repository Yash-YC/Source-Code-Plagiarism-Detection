package round1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

public class ProblemA {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int t = Integer.parseInt(br.readLine());
		
		for (int g = 1; g <= t; g++) {
			StringTokenizer tks = new StringTokenizer(br.readLine());
			List<Integer> bases = new LinkedList<Integer>();
			
			while (tks.hasMoreTokens()) {
				bases.add(new Integer(tks.nextToken()));
			}
			
			int result = bases.get(0);
			
			while (true) {
				boolean failed = false;
				
				for (Integer b : bases) {
					String s = Integer.toString(result, b);
//System.out.println("ver "+result+" in base "+b+":"+s+"|"+happy(s, b));
					if (!happy(s, b)) {
						failed = true;
						break;
					}
				}
				
				if (!failed) break;
				else result++;
			}
			
			System.out.println("Case #" + g + ": " + result);
		}
	}

	static boolean happy(String s, int b) {
		Set<String> used = new HashSet<String>();
		used.add(s);
		
		long sum;
		do {
//System.out.println(s);
			sum = 0;
			for (int i = 0; i < s.length(); i++) {
				int digit = Integer.parseInt(String.valueOf(s.charAt(i)), b);
				sum += digit * digit;
			}
			s = Long.toString(sum, b);
			if (!used.add(s)) return false;
		} while (sum != 1);
		
		return true;
	}

}
