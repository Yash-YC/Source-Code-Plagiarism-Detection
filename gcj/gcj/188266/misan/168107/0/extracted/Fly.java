// by Miguel Sanchez misan@disca.upv.es
import java.io.*;
import java.util.*;

class Fly {

static int counter=100;

	public static boolean happy(int num, int base) {
		counter--;
		String s = Integer.toString(num,base);
		//System.out.println(num+":"+s);
		if(num==0) return false;
		if(s.equals("1")) return true;
		else {
			int n=0;
			for(int j=0;j<s.length();j++) { 
				int a = Integer.parseInt(s.substring(j,j+1));
				n+=a*a;
			}
			if(counter==0) {counter=100; return false; } else return happy(n,base);
		}
	}
	public static void main(String args[])throws IOException {
		//for(int a=0;a<10; a++) System.out.println(hit(a+0.1,10,1,1,1));
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();  in.nextLine();
		for(int i=1;i<=cases;i++) {  // FOR EACH CASE ....
			String line = in.nextLine();
			String[] tokens = line.split(" ");
			int[] bases = new int[tokens.length];
			for(int k=0;k<tokens.length; k++) {
				bases[k]=Integer.parseInt(tokens[k]);				
			}

			int l=2;			
			int hits=0;
			while(hits<bases.length) {
				hits=0;	
				for(int each : bases) {			
					if (happy(l,each)) hits++;
				}
				if(hits==bases.length) break; else l++;
			}





	
	

		System.out.println("Case #"+i+": "+l);
		}
  	}

}
