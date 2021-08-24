package it.vito.round1A;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;

public class Prob3 {

	public static final void main(String args[]) throws FileNotFoundException {
		try{
			
			InputStreamReader convert = new InputStreamReader(System.in);
			BufferedReader stdin = new BufferedReader(convert);
			System.out.print("Input file: ");
			String file = stdin.readLine();
			
			FileInputStream fstream = new FileInputStream(file);
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			
			FileOutputStream fos = new FileOutputStream("C-out.txt");
			PrintStream out = new PrintStream(fos);
			
			double precision = 1e-7;
			
			int T = Integer.parseInt(br.readLine());
			for ( int t=0; t<T; t++ ) {
				if ( t==96 ) 
					System.out.print("");
				String line[] = br.readLine().split(" ");
				int C = Integer.parseInt(line[0]);
				int N = Integer.parseInt(line[1]);
				
				double E = 0.0;
				double lastE = -1;
				//P[X=n] = 0 if n < C/N+1
				int round = (C-1)/N+1;
				while (E - lastE > precision ) {
					lastE = E;
					double P = 0;	
					for ( int n=1; n<=N; n++ ) {
						double p = 1.0;
						//Probability of missing only n cards, per every take
						double totalPerm = binomialCoefficient(C, N);
						double missingPerm = (C-n)>=N?binomialCoefficient(C-n, N):0;
						//--> misingPerm/totalPerm
						if ( round > 1 && missingPerm > 0 )
							p *= Math.pow(missingPerm/totalPerm, round-1);
						else
							p = 0;
						//probability of taking the n missing cards now
						double takingPerm = totalPerm-missingPerm;
						p *= takingPerm/totalPerm;
						p *= binomialCoefficient(C, n);
						P += p;
					}
					E += P*round;
					
					round++;
				}
				
				
				System.out.println("Case #"+(t+1)+": "+String.format("%.5f", E));
				out.println("Case #"+(t+1)+": "+String.format("%.5f", E));
			}
			//Close the input stream
			in.close();
			out.close();
		}catch (Exception e){//Catch exception if any
			System.err.println("Error: " + e.getMessage());
			e.printStackTrace();
		}	
	}

	public static long binomialCoefficient(int n, int r) {
		long t = 1;

		int m = n - r; // r = Math.max(r, n - r);
		if (r < m) {
			r = m;
		}

		for (int i = n, j = 1; i > r; i--, j++) {
			t = t * i / j;
		}

		return t;
	}


}
