package cj2009;

import java.io.*;
import java.util.*;


public class A {

	public static void main(String[] args) throws Exception {
		PrintStream out = System.out;
		if (args.length > 1) {
			out = new PrintStream(new FileOutputStream(args[1]));
		}
        CaseData[] data = InputParser.parse(new FileInputStream(args[0]));
        CaseSolver solver = new CaseSolver();
        for (int i = 0; i < data.length; i++) {
            String solution = solver.solve(data[i]);
        	out.println("Case #" + (i + 1) + ": " + solution);
        }
    }
    
    static class CaseData {
    	List<Integer> data;
    	CaseData(List<Integer> pData) {
    		this.data = pData;
    	}
    	public String toString() {
    		return "Case[]";
    	}
    }
    
    static class InputParser {
        public static CaseData[] parse(InputStream pIs) throws IOException {
            BufferedReader reader = new BufferedReader(new InputStreamReader(pIs));
            int casesCount = Integer.parseInt(reader.readLine());
            CaseData[] result = new CaseData[casesCount];
            for (int i = 0; i < casesCount; i++) {
            	result[i] = new CaseData(parseRow(reader.readLine()));
            }
            return result;
        }
        private static List<Integer> parseRow(String pData) {
        	List<Integer> result = new ArrayList<Integer>();
        	StringTokenizer st = new StringTokenizer(pData);
        	while (st.hasMoreTokens()) {
        		result.add(Integer.valueOf(st.nextToken()));
        	}
        	return result;
        }
    }
    
    static class CaseSolver {
        public String solve(CaseData pData) {
        	int result = 1;
        	boolean allHappy = false;
        	do {
        		result++;
        		allHappy = true;
            	for (int i = 0, cnt = pData.data.size(); i < cnt; i++) {
            		int base = pData.data.get(i);
            		if (isHappy(result, base) != 1) {
            			allHappy = false;
            			break;
            		}
            	}
        	} while ( ! allHappy);
        	return Integer.toString(result);
        }   
        int isHappy(int pNumber, int pBase) {
        	int number = pNumber;
        	int cnt = 0;
        	while (number > 1 && (cnt++ < 1000)) {
        		number = getSum(Integer.toString(number, pBase), pBase);
        	}
        	return number;
        }
        int getSum(String pNumber, int pBase) {
        	int sum = 0;
        	int length = pNumber.length();
        	for (int i = 0; i < length; i++) {
        		int d = Integer.parseInt("" + pNumber.charAt(i));
        		sum += (d * d);
        	}
        	return sum;
        }
    }
}

/*

*/