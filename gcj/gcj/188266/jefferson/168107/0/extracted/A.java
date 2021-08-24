package codejam_1A;
import ds.Basics;
import java.io.*;
import java.util.*;

import jdsl.*;
 

public class A {

	public static String toStringBase (int num, int base){
		String result = "";
		while(num >= base){
			result = new Integer(num%base).toString() + result;
			num = num/base;
		}
		return new Integer(num%base).toString() + result;
	}
	
	public static boolean ishappy(int num, int base){
		if(dynamic[num][base-1] != 0){
			if(dynamic[num][base-1] == -1) return false;
			return true;
		}else{
		String n = toStringBase(num, base);
		int soma = 0;
		ArrayList<Integer> nums = new ArrayList<Integer>();
		nums.add(new Integer(num));
		while(true){
			soma = 0;
			for(int i = 0; i < n.length(); i++){
				soma += ((int)n.charAt(i) - 48)*((int)n.charAt(i) - 48);
			}
			if(soma == 1){
				dynamic[num][base-1] = 1;
				return true;
			}else{
				if(nums.contains(new Integer(soma))){
					dynamic[num][base-1] = -1;
					return false;
				}
				nums.add(new Integer(soma));
				n = toStringBase(soma, base);
			}
		}
		}
	}
	static int[][] dynamic = new int[50000][10];
	
	public static int happyinbases(int bases[], int tam){
		int num = 2;
		boolean found = true;
		while(true){
			for(int i = 0; i < tam; i++){
				if(!ishappy(num, bases[i])){
					num++;
					found = false;
					break;
				}
			}
			if(found){
				return num;
			}else{
				found = true;
			}
		}
	}
	public static void main(String[] args) throws IOException{
		String problema = "A-small-attempt0";
		BufferedReader f = new BufferedReader(new FileReader(problema + ".in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("2" + problema + ".in")));
		
		StringTokenizer st = new StringTokenizer(f.readLine());
		
		int T = ds.Basics.read_Int(st);
		int bases[] = new int[9];
		int tam = 0;
		for(int i = 0; i < T; i++){
			st = ds.Basics.read_newLine(f);
			tam = 0;
			for(int j = 0; j < 9 ;j++){
				try{
				bases[j] = ds.Basics.read_Int(st);
				tam++;
				}catch(Exception e){
					break;
				}
			}
			tam = happyinbases(bases, tam);
			System.out.println("Case #"+(i+1)+": "+tam);
		}
	}

}
