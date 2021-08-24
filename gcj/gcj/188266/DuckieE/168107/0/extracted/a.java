import java.util.*;
import java.io.*;

public class a {
    
    public static void main(String[] args) throws Exception {
	BufferedReader in = new BufferedReader(new FileReader("a1.in"));
	//BufferedReader in = new BufferedReader(new FileReader("a2.txt"));
	int cases = Integer.parseInt(in.readLine());
	for (int u = 1; u <= cases; u++) {
	    System.out.print("Case #" + u + ": ");
	    String str = in.readLine();
	    String[] sa = str.split(" ");
	    int[] nums = new int[sa.length];
	    for (int i = 0; i < sa.length; i++)
		nums[i] = Integer.parseInt(sa[i]);
	    int n = 2;
	    boolean allHappy = true;
	    do {
		allHappy = true;
		for (int i = nums.length-1; i >= 0; i--) {
		    if (nums[i] == 2 || nums[i] == 4)
			continue;
		    if (!happy(n,nums[i])) {
			n++;
			allHappy = false;
			break;
		    }
		}
	    } while(!allHappy);
		System.out.println(n);
	}
    }

    public static boolean happy(int n, int base) {
	ArrayList<Integer> lst = new ArrayList<Integer>();
	int a = 0;
	while (true) {
	    while (n > 0) {
		int rem = n%base;
		a += rem*rem;
		n /= base;
	    }
	    if (a == 1)
		return true;
	    if (lst.contains(a))
		return false;
	    lst.add(a);
	    n = a;
	    a = 0;
	}
    }
}
