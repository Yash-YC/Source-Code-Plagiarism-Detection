import java.io.BufferedReader;
import java.io.IOException;
import java.io.Reader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;


public class TestData {

	private List<TestCase> testcases;

	public TestData(Reader rdr) throws IOException {
		BufferedReader br = new BufferedReader(rdr);
	
		testcases = new ArrayList<TestCase>();
		
		int T;
		String line = br.readLine(); // first line
		T = Integer.parseInt(line);
		//System.err.println("T="+T);
		int count = T;
		while (count>0) {
			line = br.readLine(); // first line
			StringTokenizer tokenizer = new StringTokenizer(line," ");
			List<Integer> bases = new ArrayList<Integer>();
			while (tokenizer.hasMoreTokens()) {
				int base = Integer.parseInt(tokenizer.nextToken());
				bases.add(base);
			}
			testcases.add(new TestCase(bases));
			count--;
		}
		br.close();
	}
	
	List<TestCase> getTestCases() {
		
		return testcases;
	}
}
