package sbeam.Round1A;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class CollectingCards {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		// io stuff
		FileInputStream file = null;
		FileWriter output = null;
		
		try {
			file = new FileInputStream("C-small-attempt0.in");
			output = new FileWriter("C-small0-out.txt");
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		Scanner in = new Scanner(file);
		int numCases = in.nextInt();
		
		for(int i = 1; i <= numCases; i++)
		{
			double num = 1d;
			
			int C = in.nextInt();
			int N = in.nextInt();
			double numerator = fact(C) / (fact(N) * fact(C - N));
			int Np = C - N;
			
			while(Np > 0)
			{
				double denom;
				if(Np > N)
					denom = fact(Np) / (fact(N) * fact(Np - N));
				else
					denom = fact(N) / (fact(Np) * fact(N - Np));
				num += (numerator / denom);
				
				Np = Np - N;
			}
			
			System.out.println(String.format("Case #%d: %#.7f", i, num));
			output.write(String.format("Case #%d: %#.7f\n", i, num));
		}
		
		output.close();
	}
	
	public static long fact(int a)
	{
		long mult = 1;
		for(int x = 1; x <= a; x++)
		{
			mult *= x;
		}
		
		return mult;
	}

}
