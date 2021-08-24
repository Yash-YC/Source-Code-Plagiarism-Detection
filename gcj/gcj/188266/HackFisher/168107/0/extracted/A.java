import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.HashSet;


public class A {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		solve("D:\\in\\A-example.in");
	}

	public static void solve(String path) throws Exception {
		PrintWriter writer = new PrintWriter(new FileOutputStream(new File("D:\\out\\A-out.text")));
		
		int line_count = 0;
		BufferedReader reader = new BufferedReader(new FileReader(new File(path)));
		
		String line_str;
		
		if((line_str = reader.readLine()) != null) {
			line_count = Integer.parseInt(line_str);
		}
		
		for (int i = 0; i < line_count; i ++) {
			if ((line_str = reader.readLine()) != null) {
				int min_num = 0;
				String[] bases = line_str.split(" ");
				int[] base_num = new int[bases.length];
				for (int k = 0; k < bases.length; k ++) {
					base_num[k] = Integer.parseInt(bases[k]);
				}
				
				for(int x = 2; ; x ++) {
					int k = 0;
					for (k = 0; k < base_num.length; k ++) {
						if (! isHappyNumber(x, base_num[k], new HashSet<Integer>())) {
							break;
						}
					}
					
					if (k >= base_num.length) {
						min_num = x;
						break;
					}
				}
				
				System.out.println("Case #" + (i + 1) + ": " + min_num);
				writer.println("Case #" + (i + 1) + ": " + min_num);
			}
		}
		
		writer.flush();
		writer.close();
	}
	
	protected static boolean isHappyNumber(int d, int base, java.util.HashSet<Integer> repeat_set) {
		int num = d;
		int sum = 0;
		while (num > 0) {
			int left = num % base;
			sum += left * left;
			num = num / base;
		}
		
		if (sum == 1) {
			return true;
		} else if (sum > 1 && ! repeat_set.contains(d)) {
			repeat_set.add(d);
			return isHappyNumber(sum, base, repeat_set);
		} else {
			return false;
		}
	}
}
