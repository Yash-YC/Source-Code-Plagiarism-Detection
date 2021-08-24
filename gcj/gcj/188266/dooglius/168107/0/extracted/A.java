import java.io.*;
import java.util.StringTokenizer;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
public class A{
	private static HashMap<Node,Boolean> cache;
	private static HashSet<Node> soFar;
	private static LinkedList<Integer> bases;
	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new FileReader("A-small-attempt0.in"));
		int T = Integer.parseInt(in.readLine());
		BufferedWriter out = new BufferedWriter(new FileWriter("A-small-attempt0.out"));
		cache = new HashMap<Node,Boolean>();
		for(int i = 1; i<=T; i++){
			System.out.println("Case "+i);
			StringTokenizer getInfo = new StringTokenizer(in.readLine());
			bases = new LinkedList<Integer>();
			while(getInfo.hasMoreTokens()){
				bases.add(new Integer(getInfo.nextToken()));
			}
			int x = 2;
			while(!good(x++));
			out.write("Case #"+i+": "+(x-1)+"\n");
		}
		System.out.println("done");
		in.close();
		out.close();
	}
	private static boolean good(int x){
		for(Integer b: bases){
			soFar = new HashSet<Node>();
			if(!go(x,b.intValue())) return false;
		}
		return true;
	}
	private static boolean go(int x,int b){
		if(x==1) return true;
		Node n = new Node(b,x);
		Boolean boo = cache.get(n);
		if(boo!=null){
			return boo.booleanValue();
		}
		if(soFar.contains(n)){
			return false;
		}
		soFar.add(n);
		boolean ans = go(sumsquares(x,b),b);
		cache.put(n,new Boolean(ans));
		return ans;
	}
	private static int sumsquares(int x,int b){
		int ans = 0,t;
		while(x>0){
			t = x/b;
			ans+=(x-t*b)*(x-t*b);
			x=t;
		}
		return ans;
	}
	private static class Node{
		public int base, num;
		public Node(int a, int b){
			base=a;
			num=b;
		}
		public boolean equals(Object o){
			return ((Node)o).base==base && ((Node)o).num==num;
		}
		public int hashCode(){
			return num*103+base;
		}
		public String toString(){ return "base "+base+", num "+num;}
	}
}