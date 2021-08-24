import java.util.*;

public class R1A {

	static int LIM = 1000000;
	
	public static void main(String[] args) {
		boolean[][] arr = new boolean[11][LIM];
		
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
					isGood = isGood && arr[ns[j]][i];
				}
				if(isGood){
					System.out.println("Case #" + numCase + ": " + i);
					break;
				}
			}
			
		}
		

	}
	
	public static void precom(boolean[][] arr){
		for(int n = 2 ; n <= 10 ; n++){
			

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
						newnnn += (nnn%n)*(nnn%n);
						nnn = nnn/n;
					}
					nnn = newnnn;
				}
				
				
				//if(n == 2 && !isBad)
					//System.out.println(n + " " + num);
				if(!isBad)
					arr[n][num] = true;
				else
					arr[n][num] = false;
			}			
			
			//System.out.println(Arrays.toString(arr[n]));
		}
	}
	
}
