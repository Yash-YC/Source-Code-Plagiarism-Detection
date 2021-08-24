package codejam.round1a;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;

public class Solver {

//	private static final String DOWNLOAD_DIR = "/home/nick/downloads";
	private static final String DOWNLOAD_DIR = "/home/nick/programming/codejam";
	private static final String OUTPUT_DIR = "/home/nick/programming/codejam";
//	private static final String TYPE = "large";
	private static final String TYPE = "small-attempt0";
	private static final String ID = "A";
	private static final String IN_FILENAME = ID + "-" + TYPE + ".in";
	private static final String OUT_FILENAME = ID + "-" + TYPE + ".out";

	public static void main(String[] args) throws Exception {
		final File inputFile = new File(DOWNLOAD_DIR, IN_FILENAME);
		BufferedReader fileReader = new BufferedReader(new FileReader(inputFile));
		try {		
			final File outputFile = new File(OUTPUT_DIR, OUT_FILENAME);
			outputFile.delete();
			PrintStream out = new PrintStream(new FileOutputStream(outputFile));
			try {
				String line = fileReader.readLine();
				int cases = Integer.parseInt(line);
				for (int i = 0; i < cases; i++) {
					String[] ns = fileReader.readLine().split(" ");
					int[] is = new int[ns.length];
					int x = 0;
					for (String n : ns) {
						is[x++] = Integer.parseInt(n);
					}
					Problem calc = new Problem(is);
					out.print("Case #" + (i+1) + ": ");
					out.println(calc.getResult());
				}
			} finally {
				out.close();
			}
		} finally {
			fileReader.close();
		}
	}
}
