package A;

import java.io.*;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Scanner;

public class ProbA0912 {
		
	public static String PATH = "Sep12_2009/A/"; 
	private int T;
	private int[] bases;
	
	private void writeAns(int i,int ans, BufferedWriter out) throws Exception{
		out.write("Case #"+(i+1)+": "+ans);
		out.newLine();
	}
	
	public void run(Scanner scan, BufferedWriter out) throws Exception{
		this.T = scan.nextInt();
		scan.nextLine();
		for (int i = 0; i < this.T; i++) {
			this.compute(scan.nextLine(),i,out);
		}
	}
	
	private void compute(String line, int test, BufferedWriter out) throws Exception {
		String[] temp=line.split(" ");
		bases = new int[temp.length];
		for (int i = 0; i < temp.length; i++) {
			bases[i] = Integer.parseInt(temp[i]);
		}
		int res = 2;
		while (!testInt(res)) res++;
		this.writeAns(test, res, out);
	}
	
	private boolean testInt(int res){
		for (int i = 0; i < bases.length; i++) {
			hashMap = new HashMap<Integer, Boolean>(bases[i]*bases[i]+1);
			if (!isHappy(res, bases[i])) return false;
		}
		return true;
	}
	
	HashMap<Integer, Boolean> hashMap;
	
	private boolean isHappy(int res,int base){
		if (res == 1) return true;
		if (null!=hashMap.put(res, true)) return false;
		LinkedList<Integer> list = convertToBaseArray(res, base);
		int sum = 0;
		for (Iterator<Integer> iterator = list.iterator(); iterator.hasNext();) {
			Integer integer = (Integer) iterator.next();
			sum+=integer*integer;
		}
		if (sum==res) return false;
		return isHappy(sum, base);
	}
	
	private LinkedList<Integer> convertToBaseArray(int res, int base){
		LinkedList<Integer> list = new LinkedList<Integer>();
		while (res>0){
			list.addFirst(res%base);
			res = res/base;
		}
		return list;
	}

	public static void main(String[] args) {
		args = new String[]{"A-small-attempt0.in","A-small-attempt0.out"};
		try{
			File infile = new File(PATH+args[0]);
			Scanner scan = new Scanner(infile);
			FileWriter fstream = new FileWriter(PATH+args[1]);
	        BufferedWriter out = new BufferedWriter(fstream);
	        new ProbA0912().run(scan, out);
	        scan.close();
	        out.close();
		}
		catch (Exception e)
        {
			System.err.println("Error:");
			System.err.println(e.getMessage());
			e.printStackTrace();
        }	
	}
}
