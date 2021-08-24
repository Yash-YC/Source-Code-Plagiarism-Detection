import java.io.*;
import java.util.*;
public class Round1A {
	BufferedReader re;
	PrintStream wr;
	String file_in;
	String file_out;
	public String r() throws IOException {
		return re.readLine();
	};
	public int i(String s) {
		return Integer.parseInt(s);
	};
	public long l(String s) {
		return Long.parseLong(s);
	};
	public double d(String s) {
		return Double.parseDouble(s);
	};
	public int[] ia(String[] s) {
		int[] a=new int[s.length];
		for (int i=0;i<a.length;i++) a[i]=i(s[i]);
		return a;
	}
	public String[] sp(String s) {
		return s.split(" ");
	}
	// sp: split on space, ia: string array to int array, i/l/d: string to int/long/double, r: read line
	public Round1A(String in, String out) throws IOException {
			boolean alsoScreen=true;
			file_in=in;
			file_out=out;
			re=new BufferedReader(new FileReader(file_in));
			wr=new PrintStream(file_out);
			PrintStream tempWr=wr;
			int cases=i(r());
			int[] sq=new int[10];
			for (int i=0;i<10;i++) sq[i]=i*i;
			boolean[][] memo=new boolean[11][];
			for (int i=2;i<memo.length;i++) { memo[i]=new boolean[1500]; memo[i][1]=true; }
			for (int base=2;base<=10;base++) {
				for (int i=2;i<1500;i++) {
					int m=i;
					boolean[] rep=new boolean[1500];
					boolean found=false;
					int n=m;
					while (!found) {
						int sum=0;
						while (n>0) {
							sum+=sq[n%base];
							n=n/base;
						}
						if (memo[base][sum]) { found=true; memo[base][i]=true; }
						else if (!rep[sum]) { rep[sum]=true; n=sum; }
						else found=true;
					}
				}
			}
			//for (int i=0;i<100;i++) if (memo[3][i]) System.out.print(i+",");
			for (int cn=1;cn<=cases;cn++) {

				int[] bases=ia(sp(r()));
				int happy=-1;
				for (int m=2;happy==-1;m++) {
					boolean h=true;
					for (int i=0;i<bases.length;i++) {
						int base=bases[i];
						if (m<1500) {
							if (!memo[base][m]) h=false;
						} else {
							boolean found=false;
							int n=m;
								int sum=0;
								while (n>0) {
									sum+=sq[n%base];
									n=n/base;
								}
								if (!memo[base][sum]) h=false;
						}
					}
					if (h) happy=m;
				}
				
				wr.printf("Case #%d: %s%n",cn,happy);
				//int repeatCount=alsoScreen?1:0;
				//do { wr.printf("Case #%d: %s%n",cn,happy); wr=System.out; } while (repeatCount-->0);
				//wr=tempWr;
			}
		
	}
	public static void main(String[] args) {
		try { new Round1A("A-small-attempt0.in","output.txt"); }
		catch (IOException e) { e.printStackTrace(); }
	}
}
