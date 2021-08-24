import java.util.*;
import java.io.*;

public class round1A {
	static FileWriter fw;
	
	public static void main(String[] args) throws Exception{
		Scanner sc= new Scanner(new File("round1Asmall.in.txt"));
		int n = sc.nextInt();
		fw = new FileWriter(new File("round1Asmall.out"));
		sc.nextLine();
		for(int ix=0;ix<n;ix++)
		{
			String[] arr = sc.nextLine().split(" ");
			int[] bases = new int[arr.length];
			for(int i=0;i<bases.length;i++) bases[i] = Integer.parseInt(arr[i]);
			
			out:
			for(int x=2;;x++){
				
				
				for(int i=0;i<bases.length;i++)
				{
					int rep = Integer.parseInt(Integer.toString(x,bases[i]));
					HashSet<Integer> vis = new HashSet<Integer>();
					
					boolean fail = false;
					while(rep!=1){
						if(!vis.add(rep)){
							fail = true;
							break;
						}
						int sum = 0;
						while(rep>0){
							int dig = rep%10;
							sum += dig * dig;
							rep/=10;
						}
						
						rep = Integer.parseInt(Integer.toString(sum,bases[i]));
					}
					if(fail){
						break;
					}
					if(i==bases.length-1)
					{
						
						//System.out.println(x);
						fw.write("Case #"+(ix+1)+":" + " "+x);
						fw.write(System.getProperty("line.separator"));
						break out;
					}
				}
			}
		}
		fw.close();
	
	}
	

}
