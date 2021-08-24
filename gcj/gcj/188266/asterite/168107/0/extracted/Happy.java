import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;


public class Happy {
	
	static class Pair {
		
		int number;
		int base;
		
		public Pair(int number, int base) {
			this.number = number;
			this.base = base;
		}
		
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + base;
			result = prime * result + number;
			return result;
		}
		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Pair other = (Pair) obj;
			if (base != other.base)
				return false;
			if (number != other.number)
				return false;
			return true;
		}
		
	}
	
	private static Map<Pair, Boolean> cache = new HashMap<Pair, Boolean>();
	
	public static String minHappy(String filename) throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader(filename));
		
		int lines = Integer.parseInt(reader.readLine());
		
		StringBuilder sb = new StringBuilder();
		
		for (int i = 0; i < lines; i++) {
			String line = reader.readLine();
			String[] splits = line.split(" ");
			int[] bases = new int[splits.length];
			for (int j = 0; j < splits.length; j++) {
				bases[j] = Integer.parseInt(splits[j]);
			}
			
			sb.append("Case #");
			sb.append(i + 1);
			sb.append(": ");
			sb.append(Happy.minHappy(bases));
			sb.append("\r\n");
		}
		
		reader.close();
		
		return sb.toString();
	}
	
	public static int minHappy(int ... bases) {
	mainLoop:
		for (int i = 2; true; i++) {
			for (int j = 0; j < bases.length; j++) {
				int base = bases[j];
				
				if (!isHappy(i, base)) {
					continue mainLoop;
				}
			}
			
			return i;
		}
	}
	
	public static boolean isHappy(int number, int base) {
		String str = toBase(number, base);
		
		Set<Integer> found = new HashSet<Integer>();
		found.add(number);
		
		while(true) {
			Boolean cached = cache.get(new Pair(number, base));
			if (cached != null)
				return cached;
			
			int sum = 0;
			for (int i = 0; i < str.length(); i++) {
				int d = (int)(str.charAt(i) - '0');
				sum += d * d;
			}
			
			if (sum == 1) {
				cache.put(new Pair(number, base), Boolean.TRUE);
				return true;
			}
			
			if (found.contains(sum)) {
				cache.put(new Pair(number, base), Boolean.FALSE);
				return false;
			}
			
			found.add(sum);
			
			str = toBase(sum, base);
		}
	}
	
	public static String toBase(int number, int base) {
		StringBuilder sb = new StringBuilder(10);
		
		while(number > 0) {
			int mod = number % base;
			sb.insert(0, mod);
			number /= base;
		}
		
		return sb.toString();
	}

}
