import java.io.*;
import java.nio.*;
import java.util.*;
import java.util.ArrayList;

public class A {
    public static void main(String[] args) {
        try{
			//BufferedReader in = new BufferedReader(new FileReader("a.in"));
			BufferedReader in = new BufferedReader(new FileReader("a-small.in"));
			System.setOut(new PrintStream(new FileOutputStream("a-small.out")));

			//BufferedReader in = new BufferedReader(new FileReader("a-large.in"));
			//System.setOut(new PrintStream(new FileOutputStream("a-large.out")));
			int n = Integer.parseInt(in.readLine());
			for(int cases =1 ;cases<=n;cases++){
				String[] toks = in.readLine().split(" ");
				int bases[] =new int[toks.length];

				for(int j=0;j<toks.length;j++)
					bases[j]=Integer.parseInt(toks[j]);

				int result=search(bases);

				System.out.printf("Case #%d: %d\n",cases,result);
			}
			in.close();
		}catch(Exception e){
			e.printStackTrace();
		}
    }

	static int search(int[]bases){
		for(int i=2;i<Integer.MAX_VALUE;i++){
			int j=0;
			for(j=0;j<bases.length;j++){
				if(!happy(i,bases[j])){
					break;
				}
					
			}
			if(j==bases.length) return i;
		}
		return -1;
	}

	static boolean happy(int n, int b){
		int src = n;
		HashMap<Integer,Boolean> visited = new HashMap<Integer,Boolean>();
		String a = Integer.toString(n, b);
		while(a.length() >= 1 && visited.get(n)==null){
			visited.put(n,true);
			int aux = 0;
			for(int i=0;i<a.length();i++){
				aux += (a.charAt(i)-'0')*(a.charAt(i)-'0');
			}

			if(aux == 1) return true;
			
			n = aux;
			a = Integer.toString(n, b);
		}
		return false;
	}
}