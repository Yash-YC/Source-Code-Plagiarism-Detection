import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;


public class Main1 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=getReader("A-small-attempt0.in");
		int n=Integer.parseInt(br.readLine());
		
		for(int i=1;i<=n;i++){
			int ans=2;
			
			String[] input=br.readLine().split(" ");
			int[] base=new int[input.length];
			for(int j=0;j<input.length;j++){
				base[j]=Integer.parseInt(input[j]);
			}
			
			
			while(true){
				boolean happy=true;
				for(int j=0;j<base.length;j++){
					if(ishappy(ans,base[j])==false){
						happy=false;
						break;
					}
				}
				if(happy==true){
					break;
				}
				ans++;
			}
			
			
			System.out.println("Case #"+i+": "+ans);
		}
	}
	
	public static boolean ishappy(int num,int base){
		HashSet<Integer> hs=new HashSet<Integer> ();
		int itor=num;
		while(true){
			if(hs.contains(itor)==false){
				hs.add(itor);
			}else{
				return false;
			}
			String temp=convert(itor,base);
			int tans=0;
			for(char c:temp.toCharArray()){
				tans+=(c-'0')*(c-'0');
			}
			if(tans==1){
				return true;
			}
			itor=tans;
		}
		
	}
	
	public static String convert(int num,int base){
		//System.out.println(base);
		StringBuffer sb=new StringBuffer();
		while(true){//System.out.println("aaa:"+base);
			if(num/base==0){
				sb.append(num);
				break;
			}else{
				sb.append(num%base);
			}
			num=num/base;
		}
		
		return sb.toString();
	}
	
	public static BufferedReader getReader(String file) {
		BufferedReader bf = null;
		try {
			bf = new BufferedReader(new FileReader(file));
			//bf = new BufferedReader(new InputStreamReader(System.in));
		} catch (Exception e) {
			e.printStackTrace();
		}

		return bf;
	}

	public static BufferedWriter getWriter() {
		BufferedWriter bw = null;
		try {
			bw = new BufferedWriter(new FileWriter("output.txt"));
		} catch (Exception e) {
			e.printStackTrace();
		}

		return bw;
	}

}
