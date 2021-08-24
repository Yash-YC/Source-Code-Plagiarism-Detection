import java.util.*;
import java.io.*;

public class C {
	
	public static void main(String[] args) throws FileNotFoundException {
		
		Scanner scan = new Scanner(new File("C-small-attempt1.in"));
		//Scanner scan = new Scanner(new File("foo.txt"));
		int num_cases = scan.nextInt();
		for (int index = 0; index < num_cases; index++){
			
			int c = scan.nextInt();
			int n = scan.nextInt();
			double x = run_test_case(c,n);
			System.out.println("Case #" + (index + 1) + ": " + x);
		}
	}
	
	public static double run_test_case(int c, int n){
		
		double sum = 0.0;
		if (c <= n) return 1.0;
		else {
			sum += 1.0;
			int num = choose(c-1,n);
			int dem = choose(c,  n);
			num = dem - num;
			
			double e_packs_for_card = ((double)dem) / ((double)num);
			sum += e_packs_for_card;
		}
		return sum;
	}
	
	public static int choose(int n, int how_many){
		int amt = 1;
		for (int i = 1; i <= how_many;i++){
			amt *= n;
			n--;
		}
		return amt;
	}

}
