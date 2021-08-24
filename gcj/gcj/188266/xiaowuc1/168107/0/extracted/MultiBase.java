import java.io.*;
import java.util.*;
public class MultiBase {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("multibase.txt")));
		int x = Integer.parseInt(br.readLine());
		for(int c = 1; c <= x; c++)	{
			StringTokenizer st = new StringTokenizer(br.readLine());
			ArrayList<Integer> list = new ArrayList<Integer>();
			while(st.hasMoreTokens())	{
				list.add(Integer.parseInt(st.nextToken()));
			}
			long curr = 2;
			outer: while(true)	{
				for(int base: list)	{
					if(!pass(curr, base))	{
						curr++;
						continue outer;
					}
				}
				break;
			}
			pw.println("Case #" + c + ": " + curr);
		}
		pw.close();
	}
	public static boolean pass(long x, int base)	{
		HashSet<Long> seen = new HashSet<Long>();
		long curr = x;
		while(curr != 1)	{
			if(seen.contains(curr))
				return false;
			seen.add(curr);
			String s = Long.toString(curr, base);
			long now = 0;
			for(int i = 0; i < s.length(); i++)	{
				int c = s.charAt(i) - '0';
				now += c*c;
			}
			curr = now;
		}
		return true;
	}

}
