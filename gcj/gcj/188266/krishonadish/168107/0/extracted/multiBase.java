import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

/**
 * 
 * @author kvudata
 *
 */
public class multiBase {

	public static int[] getBaseNum(int n, int b){
		
		//Get highest power that is less than n
		int exp = 0;
		for(int i = 0; true; i++)
		{
			int power = (int)Math.pow(b, i);
			if( power == n )
			{
				int[] num = new int[i+1];
				num[0] = 1;
				return num;
			}
			else if( power > n ){
				exp = i-1;
				break;
			}
		}
		
		int[] numBaseb = new int[exp+1];
		
		for(int d = 0; d < numBaseb.length; d++)
		{
			int power = (int)Math.pow(b, exp);
			for(int i = 1; i <= b; i++)
			{
				if( n - i*power < 0 ){
					numBaseb[d] = i-1;
					n -= (i-1)*power;
					break;
				}
				else if( n - i*power == 0 )
				{
					numBaseb[d] = i;
					return numBaseb;
				}
			}
			exp--;
		}
		return numBaseb;
	}
	
	public static boolean checkHappy(int n, int b){
		HashSet<Integer> prev = new HashSet<Integer>();
		prev.add(n);
		
		int[] digits = new int[0];
		int s = n;
		
		int sum = 0;
		digits = getBaseNum(s, b);
		for(int d:digits)
			sum += Math.pow(d, 2);
		s = sum;
		
		
		if(s == 1)
			return true;
			
			while( s != 1 && !prev.contains(s) ){
				prev.add(s);
				sum = 0;
				digits = getBaseNum(s, b);
				for(int d:digits)
					sum += Math.pow(d, 2);
				s = sum;
			}
		
		if( s == 1 )
			return true;
		else
			return false;
	}
	
	public static void main(String[]args){
		Scanner key = new Scanner("");
		try {
			key = new Scanner(new File("src/A-small-attempt0.in"));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		int cases = Integer.parseInt(key.nextLine());
		
		for(int i = 1; i <= cases; i++)
		{
			String s = key.nextLine();
			String[] bases = s.split("\\s");
			int n = 2;
			
			boolean done = false;
			while(!done){
				
				for(int j = 0; j < bases.length; j++){
					boolean d = checkHappy(n, Integer.parseInt(bases[j]));
					if( !d )
						break;
					else if( d && j==bases.length-1 )
						done = true;
				}
				if(!done)
					n++;
			}
			System.out.println("Case #"+i+": "+n);
		}
	}
}
