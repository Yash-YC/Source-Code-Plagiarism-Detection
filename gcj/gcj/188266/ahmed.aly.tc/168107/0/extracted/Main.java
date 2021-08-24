import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Vector;


public class Main {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner cin=new Scanner(new File("a.txt"));
		PrintWriter out=new PrintWriter(new File("b.txt"));
		int N=cin.nextInt();
		String s=cin.nextLine();
		for(int nn=0;nn<N;nn++){
			s=cin.nextLine();
			Vector<Integer> v=new Vector<Integer>();
			for(int i=0;i<s.length();i++)
				if(s.charAt(i)!=' '){
					if(i<s.length()-1 && s.charAt(i+1)!=' '){
						v.add(10);
						i++;
					}
					else
						v.add(s.charAt(i)-'0');
				}
			int ret=-1;
			for(int num=2;;num++){
				int cnt=0;
				for(int j=0;j<v.size();j++){
					int base=v.get(j);
					HashSet<String> hs=new HashSet<String>();
					String ss=Integer.toString(num, base);
					while(true){
						if(Integer.valueOf(ss)==1){
							cnt++;
							break;
						}
						if(hs.contains(ss))
							break;
						hs.add(ss);
						int sum=0;
						for(int i=0;i<ss.length();i++)
							sum+=(ss.charAt(i)-'0')*(ss.charAt(i)-'0');
						ss=Integer.toString(sum,base);
					}
				}
				if(cnt==v.size()){
					ret=num;
					break;
				}
			}
			out.printf("Case #%d: %d\n",nn+1,ret);
		}
		out.close();
	}

}
