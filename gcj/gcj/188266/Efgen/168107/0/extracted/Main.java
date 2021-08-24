import java.io.*;         
import java.util.*;         
import java.math.*;         

public class Main implements Runnable  {   
StreamTokenizer ST;      
PrintWriter out;      
BufferedReader br;   
int inf = 1000000000;   

int nextInt() throws IOException{      
    ST.nextToken();      
    return (int)ST.nval;      
}

long nextLong() throws IOException{      
    ST.nextToken();      
    return (long)ST.nval;      
}      
String next() throws IOException{      
    ST.nextToken();      
    return ST.sval;      
}      
double nextD() throws IOException{      
    ST.nextToken();      
    return ST.nval;      
}      
public static void main(String[] args) throws IOException {       
    new Thread(new Main()).start();      
}      
public void run()  {      
    try {          
    	br = new BufferedReader(new FileReader(new File("input.txt")));
    	out = new PrintWriter(new BufferedWriter(new FileWriter(new File("output.txt"))));
        ST = new StreamTokenizer(br);      
        solve();      
        out.close();              
    }         
    catch (IOException e) {        
    throw new IllegalStateException(e);       
    }      
}
int n = 1000000;
int[][] a = new int[10][n];
int f(int x, int b) {
	int res = 0;
	while (x>0) {
		int y = x%b;
		res += y*y;
		x/=b;
	}
	return res;
}
int go(int x, int b) {
	if (x==1) return 1;
	if (a[b-1][x]!=0) return a[b-1][x]; else {
		a[b-1][x] = -1;
		a[b-1][x] = go(f(x, b), b);
		return a[b-1][x];
	}
}
public void solve() throws IOException {	
	for (int b=2; b<=10; b++)
		for (int x=2; x<=100000; x++) {
			go(x, b);
		}
	int tt = Integer.parseInt(br.readLine());
	for (int t=1; t<=tt; t++) {
		String[] ss = br.readLine().split(" ");
		boolean[] f = new boolean[10];
		for (String s:ss) f[Integer.parseInt(s)-1] = true;
		boolean ok = false;
		int x = 2;
		for (x=2; !ok &&x<n; x++) {
			ok = true;
			for (int i=1; i<10; i++)
				if (f[i] && a[i][x]!=1) {
					ok = false;
					break;					
				}
			
		}
		out.println("Case #"+t+": "+(x-1));
	}
}
}







