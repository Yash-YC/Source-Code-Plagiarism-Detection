package multibase;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Main {

	private static BufferedReader input;
	private static BufferedWriter output;
	public Main(String input_file, String output_file) throws Exception {
		input = new BufferedReader(new FileReader(input_file));
		output = new BufferedWriter(new FileWriter(output_file));
	}

	public static void main(String[] args) throws Exception{
		new Main("C:\\Documents and Settings\\TEMP.TD-CSF.000\\workspace\\CodeJam Round 1A\\src\\input\\multibase3.txt",
				"C:\\Documents and Settings\\TEMP.TD-CSF.000\\workspace\\CodeJam Round 1A\\src\\output\\multibase3.txt").run();
	}

	public void run() throws Exception{
		String s = input.readLine();
		int cases = Integer.parseInt(s);
		for(int i=1;i<=cases;i++){
			System.out.println("Working on case "+i+"...");
			Solver model = new MultibaseSolver(input);
			String $ = model.solve();
			output("Case #"+i+": ");
			outputln($);
			System.out.println("Case "+i+" finished!");
		}
		input.close();
		output.close();
	}

	public static void outputln(String s){
		try {
			output.write(s);
			output.newLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void output(String s){
		try {
			output.write(s);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
