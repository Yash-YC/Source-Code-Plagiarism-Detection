package it.vito.round1A;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Set;
import java.util.TreeSet;

public class Prob1 {

	public static final void main(String args[]) throws FileNotFoundException {
		try{
			
			InputStreamReader convert = new InputStreamReader(System.in);
			BufferedReader stdin = new BufferedReader(convert);
			System.out.print("Input file: ");
			String file = stdin.readLine();
			
			FileInputStream fstream = new FileInputStream(file);
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			
			FileOutputStream fos = new FileOutputStream("A-out.txt");
			PrintStream out = new PrintStream(fos);	
			
			int T = Integer.parseInt(br.readLine());
			for ( int t=0; t<T; t++ ) {
				String line[] = br.readLine().split(" ");
				int bases[] = new int[line.length];
				for ( int n=0; n<bases.length; n++ )
					bases[n] = Integer.parseInt(line[n]);
				
				boolean found = false;
				int N = 2;
				while ( !found ) {
					if ( N == 91 ) 
						System.out.print("");
					found = true;
					for ( int nb=0; nb<bases.length; nb++ ) {
						int base = bases[nb];
						//represent the number in this base
						int nj=0;
						int j = N;
						while ( j >= base ) {
							j /= base;
							nj++;
						}
						int n[] = new int[nj*2+5];
						j = N;
						Set<Integer> seen = new TreeSet<Integer>();
						while ( !seen.contains(j) ) {
							seen.add(j);
							for ( nj=0; nj<n.length; nj++ )
								n[nj] = 0;
							nj=0;
							while ( j > 0 ) {
								n[nj] = j % base;
								j /= base;
								nj++;
							}
							//check if it is happy
							for ( nj=0; nj<n.length; nj++ )
								j += n[nj]*n[nj];
						}
						if ( j != 1 )
							found = false;
					}
					
					
					N++;
				}
				
				
				System.out.println("Case #"+(t+1)+": "+(N-1));
				out.println("Case #"+(t+1)+": "+(N-1));
			}
			//Close the input stream
			in.close();
			out.close();
		}catch (Exception e){//Catch exception if any
			System.err.println("Error: " + e.getMessage());
			e.printStackTrace();
		}	
	}

}
