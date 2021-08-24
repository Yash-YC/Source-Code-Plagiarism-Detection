import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.Scanner;


public class Round1C_09
{
	public void process(String srcfile, String targetfile)
	{
		try{
//			ArrayList<String> language=new ArrayList<String>();
			BufferedReader reader=new BufferedReader(new 
					InputStreamReader(new FileInputStream(srcfile), "utf-8"));
			BufferedWriter out = new BufferedWriter(new FileWriter(targetfile));
			
			Scanner sc = new Scanner(reader);
			String line=sc.nextLine();;
			int T = Integer.parseInt(line); //number of testcases
			for(int i=0; i<T; i++)
			{
				int C=sc.nextInt();
				int N=sc.nextInt();
				double p=1-(double)N/C;
				
				int n=C/N;
				if(C%N>0)
					n=n+1;
				
				double r=n*Math.pow(p, n-1)+(1-n)*Math.pow(p, n);
				r=r*C*C/N;
				out.write("Case #"+(i+1)+": "+r+"\r\n");
			}
			out.close();
			reader.close();
			
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	public static void main(String[]args)
	{
		String indir="I:\\dataSet\\gcj\\";
		new Round1C_09().process(indir+"C-small-attempt0.in", indir+"result.in");
	}
}
