import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.TreeSet;


public class MultibaseHappiness {
	static final String digits = "0123456789abcdefghijklmnopqrstuvwxyz";
	
	public static String convertToBase(int x, int b) {
		String str = "";
		while (x > 0) {
			str = digits.charAt(x%b) + str;
			x = x/b;
		}
		return str;
	}
	
	public static int sumSquareDigits(String str) {
		int sumSq = 0, tmp;
		for (char c : str.toCharArray()) {
			tmp = digits.indexOf(c);
			sumSq += tmp*tmp;
		}
		return sumSq;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader infile = new BufferedReader(new FileReader("multibase.in"));
		BufferedWriter outfile = new BufferedWriter(new FileWriter("multibase.out"));
		
		StringTokenizer st = new StringTokenizer(infile.readLine());
		int T = Integer.parseInt(st.nextToken());

		for (int i = 0; i < T; i++) {
			st = new StringTokenizer(infile.readLine());
			ArrayList<Integer> bases = new ArrayList<Integer>();
			while (st.hasMoreTokens()) bases.add(Integer.parseInt(st.nextToken()));
			int curNum;
			numloop: for (int j = 2; j <= 1e6; j++) {
				boolean works = true;
				baselp: for (int base : bases) {
					curNum = j;
					TreeSet<Integer> usedNums = new TreeSet<Integer>();
					while (!usedNums.contains(curNum)) {
						usedNums.add(curNum);
						curNum = sumSquareDigits(convertToBase(curNum, base));
						//System.out.println(j + " " + base + " " + curNum);
						if (curNum == 1) continue baselp;
					}
					works = false;
					break;
				}
				if (works) { 
					outfile.write("Case #"+(i+1)+": "+j+"\n");
					break;
				}
			}
		}
		
		outfile.close();
	}

}
