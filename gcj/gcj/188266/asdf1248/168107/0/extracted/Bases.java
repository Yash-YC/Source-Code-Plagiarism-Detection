import java.io.*;
import java.util.*;

public class Bases {
	// ON HOLD
	public static void main(String[] args) throws FileNotFoundException {
		InputStream is = new FileInputStream("A-small-attempt0.in"); 
		Scanner sc = new Scanner(is);
		int n = sc.nextInt();
		sc.nextLine();
		
		for (int i = 1; i <= n; i++) {
			System.out.println("Case #" + i + ": " + doStuff(sc.nextLine()));
		}
	}
	
	public static int doStuff(String line) {
		int number = 1;
		int count = 0;
		int[] arr = new int[9];
		for(int i = 0; i < arr.length; i++) {
			arr[i] = 0;
		}
		
		boolean stillGoing = true;
		while(stillGoing) {
			int a = Integer.parseInt(""+line.charAt(0));
			if (line.length() > 1 && line.charAt(1) == '0') {
				a *= 10;
			}
			arr[count] = a;
			count++;
			if (line.length() <= 2) {
				stillGoing = false;
			} else {
				line = line.substring(line.indexOf(' ')+1);
			}
		}
		
		boolean found = false;
		while(!found) {
			number++;
			found = true;
			for (int i = 0; i < count; i++) {
				found = found & happyNo(toBase(number, arr[i]), arr[i]);
			}
		}
		return number;
	}
	
	public static boolean happyNo(int num, int base) {
		// num starts in base 10
		int a = 0;
		int[] arr = new int[100];
		for(int i = 0; i < arr.length; i++) {
			arr[i] = 0;
		}
		
		boolean stillIn = true;
		boolean hn = false;
		int numToUse = num;
		while (stillIn) {
			int sum = 0;
			while (numToUse > 0) {
				sum = baseAdd(sum, baseSquare(numToUse%10, base), base);
				numToUse /= 10;
			}
			for(int i = 0; i < a-1; i++) {
				if (arr[i] == sum) {
					stillIn = false;
				}
			}
			arr[a] = sum;
			a++;
			if (a - 2 >= arr.length) {
				int[] brr = new int[a*2];
				for(int i = 0; i < a*2; i++) {
					brr[i] = arr[i];
				}
				arr = brr;
			}
			if (sum == 1) {
				stillIn = false;
				hn = true;
			}
			numToUse = sum;
		}
		
		return hn;
	}
	
	public static int toBase(int num, int base) {
		if (num == 0) return 0;

	       String digits = "0123456789";
	       String s = "";
	       while (num > 0) {
	          int d = num % base;
	          s = digits.charAt(d) + s;
	          num = num / base;
	       }
	       return Integer.parseInt(s);
	}
	
	static int fromBase(int num, int base) {
		String s = ""+num;
		int result = 0;
	       int digit = 0;
	       for (int i = 0; i < s.length(); i++) {
	          char c = s.charAt(i);
	          if (c >= '0' && c <= '9')
	             digit = c - '0';
	          else if (c >= 'A' && c <= 'Z')
	             digit = 10 + c - 'A';
	          else inputError(s);

	          if (digit < base) result = base * result + digit;
	          else inputError(s);
	       }
	       return result;
	}
	
	static void inputError(String s) {
        throw new RuntimeException("Input error with" + s);
    }
	
	static int baseSquare(int num, int base) {
		int nts = fromBase(num, base);
		int prod = nts * nts;
		return toBase(prod, base);
	}
	
	static int baseAdd(int a, int b, int base) {
		return toBase(fromBase(a, base) + fromBase(b, base), base);
	}
}
