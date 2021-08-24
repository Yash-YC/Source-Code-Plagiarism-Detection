import java.io.File;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Vector;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			Scanner in = new Scanner(new File("input"));
			PrintWriter out = new PrintWriter(new File("output"));
			int tc = in.nextInt();
			in.nextLine();
			for(int t = 0; t < tc; t++) {
				String s = in.nextLine();	
				String[] a = s.split(" ");
				int b = Integer.parseInt(a[0]);
				if(a.length == 1 && b == 2) {
					out.println("Case #"+(t+1) + ": 2");
					continue;
				}
				int st = 0;
				if(b == 2) st = 1;
				b = Integer.parseInt(a[st]);
				int m;
				boolean f = true;
				for(int j = 2; j < 3000000; j++){
					if(isHappy(j,b)) {
						//System.out.println("^"+j);
						f = true;
						for(int i = st + 1; i < a.length; i++){
							m = Integer.parseInt(a[i]);
							if(!isHappy(j,m)){
								f = false;
								break;
							}
							
						}
						if(f){
							out.println("Case #"+(t+1) + ": "+j);
							break;
						}
					}
				}
				
			}
			out.close();
			
		} catch(Exception e){
			
		}
	}
	
	public static boolean isHappy(int n, int b){
		int sum = 0;
		HashSet<Integer>u = new HashSet<Integer>();
		boolean f = true;
		while(f){
			sum = 0;
			//System.out.println(n);
			while(n > 0) {
				sum += (n % b)*(n % b);
				n /= b;
			}
			if(sum == 1){
				return true;
			}
			if(u.contains(sum)){
				return false;
			}
			u.add(sum);
			n = sum;
		}
		return false;
	}

}
