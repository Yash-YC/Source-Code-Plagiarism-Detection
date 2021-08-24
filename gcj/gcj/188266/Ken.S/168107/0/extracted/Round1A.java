import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

/**
 * gcj 2009
 * 
 * Round 1 Problem A : 20090911 9:00 
 * 
 * 
 * 
 * @author kspokas
 *
 */
public class Round1A {
	
	
	public static void main(String args[]) {
		Round1A instance = new Round1A();
		
        BufferedReader in = null;
        BufferedWriter out = null;

        try {
            in = new BufferedReader(new FileReader(args[0]));
            out = new BufferedWriter(new FileWriter(args[0] + ".out"));

            int testCount = Integer.parseInt(in.readLine());
            
            for (int i = 0; i < testCount; i++) {
            	out.write("Case #" + (i + 1) + ": " + instance.getSmallestHappyNumber(in.readLine()) + "\n");
            }
            
            
        } catch (Exception ex) {
            System.err.println("Barf");
            ex.printStackTrace();
        } finally {
            try { if (in != null) { in.close(); } } catch (Exception ignore) { }
            try { if (out != null) { out.close(); } } catch (Exception ignore) { }
            in = null; out = null; instance = null;
        }
	}
	
	private Round1A() {
	}
	
	private String getSmallestHappyNumber(String listOfBases) {
		String[] baseArray = listOfBases.split(" ");
		Map<Integer, List<String>> resultMap = new HashMap<Integer, List<String>>();
		for (int i = 0; i < baseArray.length; i++) {
			resultMap.put(new Integer(baseArray[i]), new ArrayList<String>());			
		}
		
		boolean stillChecking = true;
		Integer numberCheck = 2;
		while (stillChecking) {
			boolean isHappy = true;
			Iterator<Integer> it = resultMap.keySet().iterator();
			while (it.hasNext() && isHappy) {
				Integer nextBase = it.next();
				BigInteger holder = new BigInteger(Integer.toString(numberCheck, nextBase), nextBase);
				List<String>attemptedValues = new ArrayList<String>();
				do {
					attemptedValues.add(holder.toString());
					holder = getNextNumber(holder, nextBase);
				} while (!attemptedValues.contains(holder.toString()) && 
							!"1".equals(holder.toString()));
				
				if (!"1".equals(holder.toString())) {
					isHappy = false;
				}
			}
			
			stillChecking = !isHappy;
			numberCheck++;
		}
		
		return "" + (numberCheck - 1);
	}	
	
	private BigInteger getNextNumber(BigInteger number, int base) {
		String digitString = number.toString(base);
		BigInteger nextNumber = new BigInteger("0", base);
		for (int i = 0; i < digitString.length(); i++) {
			int nextDigit = Integer.parseInt("" + digitString.charAt(i), base);
			nextDigit = nextDigit * nextDigit;
			
			nextNumber = nextNumber.add(new BigInteger(Integer.toString(nextDigit, base), base));
		}
		return nextNumber;
	}
}
