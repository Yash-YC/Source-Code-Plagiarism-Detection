import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;
import java.util.StringTokenizer;


public class C {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		File fin = new File("C:\\codejam\\C-small-attempt3.in");
		File fout = new File("C:\\codejam\\C-small-attempt3.out");
		FileReader fr = new FileReader(fin);
		FileWriter fw = new FileWriter(fout);
		BufferedReader br = new BufferedReader(fr);
		BufferedWriter bw = new BufferedWriter(fw);
		
		String str;
		int n;
		str=br.readLine();
		n = Integer.parseInt(str);
		int C,N;
		double P,Q,sum,last;
		
		StringTokenizer st;
	
		for(int t=1;t<=n;t++){
			st = new StringTokenizer(br.readLine());
			C = Integer.parseInt(st.nextToken());
			N = Integer.parseInt(st.nextToken());
			
			P = (((double)N)/((double)C));
			Q = 1-P;
			sum = 0;
			last = P;
			
			for (int i = 1; i < 1000000; i++) {
				sum+=last*i;
				last*=Q;
			}
			
			DecimalFormat df = new DecimalFormat("0.0000000");
			str = df.format(sum);
			str=str.replace(',', '.');
			
			fw.append("Case #"+t+": "+str+"\n");
			
		}
		
		br.close();
		bw.close();
	}

}
