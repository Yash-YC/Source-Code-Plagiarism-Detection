import java.io.*;
import java.util.*;
public class Round1C {
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
	double[][] memo;
	// sp: split on space, ia: string array to int array, i/l/d: string to int/long/double, r: read line
	public Round1C(String in, String out) throws IOException {
			boolean alsoScreen=true;
			file_in=in;
			file_out=out;
			re=new BufferedReader(new FileReader(file_in));
			wr=new PrintStream(file_out);
			PrintStream tempWr=wr;
			int cases=i(r());
			for (int cn=1;cn<=cases;cn++) {
				int[] xy=ia(sp(r()));
				int c=xy[0];
				int p=xy[1];
				//memo=new Fraction[c+1][200];
				//for (int i=0;i<=c;i++) for (int j=0;j<200;j++) memo[i][j]=new Fraction(0,1);
				//memo[0][0]=new Fraction(1,1);
				memo=new double[c+1][4000];
				memo[0][0]=1;
				for (int n=1;n<=c;n++) {
					for (int k=1;(k<4000);k++) {
						double sum=0;
						//Fraction sum=new Fraction(0,1);
						for (int t=0;(t<=p) && (n>=t);t++) {
							//if ((t!=0) || (n!=c))  sum.add(memo[n-t][k-1].multiply(pro(t,c,p,n-t)));
							if ((t!=0) || (n!=c)) sum+=memo[n-t][k-1]*prob(t,c,p,n-t);
						}
						memo[n][k]=sum;
					}
				}
				//for (int i=0;i<=c;i++) {
				//	System.out.print(i+": ");
				//	for (int j=0;j<100;j++) System.out.print(memo[i][j]+" "); 
				//	System.out.println();
				//}
				double a=0;
				for (int k=1;k<4000;k++) a+=memo[c][k]*k;
				//wr.printf("Case #%d: %s%n",cn,"?");
				int repeatCount=alsoScreen?1:0;
				do { wr.printf("Case #%d: %.7f%n",cn,a); wr=System.out; } while (repeatCount-->0);
				wr=tempWr;
			}
		
	}
	public double prob(int x, int c, int p, int n) {
		return choose(n,p-x)*choose(c-n,x)/choose(c,p);
	}

	
	private long gcd(long a, long b) {
		while (b!=0) {
			long t=a%b;
			a=b;
			b=t;
		}
		return a;
	}
	public double choose(int a, int b) {
		if (a<b) return 0;
		double s=1;
		int c=a-b;
		if (c<b) b=c;
		for (int i=0;i<b;i++) {
			s*=(a-i);
			s/=i+1;
		}
		return s;
	}
	public long ch(int a, int b) {
		if (a<b) return 0;
		long s=1;
		int c=a-b;
		if (c<b) b=c;
		for (int i=0;i<b;i++) {
			s*=(a-i);
			s/=i+1;
		}
		return s;
	}
	public static void main(String[] args) {
		try { new Round1C("C-small-attempt0.in","output.txt"); }
		catch (IOException e) { e.printStackTrace(); }
	}
}
