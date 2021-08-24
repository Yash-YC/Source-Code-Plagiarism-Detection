import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;


public class RankAndFile {
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		
		for (int i = 1; i <= n; i++) {
			int x = input.nextInt();
			List<Integer> numbers = new LinkedList<Integer>();
			
			for (int j = 0; j < (2*x-1)*x; j++) {
				numbers.add(input.nextInt());
			}
			
			solve(i, numbers);
		}
		
		input.close();
	}
	
	private static void solve(int n, List<Integer> numbers) {
		Collections.sort(numbers);
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		
		for (Integer i : numbers) {
			if (map.containsKey(i)) {
				map.put(i, map.get(i) + 1);
			} else {
				map.put(i, 1);
			}
		}
		
		List<Integer> result = new LinkedList<Integer>();
		
		for (Integer i : map.keySet()) {
			if (map.get(i) % 2 == 0) continue;
			result.add(i);
		}
		
		Collections.sort(result);
		
		StringBuilder formatter = new StringBuilder();
		
		for (Integer c : result) {
			formatter.append(c);
			formatter.append(" ");
		}
		
		System.out.println(String.format("Case #%s: %s", n, formatter.toString()));
	}

}
