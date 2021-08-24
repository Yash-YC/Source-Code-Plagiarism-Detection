import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/**
 * Base class for solving a Code Jam problem.
 *
 * @author arcatdmz
 */
public abstract class CodeJamBase {

	public CodeJamBase(String[] args) {

		// Check arguments.
		if (args == null || args.length != 2) {
			System.out.println(
					"Usage: "+getClass().getSimpleName()+
					" [input file name] [output file name]");
			return;
		}

		// Initialize file streams.
		File inputFile = new File(args[0]);
		File outputFile = new File(args[1]);
		BufferedReader reader = null;
		BufferedWriter writer = null;
		try {
			reader = new BufferedReader(
					new FileReader(inputFile));
			writer = new BufferedWriter(
					new FileWriter(outputFile));

			// Solve the problem.
			solve(reader, writer);

		} catch (FileNotFoundException e) {
			System.out.println("File not found: "+
					inputFile.getPath());
		} catch (IOException e) {
			e.printStackTrace();

		// Close streams.
		} finally {
			try {
				if (reader != null) {
					reader.close();
				}
				if (writer != null) {
					writer.close();
				}
			} catch (Exception e) {
				// Do nothing.
			}
		}
	}

	/**
	 * Solve the problem.
	 * @param reader Input stream
	 * @param writer Output stream
	 * @throws IOException
	 */
	public abstract void solve(BufferedReader reader, BufferedWriter writer) throws IOException;

}
