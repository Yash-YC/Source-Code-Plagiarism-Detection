import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class Main {
	
	static int size;

	static boolean happy(int num, int  base) {
		int count = 0;
		double dCount;
		int iHappy = 0;
		int itr = 0;
		

		int ny = 0; 

 

		while (num > 0) {

			while (num > 0) {

			
				count = (num % base);
				dCount = (double) count;
				iHappy = (int) (iHappy + Math.pow(dCount, 2));
				num = num / base;
				
				
			}

			
			itr++; 
			
			if (iHappy != 1) { 
				num = iHappy;

			} else {

				return true;
			}

			iHappy = 0;
			ny++;

			if (ny >= 15) {
				return false;
			}

		}
		return false;

	}
	
	public static boolean getHappy(int[] bases,int n)
	{
		
		for(int x = 0 ; x < size ; x++)
		{
			if(!happy(n,bases[x]))return false;
			
		}
		return true;
	}
	public static int getNumber(int[] bases)
	{
		int i = 2;
		while(!getHappy(bases,i))i++;
		return i;
	}
	
	public static void main(String[] args) throws IOException {
		
		Scanner s = new Scanner(new FileReader("A-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.out"));
		int t = s.nextInt();
		s.nextLine();
		for(int i = 1 ; i <= t ; i++)
		{
			size = 0;
			int[] bases = new int[10];
			String line = s.nextLine();
			Scanner ls = new Scanner(line);
			
			while(ls.hasNext())
			{
				bases[size]=ls.nextInt();
				size++;
			}
			pw.println("Case #"+i+": "+getNumber(bases));
			
		}
		pw.close();
		
		
	}

}
