import java.io.*;
import java.util.*;

public final class C {

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File(args[0]));
		PrintWriter writer = new PrintWriter(args[1]);
		int numtests = sc.nextInt();
		sc.nextLine();
		Random gen = new Random();
		for (int test = 0; test < numtests; test++) {
			double total=sc.nextInt();
			double boost=sc.nextInt();
			double tries=0;
			double numremain=total;
			double previous=total;
			while(numremain>0){
				tries++;
				previous=numremain;
				numremain-=Math.ceil(numremain)/total*boost;
			}
			tries+=numremain/(previous-numremain);
			writer.print("Case #" + (test + 1) + ": ");
			writer.format("%,.7f\n", tries);
		}
		sc.close();
		writer.close();
	}
}