import java.io.*;
import java.util.*;

public class ProblemA {

	public static void main(String[] args) throws IOException {

		Scanner sc = new Scanner(new File("c:\\Asmall.in"));
		PrintWriter out = new PrintWriter(new FileWriter("c:\\Asmall.out"));
		
		int T = Integer.parseInt(sc.nextLine().trim());
		//int T = 1;
		
		for (int i = 0; i < T; i++) {
			String []line = sc.nextLine().split(" ");
			//String []line = {"3"};
			
			int []bases = new int[line.length];
			//int []bases = new int[]{2};
			
			for(int j = 0; j < line.length; j++ ){
				bases[j] = Integer.parseInt(line[j]);
			}
			
			int num = 1;
			
			while (true){
				int count = 0;
				num++;
				
				for(int j = 0; j < bases.length; j++){
					if(perfect(num,bases[j])){
						//System.out.println("Num = " + num + " base = " + bases[j]);
						count++;
					}
				}
				
				if(count == bases.length){
					break;
				}
				
			}
			
			out.println("Case #" + (i + 1) + ": " + num); 			
		}

		out.flush();
	}

	private static boolean perfect(int num, int base) {
		ArrayList <Integer>ls = new ArrayList<Integer>();
		return check(convertToBase(num,base), base, ls);
	}

	private static boolean check(int num, int base, ArrayList<Integer> ls) {
		if(num == 1){
			return true;
			//return checkSingleDigit(num, base);
		}
	
		else{
			int newnum = squaredigit(num,base);
			if(ls.contains(new Integer(newnum))){
				return false;
			}
			ls.add(newnum);
			return(check(newnum,base,ls));
		}
		
	
	}

	private static boolean checkSingleDigit(int num, int base) {
		if(num == 1){
			return true;
		}
		
		if((base == 9) && (num == 3)){
			return true; 
		}
		
		return false;
	}

	private static int squaredigit(int num, int base) {
		int sum = 0;
		
		while(num != 0){
		  int dig = num % 10;
		  sum += (dig * dig);
		  num = num / 10;
		}
		return convertToBase(sum,base);
	}

	private static int convertToBase(int num, int base) {
		if(base == 10){
			return num;
		}
		
		StringBuffer buf = new StringBuffer();
		
		if(num == 0){
			return num;
		}
		
		while(num != 0){
			buf.append(num % base);
			num = num / base;
		}
		return Integer.parseInt(buf.reverse().toString());	
	}

}
