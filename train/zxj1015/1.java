import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.math.BigDecimal;

public class Main {
	
	public static void main(String[] args) {
		init();
		Scanner scanner = new Scanner(System.in);
		int cases = Integer.parseInt(scanner.nextLine());
		for (int i = 0; i < cases;++i) {
			String input = scanner.nextLine();
			String result = "";
			for (int j = 0; j < input.length(); ++j) {
				String s1 = result + input.charAt(j);
				String s2 = input.charAt(j) + result;
				if (s1.compareTo(s2) > 0) {
					result = s1;
				} else {
					result = s2;
				}
			}
			System.out.println("Case #" + (i + 1) + ": " + result);
		}
	}
	
	
	
	
	
	
	
	
	
	public static void init() {
		FileInputStream fis = null;
		try {
			fis = new FileInputStream("/Users/zxj/Documents/workspace/Algorithm/src/test.in");
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}  
        System.setIn(fis); 
	}
}

