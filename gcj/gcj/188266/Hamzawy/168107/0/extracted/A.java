import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Scanner;
import java.util.StringTokenizer;

public class A {

	/**
	 * @param args
	 */

	static boolean fun(int ind, int j) {
		String str = Integer.toString(ind, j);
		HashSet<String> s = new HashSet<String>();
		do {
			long x = 0;
			s.add(str);
			for (int i = 0; i < str.length(); i++)
				x += (str.charAt(i) - '0') * (str.charAt(i) - '0');
			if (x == 1)
				return true;
			str = BigInteger.valueOf(x).toString(j);
		} while (!s.contains(str));
		return false;
	}

	static int arr[] = new int[1000000];

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(new File("A-small-attempt0.in"));
		PrintWriter p = new PrintWriter(new File("out.txt"));
		//PrintWriter p1 = new PrintWriter(new File("save.txt"));
		//p1.println(arr[0]);
		//p1.println(arr[1]);
		for (int i = 2; i < 1000000; i++) {
			for (int j = 2; j <= 10; j++) {
				if (fun(i, j)) {
					arr[i] |= (1 << j);
					//System.out.println(i + " " + j);
				}
			}
			//p1.println(arr[i]);
		}
		//p1.close();
		int t=in.nextInt();
		System.out.println(in.nextLine());
		for(int K=0;K<t;K++)
		{
			p.print("Case #"+(K+1)+": ");
			StringTokenizer ss = new StringTokenizer(in.nextLine());
			int x=0;
			while(ss.hasMoreTokens())
				x|=(1<<Integer.valueOf(ss.nextToken()));
			for(int i=2;i<1000000;i++)
				if((arr[i]&x)==x)
				{
					p.println(i);
					break;
				}
		}
		p.close();
	}

}
