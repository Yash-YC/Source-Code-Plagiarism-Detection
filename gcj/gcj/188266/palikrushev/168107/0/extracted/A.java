import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.*;

public class A {

	static boolean GOOD[][];
	static boolean BAD[][];
	static int bases[];

	public static void main(String[] args) throws Exception {
		File fin = new File("C:\\codejam\\A-small-attempt1.in");
		File fout = new File("C:\\codejam\\A-small-attempt1.out");
		FileReader fr = new FileReader(fin);
		FileWriter fw = new FileWriter(fout);
		BufferedReader br = new BufferedReader(fr);
		BufferedWriter bw = new BufferedWriter(fw);

		String str;
		int n;
		str = br.readLine();
		n = Integer.parseInt(str);
		StringTokenizer st;
		ArrayList<Integer> list;
		boolean can;
		int THENUMBER=-1;

		

		for (int t = 1; t <= n; t++) {
			list = new ArrayList<Integer>();
			st = new StringTokenizer(br.readLine());

			while (st.hasMoreTokens()) {
				list.add(Integer.parseInt(st.nextToken()));
			}

			bases = new int[list.size()];

			for (int i = 0; i < list.size(); i++) {
				bases[i] = list.get(i);
			}

			GOOD = new boolean[bases.length][1000000];
			BAD = new boolean[bases.length][1000000];
			for (int i = 0; i < bases.length; i++) {
				GOOD[i][1]=true;
			}
			//System.out.println(t);

			for (int i = 2; i < 1000000; i++) {
				//System.out.println("  "+i);
				can=true;
				for (int j = 0; j < bases.length; j++) {
					
					//System.out.println(i+" "+bases[j]+"\n");
					
					if(!go(i,j)){
						can=false;
					}
					//System.out.println("\n\n\n");
				}
				if(can){
					THENUMBER = i;
					break;
				}
				
			}

			fw.append("Case #" + t + ": "+THENUMBER+ "\n");
		}

		br.close();
		bw.close();
	}

	public static boolean go(int number, int k) {
		//int start = number;
		int base = bases[k];
		ArrayList<Integer> ar = new ArrayList<Integer>();
		boolean pass[] = new boolean[1000000];
		pass[number]=true;
		String tmp;
		int sum, temp;
		
		while (true) {
			
			
			sum = 0;
			tmp = Integer.toString(number, base);
			for (int i = 0; i < tmp.length(); i++) {
				temp = Integer.parseInt(tmp.substring(i, i + 1));
				
				sum += temp * temp;
			}
			
			//System.out.println(tmp+"  "+sum);
			
			if(GOOD[k][sum]){
				for (int i = 0; i < ar.size(); i++) {
					GOOD[k][ar.get(i)]=true;
				}
				return true;
			}else if(pass[sum]||BAD[k][sum]){
				for (int i = 0; i < ar.size(); i++) {
					BAD[k][ar.get(i)]=true;
				}
				BAD[k][sum]=true;
				return false;
			}else{
				pass[sum]=true;
				ar.add(sum);
			}
			number=sum;
			
			
		}
	}

}
