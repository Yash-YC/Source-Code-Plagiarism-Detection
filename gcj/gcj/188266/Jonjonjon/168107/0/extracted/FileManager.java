package src;
import java.io.*;
import java.util.*;

public class FileManager {
	private FileWriter fiw;
	private String input;
	private String[] lines;
	public FileManager(String inputFile, String outputFile) {
		try {
			File infile = new File(inputFile);
			File outfile = new File(outputFile);
			
			FileReader fis = new FileReader(infile);
			BufferedReader read = new BufferedReader(fis);
			fiw = new FileWriter(outfile);
	    	
		    String ln;
		    input = "";
		    while((ln = read.readLine())!= null) {
		    	input = input.concat(ln.concat("\n"));  		
		    }
		    
		    String str = input.concat("");
			lines = str.split("\n");
			
		    read.close();
		    fis.close();
		    
		} catch(Exception e) {
	    	
	    }
	}
	
	public boolean saveDataToOutputFile(String out) {
		try {
			fiw.write(out);
			fiw.flush();
			return true;
		} catch(Exception e) {
			return false;
		}
	}
	
	public ArrayList<Integer> getLineIntegerValues(int lineNumber) {
		String headerLine = lines[lineNumber];
		StringTokenizer tok = new StringTokenizer(headerLine);
		int num = tok.countTokens();
		ArrayList<Integer> vals = new ArrayList<Integer>();
		for(int i=0; i<num; i++) {
			vals.add(Integer.parseInt(tok.nextToken()));
		}
		return vals;
	}
	
	public int[] getLineIntegerValues(int lineNumber, int numEntries) {
		String headerLine = lines[lineNumber];
		StringTokenizer tok = new StringTokenizer(headerLine);
		int[] vals = new int[numEntries];
		for(int i=0; i<numEntries; i++) {
			vals[i] = Integer.parseInt(tok.nextToken());
		}
		return vals;
	}
	
	public int[][] getBlockIntegerValues(int firstLine, int lastLine, int numEntriesPerLine) {
		int numLines = lastLine - firstLine;
		int[][] block = new int[numLines+1][numEntriesPerLine];
		for(int i=0; i<=numLines; i++) {
			block[i] = getLineIntegerValues(i+firstLine, numEntriesPerLine);
		}
		return block;
	}
	
	public ArrayList<ArrayList<Integer>> getBlockIntegerValues(int firstLine, int lastLine) {
		ArrayList<ArrayList<Integer>> block = new ArrayList<ArrayList<Integer>>();
		for(int i=firstLine; i<=lastLine; i++) {
			block.add(getLineIntegerValues(i));
		}
		return block;
	}
}
