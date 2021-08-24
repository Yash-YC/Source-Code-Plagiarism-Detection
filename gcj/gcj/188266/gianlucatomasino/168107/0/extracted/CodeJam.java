import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class CodeJam {

	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader(args[0]));
		BufferedWriter writer = new BufferedWriter(new FileWriter(args[1]));

		int t = Integer.valueOf(reader.readLine());

		for (int cases = 0; cases < t; cases++) {
			String bases[] = reader.readLine().split(" ");

			int start = 2;
			int start2 = 2;
			int index = 0;

			while (index < bases.length) {
				start2 = findHappy(start, Integer.valueOf(bases[index]));
				if (start2 == start)
					index++;
				else {
					start = start2;
					index = 0;
				}
			}
			writer.write("Case #" + (cases+1) + ": " 
					+start +"\n");
			writer.flush();
		}
	}

	public static int findHappy(int start, int radix) {
		while (!isHappy(start, radix))
			start++;

		return start;
	}

	public static boolean isHappy(int num, int radix) {
		String number = String.valueOf(Integer.toString(num, radix));
		List<Integer> nums = new ArrayList<Integer>();
		
		int happy = 0;
		while (true) {
			for (int i = 0; i < number.length(); i++) {
				int molt = Integer.valueOf("" + number.charAt(i))
						* Integer.valueOf("" + number.charAt(i));
				
				happy += molt;
			}
			if (happy == 1)
				return true;
			
			happy = Integer.parseInt(Integer.toString(happy, radix));
		
			number = String.valueOf(happy);
			if (nums.contains(happy))
				return false;
			
			nums.add(happy);
			happy = 0;
		}
	}

}
