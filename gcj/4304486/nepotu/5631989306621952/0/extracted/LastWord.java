import java.io.PrintWriter;
import java.util.Scanner;

public class LastWord {
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		int T = sc.nextInt();
		sc.nextLine();
		for (int i=0;i<T;i++){
			String s=sc.nextLine();
		//	System.out.println(s);
			pw.println("Case #"+(i+1)+": "+ solution(s));
		}
		pw.close();
	}
	static String solution(String s){
		String sol = new String();
		String aux;
		sol=sol+s.charAt(0);
		for (int i=1;i<s.length();i++)
		{
			if (s.charAt(i)>=sol.charAt(0)){
				// add char at the beginiing
				 sol =s.charAt(i)+ sol;
			}
			else
			{
				sol = sol + s.charAt(i);
			}
		}
		return sol;
	}
}
