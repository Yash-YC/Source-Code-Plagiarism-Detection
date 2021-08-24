package Round1A;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Happiness {

	public static void main(String [] args) {
		try {
			BufferedReader r = new BufferedReader(new FileReader(new File("C:\\A-small.in")));
			BufferedWriter writer = new BufferedWriter(new FileWriter(new File("c:\\A-small.out")));

			int t = Integer.parseInt(r.readLine());

			for (int c = 0; c < t; ++c) {
				String s = r.readLine();
				String [] split = s.split(" ");

				int [] bases = new int [split.length];
				for (int x = 0; x < split.length; ++x) {
					bases[x] = Integer.parseInt(split[x]);
				}

				int lowest = 1;
				boolean works = false;
				boolean happy[][] = new boolean[100000][bases.length];
				for (int x = 0; x < bases.length; ++x){
					happy[1][x] = true;	
				}

				while(!works) {
					++lowest;

					works = true;
					
					for (int x = 0; x < bases.length; ++x) {
						int number = lowest;
						
						boolean [] visited = new boolean[100000];
						
						while(number >= lowest && (!visited[number])) {
							visited[number] = true;
							
							int new_number = 0;
							while (number > 0) {
								int digit = number % bases[x];
								number = number / bases[x];
								int square = digit*digit;
								new_number += square;
							}
							
							number = new_number;

							if (number == lowest) {
								happy[lowest][x] = false;
								break;
							}
						}
						
						happy[lowest][x] = happy[number][x];
						works = works && happy[number][x];
					}
				}

				writer.write("Case #" + (c+1) + ": " + lowest + "\n");
			}

			writer.flush();
			writer.close();
		} catch (IOException e) {
			System.err.println(e);
		}
	}
}
