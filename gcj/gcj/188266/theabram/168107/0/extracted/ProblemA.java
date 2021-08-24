package a;

import java.util.*;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class ProblemA {

	private static long step(long n,int base) {
		long res=0; 
			while (n!=0) {
				res += (n%base)*(n%base);
				n/=base;
			}
		return res;	
	}
	
	private static boolean isHappy(long a,int base) {
		HashSet<Long> ht = new HashSet<Long>();
		
		
		
		for (long res = a;res!=1;res = step(res,base)) {
			if (res==1) return true;
			if (ht.contains(res)) return false;
			
			ht.add(res);
			
		}
		// should be unreachable...
		return true;
		
	}
	
	
	
	public static void main(String[] args) {
		
		
		

		
		try {
			BufferedReader in = new BufferedReader(new FileReader(args[0]));
			BufferedWriter out = new BufferedWriter(new FileWriter(args[1]));
			
			
			
			int casesNum = Integer.parseInt(in.readLine());
			
			for (int aCase=0; aCase < casesNum; ++aCase) {
				String[] basesLine = in.readLine().split(" ");
				int[] bases = new int[basesLine.length];
				for (int b = 0; b < basesLine.length; ++b) {
					bases[b] = Integer.parseInt(basesLine[b]);
					
				}
				for (int i=2;i<Integer.MAX_VALUE;++i) {
					int b=0;
					for (b=0;b<basesLine.length;++b) {
						if (!isHappy(i,bases[b])) break;
					}
					if (b < basesLine.length && !isHappy(i,bases[b])) continue;
					
					System.out.print("Case #"+(aCase+1)+": "+i+"\n");
					out.write("Case #"+(aCase+1)+": "+i+"\n");	
					
					break;
				}
				
			}
			
			
			in.close();
			out.close();
		} catch (Exception e) {
			// TODO: handle exception
		}

	}

}
