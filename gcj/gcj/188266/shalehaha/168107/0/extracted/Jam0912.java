import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Jam0912 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int cases = scanner.nextInt();
		StringBuffer sb = new StringBuffer();
		scanner.nextLine();
		for (int i = 0; i < cases; i++) {
			String line = scanner.nextLine();
			List<Integer> bases = new ArrayList<Integer>();
			while (line.length() > 0) {
				int index = line.indexOf(" ");
				if (index > 0) {
					bases.add(new Integer(line.substring(0, index)));
					line = line.substring(index + 1);
				} else {
					bases.add(new Integer(line));
					break;
				}
			}
			int num = 2;
			while (true) {
				boolean flag = true;
				for (int base : bases) {
					if (!isHappy(num, base,0)) {
						flag = false;
						break;
					}
				}
				if (flag) {
					sb.append("Case #").append(i + 1).append(": ").append(num)
							.append("\n");
					break;
				} else
					num++;
			}

		}
		System.out.println(sb.toString());
	}

	static boolean isHappy(int number, int base,int step) {
		if(step>100)
			return false;
		String numString = Integer.toString(number, base);
		int total = 0;
		for (int i = 0; i < numString.length(); i++) {
			int digit = numString.charAt(i)-48 ;
			total += digit * digit;
		}
		if (total != 1) {
			return isHappy(total, base,step+1);

		} else {
			if (total == number)
				return false;
			else 
				return true;
		}
		

	}
}
