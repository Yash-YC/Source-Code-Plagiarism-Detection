import java.util.*;
public class A{
	static boolean [][] happy = new boolean [1000000][11];
	static boolean [][] vis = new boolean [1000000][11];
	static LP [][] ch = new LP[1000000][11];
	public static void main (String [] arg)throws Throwable{
		///*
		for (int j =2; j<happy.length; ++j) {
			for (int b = 2; b<happy[0].length; ++b) {
				int V = step(j,b);
				if (V >= ch.length) continue;
				if (ch[V][b] == null) ch[V][b] = new LP();
				ch[V][b].add(new Pair(j,b));
			}
		}
		LinkedList<Pair> L = new LinkedList<Pair>();
		for (int i = 2; i<happy[0].length; ++i) {happy[1][i] = true;L.add(new Pair(1,i));}
		while (!L.isEmpty()) {
			Pair p = L.remove();
			if (vis[p.i][p.j]) continue;
			vis[p.i][p.j]=true;
			happy[p.i][p.j]=true;
			if (ch[p.i][p.j] == null) continue;
			for (Pair q : ch[p.i][p.j]) {
				L.add(q);
			}
		}//*/
		
		String s = nextLine();
		int T = Integer.parseInt(s);
		for (int z = 1; z<=T; ++z) {
			String [] b = nextLine().split(" +");
			int [] a = new int [b.length];
			int ans = 0;
			for (int i = 0; i<a.length;++i) a[i] = Integer.parseInt(b[i]);
			GG: for (int i = 2; i<happy.length; ++i) {
				for (int j=0;j<a.length; ++j) {
					if (!happy[i][a[j]]) continue GG;
				}
				ans = i; break;
			}
			System.out.println("Case #"+z+": " + ans);
		}
	
	}
	public static int step(int i, int b) {
		String s = Integer.toString(i,b);
		int ans = 0;
		for (int j=0;j<s.length(); ++j) ans += (s.charAt(j)-'0')*(s.charAt(j)-'0');
		return ans;
	}
	static class LP extends LinkedList<Pair>{}
	static class Pair { int i,j;public Pair(int ii, int jj){i=ii;j=jj;}}

public static int nextInt() throws Throwable {
		int i = 0;
		boolean negative = false;
		while (i < 44) i = System.in.read();
		if (i == 45) {
			negative = true; i = 0;
		} else {
			 i = i - 48;
		}
		int j = System.in.read();
		while (j > 47) {i*=10;i+=j-48;j = System.in.read();}
		return (negative) ? -i : i;
}

public static String nextLine() throws Throwable {
		StringBuilder b = new StringBuilder(7);
		int j = System.in.read();
		while (j < 30) j = System.in.read();
		while (j != 10) {
			b=b.append((char)j);
			j=System.in.read();
		}
		//System.err.println("Input : " + b);
		return b.toString().replaceAll("[^0-9 ]","");
	}}