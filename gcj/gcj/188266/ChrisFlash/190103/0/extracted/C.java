package j2009r1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.regex.Pattern;

public class C {
	public static String inputDirectory="src/j2009r1a/";
	public static String inputFile="C.in";
	public static String outputFile="C.out";
	public static PrintWriter output;
	public static Map<String,Integer> wayMap;
	public static void main(String[] args) throws FileNotFoundException{
		Scanner s=new Scanner(new File(inputDirectory+inputFile));
		output=new PrintWriter(new File(inputDirectory+outputFile));
		
		int N=s.nextInt();
		for(int Case=1;Case<=N;Case++){
			s.nextLine();
			int stamps=s.nextInt();
			int packs=s.nextInt();
			double times=1;
			int collected=packs;
			while(collected<stamps){
				double probMiss=1;
				for(int i=0;i<packs;i++){
					probMiss*=((double)(collected-i))/(stamps-i);
				}
				double probHit=1-probMiss;
				//out("prob getting new of "+stamps+" when "+collected+" have been collected is "+probHit);
				times+=1/probHit;
				collected++;
			}
			output.printf("Case #%d: %f\n",Case,times);
			//out("Case #"+Case+": "+times);
		}
		output.flush();
	}

	public static void out(String s){
		output.println(s);
		System.out.println(s);
	}
}
