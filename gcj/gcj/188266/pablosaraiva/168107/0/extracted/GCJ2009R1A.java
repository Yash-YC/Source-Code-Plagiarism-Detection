import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;


public class GCJ2009R1A {

	/**
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("/Users/pablosaraiva/Downloads/A-small-attempt0.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("/Users/pablosaraiva/Downloads/A-small-attempt0.out"));
		String linha;
		long K;
		boolean allHappy;
		int base;
		br.readLine();
		int caseNum = 0;
		
		while ((linha = br.readLine())!= null) {
			caseNum++;
			K = 2;
			allHappy = false;
			while (!allHappy) {
				allHappy = true;
				for (String str: linha.split(" ")) {
					base = Integer.parseInt(str);
					allHappy = allHappy && happy(K,base);
				}
				K++;
			}
			K--;
			bw.write("Case #" + caseNum + ": " + K + "\n");
		}
		
		br.close();
		bw.close();
	}
	
	
	public static boolean happy(long K, int base) {
		ArrayList<String> digits = new ArrayList<String>();
		ArrayList<String> ocorrencias = new ArrayList<String>();
		long rem = K;
		long iDigit;
		String sDigit;
		String sRem ;
		sRem = Long.toString(rem);
		while (rem != 1) {
			digits.clear();
			
			while (rem != 0) {
				iDigit = rem % base;
				sDigit = Long.toString(iDigit);
				digits.add(sDigit);
				rem = (rem - iDigit) / base;
			}
			
			for (String str: digits) {
				rem = rem + (Integer.parseInt(str) * Integer.parseInt(str));
			}
			
			sRem = Long.toString(rem);
			for (String str: ocorrencias) {
				if (str.equals(sRem)) {
					return(false);
				}
			}
			ocorrencias.add(sRem);
		}
		return true;
	}

}
