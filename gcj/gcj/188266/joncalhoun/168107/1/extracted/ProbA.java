//Jon Calhoun
//joncalhoun@gmail.com

import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.io.*;

public class ProbA {
	int N;
	public void solve() throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("ProbA.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("ProbA.out")));
		String split[] = in.readLine().split("[ ]+");
		int bases[];

		N = Integer.parseInt(split[0]);

		for(int n = 1; n <= N; n++) {
			split = in.readLine().split("[ ]+");
			bases = new int[split.length];
			for(int i = 0; i < bases.length; i++) {
				bases[i] = Integer.parseInt(split[i]);
			}
			int test = 2;
			boolean win = false;
			while(!win) {
				win = true;
				for(int i = 0; i < bases.length; i++) {
					win &= happy(test, bases[i]);
					if(!win) break;
				}
				test++;
			}
			test--;
			out.println("Case #" + n + ": " + test);
		}
		out.close();
	}
	public boolean happy(int num, int base) {
		ArrayList<Integer> dig = new ArrayList<Integer>();
		PriorityQueue<Integer> found = new PriorityQueue<Integer>();
		int next = num;
		int test = 0;

		while(!found.contains(next) && next != 1) {
			found.add(next);
			dig = new ArrayList<Integer>();
			num = next;
			next = 0;
			while(num > 0) {
				test = num%base;
				dig.add(test);
				num /= base;
			}
			for(int i = 0; i < dig.size(); i++) {
				next += dig.get(i)*dig.get(i);
			}
		}

		if(next == 1) return true;
		else return false;
	}

	public static void main(String[] argv) throws IOException {
		new ProbA().solve();
	}
}