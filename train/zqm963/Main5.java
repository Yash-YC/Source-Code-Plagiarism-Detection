import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main5 {
	private String LastWord(String s) {
		if(s==null || s.length()==0){
			return "";
		}
		String ans = "";
		ans = ans + s.charAt(0);
		for (int i = 1; i < s.length(); i++) {
			if(ans.charAt(0)<= s.charAt(i)){
				ans = s.charAt(i) + ans;
			}else{
				ans =ans+ s.charAt(i);
			}
		}
		return ans;
	}

	public static void main(String[] args) {
		Main5 m = new Main5();
//		System.out.println(m.LastWord("JAM"));
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(
				System.in)));
		int t = in.nextInt(); // Scanner has functions to read ints, longs,
								// strings, chars, etc.
		for (int i = 1; i <= t; ++i) {
			String s = in.next();
			System.out.println("Case #" + i + ": " + m.LastWord(s));
			
		}
	}
}