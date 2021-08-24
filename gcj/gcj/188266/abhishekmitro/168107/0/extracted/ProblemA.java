package Round1A;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ProblemA {

	
	static boolean  unhappy[][] = new boolean[10][1000];
	public static void main(String[] args) throws Exception {
		
		
		
		for(int i =0;i<10;i++)
		Arrays.fill(unhappy[i], false);
			
		File inputFile = new File("./Round1/ProblemA.in.txt");
		File outputFile = new File("./Round1/ProblemA.out.txt");

		BufferedReader br = new BufferedReader(new FileReader(inputFile));
		BufferedWriter bw = new BufferedWriter(new FileWriter(outputFile));
		
		int testcases = Integer.parseInt(br.readLine());
		System.out.println(testcases);
		
		for(int i=0;i<testcases;i++){
			
			String tmp[] = br.readLine().split(" ");
			
			int min=2;
			boolean found = false;
			System.out.println("case " + i);
			outer:
			do{
				System.out.println("Min " + min);
				found = true;
				inner:
			for(int j=0;j<tmp.length;j++){
				
				int base = Integer.parseInt(tmp[j]);
				
				
				if(!isHappy(min, base, new ArrayList<String>())){
					found = false;
						break inner;
				}
			
				
				
					
				}
				
				if(found)
					break outer;
			
				min++;
//				System.out.println(min);
			}while(!found);
				
			bw.write("Case #" + (i+1) + ": " + min);
			bw.newLine();
			}
		
		bw.close();
		br.close();

		
		
	}
	
	static String convertToBase(int n, int base) {
	      if (n == 0) return "0";

	       String digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	       String s = "";
	       while (n > 0) {
	          int d = n % base;
	          s = digits.charAt(d) + s;
	          n = n / base;
	       }
	       return s;
	    }

	
	private static boolean isHappy(int min, int base, List<String> list){
		
		String str = convertToBase(min, base);
		
		System.out.println("Num:" + str +  " Base:" + base + " List:" + list);
		int sum = 0;
		for(int i=0;i<str.length();i++){
			sum += Math.pow(Integer.parseInt(""+str.charAt(i)),2);
		}
			System.out.println(sum);
		if(sum == 1)
			return true;
		
		else{
			
			if(unhappy[base-1][sum])
				return false;
			
			String str1 = convertToBase(sum, base);
			
			if(list.contains(str1)){
				
				unhappy[base-1][sum] = true;
				return false;
			}
				
			
			list.add(str1);
			return isHappy(sum, base, list);
		}
			
		
		
		
	}

}
