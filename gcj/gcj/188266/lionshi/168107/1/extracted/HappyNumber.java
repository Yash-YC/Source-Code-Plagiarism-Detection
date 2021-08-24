import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.regex.Pattern;


public class HappyNumber {
	private static final Pattern SPACE = Pattern.compile(" ");
	
	public static void main(String[] args) {
		try {
			BufferedReader input = new BufferedReader(new FileReader("A-large.in"));
			BufferedWriter output = new BufferedWriter(new FileWriter("A-large.out"));
			
			int T = Integer.valueOf(input.readLine());
			for(int i=0; i<T; i++) {
				//Input
				String[] numbers = SPACE.split(input.readLine());
				
				int b[] = new int[numbers.length];
				for(int j=0; j<numbers.length; j++)
					b[j] = Integer.valueOf(numbers[j]);

				boolean found = false;
				int result = 1;
				
				while(!found){
					result++;
					for(int k=0; k<b.length; k++) {
						if(!isHappy(result, b[k]))
							break;
						if (k == b.length - 1)
							found = true;
					}
				}
				
				// Output
				output.write("Case #" + (i+1) + ": " + result);
				output.newLine();
			}
			
			input.close();
			output.close();
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	static boolean isHappy(int number, int b) {
		int n = number;
		java.util.HashSet<Integer> hitted = new java.util.HashSet<Integer>();
		
		while(n>0){
			int m =0;
			hitted.add(n);
			
			while(n>0){
				int d = n%b;
				m += d*d;
				n = n/b;
			}
			if (m==1)
				return true;
			if(hitted.contains(m))
				return false;
			
			n=m;
			
		}
		return false;
	}
}
