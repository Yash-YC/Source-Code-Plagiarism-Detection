package com.google.codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Q1 {

	private String inputFileName = "c:\\input.in";
	private String outputFileName = "c:\\output.out";
	
	BufferedReader reader;
	PrintWriter writer;
	StringTokenizer st;// = new StringTokenizer(reader.readLine());
	
	public Q1() throws IOException {
		 reader = new BufferedReader(new FileReader(inputFileName));
		 writer = new PrintWriter(new BufferedWriter(new FileWriter(outputFileName)));
	}
	
	private void closeWriter() {
		writer.close();
	}
	
	private void readInput() throws IOException {
		//TODO:
	}
	
	private void execute() throws IOException {
		int count = Integer.parseInt(reader.readLine());
		for (int i=0; i<count; i++) {
			String[] s =  reader.readLine().split(" ");
			int [] bases = new int[s.length];
			for (int j=0; j<s.length; j++) {
				bases[j] = Integer.parseInt(s[j]);
			}
			long number = 1;
			String n;
			Long x;
			HashSet<Long> set = new HashSet<Long>();
			while (true) {
				number++;
				boolean found = false;
				
				for (int j=0; j<s.length; j++ ) {
					found = false;
					set.clear();
					x = number;
					while (!set.contains(x)){
						set.add(new Long(x));
						n = numberToBase(bases[j], x);
						x = multiply(n);
						if (x==1) {
							found = true;
							break;
						}
					}
					if (!found) break;
				}
				if (found) {
					writer.write("Case #" + (i+1) + ": " + number + "\n");
					break;
				}
			}
			
		
			
		}
		readInput();
	}
	
	public String numberToBase(int base, long number) {
		String num = "";
		long x = base;
		while (x<=number) {
			x *= base;
		}
		do {
			x /= base;
			num += number/x;
			number = number % x;
		} while (x>1);
		return num;
	}

	private long multiply(String s) {
		int x = 0;
		int y;
		for (int i=0; i<s.length(); i++) {
			y = s.charAt(i)-'0';
			x += y*y;
		}
		return x;
	}
	
	public static void main(String[] args) throws IOException {
		Q1 obj = new Q1();
		obj.execute();
		obj.closeWriter();
	}

}
