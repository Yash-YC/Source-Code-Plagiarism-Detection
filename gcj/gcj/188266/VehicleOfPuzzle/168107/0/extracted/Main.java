import java.io.*;
import java.util.*;

public class Main {
	static List<HashSet<Integer>> evil = new ArrayList<HashSet<Integer>>();

	public static void main(String[] arg) throws Throwable {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int i = 0; i <= 10; ++i) evil.add(new HashSet<Integer>());
		int t = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= t; ++tc) {
			System.out.print("Case #" + tc + ": ");
			String[] bases = br.readLine().split(" ");
			int[] b = new int[bases.length];
			for(int i = 0; i != bases.length; ++i) b[i] = Integer.parseInt(bases[i]);
			for(int ans = 2; ; ++ans) {
				boolean good = true;
				for(int base: b) if(!isHappy(ans, base)) {
					good = false;
					break;
				}
				if(good) {
					System.out.println(ans);
					break;
				}
			}
		}
	}
	
	static boolean isHappy(int num, int base) {
		if(evil.get(base).contains(num)) return false;
		HashSet<Integer> tried = new HashSet<Integer>();
		for(;;) {
			if(tried.contains(num)) {
				for(Integer bad: tried) evil.get(base).add(bad);
				return false;
			}
			tried.add(num);
			char[] dig = Integer.toString(num, base).toCharArray();
			num = 0;
			for(char d: dig) {
				d -= '0';
				num += d * d;
			}
			if(num == 1) return true;
		}
	}
}
