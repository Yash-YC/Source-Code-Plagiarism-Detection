import java.io.*;
import java.util.*;

public class MultiBaseHappiness{
	public static void main(String[] args){
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try{
			int T = new Integer(br.readLine());
			for(int i = 0; i < T; i++){
				List<Integer> bases = new ArrayList<Integer>();
				for(String base : br.readLine().split(" ")){
					bases.add(new Integer(base));
				}
				for(int num = 2; num < Integer.MAX_VALUE; num++){
					if(isAllHappy(num, bases)){
						System.out.printf("Case #%d: %d\n", i+1, num);
						break;
					}
				}
			}
		}
		catch(Exception e){
						e.printStackTrace();
		}
	}

	public static boolean isAllHappy(int num, List<Integer> bases){
		for(int base : bases){
			if(!isHappy(Integer.toString(num, base), base)){
				return false;
			}
		}
		return true;
	}

	public static boolean isHappy(String num, int base){
		Set<String> set = new HashSet<String>();
		String n = num;
		do{
			if(!set.add(n)){
				return false;
			}
			n = Integer.toString(new Integer(digitSquare(n)),base);
		}while(!n.equals("1"));
		return true;
	}

	public static String digitSquare(String num){
		int result = 0;
		for(char cdigit : num.toCharArray()){
			int digit = new Integer(Character.toString(cdigit));
			result += digit * digit;
		}
		return ""+result;
	}
}
