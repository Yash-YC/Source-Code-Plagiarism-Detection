import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

public class ProblemOne {

	public static void main(String[] args) {
		try {
			Scanner sc = new Scanner(new File("A-small-attempt0.in"));
			PrintWriter pw = new PrintWriter("A-small.out");
			
			int n = sc.nextInt();
			sc.nextLine();
			for(int i=0; i<n; i++){
				String str = sc.nextLine();
				Scanner sc2 = new Scanner(str);
				List<Integer> list = new ArrayList<Integer>();
				while(sc2.hasNextInt()){
					list.add(sc2.nextInt());
				}
				sc2.close();
				
				int res = doCalc(list);
				pw.println("Case #" + (i+1) + ": " + res);
			}
			
			pw.close();
			sc.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static int doCalc(List<Integer> list) {
		boolean ok;
//		System.out.println(list);
		for(int i=2;;i++){
			ok = true;
			for(int base : list){
				if(!happy(base, i)){
					ok = false;
					break;
				}
			}
			if(ok){
				return i;
			}
		}
	}
	
	public static boolean happy(int base, int num){
//		System.out.println("Checking happy " + base + " " + num);
		HashSet<Integer> set = new HashSet<Integer>();
		boolean res = false;
		int squaredSum = num;
		while(true){
			squaredSum = getSquaredSum(base, squaredSum);
//			System.out.println(squaredSum);
			if(set.contains(squaredSum)){
				break;
			}
			if(squaredSum == 1){
				res = true;
				break;
			}
			set.add(squaredSum);
		} 
		return res;
	}
	
	public static int getSquaredSum(int base, int num){
		int res = 0;
		int mod;
//		System.out.println("getSquaredSum " + base + " " + num);
		while(num != 0){
			mod = num % base;
			num /= base;
			res += (mod*mod);
//			System.out.println("num " + num + " mod  " + mod);
		}
		return res;
	}
	
	

}
