import java.io.*;
import java.util.*;

public class Main implements Runnable{
	
	public static void main(String[] ar){
		new Main().run();
	}

	int MAX = 1100000;
	BufferedReader in;
	boolean[] a = new boolean[11];
	
	int[][] happy = new int[11][MAX];
	int base = 0;
	int x = 0, c = 0, sum = 0;
	
	boolean happy(int n){
		//System.out.println(base + " " + n);
		if (n >= MAX) return false;
		if (happy[base][n] == 0){
			happy[base][n] = 1;
			sum = 0;
			x = n; c = 0;
			while (x > 0){
				c++;
				sum += (x%base)*(x%base);
				x /= base;
			}
			
			if (c == 1 && sum == 1){
				happy[base][n] = 2;
				return true;
			}
			
			if (happy(sum))
				happy[base][n] = 2; else
				happy[base][n] = 1;
		}
		return happy[base][n] == 2;		
	}
	
	
	@Override
	public void run() {
		
		for (base=2;base<=10;base++){
			happy[base][0] = 1;
			happy[base][1] = 2;
			for (int i=2;i<MAX;i++)
				if (happy(i))
					happy[base][i] = 2; else
					happy[base][i] = 1;
			System.out.println(base);
		}
		
		try{
			in = new BufferedReader(new FileReader("A-small.in"));
			BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
			
			int T = Integer.parseInt(in.readLine());
			for (int ttt = 1;ttt<=T;ttt++){
				out.write("Case #" + String.valueOf(ttt) + ": ");
				String[] temp = in.readLine().split(" ");
				Arrays.fill(a, false);
				for (int i=0;i<temp.length;i++)
					if (temp[i].length() > 0){
						int x = Integer.parseInt(temp[i]);
						a[x] = true;
					}
				boolean ok = false;
				for (int i=2;i<MAX;i++){
					boolean f = true;
					for (int j=0;j<11;j++)
						if (a[j] && happy[j][i] == 1){
							f = false;
							break;
						}
					if (f){
						out.write(String.valueOf(i));
						ok = true;
						break;
					}
				}
				if (!ok) System.out.println("shoot!");
				out.write("\n");
			}
			
			out.flush();
		}catch(Exception ex){
			ex.printStackTrace();
		}
	}
}