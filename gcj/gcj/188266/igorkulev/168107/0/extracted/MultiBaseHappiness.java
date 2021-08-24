import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class MultiBaseHappiness {
	
	static int convert(int N, int base) {
		int i;
		int score = N;
		int newnum = 0;
		// we convert the number in base B
		String p = "";
		String k = "";
		
		while (score > 0) {
			p += (char)((int)'0'+score%base);
			
			score /= base;
		}
		
		if (p == "") {
			newnum = 0;
		} else {
			
			for (i=p.length()-1;i>=0;i--) {
				k += p.charAt(i);
			}
			
			newnum = Integer.parseInt(k);
		}
		
		return newnum;
	}
	
	// we check if the number is happy in base 10
	static boolean isHappy10(int N) {
		int i;
		String a;
		boolean digit[] = new boolean[10];
		
		while (true) {
			a = Integer.toString(N);
			N = 0;
			for (i=0;i<a.length();i++) {
				N += ((int)a.charAt(i)-(int)'0')*((int)a.charAt(i)-(int)'0');
			}
			
			if (N == 1) break;
			
			if (N <= 9) {
				if (digit[N] == true) {
					break;
				} else {
					digit[N] = true;
				}
			}
			
		}
		
		if (N == 1) {
			return true;
		} else {
			return false;
		}
	}
	
	static boolean isHappyBase(int N, int B) {
		int i,j,k;
		
		
		String a;
		boolean digit[] = new boolean[10000];
		
		//System.out.println("BEFORE: "+N);
		N = convert(N, B);
		//System.out.println("AFTER: "+N);
		
		while (true) {
			// we put the number in String a
			a = Integer.toString(N);
			
			
			
			N = 0;
			for (i=0;i<a.length();i++) {
				N += ((int)a.charAt(i)-(int)'0')*((int)a.charAt(i)-(int)'0');
			}
			
			//System.out.println("BEFORE: "+N);
			
			N = convert(N, B);
			//System.out.println("AFTER: "+N);
			
			if (N == 1) break;
			
			
			if (digit[N] == true) {
				break;
			} else {
				digit[N] = true;
			}
			
		}
		
		//System.out.println("KRAJ "+N);
		
		if (N == 1) {
			return true;
		} else {
			return false;
		}
		
	}
	
	public static void main(String[] args) throws Exception {
		int i,j,k,m;
		int T;
		String line;
		boolean good;
		
		BufferedReader br = new BufferedReader(new FileReader("A-small.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-small.out")));
		
		StringTokenizer st;
		
		line = br.readLine();
		st = new StringTokenizer(line);
		T = Integer.parseInt(st.nextToken());
		
		int base[] = new int[20];
		
		for (k=1;k<=T;k++) {
			
			line = br.readLine();
			st = new StringTokenizer(line);
			
			j = 0;
			
			while (st.hasMoreTokens() == true) {
				base[j] = Integer.parseInt(st.nextToken());
				j++;
			}
			
			i = 2;
			while (true) {
				// we work i
				
				good = true;
				
				for (m=0;m<j;m++) {
					if (isHappyBase(i, base[m]) == false) {
						good = false;
					}
				}
				
				if (good == true) {
					
					out.println("Case #"+k+": "+i);
					
					break;
				}
				
				i++;
			}
			
		}
		
		out.close();
		System.exit(0);	
		
	}
	
}

