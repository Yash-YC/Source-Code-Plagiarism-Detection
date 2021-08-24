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

public class AApp {

	private PrintWriter writer = null;
	private Scanner scanner = new Scanner(System.in);
	private int testCases;

	public AApp() {
		try {
			writer = new PrintWriter(new File("roundone/a/Aresult.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		try {
			scanner = new Scanner(new File("roundone/a/A-small-attempt0.in"));
//			scanner = new Scanner(new File("roundone/a/A-large-attempt0.in"));
//			scanner = new Scanner(new File("roundone/a/Atest.in"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	List<Integer> bases;
	public void run() {

		testCases = scanner.nextInt();
		scanner.nextLine();

		long time = System.currentTimeMillis();
		for (int testCase = 1; testCase <= testCases; testCase++) {
			String line = scanner.nextLine();
			bases = new ArrayList<Integer>();
			for(String str:line.split(" ")){
				bases.add(Integer.parseInt(str));
			}
			
			String ergebnis = ("Case #" + testCase + ": " + calcResult());

			System.out.println(ergebnis);
			writer.write(ergebnis + "\n");
		}
		writer.flush();
		writer.close();
		System.out.println(System.currentTimeMillis() - time);
	}
	private int toBase(int nr,int base){
		String result ="";
		if(nr==0){
			return 0;
		}
		while(nr !=0){
			int rest = nr%base;
			result=rest+result;
			nr = nr/base;
		}
		return Integer.parseInt(result);
	}
	
	private boolean isHappy(int nr,int base){
		List<Integer> bereitsGetestet = new ArrayList<Integer>();
		while(true){
		if(bereitsGetestet.contains(nr)){
			return false;
		}
			bereitsGetestet.add(nr);
			String nummer = ""+nr;
			int summe = 0;
			for(int i = 0;i<nummer.length();i++){
				int zahl = Integer.parseInt(""+nummer.charAt(i));
				zahl = zahl*zahl;
				summe = summe+zahl;
				
			}
			if(summe == 1){
				return true;
			}else{
				nr = toBase(summe,base);
			}
		}
			
		
	}
	private String calcResult() {
		int toTest = 2;
		for(int i =0;i< bases.size();){
//			System.out.println("Teste"+toTest+" "+ bases.get(i));
//			System.out.println(toTest+ " "+ bases.get(i)+" "+toBase(toTest, bases.get(i))+isHappy(toBase(toTest, bases.get(i))));
			System.out.println(toBase(toTest, bases.get(i))+" "+bases.get(i));
			if(!isHappy(toBase(toTest, bases.get(i)),bases.get(i))){
				toTest++;
				i=0;
			}else{
				i++;
			}
		}
		return ""+toTest;
	}

	public static void main(String[] args) {
		new AApp().run();
	}
}
