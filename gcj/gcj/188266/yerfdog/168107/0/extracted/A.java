import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.StringTokenizer;


public class A {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(new File("A-small.in"));
		FileWriter fstream = new FileWriter("out.txt");
		BufferedWriter out = new BufferedWriter(fstream);
		int T = Integer.parseInt(scan.nextLine());
		for (int x = 1; x <= T; x++) {
			StringTokenizer str = new StringTokenizer(scan.nextLine());
			int[] bases = new int[str.countTokens()];
			for(int a =0; a< bases.length; a++){
				bases[a] = Integer.parseInt(str.nextToken());
			}
			int K = 2;
			outer:
			while(true){
				for(int a = bases.length -1; a>=0; a--){
					HashSet<Integer> set = new HashSet<Integer>();
					int base = bases[a];
					int cur = K;
					
					while(!set.contains(cur) && cur!=1){
						set.add(cur);
						String s = Integer.toString(cur, base);
						cur = 0;
						for(int b=0; b<s.length(); b++){
							int dig = Integer.parseInt(s.charAt(b)+"");
							cur += dig*dig;
						}
						
					}
					if(cur==1){
						if(a==0){
							out.write("Case #" + x + ": " + K + "\n");
							break outer;
						}
					}else{
						break;
					}
				}
				
				K++;
			}
		}
		out.close();
	}

}
