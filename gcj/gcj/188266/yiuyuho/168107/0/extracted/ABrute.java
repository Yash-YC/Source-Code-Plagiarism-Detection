import java.io.*;
import java.util.*;
import java.text.*;

public class ABrute
{
	public PrintStream out = System.out;
	public PrintStream err = System.err;
	public Scanner in = new Scanner(System.in);
	public DecimalFormat fmt = new DecimalFormat("0.000000000");
	
	public TreeSet<Integer>[] happy, sad;
	
	public int MaxBase = 10;

	public void main()
	{
		try
		{
//			err=new PrintStream(new FileOutputStream("error.log"),true);
			out = new PrintStream(new FileOutputStream("ABrute.out"),true);

			happy = new TreeSet[MaxBase+1];
			sad = new TreeSet[MaxBase+1];
			
			int i,j,k,x,y;

			for(x=2;x<=MaxBase;++x)
			{
				happy[x] = new TreeSet<Integer>();
				sad[x] = new TreeSet<Integer>();
			}

			for(x=2;x<=MaxBase;++x) happy[x].add(1);
			
			int[] res = new int[1<<(MaxBase+1)];
			Arrays.fill(res, 2000000000);

			k = 2;
			while(true)
			{
				boolean good = true;
				int mask = 0;
				for(x=2;x<=MaxBase;++x)
				{
					if(happy(k, x)) mask |= (1<<x);
					else
					{
						good = false;
					}

					//out.println("happy("+k+","+x+") = "+happy(k, x));
				}
				if(k < res[mask]) res[mask] = k;

				if(good) break;
				++k;
				if(k%10000==0) err.println("k = "+k);
			}

			err.println("Max = "+k);

			for(i=0;i<res.length;++i)
			{
				if(i%100==0) out.println();
				out.print(res[i]+",");
			}
			out.println();
		}
		catch(Exception e) { e.printStackTrace(); }
	}//end public void main()
	
	public int Max = 300;

	public boolean happy(int k, int x)
	{
		if(happy[x].contains(k)) return true;
		if(sad[x].contains(k)) return false;

		//unknown
		int value = k;
		TreeSet<Integer> S = new TreeSet<Integer>();

		while(true)
		{
			if(happy[x].contains(k))
			{
				if(value <= Max) happy[x].addAll(S);
				else
				{
					S.remove(value);
					happy[x].addAll(S);
				}
				return true;
			}

			if(sad[x].contains(k))
			{
				if(value > Max) S.remove(value);
				sad[x].addAll(S);

				return false;
			}

			if(S.contains(k))
			{
				if(value > Max) S.remove(value);
				sad[x].addAll(S);
				return false;
			}

			S.add(k);
			k = next(k, x);
		}
	}

	public int next(int k, int x)
	{
		int ret = 0;
		while(k > 0)
		{
			ret += (k%x)*(k%x);
			k /= x;
		}
		return ret;
	}

	public int Int() { return in.nextInt(); }
	public long Long() { return in.nextLong(); }
	public String Token() { return in.next(); }
	public String Line() { return in.nextLine(); }

	public static void main(String[] args)
	{
		long startTime = System.currentTimeMillis();

		(new ABrute()).main();

		System.err.println("Time Spent: "+(System.currentTimeMillis()-startTime)+"(ms)");
	}
}

