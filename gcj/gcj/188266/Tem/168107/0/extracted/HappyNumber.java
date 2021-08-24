import java.util.*;
import java.io.*;


public class HappyNumber{
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("1A-small.in"));
		FileWriter fw = new FileWriter(new File("1A-small.out"));
		
		int T = sc.nextInt();sc.nextLine();
		for(int t=1; t<=T; t++){
			fw.write("Case #" + t + ": ");
			String[] tmp = sc.nextLine().split(" ");
			int[] base = new int[tmp.length];
			for(int j=0; j<tmp.length; j++)
				base[j] = Integer.parseInt(tmp[j]);
			for(int n=2;;n++){
				boolean b = false;
				for(int i=0; i<base.length; i++){
					String temp = toBase(n, base[i]);
					HashSet<String> ss = new HashSet<String>();
					boolean found = false;
					while(!ss.contains(temp)){
						ss.add(temp);
						int sum=0;
						for(int j=0; j<temp.length(); j++){
							int zz=Integer.parseInt(temp.charAt(j)+"");
							sum += zz*zz;
						}
						temp = toBase(sum, base[i]);
						if(temp.compareTo("1") == 0){
							found = true;
							break;
						}
					}
					if(!found) break;
					if(i == base.length-1) b = true;
				}
				if(b){
					fw.write(n + "\n");
					break;
				}
			}
			
		}
		fw.flush();
		fw.close();
	}
	public static String toBase(int n, int base){
		String res = "";
		while(n!=0){
			res = n%base + res;
			n = n/base;
		}
		return res;
	}
}