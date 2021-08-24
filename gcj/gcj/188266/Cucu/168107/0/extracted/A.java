import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class A {
	public static int readInt(BufferedReader br) throws IOException {
		String s = br.readLine();
		return Integer.parseInt(s);
	}

	 
	public static boolean ishappy(int n, int base) {
		return ishappy(n,base,new boolean[100000]);
	}
	public static boolean ishappy(int n, int base, boolean analized[]) {
		if (n==1) return true;
		if (analized[n]) return false;
		analized[n] = true;
		int sum = 0;
		while (n>0) {
			sum += (n % base) * (n % base);
			n = (int) n / base;
		}
		
		return ishappy(sum,base,analized);
	}
	
	public static int[] readIntArray(BufferedReader br) throws IOException {
		String s = br.readLine();
		String a[] = s.split(" ");
		int r[] = new int[a.length];
		for (int i = 0 ; i < a.length ; i++) r[i] = Integer.parseInt(a[i]);
		return r;
	}

	public static void main(String[] args) {
//		String name = "A-test";
		String name = "A-small-attempt0";
//		String name = "A-large";
		try {
			BufferedReader br = new BufferedReader(new FileReader(name +".in"));
			PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(name + ".out")));
			
			long start = System.currentTimeMillis();
			int N = readInt(br); 
			for (int casen = 0; casen < N; casen++) {
				System.out.println("Running Case " + (casen +1 ) + " of " + N);

				int b[] = readIntArray(br);
				int h = 2;
				while(true) {
					boolean ok = true;
					for (int i = 0; i < b.length; i++) {
						if (!ishappy(h,b[i])) { ok = false; break;}
					}
					if (ok) break;
					h++;
				}
				
				out.println("Case #" + (casen +1 ) + ": " + h);
			}
			out.close();
			long stop = System.currentTimeMillis();
			System.out.println("Finished in " + ((stop - start)) / 1000 + " seconds.");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
