package roundone;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class CApp {

	private PrintWriter writer = null;
	private Scanner scanner = new Scanner(System.in);
	private int testCases;

	public CApp() {
		try {
			writer = new PrintWriter(new File("roundone/c/Cresult.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		try {
			scanner = new Scanner(new File("roundone/c/C-small-attempt0.in"));
//			scanner = new Scanner(new File("roundone/c/C-large-attempt0.in"));
//			scanner = new Scanner(new File("roundone/c/Ctest.in"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	public void run() {

		testCases = scanner.nextInt();
		// scanner.nextLine();

		long time = System.currentTimeMillis();
		for (int testCase = 1; testCase <= testCases; testCase++) {
			
			double a = Double.parseDouble(scanner.next());
			double b = Double.parseDouble(scanner.next());
			String ergebnis = ("Case #" + testCase + ": " + ((a/b)+1));

			System.out.println(ergebnis);
			writer.write(ergebnis + "\n");
		}
		writer.flush();
		writer.close();
		System.out.println(System.currentTimeMillis() - time);
	}

	private String calcResult() {
		
		return null;
	}

	public static void main(String[] args) {
		new CApp().run();
	}
}
