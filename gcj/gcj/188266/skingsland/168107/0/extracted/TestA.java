import java.io.*;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.regex.Pattern;

public class TestA {
    String inputFileName = "D:\\Users\\Steve\\Downloads\\A-small-attempt0.in";
    String outputFileName = "D:\\Users\\Steve\\Downloads\\output.txt";

    int numTestCases;

    List<Set<Integer>> testCasesList = new ArrayList<Set<Integer>>();
    
    List<Integer> outputList = new ArrayList<Integer>();

    /**
     * @param args
     */
    public static void main(String[] args) {
        TestA test = new TestA();

        try {
        	
//        	System.out.println(test.isHappy("82", 10));
//        	System.out.println(test.isHappy("82", 3));

        	test.readInputFile();
            
            test.solveProblem();
            
            test.writeOutputFile();
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    
    private void readInputFile() throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(inputFileName));

        try {
            String line = reader.readLine();
            StringTokenizer st = new StringTokenizer(line);

            numTestCases = Integer.parseInt(st.nextToken());

            System.out.println("numTestCases = " + numTestCases);

            // now read the test cases
            for (int i = 0; i < numTestCases; i++) {
            	Set basesSet = new HashSet();
            	
                line = reader.readLine();
                st = new StringTokenizer(line);
                
                while (st.hasMoreTokens()) {
                	int base = Integer.parseInt(st.nextToken());
                	
                	basesSet.add(base);
                }
                testCasesList.add(basesSet);
            }
        } finally {
            reader.close();
        }
    }

    private void solveProblem() {
        // for each test case
        for (Set<Integer> bases : testCasesList) {
//        	System.out.println("Starting new test case...");
        	
        	for (int num=2; true; num++) {
//        		System.out.println("testing number " + num);
        		boolean happy = true;
        		
        		// check to see if the number is happy in the first base
        		for (Integer base : bases) {
        			// if it's not happy in this base, break
        			if (!isHappy(num, base)) {
            			happy = false;
        				break;
        			}
        			// if it IS happy, continue checking the number with the next base
//        			System.out.println("Num " + num + " is happy in base " + base + "!");
        		}
        		// if NONE of the bases failed for this number, then we found the min. number that succeeds in all bases!
        		if (happy) {
//        			System.out.println("ANSWER FOR TEST CASE: " + num);
        			outputList.add(num);
        			break;
        		}
        	}
        }
    }
    
    boolean isHappy(int num, int base) {
    	String strNumber = Integer.toString(num, base);
    	
    	Set previousTotals = new HashSet();
    	
    	while (true) {
        	int total = getTotal(strNumber);
    		
//    		System.out.println(total);
        	
        	if (total == 1) {
        		return true;
        	}
    		if (previousTotals.contains(total)) {
    			return false;
    		}
    		previousTotals.add(total);
    		
    		strNumber = Integer.toString(total, base);
    	}
    }

    int getTotal(String strNumber) {
    	int sum = 0;
    	
    	for (int i = 0; i < strNumber.length(); i++) {
			int num = Integer.parseInt(strNumber.substring(i, i+1));
			sum += num*num;
		}
    	return sum;
    }

    private void writeOutputFile() throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter(outputFileName));

        try {
            for (int i=1; i<=numTestCases; i++) {
                Integer count = outputList.get(i-1);

                writer.write("Case #" + i + ": " + count);
                writer.newLine();
            }
        } finally {
            writer.close();
        }
    }
}
