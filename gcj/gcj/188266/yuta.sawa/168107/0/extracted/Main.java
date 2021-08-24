import java.util.*;
import java.math.*;
class Main{
	public static int next(int num, int base){
		int sum = 0;
		while(num > 0){
			int mod = num % base;
			sum += mod * mod;
			num /= base;
		}
		return sum;
	}
	public static void main(String [] argv){
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		sc.nextLine();
		//LinkedList<Set<Integer>> list = new LinkedList<Set<Integer>>();
		//for(int i = 2; i <= 10; i++){
		//	list.add();
		//}
		
		for(int c = 0; c < cases; c++){
			System.out.printf("Case #%d: ", c + 1);
			String [] line = sc.nextLine().split("\\s");
			int [] nums = new int[line.length];
			for(int i = 0; i < line.length; i++){
				nums[i] = Integer.parseInt(line[i]);
			}
			solve(nums);
		}
		
	}
	public static void solve(int [] nums){
		int c = 2;
		while(true){
			boolean flg = true;
			for(int i = 0; i < nums.length; i++){
				flg = flg & isHappy(c, nums[i]);
			}
			if(flg){
				System.out.println(c);
				return;
			}
			c++;
		}
		
	}
	public static boolean isHappy(int num, int base){
		//System.out.printf("ishappy(%d %d)\n", num, base);
		TreeSet<Integer> set = new TreeSet<Integer>();
		set.add(num);
		while(true){
			int n = next(num, base);
			if(set.contains(n))
				return false;
			if(n == 1)
				return true;
			set.add(n);
			num = n;
		}
	}

}
