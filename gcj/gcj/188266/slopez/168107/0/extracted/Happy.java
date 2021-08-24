import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;


public class Happy {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		String line;
		String filename="in.txt"; 
		BufferedReader in = new BufferedReader(new FileReader(filename));
		int numeros[][] = new int[11][100000];
		
		int n = Integer.valueOf(line = in.readLine());
		int resp[] = new int[n];
		for(int t=0;t<n;t++){
			String [] k= in.readLine().split(" ");
			for(int num=2;num<100000;num++){
				boolean flag = true;
				for(int c =0;c<k.length;c++){
					int exp = Integer.valueOf(k[c]);
					if(numeros[exp][num]==0){
						numeros[exp][num] =buscar(num,exp);
					}
					if(numeros[exp][num]==-1){
						flag = false;
						break;
					}
				}
				if(flag){
					resp[t]=num;
					break;
				}
			}
		}
		
		
		BufferedWriter writer = new BufferedWriter(new FileWriter("out.txt"));
		for(int c=0;c<n;c++){
			writer.write("Case #"+String.valueOf((c+1))+": " + resp[c]);
			writer.newLine();
        }
		writer.close();
        in.close();
	}
	
	static int buscar(int num, int exp){
		HashMap<Integer, Integer> resp=  new HashMap<Integer, Integer>();
		while(resp.get(num)==null){
			int sum =0;
			char [] a = Integer.toString(num,exp).toCharArray();
			for(char t:a){
				sum+= Math.pow((t-48),2);
			}
			if(sum==1){
				return 1;
			}
			resp.put(num, sum);
			num = sum;
		}
		return -1;
	}

}
