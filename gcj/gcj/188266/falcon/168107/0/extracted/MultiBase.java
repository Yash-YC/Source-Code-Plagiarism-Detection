import java.util.HashMap;


public class MultiBase 
{
	public boolean isHappy(int num,int base)
	{
		HashMap<String,Boolean> seen=new HashMap<String,Boolean>();
		String str=Integer.toString(num,base);
		while(true)
		{
			if(seen.get(str)!=null && seen.get(str))
				break;
			seen.put(str, true);
			if(str.equals("1"))
				return true;
			int sum=0;
			for(int i=0;i<str.length();++i)
			{
				int cc=str.charAt(i)-'0';
				cc*=cc;
				sum+=cc;
			}
			str=Integer.toString(sum,base);
		}	
		return false;
		
	}
	public int smallest(int[] bases)
	{
		int MAX=1000000;
		for(int i=2;i<=MAX;++i)
		{
			boolean hpy=true;
			for(int j=0;j<bases.length;++j)
			{
				hpy&=(isHappy(i, bases[j]));
			}
			if(hpy)
				return i;
		}
		return -1;
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) 
	{
		MultiBase obj=new MultiBase();
		InputProcessor inp=new InputProcessor();
		int T=inp.getNextInteger();
		for(int i=1;i<=T;++i)
		{
			int[] bases=inp.getIntegers(inp.getNextLine());
			int small=obj.smallest(bases);
			inp.output(i, small);
		}
	}

}
