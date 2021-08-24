import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {

	/**
	 * @param args
	 */
	Scanner in;
	int c,n;
	
	public static void main(String[] args) {
		new Main().process();
	}

	void process() {
		try {
			FileInputStream fileStream = new FileInputStream("in.txt");
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
			c = in.nextInt();
			n = in.nextInt();
			
			double result=findE();
			
			System.out.printf("Case #%d: %f",i+1,result);
			System.out.println();
		}
	}
	
	double findE()
	{
		if(c==n)
			return 1;
		long f = C(c,n); long t;
		int start = c/n;
		if(c%n!=0)
			start++;
		double sum=0; double current=0; double AcP=0;
		double tmp=1;
		
			for (int i = start; ; i++) {
				for (int k = 1; k <= c-n; k++) {
					tmp*=C(c,k); t = C(c-k,n);
					for (int j = 0; j < i; j++) {
						tmp*=(double)t/f;
					}
					current+=tmp;
					tmp=(tmp/tmp)*-1;
				}
				if(1-AcP<0.00000000001)
					break;
				
				sum+=i*(1-current-AcP);
				AcP+=1-current-AcP;
				tmp=1; current=0;
			}				
		
		return sum;
	}
	
	long C(long n, long r)
	{
		// n!/(r!(n-r)!)
	      // nCr = nc(r-1) + (n-1)Cr
	      if (r == n)
	         return 1;
	      else
	         return (r+1) * C(n,r+1) / (n-r);

	}
}