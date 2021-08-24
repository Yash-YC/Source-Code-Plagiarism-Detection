import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {

	/**
	 * @param args
	 */
	Scanner in;
	int [] bases;
	int nBases;
	
	public static void main(String[] args) {
		new Main().process();
	}

	void process() {
		try {
			FileInputStream fileStream = new FileInputStream("in2.txt");
			System.setIn(fileStream);
		} catch (Exception ex) {
			ex.printStackTrace();
		}

		try {
			FileOutputStream fileStream = new FileOutputStream("out.txt");
			System.setOut(new PrintStream(fileStream));
		} catch (Exception ex) {
			ex.printStackTrace();
		}
		
		in = new Scanner(System.in);
		int cases = in.nextInt();
		
		in.nextLine();
		for (int i = 0; i < cases; i++) 
		{
			String tmp = in.nextLine();
			String [] token = tmp.split(" ");
			bases = new int[token.length];
			nBases = 0;
			for (int j = 0; j < token.length; j++) {
				if(token[j]=="")
				{
					continue;
				}
				bases[nBases] = Integer.parseInt(token[j]);
				nBases++;
			}
			
			int result = findHappy(); 
			
			System.out.printf("Case #%d: %d",i+1,result);
			System.out.println();
		}
	}
	
	int findHappy()
	{
		int current = 2;
		boolean flag = false;
		while(!flag)
		{
			flag=true;
			for (int i = 0; i < nBases; i++) {
				if(!happy(current,bases[i]))
				{
					flag=false;
					break;
				}
			}
			current++;
	 	}
		return current-1;
	}
	
	boolean happy(int n, int base)
	{
		boolean [] num = new boolean[100000];
		while(n!=1)
		{
			String tmp = Converter.toString(n, base);
			int sum=0;
			for (int i = 0; i < tmp.length(); i++) {
				sum+=(tmp.charAt(i)-'0')*(tmp.charAt(i)-'0');
			}
			if(num[sum])
				break;
			n = sum;
			num[n]=true;
		}
		if(n==1)
			return true;
		else
			return false;
	}
}