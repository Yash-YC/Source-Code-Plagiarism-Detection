import java.io.*;
import java.util.*;

public final class A {

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File(args[0]));
		PrintWriter writer = new PrintWriter(args[1]);
		int numtests = sc.nextInt();
		sc.nextLine();
		for (int test = 0; test < numtests; test++) {
			LinkedList<Integer> bases = new LinkedList<Integer>();
			String line[]=sc.nextLine().split(" ");
			for(String s:line){
				bases.add(new Integer(s));
			}
			int currnum=1;
			int ishappy=0;
			while(ishappy!=line.length){
				ishappy=0;
				currnum++;
				for(Integer bas:bases){
					int currbase=bas.intValue();
					int tempnum=currnum;
					LinkedList<String> tested = new LinkedList<String>();
					while(tempnum!=1){
						String b="";
						while(tempnum!=0){
							b=tempnum%currbase+""+b;
							tempnum/=currbase;
						}
						if(tested.contains(b)){
							break;
						}else{
							tested.add(b);
						}
						for (int i = 0; i < b.length(); i++) {
							tempnum+=(b.charAt(i)-'0')*(b.charAt(i)-'0');
						}
					}
					if(tempnum==1){
						ishappy++;
					}
				}
			}
			
			writer.println("Case #" + (test + 1) + ": " + currnum);
		}
		sc.close();
		writer.close();
	}
}