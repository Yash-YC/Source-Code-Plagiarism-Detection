import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;


public class mbhappy {

	public static void main(String[] args) {			
		File file = new File("A-small-attempt0.in");
		FileWriter outfile = null;
		FileInputStream in = null;
		BufferedWriter out = null;
		
		try {
			in = new FileInputStream(file);
			BufferedReader reader = new BufferedReader(new InputStreamReader(in));
			String line = null;
			
			outfile = new FileWriter("A-small-attempt0.out");
			out = new BufferedWriter(outfile);
			
			int lineno = 0;
			while ((line = reader.readLine()) != null) {
				System.out.println(line);
				
				if (lineno == 0) {
					System.out.println("Test cases: " + line);			
					lineno++;
					continue;
				}

				StringTokenizer st = new StringTokenizer(line);
				ArrayList<Integer> baselist = new ArrayList<Integer>();
				while (st.hasMoreTokens()) {
					baselist.add(new Integer(st.nextToken()));
				}
				
				System.out.print("Bases: ");
				for (int i = 0; i < baselist.size(); i++) {
					System.out.print(baselist.get(i) + " ");
				}
				System.out.print("\n");
				
				int r = eval(baselist);
				System.out.print("Case #" + lineno + ": " + r + "\n\n");
				out.write("Case #" + lineno + ": " + r + "\n");
				
				lineno++;
			}
			
			System.out.println(sumSquares(82,10));
			
			out.close();
			
		} catch (IOException x) {
			System.err.println(x);
		} 
	}
	
	static int eval(ArrayList<Integer> baselist) {
		
		int r = 2;
		loop: for (; r < 100000; r++) {
			basecheck: for (int i = 0; i < baselist.size(); i++) {
				HashSet<Integer> hitlist = new HashSet<Integer>();
				
				int x = Integer.parseInt(Integer.toString(r, baselist.get(i)));
				System.out.println(r + " in base " + baselist.get(i) + " is " + x);
				
				while (!hitlist.contains(x)) {
					hitlist.add(x);
					x = sumSquares(x, baselist.get(i));
					System.out.println(x);
					if (x == 1) {
						System.out.println(r + " is happy in base " + baselist.get(i));
						continue basecheck;
					}
				}
				System.out.println(r + " is NOT happy in base " + baselist.get(i)
									 + " repeats at " + x);
				
				continue loop;
			}
			return r;
		}
		
		if (r == 100000) {
			System.err.print("HUGE small number");
			System.exit(0);
		}
		
		return r;
	}
	
	static int sumSquares(int x, int base) {
		int r = 0;
		
		while (x != 0) {
			int y = x%10;
			x /= 10;
			r += y*y;
		}
		
		return Integer.parseInt(Integer.toString(r, base));
	}
}
