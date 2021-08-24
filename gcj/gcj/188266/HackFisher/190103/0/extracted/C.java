import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintWriter;


public class C {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		solve("D:\\in\\C-small-attempt1.in");

	}

	public static void solve(String path) throws Exception {
		PrintWriter writer = new PrintWriter(new FileOutputStream(new File("D:\\out\\C-small-attempt1-out.text")));
		
		int line_count = 0;
		BufferedReader reader = new BufferedReader(new FileReader(new File(path)));
		
		String line_str;
		
		if((line_str = reader.readLine()) != null) {
			line_count = Integer.parseInt(line_str);
		}
		
		for (int i = 0; i < line_count; i ++) {
			
			if ((line_str = reader.readLine()) != null) {
				double expected = 1;
				
				String[] CN = line_str.split(" ");
				int C = Integer.parseInt(CN[0]);
				int N = Integer.parseInt(CN[1]);
				
				expected = ((double)(C*(C - N)))/N + 1;
				
				System.out.println("Case #" + (i + 1) + ": " + expected);
				writer.println("Case #" + (i + 1) + ": " + expected);
			}
		}
		
		writer.flush();
		writer.close();
	}
}
