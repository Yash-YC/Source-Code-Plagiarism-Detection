package j2009r1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.regex.Pattern;

public class A {
	public static String inputDirectory="src/j2009r1a/";
	public static String inputFile="A.in";
	public static String outputFile="A.out";
	public static PrintWriter output;
	public static Map<String,Boolean> happyMap;
	public static void main(String[] args) throws FileNotFoundException{
		Scanner s=new Scanner(new File(inputDirectory+inputFile));
		output=new PrintWriter(new File(inputDirectory+outputFile));
		happyMap=new HashMap<String,Boolean>();
		int N=s.nextInt();
		s.nextLine();
		/*for(int i=0;i<20;i++){
			for(int j=2;j<=10;j++){
				out(i+" in base "+j);
				digitsBaseN(i,j);
			}
		}*/
		for(int Case=1;Case<=N;Case++){
			List<Integer> nums=new ArrayList<Integer>();
			Scanner s2=new Scanner(s.nextLine());
			while(s2.hasNextInt())nums.add(s2.nextInt());
			long smallestNum=2;
			while(true){
				boolean pass=true;
				for(int i=0;i<nums.size();i++){
					pass=pass && isHappy(smallestNum,nums.get(i));
				}
				if(pass)break;
				smallestNum++;
			}
			
			out("Case #"+Case+": "+smallestNum);
		}
		output.flush();
	}
	public static boolean isHappy(long num, int base){
		String key=base+" "+num;
		if(happyMap.get(key)!=null)return happyMap.get(key);
		happyMap.put(key,false);
		//out("is "+num+" happy in base "+base);
		int[] digs=digitsBaseN(num,base);
		int sum=0;
		for(int i=0;i<digs.length;i++)sum+=digs[i]*digs[i];
		boolean happy=sum==1 || isHappy(sum,base);
		happyMap.put(key,happy);
		//out(""+happy);
		return happy;
	}
	public static int[] digitsBaseN(long num, int base){
		if(num==0)return new int[]{0};
		String s="";
		while(num>0){
			s=num%base+s;
			num/=base;
		}
		//out(s);
		int[] arr=new int[s.length()];
		for(int i=0;i<arr.length;i++)
			arr[i]=Integer.parseInt(""+s.charAt(i));
		return arr;
	}

	public static void out(String s){
		output.println(s);
		System.out.println(s);
	}
}
