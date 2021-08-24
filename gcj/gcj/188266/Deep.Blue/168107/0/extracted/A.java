import java.io.File;
import java.io.FilenameFilter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class A {
	private final static String QUESTION_PREFIX = "A";
	
	private static Scanner scanner;
	private static PrintWriter outputFileWriter;
	private static int lineNo;
	
	public static void main(String[] args) throws IOException {
		setupIO (args.length == 0 ? null : args[0]);
		
		int totalTC = scanner.nextInt();
		scanner.nextLine();
		
		for (int tcIdx = 0; tcIdx < totalTC; ++tcIdx) {
			// Read input						
			String s  = scanner.nextLine();
			
			String[] input = s.split(" ");
			
			int result = 1;
			boolean found = false;
			for (int i = 2; !found; i++) {
				
				boolean happy = false;
								
				for (String base : input) {
					happy = isHappy (i, Integer.parseInt(base));
					
					if (!happy) {
						break;
					}
				}
				
			   if (happy) {
			   	result = i;
			   	found = true;
			   }
			}
			
			
			
			// Calculate												
			println (result + "");
		}				
	}
	
	private static Map<Integer, Map<Integer, Boolean>> map = new HashMap<Integer, Map<Integer, Boolean>>();
	
	
	
	
	private static boolean isHappy (int no, int base) {
		Map<Integer,Boolean> baseMap = map.get(base);
		
		if (baseMap == null) {
			baseMap = new HashMap<Integer, Boolean>();
			map.put(base, baseMap);
		}						

		
		Set<Integer> trackingSet = new HashSet<Integer>();
		
		
		while (true) { 
			if (baseMap.get(no) != null) {
				boolean result = baseMap.get(no);
				for (Integer i : trackingSet) {
					baseMap.put(i, result);
				}
				
				return result;
			} else if (trackingSet.contains(no)) {
				boolean result = false;
				baseMap.put(no, false);
				
				for (Integer i : trackingSet) {
					baseMap.put(i, result);
				}
				
				return result;			
			} else if (no == 1) {
				boolean result = true;
				baseMap.put(no, true);
				
				for (Integer i : trackingSet) {
					baseMap.put(i, result);
				}
				
				return result;	
			} else {
				trackingSet.add(no);
			   Integer[] baseNos = convertToBase (no, base);
				
			   int total = 0; 
			   
			   for (Integer i : baseNos) {
			   	total += i*i;
			   }
				no = total;			
			}
		}
	}
	
	private static int convertToDecimal (Integer[] no, int base) {
		int result = 0;
		
	   for (int i = 0; i <no.length; ++i) {
	   	result += no[i] * Math.pow(base, i);	   	
	   }
	   
	   return result;
	}
	
	private static Integer[] convertToBase(int no, int base) {
		List<Integer> baseNo = new ArrayList<Integer>();		
		
		while (no >= base) {
			baseNo.add(no % base);
			no = no / base;
		}
		
		if (no > 0)
			baseNo.add(no);
		
		// Collections.reverse(baseNo);
		
		return baseNo.toArray(new Integer[baseNo.size()]);
	}
	
	private static void setupIO (String inputFileName) throws IOException{
		if (inputFileName == null) {
			inputFileName = selectInputFile();
		}
		
		File inputFile = new File (inputFileName);
		scanner = new Scanner(inputFile);
		outputFileWriter = new PrintWriter(new File(inputFile.getName().replaceAll("\\..*", ".out")));
		lineNo = 1;
		
		Runtime.getRuntime().addShutdownHook(new Thread() {
			@Override
			public void run() {
				if (scanner != null) {
					scanner.close();					
				}
				
				if (outputFileWriter != null)
					outputFileWriter.close();
			}
			
		});		
	}
	
	private static String selectInputFile() {
		File[] files = new File (".").listFiles(new FilenameFilter() {
			@Override
			public boolean accept(File dir, String name) {
				if (name.endsWith(".in") && name.startsWith(QUESTION_PREFIX))
					return true;
				else
					return false;
			}			
		});
						
		File latestFile = null;
		
		for (int i = 0; i < files.length; ++i) {
			File file = files[i];
			if (latestFile == null || file.lastModified() > latestFile.lastModified()) {
				latestFile = file;
			}
		}
						
		System.out.println ("Running " + latestFile.getName() + "......");
		return latestFile.getName();		
	}
	
	private static void println (String s) throws IOException {
		outputFileWriter.write("Case #" + (lineNo++) + ": " + s + "\n");
	}
}

class DummyAComparator implements Comparator<String> {
	public int compare(String o1, String o2) {
		
		
		return 0;
	}	
}

class DummyAComparable implements Comparable<DummyCComparable> {

	public int compareTo(DummyCComparable o) {
		
		
		return 0;
	}	
}