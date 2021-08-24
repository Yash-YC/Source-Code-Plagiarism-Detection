import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.NumberFormat;


/**
 * @author Rycus
 *
 */
public class CollectingCards {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		File file = new File("D:\\CodeJam2009\\C-small.in");
		BufferedReader reader = new BufferedReader(new FileReader(file));
		
		File outputFile = new File("D:\\CodeJam2009\\C-small.out");
		outputFile.createNewFile();
		BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile));
		
		int cases = Integer.parseInt(reader.readLine());
		
		NumberFormat format = NumberFormat.getNumberInstance();
		format.setMaximumIntegerDigits(Integer.MAX_VALUE);
		format.setGroupingUsed(false);
		format.setMinimumFractionDigits(6);
		format.setMaximumFractionDigits(6);
		for(int caseIndex = 0; caseIndex < cases; caseIndex++) {
			String[] params 	= reader.readLine().split("\\s");
			double numberOfCards 	= Double.parseDouble(params[0]);
			double cardsInPack		= Double.parseDouble(params[1]);
			
			double result = 0;
			
			if(cardsInPack >= numberOfCards) {
				result = 1.0;
			} else {
				double prob = cardsInPack / numberOfCards;
				result = 1.0 + ((1 / prob) * (numberOfCards - cardsInPack));
			}
			
			writer.write("Case #" + (caseIndex + 1) + ": " + format.format(result));
			writer.newLine();
		}
		
		writer.flush();
		writer.close();
		reader.close();
	}

}
