package info.jonadams.codejam.r1a;

import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;



public class A {
	public HashMap<Key,Boolean> cache = new HashMap<Key,Boolean>();
	
	public static class Key{
		List<Long> number;
		int base;
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + base;
			result = prime * result
					+ ((number == null) ? 0 : number.hashCode());
			return result;
		}
		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Key other = (Key) obj;
			if (base != other.base)
				return false;
			if (number == null) {
				if (other.number != null)
					return false;
			} else if (!number.equals(other.number))
				return false;
			return true;
		}
	}
	
	public boolean isHappy(List<Long> number, int base){
		Key key = new Key();
		key.number = number;
		key.base = base;
		Boolean result = cache.get(key);
		if(result == null){
			try{
				result = isHappyCalc(number, base);
			}catch(StackOverflowError e){
				return false;
			}			
			cache.put(key, result);
		}
		return result;
	}
	public boolean isHappyCalc(List<Long> number, int base){
		long sum = 0;
		for (Long digit : number) {
			sum += digit * digit;
		}
		if(sum == 1){
			return true;
		}else{
			return isHappy(getNumberInBase(sum,base),base);
		}
	}
	
	
	public static List<Long> getNumberInBase(long number,int base){
		long digit = base;
		List<Long> result = new ArrayList<Long>();
		while(number > 0){			
			long digitValue = number % digit;
			result.add(0,digitValue);
			number = (number - digitValue)/base;
		}
		return result;
	}
	public long getLowestHappy(List<Integer> bases){
		for (int i = 2; i < 100000; i++) {
			boolean resultFound = true;
			for (Integer base : bases) {
				if(!isHappy(getNumberInBase(i,base),base)){
					resultFound = false;
					break;
				}
			}
			if(resultFound){
				return i;
			}
		}
		return -1;
	}
	
	/*public static void main(String[] args) {		
		A a = new A();
		List<Integer> bases = new ArrayList<Integer>();
		bases.add(2); 
		bases.add(3); 
		bases.add(7); 
		System.out.println(a.getLowestHappy(bases));
					
	}*/
	
	public static void main(String[] args) throws IOException {
		Class<?> problemClass = A.class;
		PrintStream ps = new PrintStream("out/A-small.out");
		Scanner scanner = new Scanner(problemClass.getResourceAsStream("A-small.in"));
		int tests = scanner.nextInt();
		scanner.nextLine();
		A a = new A();
		for (int i = 0; i < tests; i++) {
			String line = scanner.nextLine();
			String[] sbases=line.split(" ");
			List<Integer> bases = new ArrayList<Integer>();
			for (String sbase : sbases) {
				bases.add(Integer.parseInt(sbase));
			}
			long lowest = a.getLowestHappy(bases);
			String outLine = "Case #"+(i+1)+": "+lowest; 
			ps.println(outLine);
			System.out.println(outLine);
		}
	}
}
