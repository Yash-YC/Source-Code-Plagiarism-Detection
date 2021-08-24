import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class QuestionA {

	public static void main(String[] args) {
		int t;
		boolean[] bases = new boolean[11];
		Scanner scanner = null;
		
		try {
			scanner = new Scanner(new File("A-small-attempt0.in"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		BufferedWriter writer = null;
		try {
			writer = new BufferedWriter(new FileWriter("A.out"));
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		String str = scanner.nextLine();
		t = Integer.parseInt(str);
		
		for (int i = 0; i != t; ++i) {
			String line = scanner.nextLine();
			Scanner lineScanner = new Scanner(line);
			for (int j = 2; j != 11; ++j) {
				bases[j] = false;
			}
			while (lineScanner.hasNext()) bases[lineScanner.nextInt()] = true;
			
			int num = 2;
			while (true) {
				boolean flag = true;
				for (int j = 2; j != 11; ++j) {
					if (bases[j]) {
						if (!check(num, j)) {
							flag = false;
							break;
						}
					}
				}
				if (flag) break;
				++num;
			}
			
			try {
				writer.write("Case #" + (i + 1) + ": " + num + "\n");
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		
		try {
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		
	}

	private static boolean check(int num, int base) {
		int res = num;
		boolean[] b = new boolean[5000];
		b[1] = true;
		do {
			int temp = res, sum = 0;
			while (temp / base != 0) {
				sum += (temp % base) * (temp % base);
				temp /= base;
			}
			sum += temp * temp;
			res = sum;
			if (b[res]) break;
			b[res] = true;
		} while (true);
		
		if (res == 1) {
			return true;
		}
		else return false;
	}
	
}
