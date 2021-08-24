package com.gplex.year2016.world.round_1A;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;


public class A_TheLastWord_small {
	private static final Logger logger = LoggerFactory.getLogger(A_TheLastWord_small.class); private static Scanner sc; 	private static PrintWriter pw;	private static File in, out;
	public static void init(){ try {  String path = "src/main/java/" + A_TheLastWord_small.class.getCanonicalName().replace(".", "/"); in = new File(path + "_in.txt"); in.createNewFile(); sc = new Scanner(in); out = new File(path +"_out.txt"); pw = new PrintWriter(new FileWriter(out));}catch(Exception e){logger.error("",e);}}
    public static void closeFiles(){ pw.flush(); pw.close(); sc.close();}	
    public static long gcd(long a, long b) { if (b==0) return a;  return gcd(b,a%b);} public static long lcm(long a, long b){ return a * (b / gcd(a, b));}
    
	public static void main(String[] args) throws Throwable{
	    init();
		int numberOfTestCases =  sc.nextInt(10);
		//numberOfTestCases = 1;
		sc.nextLine();
		for(int caseNum=0;caseNum<numberOfTestCases;caseNum++){

		    char[] word = sc.nextLine().toCharArray();
			String s = ""+word[0];
			for(int i= 1; i< word.length; i++){

			if(s.charAt(0) <= word[i]){
				s = word[i]+s;

			}else{
				s+= word[i];
			}

			}
			String result = String.format("Case #%d: %s", caseNum+1,s);
			pw.println(result);
			logger.debug("{}\n\n", new Object[]{result});
		
		}
  	    closeFiles();
 		
	}

}
