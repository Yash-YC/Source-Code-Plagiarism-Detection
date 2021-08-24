import java.util.LinkedList;
import java.util.Scanner;


public class LastWord {
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		
		for (int i = 1; i <= n; i++) {
			String current = input.next();
			solve(i, current);
		}
		
		input.close();
	}
	
	private static void solve(int n, String current) {
		LinkedList<Character> result = new LinkedList<Character>();
		char lastChar = '#';
		
		for (Character c : current.toCharArray()) {			
			if (lastChar == '#' || c >= lastChar) {
				result.addFirst(c);
				lastChar = c;
			} else {
				result.add(c);
			}
		}
		
		StringBuilder formatter = new StringBuilder();
		for (Character c : result) {
			formatter.append(c);
		}
		
		System.out.println(String.format("Case #%s: %s", n, formatter.toString()));
	}

}
