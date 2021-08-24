import java.io.*;
import java.util.*;


public class P1 {

	Scanner sc;
	PrintWriter pw;
	
	public void init() {
		sc.nextLine();
	}
	
	public int sumnums(int num, int base) {
		int sum = 0;
		while (num > 0) {
			sum = sum + (num % base) * (num % base);
			num = num / base;
		}
		return sum;
	}
	
	public boolean isPerfect(int num, int base) {
		boolean alma[];
		alma = new boolean[1000];
		Arrays.fill(alma, false);
		int sum = 0;
		do {			
		  if (sum == 1) {
			  return true;
		  }
		  alma[sum] = true;
		  sum = sumnums(num, base);
		  num = sum;
		} while (!alma[sum]);
		return false;
	}
	
	public void solvecase(long casenum) {
		int numbers[] = new int[501];
		int count = 0;
		for (String s : sc.nextLine().split(" ")) {
			numbers[count++] = Integer.parseInt(s);
		}
		boolean perfect;
		int i = 1;
		do {
			i++;
			perfect = true;
			for (int j=0; j< count; j++) {
				if (!isPerfect(i, numbers[j])) {
					perfect = false;
					break;
				}
			}
		} while (!perfect);
		pw.print(i);
		
	}
	
	public void solve() throws Exception {
	       sc = new Scanner(new FileReader("A-large.in"));
	       pw = new PrintWriter(new FileWriter("/dev/stdout"));
	       long cases = sc.nextLong();
	       init();
	       for (long casenum = 1; casenum <= cases; casenum++) {
	    	   pw.print("Case #" + casenum + ": ");
	    	   solvecase(casenum);
	    	   pw.println();
	    	   pw.flush();
	       }
	       sc.close();
	       pw.close();
	}
	
	
	public static void main(String[] args) {
		try {
           (new P1()).solve();
		   System.out.println("Program ended.");
		} catch (Exception e) {
			System.err.print("Exception: ");
			e.printStackTrace();
		}
	}

}
