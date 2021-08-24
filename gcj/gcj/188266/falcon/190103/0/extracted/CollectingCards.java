
public class CollectingCards 
{
	private int maxIdx;
	private double ret;
	private int C;
	private int N;
	private int NCR(int N,int R)
	{
		int num=1,denom=1;
		int t=N;
		if(N==R || R==0)
			return 1;
		for(int i=1;i<=R;++i,--t)
		{
			denom*=i;
			num*=t;		
		}
		int ret=num/denom;
		return ret;
	}
	private void solve(int idx,int mask,double prevProb)
	{
		if(idx>=maxIdx || prevProb<1e-5)
			return;
		if(Integer.bitCount(mask)==C)
		{
			ret+=(idx-1)*prevProb;
			return;
		}
		double prob=1.0/(double)NCR(C,N);
		int max=(1<<C);
		for(int i=0;i<max;++i)
		{
			if(Integer.bitCount(i)==N)
			{
				int nm=mask|i;
				double nextProb=prevProb*prob;
				solve(idx+1,nm,nextProb);
			}				
		}
	}
	public double getExpectation(int N,int C)
	{
		this.maxIdx=10;
		this.N=N;
		this.C=C;
		this.ret=0.0;
		solve(1,0,1.0);
		return ret;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args)
	{
		CollectingCards obj=new CollectingCards();
		InputProcessor inp=new InputProcessor();
		int T=inp.getNextInteger();
		for(int i=1;i<=T;++i)
		{
			int[] inputs=inp.getIntegers(inp.getNextLine());
			double ret=obj.getExpectation(inputs[1],inputs[0]);
			inp.output(i, ret);
		}
		

	}

}
