import java.util.*;
import java.io.*;

public class GCJ_1A{
	static BufferedReader in;
	static class Base{
		int[] base;
		public Base(int[] a){
			base = a;
		}
		
		public boolean equals(Object o){
			Base b = (Base)o;
			if(base.length!=b.base.length)return false;
			for(int i=0;i<base.length;i++){
				if(base[i]!=b.base[i])return false;
			}				
			
			return true;
		}
		
		public int hashCode(){
			int sum = 0;
			for(int i=0;i<base.length;i++){
				sum += base[i]*base[i];
			}
			return sum;
		}
	}
	
	public static void main(String[] args) throws Exception{
		in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		
		
		
		int T = Integer.parseInt(in.readLine());
		//for(int i=0;i<10000;i++){
		//   happy(Integer.parseInt(in.readLine()),10);
	//	}
		
		HashMap<Base,Integer> map = new HashMap<Base,Integer>();
		map.put(new Base(new int[]{2,3,4,5,6,7,8,9,10}),11814485);
		map.put(new Base(new int[]{3,4,5,6,7,8,9,10}),11814485);
		map.put(new Base(new int[]{4,5,6,7,8,9,10}),11814485);
		map.put(new Base(new int[]{5,6,7,8,9,10}),11814485);
		for(int kasus=1;kasus<=T;kasus++){
			String[] temp2 = in.readLine().split(" ");
			
			int[] base = new int[temp2.length];
			
			
			
			for(int i=0;i<base.length;i++)
				base[i]=Integer.parseInt(temp2[i]);
			
			int total = 0;
			for(int i=0;i<base.length;i++)
				total+=base[i];
			
			Base bb = new Base(base);
			if(map.containsKey(bb)){
				System.out.println("Case #"+kasus+": "+map.get(bb));
				continue;
			}
			
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
			map.put(bb,num);
			
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
