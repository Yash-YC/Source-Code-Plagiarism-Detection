package src;
import java.io.*;
import java.util.*;
import java.util.regex.*;

public class Main {
	public static void main(String[] args) {
		FileManager fileManager = new FileManager("C:/codejam/A-small-attempt0.in", 
				"C:/codejam/A-small-attempt0.out");
		int testCases = fileManager.getLineIntegerValues(0, 1)[0]+1;
		ArrayList<Integer> bases;
		Integer[] bas;
		int hnum = 0;
		int c = 0;
		int cbase;
		boolean haphap;
		MultiBase num;
		String output = "";
		int size;
		for(int i=1; i<testCases; i++) {
			bases = fileManager.getLineIntegerValues(i);
			size = bases.size();
			bas = new Integer[size];
			bases.toArray(bas);
			hnum = 1;
			c = 0;
			haphap = false;
			while(!haphap) {
				hnum++;
				num = new MultiBase(((Integer)hnum).toString(), 10);
				for(int j=0; j<size; j++) {
					cbase = (int)bas[j];
					haphap = num.isHappy(cbase);
					if(!haphap) {
						break;
					}
				}
			}
			output = output.concat("Case #").concat(((Integer)i).toString().concat(": "));
			output = output.concat(((Integer)hnum).toString().concat("\n"));
		}
		fileManager.saveDataToOutputFile(output);
	}
}
