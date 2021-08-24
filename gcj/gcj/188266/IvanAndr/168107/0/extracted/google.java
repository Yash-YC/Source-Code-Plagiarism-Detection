import java.io.*;
import java.util.*;
import java.lang.*;
public class google {
	public static int[] use;
	public static String convert(String num, int base){
		int ans = 0;
		ans = Integer.parseInt(num);
		String buf = "";
		while (ans != 0) {
			buf = buf + (ans % base);
			ans/=base;
		}
		String res = "";
		for (int i = buf.length() - 1; i>=0; i--){
			res+=buf.charAt(i);
		}
		return res;
	}
	public static boolean check(String num, int base){
		int x = Integer.parseInt(num);
		num = convert(num,base);
		Arrays.fill(use, 0);
		while ((use[x] < 2) && (!num.equals("1"))){
			int ans = 0;
			for (int i = 0; i < num.length(); i++)
				ans+=(num.charAt(i) - '0')*(num.charAt(i) - '0');
			num = ans + "";
			use[Integer.parseInt(num)]++;
			if (use[Integer.parseInt(num)] == 2) break;
			x = Integer.parseInt(num);
			num = convert(num,base);
			
			
		}
		if (num.equals("1")) return true; else return false;
	}
	public static void main(String[] args) throws FileNotFoundException{
		int T;
		use = new int[100000];
		Scanner in = new Scanner(new File("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter("output.txt");
		T = in.nextInt();
		in.nextLine();
		for (int glob = 0; glob < T; glob++){
			String s = in.nextLine();
			int base[] = new int[11];
			for (int i = 0; i<s.length(); i+=2){
				base[base[0] + 1] = s.charAt(i) - '0';
				if (base[base[0]+1] == 1) {base[base[0]+1] = 10; };
				base[0]++;
			}
			int num = 2;
			while (num<10000000) {
				boolean bo = true;
				for (int i = 1; i < base[0] + 1; i++)
					if (check(num+"",base[i]) == false) { bo = false; break;}
				if (bo) {
					out.println("Case #" + (glob+1) + ": " + num);
					out.flush();
					break;
				}
				num++;
			}
		}
	}

}
