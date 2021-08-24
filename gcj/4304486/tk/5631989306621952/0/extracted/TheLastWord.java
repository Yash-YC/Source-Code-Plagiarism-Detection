import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class TheLastWord {

	
	public static String appendFront(String s, char c){
			String ret = Character.toString(c);
			return ret + s;
	}
	
	
	public static void printAnswer(String s, int j){
		
		int numLetters = s.length();
		String ret = Character.toString(s.charAt(0));
		
		for(int i=1; i<numLetters; i++){
			char c = s.charAt(i);
			if((int)c>=(int)ret.charAt(0))
				ret = appendFront(ret,c);
			else
				ret += Character.toString(c);
			
		}
		
		
		System.out.println("Case #"+ (j+1)+ ": " + ret);
	}
	
	public static void main(String args[]) throws FileNotFoundException{
		File file = new File("input.txt");
		Scanner in = new Scanner(file);
		int t = in.nextInt();
		//System.out.println(t);
		String s = in.nextLine();
		
		for(int i=0;i<t;i++){
			s = in.nextLine();
			//System.out.println(s);
			printAnswer(s, i);
			
		}

	

	}	
	
}
