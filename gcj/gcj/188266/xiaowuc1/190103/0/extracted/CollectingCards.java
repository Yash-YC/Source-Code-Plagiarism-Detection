import java.io.*;
import java.util.*;
public class CollectingCards {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("cards.txt")));
		int x = Integer.parseInt(br.readLine());
		for(int num = 1; num <= x; num++)	{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			//System.out.println("For " + n + " and " + c);
			int numLeft = n-c;
			int numHave = n - numLeft;
			double exp = 1;
			while(numLeft > 0)	{
				double cont = 1;
				for(int i = 0; i < c; i++)	{
					cont *= (numHave - i);
				}
				for(int i = 0; i < c; i++)	{
					cont /= (n-i);
				}
				double expected = 1.0 / (1 - cont);
				exp += expected;
				numHave++;
				numLeft--;
			}
			pw.println("Case #" + num + ": " + exp);
		}
		pw.close();
	}
}
