package gcj091a;

import java.awt.Point;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;

public class HappyBases
{
	public static void main(String...none) throws Exception
	{
		if(false) proc("C:\\jam\\files\\a.test.in.txt", "C:\\jam\\files\\a.test.out.txt");
		if(true) proc("C:\\jam\\files\\A-small-attempt0.in", "C:\\jam\\files\\A-small-attempt0.out.txt");
		if(false) proc("C:\\jam\\files\\A-large.in", "C:\\jam\\files\\A-large.out.txt");
	}
	
	static void proc(String infile, String outfile) throws Exception
	{
		BufferedReader br=new BufferedReader(new FileReader(infile));
		BufferedWriter bw=new BufferedWriter(new FileWriter(outfile));
		
		int numcases=Integer.parseInt(br.readLine().trim());
		System.out.println("case count: "+numcases);
		
		for(int i=1; i<=numcases; ++i)
		{
			System.out.println("case #: "+i);
			StringTokenizer st=new StringTokenizer(br.readLine());
			int[] bases=new int[st.countTokens()];
			for(int j=0; j<bases.length; ++j)
				bases[j]=Integer.parseInt(st.nextToken());
			
			bw.write("Case #"+i+": "+new HappyBases().solve(bases)+"\r\n");
		}
		br.close();
		bw.flush();
		bw.close();
	}
	
	int solve(int[] bases)
	{
		Arrays.sort(bases);
		Set<Integer> sbases=new HashSet<Integer>();
		for(int base:bases)
			sbases.add(base);
		
		int startat=2;
		for(Set<Integer> solved:cache2.keySet())
			if(sbases.containsAll(solved))
			{
				if(solved.containsAll(sbases))
					return cache2.get(solved);
				startat=Math.max(startat, cache2.get(solved));
			}
		
		outer:for(int i=startat;;++i)
		{
			for(int base:bases)
				if(!isHappy(i, base, new HashSet<Integer>()))
					continue outer;
			cache2.put(sbases, i);
			return i;
		}
	}
	
	static Map<Point, Boolean> cache=new HashMap<Point, Boolean>();
	static Map<Set<Integer>, Integer> cache2=new HashMap<Set<Integer>, Integer>();
	
	
	boolean isHappy(int number, int base, Set<Integer> checked)
	{
		if(number==1)
			return true;
		
		Point point=new Point(number, base);
		Boolean cached=cache.get(point);
		if(cached!=null)
			return cached.booleanValue();
		
		if(!checked.add(number))
			return cache(point, false);
		
		String nInBase=Integer.toString(number, base);
		int sum=0;
		for(char c:nInBase.toCharArray())
		{
			int d=c-'0';
			sum+=(d*d);
		}
		
		if(sum==1)
			return cache(point, true);
		return cache(point, isHappy(sum, base, checked));
	}
	
	static boolean cache(Point point, boolean result)
	{
		if(point.x>20000)
			return result;
		cache.put(point, result?Boolean.TRUE:Boolean.FALSE);
		return result;
	}
}
