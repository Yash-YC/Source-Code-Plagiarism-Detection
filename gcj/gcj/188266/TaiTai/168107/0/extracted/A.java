package round1a09;

import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class A {
	static int Max = 20000000;
	
	public static void main(String[] args) {
		new A().run(new Scanner(System.in));
	}

	void run(Scanner sc) {
		int n = sc.nextInt();
		sc.nextLine();
		for(int i = 1; n-- > 0; i++)
			solve(sc, i);
	}

	void solve(Scanner sc, int case_num) {
		StringTokenizer st = new StringTokenizer(sc.nextLine());
		List<Integer> nums = new ArrayList<Integer>();
		while(st.hasMoreTokens()) {
			nums.add(Integer.parseInt(st.nextToken()));
		}
		System.out.printf("Case #%d: ", case_num);
		boolean res = false;
		a:for(int i = 2; i <= Max; i++) {
			for(int num : nums) {
				if(!cal2(i, num)) continue a;
			}
			System.out.println(i);
			res = true;
			break;
		}
	}
	
//	public static void main(String[] args) {
//		Scanner sc = new Scanner(System.in);
////		System.out.println(Integer.toString(sc.nextInt(), sc.nextInt()));
////		System.out.println(cal2(sc.nextInt(), sc.nextInt()));
//		
////		for(int i = 2; i < 4; i++) {
//		int i = sc.nextInt();
//			for(int j = 2; j < 200; j++) {
//				boolean res = cal2(j, i);
//				if(res)System.out.println(i+" "+j);
//			}
////		}
//	}
	
	static int[][] memo = new int[11][];
	
	static {
		for(int i = 2; i < 11; i++) {
			memo[i] = new int[Max];
			memo[i][1] = 1; memo[i][0] = 2;
		}
	}
	
	static boolean cal2(int num, int base) {
		if(memo[base][num] == 3) return false;
		if(memo[base][num] != 0) return memo[base][num] == 1;
		memo[base][num] = 3;
//		boolean[] check = new boolean[10000];
//		System.out.println(num+" "+base);
		int next = cal(num, base);
		boolean res = cal2(next, base);
		if(res) memo[base][num] = 1;
		else memo[base][num] = 2;
		return res;
//		check[num] = true;
//		while(num != 1) {
//			int next = cal(num, base);
//			System.out.println(next);
//			if(check[next]) return false;
//			check[next] = true;
//			num = next;
//		}
//		return true;
	}
	
	static int cal(int num, int base) {
		int sum = 0;
		while(num >= base) {
			int tmp = num % base;
			num /= base;
			sum += tmp * tmp;
		}
		return sum + num * num;
	}
}
