import java.io.*;
import java.util.*;

public class Main {
	static boolean[][] happy = new boolean[10000][11];

	public static void main(String[] arg) throws Throwable {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int i = 2; i != happy.length; ++i) for(int j = 2; j <= 10; ++j) isHappyMemo(i, j);
		int t = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= t; ++tc) {
			System.out.print("Case #" + tc + ": ");
			String[] bases = br.readLine().split(" ");
			int[] b = new int[bases.length];
			for(int i = 0; i != bases.length; ++i) b[i] = Integer.parseInt(bases[i]);
			for(int ans = 2; ; ++ans) {
//				if(ans % 1000 == 0) System.out.println("Trying " + ans);
				boolean g = true;
				for(int base: b) if(!isHappy(ans, base)) {
					g = false;
					break;
				}
				if(g) {
					System.out.println(ans);
					break;
				}
			}
		}
	}
	
	static boolean isHappy(int num, int base) {
		while(num >= happy.length) {
			char[] dig = Integer.toString(num, base).toCharArray();
			num = 0;
			for(char d: dig) {
				d -= '0';
				num += d * d;
			}
		}
		return happy[num][base];
	}
	
	static boolean isHappyMemo(int num, int base) {
		int numBak = num;
		HashSet<Integer> tried = new HashSet<Integer>();
		boolean works = false;
		for(;;) {
			if(tried.contains(num)) {
				works = false;
				break;
			}
			tried.add(num);
			char[] dig = Integer.toString(num, base).toCharArray();
			num = 0;
			for(char d: dig) {
				d -= '0';
				num += d * d;
			}
			if(num == 1) {
				works = true;
				break;
			}
		}
		happy[numBak][base] = works;
		return works;
	}
}
