import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Scanner;

public class A {

	public static String decToBase(int decval, int base) {
		String res = "";
		while (decval > 0) {
			res = String.valueOf(decval % base) + res;
			decval /= base;
		}
		return res;
	}

	public static boolean isHappy(String val, int base) {
		HashSet<String> vals = new HashSet<String>();
		
		while (!val.equals("1") && !vals.contains(val)) {
			vals.add(val);
			
			int sqr = 0;
			for (int i = 0; i < val.length(); i++) {
				sqr += ((val.charAt(i) - '0') * (val.charAt(i) - '0'));
			}
			val = decToBase(sqr, base);
//			System.out.println(val);
		}
		
		return val.equals("1");
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(new InputStreamReader(System.in));
		int t = in.nextInt();
		in.nextLine();

		for (int x = 1; x <= t; x++) {
			String[] basestr = in.nextLine().split(" ");
			int[] bases = new int[basestr.length];
			for (int i = 0; i < basestr.length; i++)
				bases[i] = Integer.valueOf(basestr[i]);

			int i;
			for (i = 2; i < 100000000; i++) {
				boolean happy = true;
				for (int j = 0; j < bases.length; j++) {
					if (!isHappy(decToBase(i, bases[j]), bases[j])) {
						happy = false;
						break;
					}
				}
				if (happy) {
					break;
				}
			}

			System.out.printf("Case #%d: %d\n", x, i);
		}

	}

}
