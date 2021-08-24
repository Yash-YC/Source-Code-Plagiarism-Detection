import java.io.*;
import java.util.*;


public class Txxxx {
	
	Scanner in;
	PrintWriter out;
	
	static final String problem = "multi";
	boolean []used = new boolean[50000];
	
	boolean isCorrect(int x, int base){
		if (x == 1){
			return true;
		}
		Arrays.fill(used, false);
		while (true){
			if (used[x]){
				return false;
			}
			used[x] = true;
			int sum = 0;
			while (x >= base) {
				int digit = x % base;
				sum += (digit)*(digit);
				x /= base;
			}
			sum += x * x;
			x = sum;
			if (x == 1) {
				return true;
			}
		}		
	}
	
	void solveOne(){
		String s = in.nextLine();
		String v[] = s.split(" ");
		int[] base = new int[v.length];
		for (int i=0; i<v.length; i++){
			base[i] = Integer.parseInt(v[i]);
		}
		for (int i=2; ; i++){
			boolean cor = true;
			for (int b : base) {
				if (!isCorrect(i, b)){
					cor = false;
					break;
				}
			}
			if (cor){
				out.println(i);
				return;
			}
		}
	}
		
	void solve(){
		int t = in.nextInt();
		in.nextLine();
		for (int i=1; i<=t; i++){
			out.print("Case #"+i+": ");
			solveOne();
		}
	}
	
	void run() {
		try {
			in = new Scanner(new FileReader("C:\\"+problem + ".in"));
			out = new PrintWriter("C:\\"+problem + ".out");
		} catch (IOException e) {
			throw new Error();
		}
	/*	in = new Scanner(System.in);
		out = new PrintWriter(System.out);
		*/
		try {
			solve();			
		} finally {
			out.close();
		}
	}
	
	public static void main(String []args) {
		new Txxxx().run();
	}
}