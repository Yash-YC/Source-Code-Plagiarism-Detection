import java.util.*;
import java.math.*;

public class A
{
	static int MAXH = 100000;
	static int[][] happy = new int[11][MAXH];
	static HashSet<BigInteger> hash;
	
	public static void main( String[] args )
	{
		Scanner input = new Scanner(System.in);
		
		int T = Integer.parseInt( input.nextLine() );
		String[] bases2;
		int[] bases;
		BigInteger answer;
		
		for( int i = 2; i < 11; i++ )
		{
			for( int j = 0; j < MAXH; j++ )
			{
				happy[i][j] = 0;
			}
		}
		
		for( int i = 0; i < T; i++ )
		{
			String temp = input.nextLine();
			bases2 = temp.split( " " );
			bases = new int[bases2.length];

			for( int j = 0; j < bases2.length; j++ )
			{
				bases[j] = Integer.parseInt( bases2[j] );
			}
			
			answer = BigInteger.ONE;
			answer = answer.add( BigInteger.ONE );
			
			for( ; ; answer = answer.add(BigInteger.ONE) )
			{
				boolean status = true;
				
				for( int j = 0; j < bases.length; j++ )
				{
					hash = new HashSet<BigInteger>();
					
					if( !isHappy(bases[j], answer ) ) status = false;
				}
				
				if(status) break;
			}
			
			System.out.println( "Case #" + (i+1) + ": " + answer );
		}
	}
	
	
	
	public static boolean isHappy( int base, BigInteger input )
	{
		if( hash.contains(input) )
		{
			happy[base][input.intValue()] = 1;
			return false;
		}
		
		hash.add( input );
		
		
		if( happy[base][input.intValue()] == 2 ) return true;
		else if( happy[base][input.intValue()] == 1 ) return false;
		else
		{
			String tmp = input.toString(base);
			BigInteger tmpHasil = new BigInteger( "0", base );
		
			for( int i = 0; i < tmp.length(); i++ )
			{
				tmpHasil = tmpHasil.add( new BigInteger( tmp.charAt(i) + "", base ).pow(2) );
			}
			
			if( tmpHasil.toString(base).equals( "1" ) )
			{
				happy[base][input.intValue()] = 2;
				return true;
			}
			else if( tmpHasil.equals( input ) )
			{
				happy[base][input.intValue()] = 1;
				return false;
			}
			else
			{
				return isHappy( base, tmpHasil );
			}
		}
	}
}