import java.io.*;
import java.util.*;
public class MultibaseHappiness
{

	public static byte happyNumber(int n, int b,byte[][] a) 
	{
	   // 0 -
		// 1 - fail
		// 2 - ok
		// 3 - checking
		int nn = n;
		
		a[b][n] = 3;
		
//		String number = "";
		int nextNumber = 0;
		while (n>0) {
			int t = n%b;
//			number = t+ "" + number;
			nextNumber += t*t;
			n = n / b;
		}
		if (a[b][nextNumber]==3 || a[b][nextNumber]==1) return a[b][nn] = 1; else
		if (a[b][nextNumber]==2) return a[b][nn] = 2;
		return a[b][nn] = happyNumber(nextNumber,b,a);
	}
	
	public static void main(String[] args) throws Exception
	{
		Scanner sc = new Scanner(new File("MultibaseHappiness.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("MultibaseHappiness.out"));
		
		int maxN = 1000000;
		byte[][] isHappyNumber = new byte[11][maxN];		
		for (int i=2;i<11;i++) {
		 	isHappyNumber[i][1] = 2;
			for (int j=2;j<maxN;j++) {
				//System.out.println(i+" "+j);
				if (isHappyNumber[i][j] == 0) isHappyNumber[i][j] = happyNumber(j,i,isHappyNumber);
//				out.write(isHappyNumber[i][j]+" ");
			}
//			out.write("\n");
		}
		
		
		int t = Integer.parseInt(sc.nextLine());
		for (int test=1;test<=t;test++){
			String[] tmp = sc.nextLine().split(" ");
			int[] b = new int[tmp.length];
			for (int i=0;i<tmp.length;i++) 
				b[i] = Integer.parseInt(tmp[i]);
			int res = 0;
			for (int i=2;i<maxN;i++) {
				boolean ok = true;
				for (int j=0;j<b.length;j++)
					if (isHappyNumber[b[j]][i]!=2) {
						ok = false;
						break;
					}
				if (ok) {
					res = i;
					break;
				}
			}
						
			out.write("Case #"+test+": "+res+"\n");
		}
		
		sc.close();
		out.close();
	}
}