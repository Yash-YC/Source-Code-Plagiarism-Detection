import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;


public class MultiBaseHappiness {

	public static void main(String[] args) throws IOException {
		
		Scanner scn = new Scanner(new FileInputStream(args[0]));
		FileWriter writer = new FileWriter(
				args[0].substring(0, args[0].lastIndexOf('.') + 1) + "out");
		
		int cases = scn.nextInt();
		scn.nextLine();
		
		for (int i = 0; i < cases; i++) {
			String[] split = scn.nextLine().split(" ");
			List<Integer> bases = new ArrayList<Integer>();
			for (int j = 0; j < split.length; j++) {
				bases.add(Integer.valueOf(split[j]));
			}
			
			long leastHappy = 2;
			
			while (true) {
				
				boolean isHappy = true;
				
				for (Integer base : bases) {
					isHappy &= isHappy(base, leastHappy);
					if (!isHappy) {
						leastHappy++;
						break;
					}
				}
				
				if (isHappy) {
					break;
				}
			}
			
			writer.write("Case #" + (i+1) +": "  + leastHappy + "\n");
		}
		
		writer.close();
	}

	private static boolean isHappy(Integer base, long leastHappyInBase) {
		Set<Long> reachedHappy = new HashSet<Long>();
		
		long leastHappy = fromDec(leastHappyInBase, base);
		
		while (true) {
			
			long newReachedHappy = calcHappy(leastHappy, base);
			
			if (newReachedHappy == 1) {
				return true;
			}
			if (reachedHappy.contains(newReachedHappy)) {
				return false;
			}
			
			reachedHappy.add(newReachedHappy);
			leastHappy = newReachedHappy;
		}
		
	}
	
	private static long calcHappy(long number, int base) {
		long newHappy = 0;
		while (true) {
			if (number == 0) {
				break;
			}
			
			long mod = number % 10;
			newHappy += mod * mod;
			number /= 10;
		}
		return fromDec(newHappy, base);
	}
	
	private static long toDec(long number, int base) {
		long dec = 0;
		int exp = 0;
		while (true) {
			if (number == 0) {
				break;
			}
			
			long mod = number % 10;
			dec = (long) (mod * Math.pow(base, exp));
			number /= 10;
			exp++;
		}
		return dec;
	}
	
	private static long fromDec(long number, int base) {
		StringBuilder build = new StringBuilder();
		while (true) {
			if (number == 0) {
				break;
			}
			
			long mod = number % base;
			build.insert(0, mod);
			number /= base;
		}
		return Long.valueOf(build.toString());
	}
}
