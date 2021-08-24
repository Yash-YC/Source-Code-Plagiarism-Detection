import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;


public class HappyBase {
	private Map<Integer,Map<Integer,Boolean>> map;
	public HappyBase() {
		map = new HashMap<Integer,Map<Integer,Boolean>>();
		for (int i = 2; i <=10; i++) {
			Map<Integer,Boolean> baseMap = new HashMap<Integer,Boolean>();
			baseMap.put(1, true);
			baseMap.put(i, true);
			map.put(i, baseMap);
		}
	}
	
	public boolean isHappy(int number, int base) {
		Map<Integer,Boolean> computed = map.get(base);
		if (computed.containsKey(number)) {
			return computed.get(number);
		}
		computed.put(number, false);
		List<Integer> digits = getDigitsInBase(number,base);
		int sum = sumOfSquares(digits);
		boolean result = isHappy(sum, base);
		computed.put(number, result);
		return result;
	}
	
	private List<Integer> getDigitsInBase(int number, int base) {
		List<Integer> digits = new ArrayList<Integer>();
		while(number > 0) {
			digits.add(number % base);
			number = number / base;
		}
		return digits;
	}
	
	private int sumOfSquares(List<Integer> digits) {
		int sum = 0;
		for (int i=0; i < digits.size(); i++) {
			sum += digits.get(i)*digits.get(i);
		}
		return sum;
	}
	
	public static void main(String[] args) throws IOException {
		File input = new File("c:\\codejam\\A-small-attempt0.in");
		File output = new File("c:\\codejam\\A.small.output.txt");
		BufferedReader reader = new BufferedReader(new FileReader(input));
        BufferedWriter writer = new BufferedWriter(new FileWriter(output));
        int T = Integer.parseInt(reader.readLine());
        HappyBase tester = new HappyBase();
        for (int test = 1; test <= T; test++) {
			Scanner scanner = new Scanner(reader.readLine());
	        List<Integer> bases = new ArrayList<Integer>();
	        while(scanner.hasNextInt()) {
	        	bases.add(scanner.nextInt());
	        }
	        boolean happy = false;
	        int num = 1;
	        while(!happy) {
	        	num++;
	        	boolean testHappy = true;
	        	for (int base : bases) {
	        		testHappy = testHappy && tester.isHappy(num, base);
	        	}
	        	happy = testHappy;
	        }
	        writer.write("Case #" + test + ": " + num);
	        writer.newLine();
		}
		reader.close();
        writer.close();
	}
}
