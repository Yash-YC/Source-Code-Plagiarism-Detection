package round1a09;

import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class C {
	public static void main(String[] args) {
		new C().run(new Scanner(System.in));
	}
	
	void run(Scanner sc) {
		int n = sc.nextInt();
		for(int i = 1; n-- > 0; i++)
			solve(sc, i);
	}
	
	void solve(Scanner sc, int case_num) {
		int c = sc.nextInt();
		int n = sc.nextInt();
		double[] dp = new double[1 << c];
		dp[0] = 1;
		List<Integer> cards = new ArrayList<Integer>();
		int[] tmp = new int[c];
		for(int i = 0; i < n; i++) {
			tmp[c - i - 1] = 1;
		}
		for(int card = 1; card < 1 << c; card++) if(Integer.bitCount(card) == n) {
			cards.add(card);
		}
		double size = cards.size();
		double prob = 1 / size;
		double res = 0;
		
		for(int i = 1; i < 1000; i++) {
			double[] next = new double[1 << c];
			for(int j = 0; j < 1 << c; j++) {
				for(int card : cards) {
					next[j | card] += dp[j] * prob;
				}
			}
			res += i * next[(1 << c) - 1];
			dp = next;
			next[(1 << c) - 1] = 0;
		}
		
		System.out.printf("Case #%d: %.7f\n", case_num, res);
	}
}
