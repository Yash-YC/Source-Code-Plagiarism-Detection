import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class R1ALarge {

	static int LIM = 13000000;
	
	public static void main(String[] args) {
		int[][] arr = new int[8][LIM/32+1];
		
		precom(arr);
		
		Scanner sc = new Scanner(System.in);
		int num = Integer.parseInt(sc.nextLine());
		for(int numCase = 1 ; numCase <= num ; numCase++){
			String[] ss = sc.nextLine().split(" ");
			int[] ns = new int[ss.length];
			for(int i = 0 ; i < ss.length ; i++)
				ns[i] = Integer.parseInt(ss[i]);
			
			for(int i = 2 ; i < LIM ; i++){
				boolean isGood = true;
				for(int j = 0 ; j < ns.length && isGood; j++){
					if(ns[j] == 2) continue;
					isGood = isGood && (((arr[ns[j]-3][i/32]) & (0x1 << i % 32)) != 0);
				}
				if(isGood){
					System.out.println("Case #" + numCase + ": " + i);
					break;
				}
			}
			
		}
		

	}
	
	public static void precom(int[][] arr){
		for(int n = 3 ; n <= 10 ; n++){
			Arrays.fill(arr[n-3], 0xFFFFFFFF);
			

			for(int num = 2 ; num < LIM ; num++){
				int nnn = num;
				boolean isBad = false;
				HashSet<Integer> visited = new HashSet<Integer>();
				
				while(nnn != 1){
					if (visited.contains(nnn)){
						isBad = true;
						break;
					}
						
					visited.add(nnn);
					
					int newnnn = 0;
					while(nnn != 0){
						int kkk = (nnn%n);
						newnnn += kkk*kkk;
						nnn = nnn/n;
					}
					nnn = newnnn;
				}
				
				
				//if(n == 10 && !isBad)
					//System.out.println(n + " " + num);
				if(!isBad){
					//(arr[n-3][num/32]) = (arr[n-3][num/32]) & (0x1 << (num % 32));
				}
				else
					(arr[n-3][num/32]) = (arr[n-3][num/32]) & (~(0x1 << (num % 32)));
			}			
			System.out.println(n);
			
			//System.out.println(Arrays.toString(arr[n]));
		}
	}
	
}
