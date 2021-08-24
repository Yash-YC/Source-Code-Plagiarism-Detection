

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public abstract class CodeJamProblem {

	public final void main_(String[] args) {
		String fileName = args[0];
		try {
			Scanner s = new Scanner(new File(fileName + ".in"));
			TestCaseWriter w = new TestCaseWriter(fileName + ".out");
			int nTestCases = getNumTestCases(s);
			for (int i = 0; i < nTestCases; ++i) {
				TestCase t = parseTestCase(s);
				w.writeSolution(t.solve());
			}
		} catch (FileNotFoundException e) {
			throw new RuntimeException(e);
		}
	}

	protected int getNumTestCases(Scanner s) {
		return s.nextInt();
	}
	
	private static class TestCaseWriter {

		private BufferedWriter w;
		private int nCases;
		
		public TestCaseWriter(String fileName) {
			try {
				w = new BufferedWriter(new FileWriter(fileName));
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
			nCases = 0;
		}
		
		public void writeSolution(String solution) {
			try {
				String line = "Case #" + ++nCases + ": " + solution;
				w.write(line);
				w.newLine();
				w.flush();
				System.out.println(line);
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		
	}
	
	protected interface TestCase {
		public String solve();
	}
	
	protected abstract TestCase parseTestCase(Scanner s);

}
