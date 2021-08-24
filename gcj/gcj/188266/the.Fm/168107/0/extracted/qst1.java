import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;

public class qst1 {

	public static void main(String[] args) {
		qst1 qst = new qst1();
		try {
			qst.run();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public String fnIn = "F:\\JavaWork\\CodeJam\\A-small-attempt0.in";
	public String fnOut = "F:\\JavaWork\\CodeJam\\1.out";
	Set<Integer> find=new HashSet<Integer>();		
	public int sum(int num, int base) {

		find.clear();
		while (num > 1) {
			int t = num;
			int sum = 0;
			while (t > 0) {
				int p = t % base;
				t = t / base;
				sum += p * p;
			}
			if(find.contains(sum))
			{
			return 2;	
			}
			else
			{
				find.add(sum);
				num = sum;
			}
		}
		return num;
	}

	public int nextAt(int num, int base) {
		do {
			if (sum(num, base) != 1)
				num++;
			else
				return num;
		} while (true);
	}

	public int sovle(int bases[]) {
		int l = bases.length;
		int p = 0;
		int num = 2;

		while (p < l) {
			int n = nextAt(num, bases[p]);
			p++;
			if (n != num)
				p = 0;
			num=n;
		}
		return num;
	}

	public int T;

	private void run() throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(fnIn));
		BufferedWriter bw = new BufferedWriter(new FileWriter(fnOut));
		T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			String line = br.readLine();
			String t[] = line.split(" ");
			int bases[] = new int[t.length];
			for (int j = 0; j < bases.length; j++)
				bases[j] = Integer.parseInt(t[j]);
			int ans=sovle(bases);
			//int ans=nextAt(91, 9);
			bw.write("Case #"+(i+1)+": "+ans+"\n");
		}
		
		br.close();
		bw.close();

	}

}
