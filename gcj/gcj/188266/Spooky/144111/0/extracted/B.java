package round1a;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Comparator;
import java.util.PriorityQueue;

public class B {

	static StreamTokenizer in;
	static PrintWriter out;
	
	static int nextInt() throws IOException
	   {
	      in.nextToken();
	      return (int)in.nval;
	   }
	
	static String nextString() throws IOException
	   {
	      in.nextToken();
	      return in.sval;
	   }

	public static void main(String[] args) throws IOException {
		in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		out = new PrintWriter(System.out);
		in = new StreamTokenizer(new BufferedReader(new FileReader("B-small-attempt1.in")));
		//in = new StreamTokenizer(new BufferedReader(new FileReader("B-large.in")));
		out = new PrintWriter(new FileWriter("B-small-out"));
		//out = new PrintWriter(new FileWriter("B-large-out"));
		
		for (int t = nextInt(), cs = 1; t > 0; t--, cs++) {
			n = nextInt();
			m = nextInt();
			a = new int[n][m][];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) a[i][j] = new int[]{nextInt(), nextInt(), nextInt()};
			
			d = new int[2*n][2*m];
			for (int i = 0; i < 2*n; i++)
				for (int j = 0; j < 2*m; j++)
					d[i][j] = Integer.MAX_VALUE;
			
			PriorityQueue<int[]> q = new PriorityQueue<int[]>(1000, new Comparator<int[]>(){
				public int compare(int[] a, int[] b) {
					return a[2] > b[2] ? 1 : -1;
				}
			});
			
			q.offer(new int[]{2*n - 1, 0, 0});
			
			while (q.size() > 0) {
				int[] cur = q.poll();
				int x = cur[0], y = cur[1], dist = cur[2];
				
				if (d[x][y] <= dist) continue;
				
				//System.out.println(x + " " + y + " " + dist);
				
				d[x][y] = dist;
				
				if (x == 0 && y == 2*m-1) break;
				
				if (x%2 == 0 && x > 0) q.offer(new int[]{x-1, y, dist + 2});
				else if (x%2 == 1) {
					int tm = a[x/2][y/2][2], go = dist;
					while (tm > go) tm -= a[x/2][y/2][0] + a[x/2][y/2][1];
					while (tm + a[x/2][y/2][0] + a[x/2][y/2][1] <= go) tm +=  + a[x/2][y/2][0] + a[x/2][y/2][1];
					if (go >= tm + a[x/2][y/2][0]) go = tm + a[x/2][y/2][0] + a[x/2][y/2][1];
					q.offer(new int[]{x-1, y, go + 1});
				}
				
				if (x%2 == 1 && x < 2*n-1) q.offer(new int[]{x+1, y, dist + 2});
				else if (x%2 == 0) {
					int tm = a[x/2][y/2][2], go = dist;
					while (tm > go) tm -= a[x/2][y/2][0] + a[x/2][y/2][1];
					while (tm + a[x/2][y/2][0] + a[x/2][y/2][1] <= go) tm +=  + a[x/2][y/2][0] + a[x/2][y/2][1];
					if (go >= tm + a[x/2][y/2][0]) go = tm + a[x/2][y/2][0] + a[x/2][y/2][1];
					q.offer(new int[]{x+1, y, go + 1});
				}
				
				if (y%2 == 0 && y > 0) q.offer(new int[]{x, y-1, dist + 2});
				else if (y%2 == 1) {
					int tm = a[x/2][y/2][2], go = dist;
					while (tm > go) tm -= a[x/2][y/2][0] + a[x/2][y/2][1];
					while (tm + a[x/2][y/2][0] + a[x/2][y/2][1] <= go) tm +=  + a[x/2][y/2][0] + a[x/2][y/2][1];
					if (go < tm + a[x/2][y/2][0]) go = tm + a[x/2][y/2][0];
					q.offer(new int[]{x, y-1, go + 1});
				}
				
				if (y%2 == 1 && y < 2*m-1) q.offer(new int[]{x, y+1, dist + 2});
				else if (y%2 == 0) {
					int tm = a[x/2][y/2][2], go = dist;
					while (tm > go) tm -= a[x/2][y/2][0] + a[x/2][y/2][1];
					while (tm + a[x/2][y/2][0] + a[x/2][y/2][1] <= go) tm +=  + a[x/2][y/2][0] + a[x/2][y/2][1];
					if (go < tm + a[x/2][y/2][0]) go = tm + a[x/2][y/2][0];
					q.offer(new int[]{x, y+1, go + 1});
				}
			}
			
			out.println("Case #" + cs + ": " + d[0][2*m-1]);
		}
		
		out.flush();
	}

	static int n, m;
	static int[][][] a;
	static int[][] d;
}
