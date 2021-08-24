import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FilenameFilter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.regex.Pattern;

public class A implements Runnable {

	void solve(BufferedReader in, PrintWriter out, long timeStart)
			throws IOException {
		String line = in.readLine();
		int cases = Integer.parseInt(line);
		for (int i = 0; i < cases; i++) {
			line = in.readLine();
			String[] bases_s = line.split(" ");
			int[] bases = new int[bases_s.length];
			for (int j = 0; j < bases_s.length; j++) {
				bases[j] = Integer.parseInt(bases_s[j]);
			}
			long smallest = 0;
			for (long k = 2; k < 100000; k++) {
				boolean found = true;
				for (int j = 0; j < bases_s.length; j++) {
					boolean b = happy(k, bases[j]);
					if (b == false) {
						found = false;
						break;
					}
				}
				if (found == true) {
					smallest = k;
					break;
				}
			}
			out.println("Case #" + (i + 1) + ": " + smallest);

		}
		// out.println("" + a1 + "|" + a2 + "|" + a3);
		// this.estimatedTimeLeft(50, 100, timeStart);
	}

	private boolean happy(long n, int base) {
		
		long j,old_n,loops=10;
		int DELTA_LOOPS = 10;
		
		while(1==1){
			old_n = n;
			for( j= loops;j>0;j--)
				if((n = f(n,base))== old_n)break;
			if(n==old_n)break;
			loops += DELTA_LOOPS;
		}
		return n == 1 ? true : false;
	}
	
	long	f(long n , int base)
	{
		long k = 0,m;

		while(n>0){
			m = n % base; 
			n = n / base;
			k += m*m;
		}
		return k;
	}

	long Calc2(long a, int base) {
		long digit;
		long s = 0;
		while (a > 0) {
			digit = a % base; //
			a = a / base;
			s = s + digit * digit; 
		}
		return s;
	}

	private String get_n(long n, int base) {
		String s = "";
		while (1 == 1) {
			long z = n % base;
			long y = n / base;
			s = "" + z + s;
			n = y;
			if (n == 0)
				break;
		}
		return s;
	}

	void solve(File inFile) {
		long timeStart = System.currentTimeMillis();
		System.out.println("Solving [" + inFile.getPath() + ']');
		File outFile = new File(inFile.getPath() + ".out");

		try {
			BufferedReader in = new BufferedReader(new FileReader(inFile));
			PrintWriter out = new PrintWriter(outFile);

			solve(in, out, timeStart);

			in.close();
			out.close();

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.err.println("Time Spent: "
				+ (System.currentTimeMillis() - timeStart) + " ms");
	}

	public void run() {

		final Pattern inPattern = Pattern.compile("^.*\\.in$",
				Pattern.CASE_INSENSITIVE);
		final File[] inFiles = new File("C:\\workspace\\Google\\Data")
				.listFiles(new FilenameFilter() {
					public boolean accept(File dir, String name) {
						return inPattern.matcher(name).matches();
					}
				});
		for (File inFile : inFiles) {
			solve(inFile);
		}

	}

	void estimatedTimeLeft(int count, int tot, long timeStart) {
		if (tot == 0)
			return;
		long ms = (long) ((1.0 * (System.currentTimeMillis() - timeStart))
				* (tot - count) / tot);
		System.out.println(" Left (" + count + "/" + tot + ") " + (ms / 1000)
				+ " s [" + (ms / 60000) + " min]");
	}

	public static void main(String[] args) {
		new Thread(new A()).start();
	}
}
