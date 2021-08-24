import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigInteger;


public class Round1_A {
	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new FileReader("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new FileWriter("A-small-attempt0.out"));
		int number = Integer.parseInt(in.readLine());
		bbs:for(int bb = 1; bb <= number; bb++){
			String line[] = in.readLine().split(" ");
			int bases[] = new int[line.length];
			for(int i=0; i<line.length; i++){
				bases[i] = Integer.parseInt(line[i]);
			}
			cut:for(int minn = 2; minn<100000; minn++){
				for(int i=0; i<bases.length; i++){
					if(!happy(minn, bases[i]))
						continue cut;
				}
				out.println("Case #"+bb+": "+minn);
				continue bbs;
			}
			out.println("empty");
		}
		out.close();
	}
	public static boolean happy(int n, int base){
		String s = (new BigInteger(""+n)).toString(base);
		for(int i=0; i<20; i++){
			BigInteger res = BigInteger.ZERO;
			for(int j=0; j<s.length(); j++){
				res = res.add(new BigInteger(""+s.charAt(j), base));
			}
			if(res.compareTo(BigInteger.ONE) == 0)return true;
			res = BigInteger.ZERO;
			for(int j=0; j<s.length(); j++){
				res = res.add((new BigInteger(""+s.charAt(j), base).multiply(new BigInteger(""+s.charAt(j), base))));
			}
			s = res.toString(base);
		}
		return false;
	}
}
