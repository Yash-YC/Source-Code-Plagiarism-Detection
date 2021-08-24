import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class A implements Runnable {
	BufferedReader in;
	BufferedWriter out;
	final static String filein = "input1.txt";
	final static String fileout = "output1.txt";
	
	List<Integer> base3 = new LinkedList<Integer>();
	List<Integer> base5 = new LinkedList<Integer>();
	List<Integer> base6 = new LinkedList<Integer>();
	List<Integer> base7 = new LinkedList<Integer>();
	List<Integer> base8 = new LinkedList<Integer>();
	List<Integer> base9 = new LinkedList<Integer>();
	List<Integer> base10 = new LinkedList<Integer>();
/*
	int[][] unhappy = {
	{2, 4, 5, 8, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{4, 10, 13, 16, 18, 0, 0, 0, 0, 0, 0, 0},
	{5, 13, 17, 20, 25, 26, 29, 41, 0, 0, 0, 0},
	{2, 4, 8, 10, 13, 16, 17, 25, 29, 32, 37, 45},
	{4, 5, 10, 13, 16, 20, 25, 26, 52, 0, 0, 0},
	{41, 50, 53, 65, 68, 74, 89, 0, 0, 0, 0, 0},	
	};
*/
	int[] b10 = {1, 7, 10, 13, 19, 23, 28, 31, 32, 44, 
		49, 68, 70, 79, 82, 86, 91, 94, 97, 100, 103, 109, 
		129, 130, 133, 139, 167, 176, 188, 190, 192, 193, 
		203, 208, 219, 226, 230, 236, 239, 262, 263, 280, 
		291, 293, 301, 302, 310, 313, 319, 320, 326, 329, 
		331, 338, 356, 362, 365, 367, 368, 376, 379, 383, 
		386, 391, 392, 397, 404, 409, 440, 446, 464, 469, 
		478, 487, 490, 496};
	
	public void solve() throws Exception {
		int tn = iread();
		for(int test=1; test<=tn; test++) {
			//code area: 
			String b = in.readLine();

			String[] nb = b.split(" ");
			int n = nb.length;
			int[] base = new int[n];

			for(int i=0; i<n; i++) {
				base[i] = Integer.parseInt(nb[i]);
			}
			int num = 2;
			boolean flag = true;
			while(true) {
				for(int i=0; i<n; i++) {
					if(!isHappy(num, base[i])) {
						flag = false;
						break;
					}
				}
				if(flag) {
					break;
				} else {
					flag = true;
					num ++;
				}
			}
			out.write("Case #" + test + ": " + num + "\n");
		}
	}
	
	public boolean isHappy(int n, int base) {
		if(base==2 || base==4) {
			return true;
		}
		
		List<Integer> bl;
		if(base==10) {
			bl = base10;
			if(bl.contains(n)) {
				return true;
			}
			int b = 27;
			while(b-->0) {
				n = mul(n, base);
				if(n==1) return true;
				if(bl.contains(n)) {
					return true;
				}
			}
			return false;
		}
		
		switch(base) {
			case 3:
				bl = base3;
				break;
			case 5:
				bl = base5;
				break;
			case 6:
				bl = base6;
				break;
			case 7:
				bl = base7;
				break;
			case 8:
				bl = base8;
				break;
			case 9:
				bl = base9;
				break;
			default:
				return false;
				
		}

		if(bl.contains(n)) {
			return false;
		}
		
		int b = 27;
		while(b-->0) {
			n = mul(n, base);
			if(n==1) return true;
			if(bl.contains(n)) {
				return false;
			}
		}
		
		return true;
	}
	
	public int mul(int n, int base) {
		int ret = 0;
		while(n>0) {
			int temp = n%base;
			ret += temp * temp;
			n /= base;
		}
		return ret;
	}

	
	public long lread() throws Exception {
		return Long.parseLong(readword());
	}
	
	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}
	
	public String readword() throws IOException {
		StringBuilder b = new StringBuilder();
		int c = in.read();
		while (c <= ' ' && c >= 0) {
			c = in.read();
		}
		if (c < 0) return "";
		while (c > ' ') {
			b.append((char)c);
			c = in.read();
		}
		return b.toString();
	}
	
	public void run() {
		try {
			in = new BufferedReader(new FileReader(filein));
			out = new BufferedWriter(new FileWriter(fileout));
			solve();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
    
    public void init() {
    	base3.add(2);
    	base3.add(5);
    	base3.add(8);
    	base5.add(4);
    	base5.add(13);
    	base5.add(18);
    	base6.add(5);
    	base7.add(2);
    	base7.add(10);
    	base7.add(13);
    	base7.add(25);
    	base7.add(32);
    	base7.add(45);
    	base8.add(4);
    	base8.add(5);
    	base8.add(13);
    	base8.add(20);
    	base8.add(52);
    	base9.add(41);
    	base9.add(50);
    	base9.add(53);
    	base9.add(68);
    	for(int i=0; i<b10.length; i++) {
    		base10.add(b10[i]);
    	}
    }
	public static void main(String[] args) {
		A tmp = new A();
		tmp.init();
		new Thread(tmp).start();
	}    
    
}