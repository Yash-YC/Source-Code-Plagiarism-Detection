import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class MultiBaseHappiness {
	
	public static void main(String[] args){
		
		System.out.println("Input");
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		try {
			String line = in.readLine();
			int N = Integer.parseInt(line);
			
			String[] inputs = new String [N];
			
			for(int i=0;i<N;i++)
				inputs[i]=in.readLine();
			
			System.out.println("Output");
			for(int i=0;i<inputs.length;i++){
				String input = inputs[i];
				ArrayList<Integer> bases = new ArrayList<Integer>();
				StringTokenizer st = new StringTokenizer(input," ");
				while(st.hasMoreTokens()){
					bases.add(new Integer(st.nextToken()));
				}
					
				int dec = 1;
				boolean allHappy = false;
				do{
					dec++;
					allHappy = true;
					for(int j=0;j<bases.size();j++){
						int base = bases.get(j).intValue();
						int basenum = convertBaseN(dec, base);
						boolean b = isHappyNumber(base, basenum);
						if(!b) {
							allHappy = b;
							break;
						}
					}
				}while(!allHappy);
				System.out.println("Case #"+(i+1)+": "+dec);
			}
			
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public static void main1(String arg[]){
		boolean number = isHappyNumber(7, 143);
		System.out.println(number);
	}
	
	
	public static boolean isHappyNumber(int base, int number){
		
		boolean happyNumber =false;  
		boolean cont = true;
		ArrayList<Integer> cyclelist = new ArrayList<Integer>();
		cyclelist.add(new Integer(number));
		int sqaredNumber = number;
		do{
			
			sqaredNumber = digitSquaresInBaseN(base, sqaredNumber);
			if(sqaredNumber==1) {happyNumber =true;cont = false;}
			Integer n = new Integer(sqaredNumber);
			boolean exist = cyclelist.contains(n);
			if(exist==true)cont = false;
			else{ 
				cyclelist.add(n);
				cont = true;}
		}while(!happyNumber && cont);
		
		
		return happyNumber;
	}
	
	public static int digitSquaresInBaseN(int base, int number){
		
		int Sum = 0;
		do{
			int rem = number%10;
			Sum+=(int)Math.pow(rem,2);
			number /=10; 
			
		}while(number!=0);
		
		return convertBaseN(Sum,base);
	}
	

	public static int convertBaseN(int decNumber, int base){
		
		int number = 0;
		int radix = 0;
		do{
			int i = 0;
			int mult = 0;
			do{
				i++;
				mult = base*i;
			}while(mult <=decNumber);
			i--;
			number += (decNumber - i*base)*(int)Math.pow(10,radix);
			decNumber = i;
			radix++;
		}while(decNumber!=0);
		
		return number;
	}

}
