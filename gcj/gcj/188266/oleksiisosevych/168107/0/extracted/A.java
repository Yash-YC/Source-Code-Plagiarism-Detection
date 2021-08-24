import java.util.*;
import java.io.*;
public class A {

	/**
	 * @param args
	 * @throws IOExceptions 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new FileReader("E:\\programming\\workspace\\Google_Code_Jam\\input_output\\A.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("E:\\programming\\workspace\\Google_Code_Jam\\input_output\\A.out")));
		int nTests = Integer.parseInt(br.readLine());
		int casen=1;
		while (nTests-->0){
			StringTokenizer st = new StringTokenizer(br.readLine());
			int[] bases = new int[st.countTokens()];
			for (int i = 0; i < bases.length; i++) {
				bases[i]=Integer.parseInt(st.nextToken());
			}
			int res=2;
			while(true){
				boolean ok=true;
				for (int i = 0; i < bases.length; i++) {
					if(!check(to_base(res,bases[i]),bases[i]))ok=false;	
				
				}
				if(ok)break;
			res++;
			
			}
			out.println("Case #"+casen+++": "+res);
		}
		out.close();
	}
	public static String to_base(int a, int base){
		String res="";
		while(a!=0){
			res=(int)a%base+res;
			a=a/base;
		}
		return res;
	}
	public static boolean check(String num,int base){
		String res="";
		ArrayList<String> temp =new ArrayList<String>();

		while(true){
			temp.add(num);
			String a_string=num;
			int a=0;
			for (int i = 0; i < a_string.length(); i++) {
				a+=(a_string.charAt(i)-'0')*(a_string.charAt(i)-'0');
			}
			if(a==1)break;
			num=to_base(a,base);
			
			if(temp.indexOf(num)!=-1) return false;
		}
		return true;
	}
	
}
