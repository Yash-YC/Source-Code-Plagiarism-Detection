import java.io.*;
import java.util.*;
import java.math.*;

public class one{
	public static PrintStream output;
	
	public static void main(String[] args) throws FileNotFoundException{
		Scanner input = new Scanner( new File("A-small-attempt1.in") );
		output = new PrintStream(new File("output.txt") ); //System.out;//
		
		int N = Integer.parseInt(input.nextLine());
		for(int i = 1; i<= N; i++){
			output.print("Case #"+i+": ");
			Scanner line = new Scanner(input.nextLine());
			
			ArrayList<Integer> basesList = new ArrayList<Integer>();
			
			while( line.hasNext() ){
				int a = Integer.parseInt(line.next());
				basesList.add(a);
			}
			explore(basesList);
		}
		
		//BigInteger x = new BigInteger("68");
		//output.println(isHappy(x, 10));
		//output.println(convertToBaseX(10, x));
		//output.println(digitsSquared("100"));
	}
	
	public static void explore(ArrayList<Integer> list){
		//output.println(list);
		BigInteger count = new BigInteger("2");
		boolean foundANumber = false;
		while(!foundANumber){
			int length = list.size();
			boolean flag = true;
			for(int i = 0; i< length && flag; i++){
				flag = isHappy(count, list.get(i));
			}
			if(flag){
				output.println(count);
				foundANumber = true;
			}
			
			count = count.add(BigInteger.ONE);
		}
	}
	
	public static boolean isHappy(BigInteger number, int base){
		number = new BigInteger(convertToBaseX(base, number));
		for(int i = 0; i<=100; i++){
			
			BigInteger sum = digitsSquared(number.toString());
			String convertedSum = convertToBaseX(base, sum);
			//BigInteger s = digitsSquared(convertedSum);
			BigInteger cs = new BigInteger(convertedSum);
			if(cs.compareTo(BigInteger.ONE) == 0){
				//output.println(i);
				return true;
			}
			number = cs;
		}
		return false;
	}
	
	public static BigInteger digitsSquared(String number){
		BigInteger sum = BigInteger.ZERO;
		int length = number.length();
		for(int i = 0; i< length; i++){
			int digit = number.charAt(i)-'0';
			int squared = digit*digit;
			sum = sum.add(new BigInteger(""+squared));
		}
		return sum;
	}
	
	public static String convertToBaseX(int base, BigInteger number){
		//find max
		BigInteger b = new BigInteger(""+base);
		BigInteger count = BigInteger.ZERO;
		int power = 0;
		boolean maxFlag = true;
		while(maxFlag){
			count =  b.pow(power);
			if( count.compareTo(number) > 0 ){
				maxFlag = false;
			}else{
				power++;
			}
		}
		String answer = "";
		while(power>=0){
			BigInteger nextDigit = number.divide(b.pow(power));
			number = number.remainder(b.pow(power));
			answer = answer + nextDigit;
			power--;
		}
		return answer;
	}	
}