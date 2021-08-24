import java.io.*;
import java.util.*;
import java.math.*;

public class a {
	static int maxn = 100000;
	static int[][] to = new int[11][maxn];
	static boolean[][] happy = new boolean[11][maxn];
	static int[][] vis = new int[11][maxn];

	static boolean rec(int base, int num){
		if (vis[base][num]==2) return happy[base][num] = false;
		if (num==1) return happy[base][num] = true;
		if (vis[base][num]==100) return happy[base][num];
		vis[base][num]++;
		//System.out.println(base + " " + num + " " + vis[base][num]);
		happy[base][num] = rec(base,to[base][num]);
		vis[base][num] = 100;
		return happy[base][num];
	}

	public static void main(String[] args){
		List<Integer>[][] con = new ArrayList[11][maxn];

		for (int i=1; i<maxn; i++){
			for (int b=2; b<=10; b++){
				String s = Integer.toString(i,b);
				int sum = 0;
				for (int j=0; j<s.length(); j++){
					int x = s.charAt(j)-'0';
					String t = Integer.toString(x*x,b);
					sum += Integer.parseInt(t,b);
				}
				to[b][i] = sum;

				if (con[b][sum]==null) con[b][sum] = new ArrayList();
				con[b][sum].add(i);
			}
		}

		for (int b=2; b<=10; b++){
//			System.out.print(b + " ");
			for (int i=2; i<maxn; i++){
				happy[b][i] = rec(b,i);
//				if (happy[b][i]) System.out.print(" " + i);
			}
//			System.out.println();
		}

		Scanner scan = new Scanner(System.in);
		int nTC = Integer.parseInt(scan.nextLine());
		for (int TC=1; TC<=nTC; TC++){
			String[] bs = scan.nextLine().split(" ");
			int[] B = new int[bs.length];
			for (int i=0; i<bs.length; i++)
				B[i] = Integer.parseInt(bs[i]);
			for (int i=2; ; i++){
				boolean ok = true;
				for (int j=0; j<B.length; j++){
//					System.out.printf("i=%d, b=%d, h=%b\n",i,B[j], happy[B[j]][i]);
					if (!happy[B[j]][i]){ ok = false; break; }
				}
//				System.out.println(TC + " " + i);
				if (ok){
					System.out.printf("Case #%d: %d\n",TC,i);
					System.out.flush();
					break;
				}
			}
		}
	}
}
