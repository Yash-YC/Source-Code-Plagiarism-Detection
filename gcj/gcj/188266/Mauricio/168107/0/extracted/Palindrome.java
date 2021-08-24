import java.math.*;
import java.io.*;
import java.util.*;
class Main
{
	public Main() throws java.io.IOException
	{
		int a, b, x, y, c, d, l, s, f, z, v, m, w, count, t = 0;
		String A, C;
		Scanner in = new Scanner(new FileReader("A-small-attempt1.in")); 
		PrintWriter writer = null;
		try{	
			writer = new PrintWriter("Output25.txt");
			a = in.nextInt();
			in.nextLine();
			for(x = 0; x < a; x++) {
				int count2 = 0;
				A = in.nextLine();
				Scanner line = new Scanner(A);
				w = line.nextInt();
				c = line.nextInt();
				f = 2; d = 0;
				if(line.hasNext()) {
					d = line.nextInt();
					f++;
				}
				int u[] = new int[f];
				u[0] = w;
				u[1] = c;
				if(f > 2)
					u[2] = d;
				l = 1;
				while(count2 < f){
					count2 = 0;
					l++;
					for(z = 0; z < f; z++){
						w = u[z];
						m = l;
				hello:	for(y = 1; y < 250; y++) {
							m = generate(m,w);
							m = pow(m);
							if(m == 1){
							   count2++;
							   break hello;
							   }
						}
						//System.out.println(l + " " + count2 + " " + m + " " + w);
					}
				}
					//System.out.println(count2);
				writer.println("Case #"+(x+1)+": " + l);
			}
		}catch(IOException ex){
		}
		finally{
			if(writer != null);
			writer.close();
		}
    }
    public int generate(int a, int b)
    {
    	int count, x = 1; count = 0;
    	while(a >= b){
    		count += a%b*x;
    		a /= b;
    		x *= 10;
    	}
    	count += (a*x);
    	return count;
    	   
    }
    public int pow(int a){
    	String A = ""+a;
    	int x, b, c = 0;
    	for(x = 0; x < A.length(); x++) {
    		b = Integer.parseInt("" + A.charAt(x));
    		c += b*b;
    	}
    	return c;
    }
    public static void main(String args[]) throws java.io.IOException
    {
        new Main();
    }
}