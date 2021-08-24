import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;

public class qst2 {

	public static void main(String[] args) {
		qst2 qst = new qst2();
		try {
			qst.run();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public String fnIn = "F:\\JavaWork\\CodeJam\\C-large.in";
	public String fnOut = "F:\\JavaWork\\CodeJam\\2.out";

	public int T;
	public int N;
	public int C;

	private void run() throws IOException {
		DecimalFormat df = new DecimalFormat("#.0000000");
		BufferedReader br = new BufferedReader(new FileReader(fnIn));
		BufferedWriter bw = new BufferedWriter(new FileWriter(fnOut));
		T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			String t = br.readLine();
			String[] tt = t.split(" ");
			N = Integer.parseInt(tt[0]);
			C = Integer.parseInt(tt[1]);
			double ans = slove();

			bw.write("Case #" + (i + 1) + ": " + df.format(ans) + "\n");
		}

		br.close();
		bw.close();

	}

	private double slove() {
		int rt = N;
		int lt=0;
		double sl=0;
		while (lt < N) {
			if (rt >= C) {
				double p = caleP(lt, rt);
				double s = C / p;
				lt += C;
				sl+=s;
				rt -= C;
				
			} else {
				double p = caleP(lt, rt);
				double s = rt / p;
				lt += rt;
				rt = 0;
				sl+=s;
			}
		}
		return sl;

	}

	private double caleP(int lt, int rt) {
		double p = 0;
		if(lt==0)
			return C;
		
		int mini=(C<rt?C:rt);
		for (int i = mini; i > 0; i--) {
			p += i * C(i, rt)*C(C-i,lt) / C(C, N);
		}
		return p;
	}

	public double cache[][] = new double[50][50];

	public void initCache() {
		for (int i = 0; i < 50; i++)
			for (int j = 0; j < 50; j++)
				cache[i][j] = 0;

	}

	private double C(int i, int j) {
		if (cache[i][j] > 0)
			return cache[i][j];
		if(i==0)
			return 1;
		double sum = 1;
		for (int k = 0; k < i; k++) {
			sum *= (j - k);
		}
		for (int k = 2; k <= i; k++) {
			sum /= k;
		}
		cache[i][j] = sum;
		return sum;
	}
}
