import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class A {
	
	private static boolean doit(int x, int base) {
		Set<Integer> set = new HashSet<Integer>();
		set.add(x);
		String num = Integer.toString(x, base);
		while(true) {
			// num => f(num) in decimal
			int fnum = 0;
			for(int i=0;i<num.length();++i) {
				fnum += (num.charAt(i)-'0')*(num.charAt(i)-'0');
			}
			if(set.contains(fnum))
				return false;
			set.add(fnum);
			if(fnum == 1)
				return true;
			num = Integer.toString(fnum, base);
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int e = 0, T;
		String tmp = sc.nextLine();
		T = Integer.parseInt(tmp);		
		for(int i=0;i<T;i++) {
			String line = sc.nextLine();
			List<Integer> bases = new ArrayList<Integer>();
			Scanner subsc = new Scanner(line);
			while(subsc.hasNext()) {
				bases.add(subsc.nextInt());
			}			
			int ans = 0;
			
			for(int x = 2;; x++) {
				boolean failed = false;
				for(int base : bases) {
					if(!doit(x, base)) {
						failed = true;
						break;
					}
				}
				if(!failed) {
					ans = x;
					break;
				}
			}
			
			
			System.out.format("Case #%d: %d\n",++e, ans);
		}
	}
}
