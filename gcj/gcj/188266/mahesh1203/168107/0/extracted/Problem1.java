package codejam.round.one.a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * 
 * @author Mahesh K.
 * 
 */
public class Problem1 {
	public static void main(String[] args) {
		try {
			int noOfCases;
			List<Integer> bases = new ArrayList<Integer>();
			List<Long> numbers = new ArrayList<Long>();
			FileReader fr = new FileReader(new File("A-small-attempt0.in"));
			BufferedReader br = new BufferedReader(fr);

			FileWriter fw = new FileWriter("A-large.out");
			BufferedWriter bw = new BufferedWriter(fw);

			StringTokenizer st = new StringTokenizer(br.readLine());
			noOfCases = Integer.parseInt((String) st.nextElement());

			for (int caseNum = 0; caseNum < noOfCases; caseNum++) {
				String line = br.readLine().trim();
				StringTokenizer tokens = new StringTokenizer(line);
				while (tokens.hasMoreElements()) {
					bases.add(Integer.parseInt((String) tokens.nextElement()));
				}

				outer: for (int i = 2; i < Long.MAX_VALUE; i++) {
					// System.out.println(i);
					innerFor: for (int b : bases) {
						long n = i;
						numbers.clear();
						while (n != 1) {
							if (numbers.indexOf(n) == -1) {
								numbers.add(n);
							} else {
								break innerFor;
							}
							String str = Long.toString(n, b);
							Long sum = 0L;
							for (int j = 0; j < str.length(); j++) {
								Long rem = Long.parseLong(str.substring(j, j + 1));
								sum = sum + rem * rem;
							}
							n = sum;
						}
						if (n == 1) {
							if (bases.indexOf(b) < bases.size() - 1) {
								continue innerFor;
							}
							bw.write("Case #" + (caseNum + 1) + ": " + i + "\n");
							System.out.println("Case #" + (caseNum + 1) + ": " + i + "\n");
							break outer;
						} else {
							break;
						}
					}
				}

				bases.clear();
			}

			fr.close();
			br.close();
			bw.close();
		} catch (IOException ie) {
			ie.printStackTrace();
		}
	}
}
