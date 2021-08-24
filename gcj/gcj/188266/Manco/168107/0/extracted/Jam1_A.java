package src.codeJam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.HashMap;
import java.util.Scanner;

public class Jam1_A {
	static PrintStream o = System.out;
	static boolean isH = false;
	// for each base, the happy list.
	static HashMap<Integer, LinkedList<Integer>> Visit = new HashMap<Integer, LinkedList<Integer>>();
	static HashSet<Integer> Closed;
	
	public static boolean iHappy(int iSelf, int iBase){
		if (iSelf==1) return true;
		if (Closed.contains(iSelf)) return false;
		Closed.add(iSelf);
		String ss = Integer.toString(iSelf, iBase);
//		o.println(ss);
		int iLen = ss.length();
		String[] sa = new String[iLen];
		int[] ia = new int[iLen];
		int iSum = 0;
		for (int i=0; i<iLen; i++){
			sa[i] = ss.substring(i, i+1);
			ia[i] = Integer.parseInt(sa[i], iBase);
			iSum += ia[i] * ia[i];
		}
		return iHappy(iSum, iBase);
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		BufferedReader bin = new BufferedReader(new FileReader("I:/codejam/1_A-small-attempt0.in.txt"));
		PrintWriter bout = new PrintWriter(new BufferedWriter(
				new FileWriter("I:/codejam/1_A_rlt.txt")));
		int iL = Integer.parseInt(bin.readLine());

		
		for (int i=0; i<iL; i++){
//			o.println("Happy: "+iHappy(3,2));
			String nextline = bin.readLine();
			String[] sa = nextline.split(" ");
			
			int iMin = 2;
			int iLS = sa.length;
			for (int j=0; j<iLS; j++){
				int thebase = Integer.parseInt(sa[j]);
				LinkedList<Integer> list;
				list = new LinkedList<Integer>();
				Visit.put(thebase, list);
			}// init
			int iC=0,j=0, iPrev=2, iCur=0;
			while (iC<iLS){
				iC++;
				iPrev = iMin;
				int thebase = Integer.parseInt(sa[j]);
				for (; iMin<Integer.MAX_VALUE; iMin++){
					Closed = new HashSet<Integer>();
					if (iHappy(iMin, thebase)){
						break;
					}
				}
				j++; if (j>=iLS) j=0;
				if (iPrev != iMin) iC=0;
//				list.addLast(iMin);
//				iMin = Visit.get(thebase).getLast();
			}
			bout.printf("Case #%d: %d%n", i+1, iMin);
		}
		bout.close();
		bin.close();
	}

}
