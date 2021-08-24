package r1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;

/**
 * 
 * @author naoki
 * 
 */
public class CodeJam1 {
	// protected static String inputFileName = "data/r1/A-test.in";
	// protected static String outputFileName = "output/r1/A-test.out";

	protected static String inputFileName = "data/r1/A-small.in";
	protected static String outputFileName = "output/r1/A-small.out";
	// protected static String inputFileName = "data/r1/A-large.in";
	// protected static String outputFileName = "output/r1/A-large.out";

	public static void main(String[] args) throws Exception {
		File inputFile = new File(inputFileName);
		BufferedReader reader = new BufferedReader(new FileReader(inputFile));

		FileOutputStream fos = new FileOutputStream(outputFileName);

		process(reader, fos);

		reader.close();
		fos.close();
		System.out.println("normal end");
	}

	private static void process(BufferedReader reader, FileOutputStream fos)
			throws IOException {
		String head = reader.readLine();
		int qCount = Integer.valueOf(head);

		System.out.println("q = " + qCount);

		for (int loopIndex = 0; loopIndex < qCount; loopIndex++) {
			// 初期化
			// cache.clear();

			String line = reader.readLine();
			String[] splitLine = line.split(" ");
			int[] bases = new int[splitLine.length];
			for(int i = 0; i < splitLine.length; i++){
				bases[i] = Integer.parseInt(splitLine[i]);
			}

			int counter = 1;
			boolean match = false;
			while(match == false){
				counter++;
				match = checkNumber(bases, counter);
			}
						
			// for output
			outputLine(fos, loopIndex, counter);
		}
	}
	
	private static boolean checkNumber(int[] bases, int counter){
		for(int base : bases){
			boolean checker = false;
			String act = "" + parse(counter, base);
			// System.out.println("count[" + counter + "]base[" + base + "]" + act);
			for(int i = 0; i < 5; i++){
				act = checkActChar(act, base);
				if(act == null){
					checker = true;
					break;
				}
				// System.out.println("act : " + act);
			}
			if(checker == false){
				return false;
			}
		}
		
		return true;
	}
	
	public static int parse(int x, int base){
		if(x == 0) 
			return 0;
		else
			return parse(x / base, base) * 10 + x % base;
	}

	
	private static String checkActChar(String act, int base){
		char[] actChars = act.toCharArray();
		int result = 0;
		for(char actChar : actChars){
			int buf = Integer.parseInt("" + actChar);
			result += (buf*buf);
		}
		if(result > 1){
			return new String("" + parse(result, base));
		}
				
		// ok
		return null;
	}

	private static void outputLine(FileOutputStream fos, int mapIndex,
			long count) throws IOException {
		String format = "Case #%d: %d";
		String outputString = String.format(format, mapIndex + 1, count);
		System.out.println(outputString);

		fos.write((outputString + "\n").getBytes());
	}


}
