package Round1;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

public class ProblemA {
	
	public static void main(String[] args) {
		new ProblemA().run();
	}
	
	public void run(){
		try{
			BufferedReader reader=new BufferedReader(new InputStreamReader(new FileInputStream("A-small-attempt0.in")));
			FileWriter writer=new FileWriter("A-small-attempt0.out", false);
			String str=reader.readLine();
			StringTokenizer token;
			
			int nt=Integer.parseInt(str);
			for(int m=1;m<=nt;m++){
				str=reader.readLine();
				token=new StringTokenizer(str);
				List<Integer> baseList=new ArrayList<Integer>();
				while(token.hasMoreTokens()){
					baseList.add(Integer.parseInt(token.nextToken()));
				}
				
				for(int j=2;;j++){
					boolean isGet=true;
					for(int base:baseList){
						Set<Integer> set=new HashSet<Integer>();
						int k=j;
						boolean isHappy=false;
						while(true){
							if(set.contains(k))break;
							String s=Integer.toString(k, base);
							int sum=getSum(s);
							if(sum==1){
								isHappy=true;
								break;
							}else{
								set.add(k);
								k=sum;
							}
						}
						if(!isHappy){
							isGet=false;
							break;
						}
					}
					if(isGet){
						writer.write("Case #"+m+": "+j+"\n");
						break;
					}
				}
			}
			reader.close();
			writer.close();
		}
		catch(Exception e){
			e.printStackTrace();
		}
	}
	
	private int getSum(String s){
		int sum=0;
		for(int i=0;i<s.length();i++){
			char ch=s.charAt(i);
			if(ch>='0'&&ch<='9'){
				sum+=(ch-48)*(ch-48);
			}else{
				sum+=(ch-'a'+10)*(ch-'a'+10);
			}
		}
		return sum;
	}

}
