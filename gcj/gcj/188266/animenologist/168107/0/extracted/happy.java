import java.io.*;
import java.util.*;

public class happy {

	public static void main(String[] args) throws Exception{
		
		Scanner In = new Scanner(new File("input.in"));
		System.setOut(new PrintStream(new File("output.out")));
		int numCases = In.nextInt();
		In.nextLine();
		for(int currCase = 1;currCase <= numCases;currCase++){
			
			int size = 0;
			int[] bases = new int[3]; 
			
			String input = In.nextLine();
			
			Scanner read = new Scanner(input);
			while(read.hasNext()){
				bases[size] = read.nextInt();
				size++;
			}
			
			int num;
			for(num = 2;!happyBase(num, bases, size);num++);
			System.out.println("Case #"+currCase+": "+num);
		}
		
	}
	
	public static boolean happyBase(int num, int[] base, int size){
		
		for(int i = 0;i < size;i++){
			String curr = Integer.toString(num, base[i]);
			TreeSet<Integer> found = new TreeSet<Integer>();
			found.add(num);
			int c = num;
			while(c != 1){
				c = 0;
				for(int j = 0;j < curr.length();j++)
					c += (curr.charAt(j)-'0')*(curr.charAt(j)-'0');
				if(c!= 1 && found.contains(c))
					return false;
				curr = Integer.toString(c, base[i]);
				found.add(c);

			}
		}
		return true;
	}
	
}
