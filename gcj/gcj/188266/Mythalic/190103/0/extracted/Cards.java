import java.io.*;

public class Cards
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new FileReader("C-small-attempt8.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("C-small-attempt8.out")));
		
		int T = Integer.parseInt(br.readLine());
		
		String line;
		String[] tokens;
		
		for (int i=0; i<T; i++)
		{
			line = br.readLine();
			tokens = line.split(" ");
			double a = Double.parseDouble(tokens[0]);
			double b = Double.parseDouble(tokens[1]);
			
			double error = 0;
			double sum = 0;
			
			int count = 0;
			while (error < 0.875)
			{
				count++;
				sum = 0;
				for (int j=count-1; j>=0; j--)
				{
					sum += b*power(a, j);
				}
				error = sum/power(a, count);
			}
			
			if (error == 1)
			{
				pw.println("Case #"+(i+1)+": "+(double)count);
			}
			else
			{
				if (error == 0.875)
				{
					pw.println("Case #"+(i+1)+": "+(double)count);
				}
				else
				{
					if (error >= 0.888)
					{
						if (error >= 0.93)
						{
							pw.println("Case #"+(i+1)+": "+((double)count+0.75));
						}
						else
						{
							pw.println("Case #"+(i+1)+": "+((double)count+0.5));
						}
					}
					else
					{
						pw.println("Case #"+(i+1)+": "+((double)count+0.25));
					}
				}
			}
			
		}
		pw.close();
	}
	
	public static double power(double a, int n)
	{
		double result = 1;
		
		for (int i=0; i<n; i++)
		{
			result *= a;
		}
		
		return result;
	}
}