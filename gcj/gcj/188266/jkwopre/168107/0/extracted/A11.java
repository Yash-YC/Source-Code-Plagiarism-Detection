package com.codejam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class A11 {
	
	
	public static String base(long n , long r) {
		String sb = "";
		while (n != 0) {
			long rem = n % r;
			sb = rem + sb;
			n = n / r;
		}
		
		return sb;
	}
	
	public static long happy(String n, int r) {
		Map<String, String> values = new HashMap<String, String>();
		while (true) {
			long h = 0; 
			for(int i=0;i<n.length(); i++) {
				int rem = Integer.parseInt(""+n.charAt(i));
				h += (rem * rem);
			}
			if (values.get("" + h) != null) {
				return h;
			}
			values.put(""+h, ""+h);
			n = base(h,r);
		}	
	}

	/**
	 * @param argsa
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		
		File f = new File("input.txt");
		FileInputStream fis = new FileInputStream(f);
		BufferedReader br = new BufferedReader(new InputStreamReader(fis));
		File x = new File("output.txt");
		FileWriter output = new FileWriter(x);
		long t = Integer.parseInt(br.readLine());
		
		for(long i=0;i<t;i++) {
		 Scanner sc = new Scanner(br.readLine());
		 List<Integer> bases = new ArrayList<Integer>();
		 while (sc.hasNext()) {
			 bases.add(sc.nextInt());
		 }
		 
			out: for(long n=2;n<Long.MAX_VALUE;n++){
				 for(int j=0;j<bases.size();j++) {
					 long h = happy(base(n, bases.get(j)), bases.get(j));
					 if (h != 1)
						 break;
					 
					 if (j == bases.size() - 1) {
						 output.write("Case #"+ (i+1) + ": " + n + "\n");
						 break out;
					 }
				 }
		     }
			
		}

		br.close();
		output.flush();
		output.close();	
	}

}
