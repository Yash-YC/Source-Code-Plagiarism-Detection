import java.util.*;
import java.io.*;

public class GCJ_1A{
	static BufferedReader in;
	public static void main(String[] args) throws Exception{
		in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		
		
		
		int T = Integer.parseInt(in.readLine());
		//for(int i=0;i<10000;i++){
		//   happy(Integer.parseInt(in.readLine()),10);
	//	}
		
		for(int kasus=1;kasus<=T;kasus++){
			String[] temp2 = in.readLine().split(" ");
			
			int[] base = new int[temp2.length];
			
			for(int i=0;i<base.length;i++)
				base[i]=Integer.parseInt(temp2[i]);
			
			int num = 2;
			while(true){
				boolean has = true;
				
				for(int i=0;i<base.length;i++){
					if(!happy(num,base[i])){
						has=false;
						break;
					}
				}
				
				if(has){
					break;
				}
				
				num++;
			}
			
			System.out.println("Case #"+kasus+": "+num);
		}
	}
	
	public static boolean happy(int num, int base) throws Exception{
		HashSet<Integer> set = new HashSet<Integer>();
		
		while(num !=1){
			
			String aa = Integer.toString(num,base);
			//System.out.println(num+" "+aa);			
			num = 0;
			
			for(int i=0;i<aa.length();i++){
				int a = (int)(aa.charAt(i)-'0');
				num += a*a;
			}
			
			if(set.contains(num))break;
			else set.add(num);
		}
		
		if(num==1)return true;
		else return false;
	}
}
