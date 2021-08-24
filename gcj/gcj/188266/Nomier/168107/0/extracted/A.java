import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;
import java.math.BigInteger;


public class A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new A().solve();
	
		
	}
	int numbers[][]=new int [10][10];
	boolean  isHappy(String str, int j){
		ArrayList<String> list =new ArrayList<String>();
		while(!list.contains(str)){
			long  y=0;
			for (int i = 0; i < str.length(); i++) {
				y +=(str.charAt(i)-'0')*(str.charAt(i)-'0');
			}
			if(y==1)return true;
			list.add(str);
			str=new BigInteger(y+"").toString(j);
		}
		return false;
	}
	private void solve() {
		try {
			Scanner s =new Scanner(new File("A.in"));
			PrintWriter out = new PrintWriter(new File("A.out"));
//			        BigInteger number = new BigInteger("82");
			        int n =s.nextInt();
			        int no=1;
			        String line = s.nextLine();
			        for (int i = 0; i < n; i++) {
						 line = s.nextLine();
						String tok[]=line.split(" ");
						int bases[]=new int [tok.length];
						for (int j = 0; j < bases.length; j++) {
							bases[j]=Integer.parseInt(tok[j]);
						}
						int cnt =2;
						boolean done = false;
						while(true){
							BigInteger b= new BigInteger(cnt+"");
							for (int j = 0; j < bases.length; j++) {
								b.toString(bases[j]);
//								System.out.println(b.toString(bases[j]));
								boolean bool =isHappy(b.toString(bases[j]),bases[j]);
								if(!bool)break;
								if(bool && j==bases.length-1){
									done=true;
									out.println("Case #"+no+": "+b.toString(10));
									no++;
								}
							}
								if(done)break;
							cnt++;
						}
					}
			       
			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

}
