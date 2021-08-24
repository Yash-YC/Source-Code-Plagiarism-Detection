package googlejam;
import java.io.FileReader;
import java.io.IOException;

public class googlejam
{
	
	static int[] base;
	static int basenumber;
	
	public static void main(String[] args)
	{
		googlejam gj = new googlejam();
		gj.mainprocess();
	}
	
	void mainprocess()
	{
		try 
		{
			FileReader f = new FileReader("A-small-attempt0.in");
			int number = 0;
			int t;
			while ((t = f.read())!='\n')
			{
				number *= 10;
				number += t - 48;
			}
			
			int point = 1;
			while (point <= number)
			{
				
				base = new int[10];
				basenumber = 0;
				
				t = 'a';
				while (t!='\n')
				{
					int number1 = 0;
					while ((t = f.read())!=' ' && t!='\n')
					{
						number1 *= 10;
						number1 += t - 48;
					}
					basenumber++;
					base[basenumber] = number1;
				}
				
				System.out.println("Case #" + point + ": " + process());
				point++;
				//具体处理过程
			}
			f.close();
		}
		catch (IOException ex)
		{
			ex.printStackTrace();
		}
	}
	
	int process()
	{
		int mark = 1;
//		System.out.println(decompose(3,2));
		
		for (int i=2;i<=2147483647;i++)
		{
			mark = 1;
			for (int j=1;j<=basenumber;j++)
			{
				if (decompose(i,base[j]))
				{
					continue;
				}
				else
				{
					mark = 0;
					break;
				}
			}
			if (mark == 1) return i;
		}
		return 0;
	}
	
	boolean decompose(int i,int base)
	{
		int temp;
		int sum = 0;
		for (int k=1;k<=1000;k++)
		{
			temp = 0;
			while (i!=0)
			{
				temp = i%base;
				i/=base;
				sum += temp * temp;
			}
			if (sum == 1)
			{
				break;
			}
			i = sum;
			sum = 0;
		}
		
		if (sum == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
