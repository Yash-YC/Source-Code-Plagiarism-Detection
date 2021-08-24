import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
	public boolean oko(int value, int k) {
		int res = value;
		boolean[] isi = new boolean[2*k*k];
		while ((res >= 2*k*k)||(!isi[res])) {
			if (res < 2*k*k) isi[res] = true;
			int res2 = 0;
			while (res > 0) {
				int modu = res%k;
				res2 += modu*modu;
				res /= k;
			}
			res = res2;
		}
		return (res == 1);
	}
	
	public void run() throws FileNotFoundException {
		Scanner input = new Scanner(new File("input.txt"));
		PrintWriter output = new PrintWriter(new File("output.txt"));

		int t = input.nextInt();
		input.nextLine();
		
		for (int tt = 0; tt < t; tt++) {
			String s = input.nextLine();
			
			int[] vs = new int[s.split(" ").length];
			int i = 0;
			for (String v: s.split(" ")) {
				vs[i++] = Integer.parseInt(v);
			}
			
			int MAX = Integer.MAX_VALUE;
			int ans = 2;
			for (int j = 2; j < MAX; j++) {
				boolean ok = true;
				
				for (int k = 0; k < vs.length; k++)
					if (vs[k] != 2)
						if (!oko(j, vs[k])) { ok = false; break; }
				
				if (ok) {
					ans = j;
					break;
				}
			}
			
			output.println("Case #"+(tt+1)+": "+ans);
		}
		
		input.close(); output.close();	
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		(new A()).run();
	}

}