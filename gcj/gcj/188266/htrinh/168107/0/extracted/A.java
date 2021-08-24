import java.util.*;
import java.io.*;

class A
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader fin = new BufferedReader(new FileReader(args[0]));
		PrintWriter fout = new PrintWriter(new FileWriter(args[1]));
		int T;

		T = Integer.parseInt(fin.readLine());
		for (int t = 1; t <= T; t++) {
			String[] sp = fin.readLine().split(" ");
			try {
				int ans = new A().happy(sp);
				fout.println("Case #"+t+": "+ans);
				System.out.println("Case #"+t+": "+ans);
			} catch (Exception e) {
				System.err.println(e);
			}
		}
		fout.flush();
		fout.close();
	}
	public int happy(String[] sp)
	{
		int n = sp.length;
		int[] b = new int[n];
		for (int i = 0; i < n; i++)
			b[i] = Integer.parseInt(sp[i]);
		int ret = 2;
		while (true) {
			boolean ok = true;
			for (int i = 0; i < n; i++) {
				map = new HashMap<Integer, Integer>();
				visited = new HashSet<Integer>();
				if (solve(ret, b[i]) != 1) {
					ok = false;
					break;
				}
			}
			if (ok)
				break;
			ret++;
		}
		return ret;
	}
	private HashMap<Integer, Integer> map;
	private HashSet<Integer> visited;
	private int solve(int n, int base)
	{
		if (n == 1)
			return n;
		if (map.containsKey(n))
			return map.get(n);
		if (visited.contains(n))
			return n;
		visited.add(n);
		int x = compute(n, base);
		int ret = solve(x, base);
		map.put(n, ret);
		return ret;
	}
	private int compute(int m, int base)
	{
		String x = "";
		int n = m;
		while (n > 0) {
			x += n%base;
			x += " ";
			n /= base;
		}
		int ret = 0;
		String[] sp = x.split(" ");
		for (int i = 0; i < sp.length; i++) {
			int d = Integer.parseInt(sp[i]);
			ret += d*d;
		}
		return ret;
	}
}
