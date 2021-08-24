package codejam.y2009.r1.a;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.SortedSet;
import java.util.TreeSet;

public class Happiness {
	public static void main(String[] args) throws IOException{
		String basename = 
			"/home/matt/workspace/competitions/src/codejam/y2009/r1/a/A-small-attempt0";
		BufferedReader br = new BufferedReader(new FileReader(basename+".in"));
		FileWriter fw = new FileWriter(basename + ".out");
		int numCases = Integer.parseInt(br.readLine());
		for (int i = 1; i <= numCases; i++){
			int[] bases = convertStringsToInts(br.readLine().split(" "));
			int h = getSmallestHappyForGivenBases(bases);
			String output = "Case #" + i + ": " + h; 
			fw.write(output + '\n');
			System.out.println(output);
		}
		fw.close();
	}
	
	private static int getSmallestHappyForGivenBases(int[] bases) {
		SortedSet<Integer> sads = new TreeSet<Integer>();
		loop:for (int i = 2; true; i++){
			if (sads.contains(i)) continue;
			for (int base : bases){
				if (!isHappy(i, base)){
					sads.add(i);
					continue loop;
				}
			}
			return i;
		}
	}
	
	private static boolean isHappy(Integer i, int base){
		HashSet<Integer> trail = new HashSet<Integer>();
		while(true){
			if (i == 1) return true;
			else if (trail.contains(i)) return false;
			trail.add(i);
			int sum = 0;
			char[] digits = Integer.toString(i, base).toCharArray();
			for (Character c : digits){
				int digit = Integer.parseInt(c.toString(), base);
				sum += digit*digit;
			}
			i = sum;
		}
	}
	public static int[] convertStringsToInts(String[] s){
		int[] ints = new int[s.length];
		for (int i = 0; i < s.length; i++){
			ints[i] = Integer.parseInt(s[i]);
		}
		return ints;
	}
}
