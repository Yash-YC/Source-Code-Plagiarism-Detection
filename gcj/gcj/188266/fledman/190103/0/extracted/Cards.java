import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Random;
import java.util.Scanner;
import java.util.Set;


public class Cards {
	private Random random;
	private static final int TRIALS = 100000;
	
	public Cards() {
		random = new Random();
	}
	
	public double simulate(int setSize, int packSize) {
		double sum = 0;
		for (int i = 0; i < TRIALS; i++) {
			sum += doRound(setSize, packSize);
		}
		return sum / TRIALS;
	}
	
	private int doRound(int setSize, int packSize) {
		Set<Integer> complete = new HashSet<Integer>();
		int packs = 0;
		while (complete.size() < setSize) {
			packs++;
			complete.addAll(pick(packSize, setSize));
		}
		return packs;
	}
	
	private Set<Integer> pick(int number, int max) {
		Set<Integer> selection = new HashSet<Integer>();
		while (selection.size() < number) {
			int rInt = 1 + random.nextInt(max);
			if (!selection.contains(rInt)) {
				selection.add(rInt);
			}
		}
		return selection;
	}
	
	public static void main(String[] args) throws IOException {
		File input = new File("c:\\codejam\\C-small-attempt2.in");
		File output = new File("c:\\codejam\\C.small.output.txt");
		BufferedReader reader = new BufferedReader(new FileReader(input));
        BufferedWriter writer = new BufferedWriter(new FileWriter(output));
        int T = Integer.parseInt(reader.readLine());
        Cards cards = new Cards();
        for (int test = 1; test <= T; test++) {
			Scanner scanner = new Scanner(reader.readLine());
			int setSize = scanner.nextInt();
			int packSize = scanner.nextInt();
	        double expected = Math.round(cards.simulate(setSize, packSize)*1000)/1000.0;
	        writer.write("Case #" + test + ": " + expected);
	        writer.newLine();
		}
		reader.close();
        writer.close();
	}
}
