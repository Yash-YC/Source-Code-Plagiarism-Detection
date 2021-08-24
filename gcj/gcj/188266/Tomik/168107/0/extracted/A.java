package Round1A;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.StringTokenizer;

public class A {
	final static int ilen = 100000;
	static boolean[][] happy;
	
	static int findHappy_start(int curr, int currentbase, int[] list, int ilist) {
		int tmp = list[currentbase];
		while(true) {
			while(!happy[tmp][curr])
				++curr;
			int res = findHappy(curr, currentbase+1, list, ilist);
			if(res == curr)
				return res;
			else
				curr = res;
		}
	}
	
	static int findHappy(int curr, int currentbase, int[] list, int ilist) {
		if(currentbase == ilist)
			return curr;
		
		int tmp = list[currentbase];	
		int currn = curr;
		while(!happy[tmp][currn]) 
			++currn;		
		
		if(currn > curr) {			
			return currn;
		} else {
			int res = findHappy(curr, currentbase+1, list, ilist);
			return res;			
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();		
//		sc.nextLine();
		
		int[] digits = new int[20];		
		happy = new boolean[11][ilen];
		for (int i = 2; i <= 10; i++) {
			happy[i][1] = true;
		}
		for (int i = 2; i <= 10; i++) {
			boolean[] bAssigned = new boolean[ilen];
			bAssigned[1] = true;
			HashSet<Integer> hsSeen = new HashSet<Integer>();
			hsSeen.add(1);
			for (int j = 2; j < ilen; j++) {
				if(hsSeen.contains(j))
					continue;
				
				int tmp = j;
				
				HashSet<Integer> hs = new HashSet<Integer>();
				
				while( (tmp>=j) && !hs.contains(tmp) ) {
					hs.add(tmp);					
					int idigits = 0;
					while(tmp > 0) {
						digits[idigits++] = tmp%i;
						tmp /= i;
					}
					for (int k = 0; k < idigits; k++) {
						tmp += digits[k]*digits[k];
					}
				}
				if(tmp < j) {
					for(Integer in:hs)
						happy[i][in] = happy[i][tmp];					
					
				}
				
				hsSeen.addAll(hs);
			}
		}
		
		int[] list = new int[10];		
		sc.nextLine();
		for (int i = 0; i < T; i++) {	
			String str = sc.nextLine();
			StringTokenizer st = new StringTokenizer(str);
			int ilist = 0;
			while(st.hasMoreTokens()) {				
				list[ilist++] = Integer.parseInt(st.nextToken());
			}
			
			
						
			int currentbase = 0;
			int res = findHappy_start(2, currentbase, list, ilist);
			
			System.out.printf("Case #%d: %d\n", (i+1), res);
		}
	}
}
