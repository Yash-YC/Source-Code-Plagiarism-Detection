import java.util.*;
import java.io.*;
import static java.lang.System.out;
import static java.lang.Math.*;

public class A {
	public static HashMap[] cache;
	public static int b;
	public static boolean happy(String n) {
		if(cache[b].containsKey((String)n)) {
			return (boolean)((Boolean)cache[b].get(n));
		}
		int sum=0;
		for(char dig : n.toCharArray()) {
			sum+=(dig-'0')*(dig-'0');
		}
		String next=Integer.toString(sum,b);
		cache[b].put(n,(Boolean)false);
		boolean res = happy(next);
		cache[b].put(n,(Boolean)res);
		return res;
	}
	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(new File("A.in"));
		PrintWriter fout = new PrintWriter(new FileWriter("A.out"));
		int T,K;
		T = Integer.parseInt(in.nextLine());
		cache=new HashMap[11];
		for(int i=2;i<=10;i++) {
			cache[i]=new HashMap();
			cache[i].put("1",(Boolean)true);
		}
		for(int t=0;t<T;t++) {
			String[] bases = in.nextLine().split(" ");
			int[] bs = new int[bases.length];
			for(int i=0;i<bases.length;i++)
				bs[i] = Integer.parseInt(bases[i]);
o:			for(int i=2;;i++) {
				for(int base:bs) {
					b=base;
					if(!happy(Integer.toString(i,b))) continue o;
				}
				fout.printf("Case #%d: %d\n",t+1,i);
				break;
			}
		}
		fout.close();
	}
}