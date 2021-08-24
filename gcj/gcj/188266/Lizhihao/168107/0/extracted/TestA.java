package com.google.codejam.lizhihao;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileWriter;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

public class TestA {
	
	private static Map<Integer, Map<Integer, Boolean>>map = new HashMap<Integer, Map<Integer, Boolean>>();
	
	private void calculate() throws Exception{
		int T;
		InputStream in = null;
		BufferedReader br = null;
		FileWriter writer = null;
		try {
			in = ClassLoader.getSystemResourceAsStream("A-small-attempt0.in");
			br = new BufferedReader(new InputStreamReader(in));
			writer = new FileWriter(new File("d:\\A-small.out"));
			T = Integer.parseInt(br.readLine());
			
			for (int i = 0; i < T; i++) {
				String[] bases = br.readLine().split(" ");
				int num = 1;
				Map<Integer, Boolean> m;

				LOOPWHILE : while(true) {
					num++;
					for(String s : bases) {
						if(!map.containsKey(num)) {
							m = new HashMap<Integer, Boolean>();
							map.put(num, m);
						} else {
							m = map.get(num);
						}
						int base = Integer.parseInt(s);
						if(m.containsKey(base)) {
							if(m.get(base))
								continue;
							else 
								continue LOOPWHILE;
						} else {
							boolean isHappy = isHappy(num, base); 
							m.put(base, isHappy);
							if(!isHappy)
								continue LOOPWHILE;
						}
					}
					break;
				}
				writer.write("Case #" + (i+1) + ": " + num + "\n");
			}
			writer.flush();
		} finally {
			if(in != null)
				try{in.close();}catch(Exception e){}
			if(br != null)
				try{br.close();}catch(Exception e){}
			if(writer != null)
				try{writer.close();}catch(Exception e){}
		}
	}
	
	private boolean isHappy(int num, int base) {
		HashSet<Long> set = new HashSet<Long>();
		long s = Long.parseLong(Long.toString(num, base));
		while(true) {
			long count = 0;
			while(s > 0) {
				int i = (int)s%10;
				s = s/10;
				count += i*i;
			}
			count = Long.parseLong(Long.toString(count, base));
			if(set.contains(count))
				break;
			if(count == 1)
				return true;
			set.add(count);
			s = count;
			
		}
		return false;
	}
	
	public static void main(String[] args) throws Exception {
		TestA a = new TestA();
		a.calculate();
	}

}
