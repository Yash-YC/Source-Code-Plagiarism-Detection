import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;


public class Multibase {
	
	/**
	 * @param args
	 * @throws InterruptedException 
	 */
	public static void main(String[] args) throws IOException, InterruptedException {
		
		Multibase main = new Multibase();
		main.doWork();
		
	}
	
	private void doWork() throws IOException, InterruptedException
	{
		BufferedReader reader = new BufferedReader(new FileReader("C:/codejam/mb/input.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("C:/codejam/mb/output.out"));
		
//		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
//		PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
		
		int tcases = Integer.parseInt(reader.readLine().trim());
		
		HashMap<String, Integer> answer = new HashMap<String, Integer>();
		
		for (int tc=0; tc<tcases; tc++)
		{
			String line = reader.readLine().trim();
			String[] sbases = line.split(" +");
			
			ArrayList<Integer> bases = new ArrayList<Integer>();
			for (int i=0; i<sbases.length; i++)
				bases.add(new Integer(sbases[i]));
			
			int number = -1;

			if (answer.containsKey(line))
				number = answer.get(line);
			else			
			for (int i=2; ; i++)
			{
				boolean errors = false;
				for (int base : bases)
					if (!isHappy(i, base))
					{
						errors = true;
						break;						
					}
				
				if (!errors) { number = i; answer.put(line, number); break; }
				//Thread.sleep(500);
				//System.out.println(i);
			}
			
			pw.write("Case #" + (tc+1) + ": " + number + "\n");
			pw.flush();
		}
		
		
		pw.flush();
		pw.close();
	}
	
	private boolean isHappy(int n, int base)
	{
		HashSet<Long> seen = new HashSet<Long>();
		long n2 = n;
		for (int count = 0; count < 1000; count++)
		{
			long vb = tobase(n2, base);
			if (seen.contains(vb)) return false;
			seen.add(vb);
			long sum = 0;
			long vb2 = vb;
			//System.out.println(vb);
			//System.out.println(vb2);
			while (vb2 > 0)
			{
				sum += (vb2%10)*(vb2%10);
				vb2/=10;				
			}
			
			n2 = sum;
			
			if (sum == 1) return true;			
		}
		
		return false;
	}
	
	private long tobase(long n, int base)
	{
		long value = 0;
		while (n > 0)
		{
			value *= 10;
			value += n%base;
			n/=base;
		}
		
		return value;
	}
	
}
