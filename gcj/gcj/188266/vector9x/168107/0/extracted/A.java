import java.util.*;
import java.awt.*;
import static java.lang.Math.*;

public class A {
	static Scanner scan;
	public static void main(String[] args) {
		scan=new Scanner(System.in);
		scan.useLocale(Locale.US);
		new A();
	}
	
	final int DIGITS=20;
	
	String transformar(String entrada, int base)
	{
		int suma=0;
		
		for(char c: entrada.toCharArray())
		{
			int digit=c-'0';
			suma+=digit*digit;
		}
		return Integer.toString(suma, base);
	}
	
	boolean isHappy(String entrada)
	{
		boolean uno=false;
		for(char c: entrada.toCharArray())
			if(c=='1')
			{
				if(!uno)
					uno=true;
				else return false;
			}
			else if(c!='0')
				return false;
		
		return uno;
	}
	
	
	public A()
	{
		int numCasos=Integer.parseInt(scan.nextLine());
		for(int caso=1;caso<=numCasos;caso++)
		{
			String[] bases=scan.nextLine().split(" ");
			Arrays.sort(bases);
			int resul=solve(bases);
			System.out.printf("Case #%d: %d\n", caso, resul);
		}
		
	}
	
	int solve(String[] bases)
	{
		
		otronumero:
		for(int numerito=2; ; numerito++)
		{
			//System.err.println("numerito="+numerito);
			//otrabase:
			for(String strBase: bases)
			{
				//System.err.println("base="+strBase);
				int base=Integer.parseInt(strBase);
				HashSet<String> generados=new HashSet<String>();
				//generados.add(strBase);
				String actual=Integer.toString(numerito, base);
				while(true)
				{
					//String nuevo=transformar(actual,base);
					//System.err.println("actual="+actual);
					if(isHappy(actual))
					{
						//happy=true;
						//continue otrabase;
						//System.err.println("happy: "+numerito+" en base "+base);
						break;
					}
					if(generados.contains(actual))
					{
						//happy=false;
						continue otronumero;
					}
					generados.add(actual);
					actual=transformar(actual,base);
				}
			}
			return numerito;
		}
	}

}
