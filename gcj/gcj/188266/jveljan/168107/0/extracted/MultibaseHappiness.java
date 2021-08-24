package code.jam.round1a;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class MultibaseHappiness {

	private boolean isHappy(int num, int base) {
		
		List<Integer> results = new ArrayList<Integer>();
		while(true) {
			int [] cifri = getC(num, base);
			int r=0;
			for(int i=0; i<cifri.length; i++) {
				r += cifri[i]*cifri[i];
			}
			if(r==1) return true;
			if(results.indexOf(r)!=-1)
				return false;
			if(results.size()>1000) {
				System.out.println("Houston we have a problem");
				return false;
			}
			results.add(new Integer(r));
			num=r;
		}
	}
	private int[] getC(int num, int base) {
		List<Integer> ls = new ArrayList<Integer>();
		while(num!=0) {
			int c = num%base;
			num = num/base;
			ls.add(new Integer(c));
		}
		int [] rv = new int[ls.size()];
		for(int i=0; i<ls.size(); i++) {
			rv[i] = ls.get(ls.size() - 1 - i).intValue();
		}
		return rv;
	}
	
	void process(File in, File out) throws Exception {
		PrintWriter pw = new PrintWriter(out);
		FileInputStream fis = new FileInputStream(in);
		BufferedReader br = new BufferedReader(new InputStreamReader(fis));
		int lines = Integer.valueOf(br.readLine());
		for(int i=0; i<lines; i++) {
			String [] bases = br.readLine().split(" ");
			int r = calc(bases);
			pw.println("Case #" + (i+1) + ": " + r);
		}
		pw.flush();
		pw.close();
	}
	private int calc(String[] bases) {
		int num = 2;
		while(true) {
			boolean happy = true;
			for(String b : bases) {
				happy = isHappy(num, Integer.valueOf(b));
				if(!happy) break;
			}
			if(happy) return num;
			num++;
			if(num>1000000) {
				System.out.println("DAMN!");
				return num;
			}
		}
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MultibaseHappiness multibaseHappiness = new MultibaseHappiness();
		multibaseHappiness.ajde("res/A-small-attempt0.in");
		//boolean happy = multibaseHappiness.isHappy(82, 3);
		//System.out.println(happy);
		/*int[]cif=multibaseHappiness.getC(4, 2);
		for(int c : cif) {
			System.out.println(c);
		}*/
	}
	private void ajde(String string) {
		File in = new File(string);
		File out = new File(string + ".out");
		try {
			this.process(in, out);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
