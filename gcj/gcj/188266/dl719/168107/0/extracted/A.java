import java.io.*;
import java.util.*;


public class A {

	static HashSet<Integer> set;
	
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub

		Scanner scan = new Scanner(new File("A-small-attempt0.in"));
		ArrayList<Integer> bases;
		int num_cases = scan.nextInt();
		scan.nextLine();
		for (int case_no = 0; case_no < num_cases; case_no++){
			String line = scan.nextLine();
			bases = new ArrayList<Integer>();
			StringTokenizer toke = new StringTokenizer(line);
			while(toke.hasMoreTokens()){
				bases.add(Integer.valueOf(toke.nextToken()));
			}
			int[] bases_to_use = new int[bases.size()];
			for (int i = 0; i < bases.size(); i++){
				bases_to_use[i] = bases.get(i);
			}
			run_case(bases_to_use, case_no + 1);
		}
	}
	
	public static void run_case(int[] bases, int case_no){
		int n = 2;
		for (;;n++){
			boolean happy = true;
			for (int index = 0; index < bases.length; index++){
				set = new HashSet<Integer>();
				if (!is_happy(Integer.toString(n, bases[index]),bases[index])){
					happy = false;
				}
				if (!happy) break;
			}
			if(happy){
				break;
			}
		}
		System.out.println("Case #" + case_no + ": " + n);
		
	}
	
	public static boolean is_happy(String n, int base){
		
		int sum = 0;
		for (int i = 0; i < n.length(); i++){
			int c = (n.charAt(i) - '0');
			c *= c;
			sum += c;
		}
		
		if (sum == 1) return true;
		else {
			if (set.contains(sum)) return false;
			set.add(sum);
			return (is_happy(Integer.toString(sum,base),base));
		}
		
	}

}
