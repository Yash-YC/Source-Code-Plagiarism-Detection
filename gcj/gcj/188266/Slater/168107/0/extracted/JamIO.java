package jam;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class JamIO {

	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static String buffer = null;

	public static int readNextInt() throws IOException {
		if (buffer == null) buffer = in.readLine();
		String[] temp = buffer.split(" ", 2);
		buffer = (temp.length > 1) ? temp[1] : null;
		return Integer.parseInt(temp[0]);
	}

	public static double readNextDouble() throws IOException {
		if (buffer == null) buffer = in.readLine();
		String[] temp = buffer.split(" ", 2);
		buffer = (temp.length > 1) ? temp[1] : null;
		return Double.parseDouble(temp[0]);
	}

	public static String readNextString() throws IOException {
		if (buffer == null) buffer = in.readLine();
		String[] temp = buffer.split(" ", 2);
		buffer = (temp.length > 1) ? temp[1] : null;
		return temp[0];
	}

	public static String readStringUntilEndOfLine() throws IOException {
		if (buffer == null) buffer = in.readLine();
		String temp = buffer;
		buffer = null;
		return temp;
	}

	public static void printCase(int caseNo, Object... objects) {
		System.out.print("Case #" + (caseNo+1) + ":");
		for (Object o : objects) System.out.print(" " + o);
		System.out.println();
	}

}
