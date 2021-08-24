import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
		
	public static Vector<Integer> Add(Vector<Integer> sum, Vector<Integer> sq, int base){
		Vector<Integer> ret = new Vector<Integer>();
		int carry = 0;
		for(int i = 0; i < Math.max(sum.size(), sq.size()); i++){
			int total = carry;
			if(i < sum.size())
				total += sum.get(i);
			if(i < sq.size())
				total += sq.get(i);
			carry = total / base;
			if(i >= ret.size())
				ret.add(total % base);
		}
		if(carry > 0)
			ret.add(carry);
		return ret;
	}
	public static boolean IsHappy(int num, int base){
		Vector<Integer> buf = new Vector<Integer>();		
		while(num > 0){
			buf.add(num % base);
			num /= base;
		}
		Vector<Vector<Integer>> cycle = new Vector<Vector<Integer>>();
		cycle.add(buf);			
		while(true){
			Vector<Integer> sq = new Vector<Integer>();
			Vector<Integer> sum = new Vector<Integer>();
			sum.add(0);
			for(int i = 0; i < buf.size(); i++){
				int pr = buf.get(i) * buf.get(i);
				sq.add(pr % base);
				if(pr >= base)
					sq.add(pr / base);				
				sum = Add(sum, sq, base);
				sq.clear();
			}				
			int ones = 0;
			for(int i = 0; i < sum.size(); i++)
				ones += sum.get(i);
			if(ones == 1)
				return true;
			if(cycle.contains(sum))
				break;
			cycle.add(sum);
			buf = sum;
					
		}
		return false;
	}
	public static int Best(int start, Vector<Integer> bases){		
		for(int i = start; ; i++){
			boolean end = true;
			for(int j = 0; j < bases.size(); j++)
				if(IsHappy(i, bases.get(j)) == false)
					end = false;
			if(end == true)
				return i;
		}
	}
	public static void main(String[] args) throws Exception{		
		//BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader in = new BufferedReader(new FileReader("in.txt"));	
		int t = Integer.parseInt(in.readLine());
		Vector<Integer> bases = new Vector<Integer>();
		for(int i = 0; i < t; i++){
			StringTokenizer tz = new StringTokenizer(in.readLine());
			int start = 1;
			while(tz.hasMoreTokens()){
				bases.add(Integer.parseInt(tz.nextToken()));
				start = Math.max(start, bases.lastElement());
			}
			System.out.print("Case #");
			System.out.print(i + 1);
			System.out.print(": ");
			System.out.println(Best(2, bases));
			bases.clear();
		}
	}		
}
