package round1a;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;

public class HappyNum {
	public static void main(String[] args) {
		HappyNum ck=new HappyNum();
		Finder k=ck.new Finder();
		k.run(args);
	}
	
	
	class Number{
		List<Integer> digits=new ArrayList<Integer>();

		@Override
		public boolean equals(Object obj) {
			if(!(obj instanceof Number)) {
				return false;
			}else {
				Number obj1=(Number)obj;
				return obj1.digits.containsAll(digits)&&digits.containsAll(obj1.digits);
			}
		}

		@Override
		public int hashCode() {
			int tmp=0;
			for (Iterator iterator = digits.iterator(); iterator.hasNext();) {
				Integer type = (Integer) iterator.next();
				tmp+=type;
			}
			return tmp;
		}
		
	}
	
	class Finder extends Runner{

		@Override
		void runCase(int num, int[] insi) throws Exception {
			int i=2;
			HashSet<Number>[] forbidden=new HashSet[insi.length];
			HashSet<Number>[] happy=new HashSet[insi.length];
			for (int j = 0; j < happy.length; j++) {
				happy[j]=new HashSet<Number>();
			}
			for (int j = 0; j < forbidden.length; j++) {
				forbidden[j]=new HashSet<Number>();
			}
			while(true) {				
				boolean ok=false;
				for (int j = 0; j < insi.length; j++) {
					int base=insi[j];
					ok=check(i,forbidden[j],happy[j],base);		
					if(!ok)break;
				}
				if(ok) {
					System.out.println("Case #"+(num+1)+": "+i);
					return;
				}
				i++;
			}
			
		}
		boolean check(int tgt,HashSet<Number> forbidden,HashSet<Number> happy,int base) {
			HashSet<Number> tmp=new HashSet<Number>();
			while(true) {
				Number mn=getNum(tgt,base);
				if(forbidden.contains(mn)) {
					return false;
				}
				if(tmp.contains(mn)) {
					forbidden.add(mn);
					return false;
				}
				if(happy.contains(mn)) {
					return true;
				}
				if(mn.digits.size()==1&&mn.digits.contains(1)) {
					happy.add(mn);
					return true;
				}else {
					tmp.add(mn);
				}
				tgt=getSum(mn,base);
			}
		}
		int getSum(Number n,int base){
			int x=0;
			for (Iterator iterator = n.digits.iterator(); iterator.hasNext();) {
				Integer type = (Integer) iterator.next();
				x+=type*type;
			}
			return x;
		}
		Number getNum(int c,int base) {
			Number n=new Number();
			do {
				int m=c%base;
				c=c/base;
				if(m!=0) {
				n.digits.add(m);
				}
			}while(c>0);
			return n;
		}
	}
	
	abstract class Runner{
		public  void run(String[] args) {
			BufferedReader br=null;
					try {
						br=new BufferedReader(new FileReader(new File(args[0])));
						String in1=br.readLine();
						int N=Integer.parseInt(in1);
					for(int v=0;v<N;v++) {
						String ins=br.readLine();
						String[] inss=ins.split("\\s+");
						int[] insi=new int[inss.length];
						for (int i = 0; i < inss.length; i++) {
							insi[i]=Integer.parseInt(inss[i]);
						}
						runCase(v,insi);
					}
				}catch (Exception e) {
					// TODO: handle exception
							e.printStackTrace();
				}finally {
							try {
								br.close();	
							} catch (Exception e) {
								// TODO: handle exception
								e.printStackTrace();
							}
				}
		}
		abstract void runCase(int num,int[] insi) throws Exception;
	}
}
