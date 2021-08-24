import java.util.Scanner;

public class A{
	public static void main(String args[]){
		int t;
		String s;
		String res = "";
		Scanner scan = new Scanner(System.in);

		t = scan.nextInt();


		scan.nextLine();
		for(int i = 0; i < t; i++){
			res = "";
			s = scan.nextLine();
			res += s.charAt(0);

			for(int j = 1; j < s.length(); j++){
				if(s.charAt(j) >= res.charAt(0)){
					res = s.charAt(j) + res;
				}else{
					res = res + s.charAt(j);
				}
			}
			System.out.println("Case #"+(i+1)+": "+res);
		}
	}
}