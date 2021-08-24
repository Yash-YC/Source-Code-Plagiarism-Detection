import java.io.*;
import java.util.*;

public class A {
	static int N;
	static int BIG = 100000;
	public static void main(String args[]) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("A.txt"));
		BufferedWriter out = new BufferedWriter(new FileWriter("A.out.txt"));
		
		N = Integer.parseInt(in.readLine());
			boolean[][] works = new boolean[BIG+5][11]; // 0 = true, 1 = false
			int[] bases = {2,3,4,5,6,7,8,9,10};
			for(int j = 2; j <= BIG; j++) {
				for(int k = 2; k <= 10; k++) {
//					System.out.println("j="+j+" b="+bases[k]);
					Set<String> h = new HashSet<String>();
					String g = Integer.toString(j, k);
//					System.out.println(g+" "+k);
					while(!g.equals("1")) {
						int spare = 0;
						for(int l = 0; l < g.length(); l++) {
							spare += (g.charAt(l)-'0')*(g.charAt(l)-'0');
						}
						g = Integer.toString(spare, k);
						if(g.equals("1")) break;
						if(!h.add(g)) {
							works[j][k] = true;
							break;
						}
					}
//					System.out.println(g+" "+k);
//					System.out.println(works[j][k]);
				}
			}
//			for(int j = 2; j <= 500; j++) {
//				for(int k = 2; k <= 9; k++) System.out.print(j+" "+works[j][k]+" ");
//				System.out.println();
//			}
			
		for(int i = 0; i < N; i++) {
			String[] stuff = in.readLine().split(" ");
			int[] stuffInt = new int[stuff.length];
			for(int j = 0; j < stuff.length; j++) stuffInt[j] = Integer.parseInt(stuff[j]);
			int j = 2;
			for(; j <= BIG; j++) {
				int k = 0;
				for(int l = 0; l < stuffInt.length; l++) if(!works[j][stuffInt[l]]) k++;
				if(k == stuffInt.length) {
					System.out.println("Case #"+(i+1)+": "+j);
					out.write("Case #"+(i+1)+": "+j+"\n");
					break;
				}
			}
		}
		
		in.close();
		out.close();
	}
}
