import java.util.*;
import java.io.*;

public class MainA {

	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(
				System.in)));
		int t = in.nextInt(); // Scanner has functions to read ints, longs,
								// strings, chars, etc.
		for (int i = 0; i < t; i++) { // number of test cases
			String s = in.next();
			MainA m = new MainA(s);
			System.out.println("Case #" + (i+1) + ": " + m.getResult());
		}
		
		in.close();
	}

	int n;
	String s;
	
	public MainA(String s) {
	this.s = s;
		
		
	}

	 ArrayList<String> res = new ArrayList<String>();

	private String getResult() {
		compute(0,"");

		String result = "";

		
		Collections.sort(res);

		return res.get(res.size()-1);
	}

	private void compute(int i, String r) {
		if(s.length()==r.length()){
			res.add(r);
		    return;	
		}
		int old = i;
		compute(old + 1, s.charAt(i) + r);
		compute(old + 1,  r + s.charAt(i));

	}
}