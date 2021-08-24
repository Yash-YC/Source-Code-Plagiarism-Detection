import java.io.*;
import java.util.*;

public class multibase {
	public static boolean[] store;
	public static boolean[][] happy=new boolean[11][100000];
	public static boolean[][] unhappy=new boolean[11][100000];
	public static void main (String[] args) throws IOException{
		BufferedReader in=new BufferedReader(new FileReader("multibase.in"));
		PrintWriter out=new PrintWriter (new FileWriter("multiout"));
		int cases=Integer.parseInt(in.readLine());
		for (int i=1; i<=cases; i++){
			StringTokenizer st=new StringTokenizer(in.readLine());
			int[] bases=new int[st.countTokens()];
			for (int j=0; j<bases.length; j++)
				bases[j]=Integer.parseInt(st.nextToken());
			for (int curr=2; ; curr++){
				int j=0;
				for (j=0; j<bases.length; j++){
					store=new boolean[100000];
					if (happy[bases[j]][curr])
						continue;
					if (unhappy[bases[j]][curr] || !happy(curr, bases[j]))
						break;
				}
				if (j==bases.length){
					out.println("Case #"+i+": "+curr);
					break;
				}
			}
		}
		out.close();
		System.exit(0);
	}
	
	public static boolean happy (int num, int base){
		double test=Math.log(num)/Math.log(base);
		if (test==Math.floor(test)){
			happy[base][num]=true;
			return true;
		}
		int sum=0;
		while (num>0){
			sum+=(num%base)*(num%base);
			num/=base;
		}
		if (store[sum]){
			unhappy[base][num]=true;
			return false;
		}
		store[sum]=true;
		if (happy(sum,base)){
			happy[base][num]=true;
			return true;
		}
		else{
			unhappy[base][num]=true;
			return false;
		}
	}
}
