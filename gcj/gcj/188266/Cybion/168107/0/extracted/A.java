import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;

public final class A{
	public static void main(final String[] args) throws IOException{
		//		final String filename="A-small.0";
		final String filename="A-small";
		//		final String filename="A-large";
		final BufferedReader br=new BufferedReader(new FileReader(filename+".in"));
		final PrintStream out=new PrintStream(new File(filename+".out"));
		//		final PrintStream out=System.out;
		final byte T=Byte.valueOf(br.readLine());
		int nbCases=T;
		int x=0;
		String[] basesStr;
		int[] bases;
		while(nbCases-->0){
			++x;
			basesStr=br.readLine().split(" ");
			final int basesCnt=basesStr.length;
			bases=new int[basesCnt];
			for(int i=0; i<basesCnt; ++i){
				bases[i]=Integer.parseInt(basesStr[i]);
			}
			out.println("Case #"+x+": "+A.doCase(bases));
			//			out.println("Case #"+x+": "+C.formatNumber(C.countOccsForPhrase(phrase, sentence, -1)));
		}
	}

	private static final int doCase(final int[] bases){
		int found=1;
		final int basesCnt=bases.length;
		int n=1;
		while(found<=1){
			++n;
			for(int i=0; i<basesCnt; ++i){
				if(!A.isHappy(n, bases[i])){
					//					System.err.println(n+" not happy :(");
					break;
				}
				if(i==basesCnt-1){
					//					System.out.println(n+" is happy :D");
					found=n;
				}
			}
		}
		return found;
	}

	private static final boolean isHappy(int n, final int b){
		final List<Integer> list=new ArrayList<Integer>();
		while(!list.contains(Integer.valueOf(n))){
			//			System.err.println(n+" -> "+A.go(n, b));
			//			A.sleep(1000);
			list.add(Integer.valueOf(n));
			n=A.go(n, b);
			if(n==1) return true;
		}
		return false;
	}

	private static final int go(final int n, final int b){
		final int[] tab=A.getDigits(n, b);
		final int tabCnt=tab.length;
		int total=0;
		for(int i=0; i<tabCnt; ++i){
			total+=tab[i]*tab[i];
		}
		return total;
	}

	private static final int[] getDigits(final int n, final int b){
		final List<Integer> digsList=new ArrayList<Integer>();
		int rest=n;
		int powMax=0;
		int cur=(int)Math.pow(b, powMax);
		//		System.out.println(" conv: start cur = "+cur);
		do{
			cur=(int)Math.pow(b, ++powMax);
			//			System.out.println(" conv: lookfor cur = "+cur);
		}
		while(cur<=n);
		cur=(int)Math.pow(b, --powMax);
		//		System.out.println(" conv: powMax = "+powMax);
		//		System.out.println(" conv: cur = "+cur);
		while(cur>1){
			//			System.out.println(" conv: -> "+rest/cur+" * "+cur+" [rest = "+rest%cur+"]");
			digsList.add(rest/cur);
			rest=rest%cur;
			cur=cur/b;
		}
		digsList.add(rest);
		final int digsCnt=digsList.size();
		final int[] digs=new int[digsCnt];
		for(int i=0; i<digsCnt; ++i){
			digs[i]=digsList.get(i).intValue();
		}
		//		System.out.println(n+" base '"+b+"' => "+Arrays.toString(digs));
		return digs;
	}

	//	/**
	//	 * @deprecated 4 debug only
	//	 * @param millis
	//	 */
	//	@Deprecated
	//	private static final void sleep(final long millis){
	//		try{
	//			Thread.sleep(millis);
	//		}
	//		catch(final InterruptedException e){}
	//	}
}
