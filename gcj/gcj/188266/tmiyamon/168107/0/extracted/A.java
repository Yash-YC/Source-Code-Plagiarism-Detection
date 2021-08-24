
import java.io.*;
import java.util.*;

import static java.lang.Math.*;


public class A {
	public static void main(String[] args) throws Exception {
		BufferedReader  reader = new BufferedReader(new FileReader(args[0]));
		int index = 1;
		reader.readLine();
		String line = "";
		while((line = reader.readLine()) != null){
			String[] data = line.split(" ");
			int i = 2;
			while(true){
				boolean ok = true;
				for (int j = 0; j < data.length; j++) {
					int base = Integer.parseInt(data[j]);
					String c = convert(i, base);
//					System.out.println("i = " + i);
//					System.out.println("c = " + c);
//					System.out.println();
					if(!isHappy(c, base)){
						ok = false;
						break;
					}
//					System.out.println();
				}
				if(ok){
					break;
				}
				i++;
			}

			System.out.printf("Case #%d: %d\n", index++, i);
		}
	}
	private static boolean isHappy(String str, int base){
		String current = str;
		Set<String> set = new HashSet<String>();
		while(true){
			set.add(current);
			String sc = convert(calc(current),base);
			if(sc.equals("1")){
				return true;
			}
			if(set.contains(sc)){
				return false;
			}
			current = sc;
			
		}
	}
	
	private static int calc(String str){
		int n = 0;
		for (int i = 0; i < str.length(); i++) {
			int tmp =  Integer.parseInt(String.valueOf(str.charAt(i)));
			n += tmp*tmp;	
		}
		return n;
	}
	private static String convert(int n, int base){
		String ret = "";
		
		int a = n;
		while(a > 0 ){
			ret += a%base;
			a = a/base;
		}
		String tmp = "";
		for (int i = ret.length() - 1; i > -1; i--) {
			tmp += ret.charAt(i); 
			
		}
		return tmp;
	}
}