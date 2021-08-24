import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Happy {
	static int N;
	static int[]base;
	
public static String convertToBase(int x,int base){
	String ans="";
	
	while(x>0){
		ans=x%base+ans;
		x=x/base;
	}
	return ans;
}

public static boolean isHappy(String number,int base){
	int sum;
	ArrayList<Integer> visited=new ArrayList<Integer>();
	while(true){
		sum=0;
		int length=number.length();
		for(int i=0;i<length;i++){
			sum+=Math.pow(number.charAt(i)-'0',2);
		}
		if(sum==1)return true;
		if(visited.contains(sum))return false;
		visited.add(sum);
		number=convertToBase(sum,base)+"";
	}
}

public static void main(String[]args)throws Exception{
	
	FileReader file=new FileReader("A-small-attempt0.in");
	BufferedReader buffer=new BufferedReader(file);
	N=Integer.parseInt(buffer.readLine());
	StringTokenizer tok;
	base=new int[10];
	for(int i=0;i<N;i++){
		tok=new StringTokenizer(buffer.readLine());
		int length;
		for(length=0;tok.hasMoreTokens();length++){
			base[length]=Integer.parseInt(tok.nextToken());
		}
		
		int k;
		for(k=2;true;k++){
			int t;
			for(t=0;t<length;t++){
				if(!isHappy(convertToBase(k, base[t]),base[t]))break;
			}
			if(t==length)break;
		}
		System.out.println("Case #"+(i+1)+": "+k);
	}
	
	
	//System.out.println(isHappy(convertToBase(3, 2),2));
	
	

}
	
	
}
