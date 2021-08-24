import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;


public class A {

	/**
	 * @param argsreturn false;
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		boolean[][] hn =new boolean[9][40];
		for(int i=2;i<11;i++){
			hn[i-2]=findHappyNumbersByBase(i);
		}
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		for(int cases=1;cases<=N;cases++){
			String[] numst=in.nextLine().split(" ");
			int[] nums = new int[numst.length];
			for(int i=0;i<nums.length;i++)
				nums[i]=Integer.valueOf(numst[i]);
			for(int i=2;i<n;i++){
				boolean t=true;
				for(int j=0;j<nums.length;j++){
					if(!isHN(i, nums[j])) t=false;
					if(!isHN(i, nums[j])) t=false;
				}
				if(t){
					System.out.println("Case #"+cases+": "+i);
					break;
				}
			}
		}
		
	}
	
	static int n=100000;
	public static boolean[] findHappyNumbersByBase(int b){
		
		boolean[] ishn = new boolean[n];
		for(int i=0;i<n;i++){
			ishn[i]=isHN(i,b);
		}
		return ishn;
	}
	
	public static boolean isHN(int i, int b){
		Set<Integer> nums=new HashSet<Integer>();
		while(true){
		int result=0;
		while(i!=0){
			result+=Math.pow(i%b,2);
			i/=b;
		}
		i=result;
		if(i==1) return true;
		if(nums.contains(i)) return false;
		nums.add(i);
		}
		
	}

}
