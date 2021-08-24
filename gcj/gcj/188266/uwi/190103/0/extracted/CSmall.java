package gcj.r1a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;
import java.util.Formatter;
import java.util.Scanner;

public class CSmall {
	private static final SimpleDateFormat sdf = new SimpleDateFormat("_yyMMdd_hhmmss");
	
	private static final String outpath = "x:\\gcj\\r1a\\c";
//	private static final String inpath = "x:\\gcj\\r1a\\c.in";
	private static final String inpath = "x:\\gcj\\r1a\\C-small-attempt0.in";
//	private static final String inpath = "x:\\gcj\\C-large-attempt0.in";
	
	private static String input = "10 3";
	private static int mode = 1; // 0:test, 1:single thread
	
	int c, n;
	long cb;
	
	public String call() throws Exception
	{
		c = sc.nextInt();
		n = sc.nextInt();
		
		cb = comb(c, n);
		
		p(rec(c));
		return String.format("%1.7f", rec(c) - 1);
	}
	
	private long comb(int n, int k)
	{
		long ret = 1L;
		for(int i = 1;i <= k;i++){
			ret *= (n - i + 1);
			ret /= i;
		}
		return ret;
	}
	
	private double rec(int l)
	{
		if(l == 0)return 1.0;
		
		double p0 = (double)comb(c - l, n) / (double)cb;
		
		double sum = 0;
		for(int i = 1;i <= Math.min(l, n);i++){
			if(c - l < n - i)continue;
//			p(l + "\t" + i);
			sum += (double)comb(l, i) * (double)comb(c - l, n - i) / (double)cb * rec(l - i);
		}
		return (sum + 1.0) / (1.0 - p0);
	}
	
	private Scanner sc;
	
	public CSmall(Scanner sc) throws IOException
	{
		this.sc = sc;
	}
	
	public static void main(String[] args) throws Exception
	{
		long start = System.currentTimeMillis();
		if(mode > 0){
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(inpath)));
			Scanner sc = new Scanner(br);
			int n = Integer.parseInt(br.readLine());
			
			Formatter fmt = new Formatter();
			for(int i = 0;i < n;i++){
				String result = new CSmall(sc).call();
				fmt.format("Case #%d: %s\n", i + 1, result);
				System.out.println("case " + (i + 1) + " solved.\t" + result);
			}
			System.out.println(fmt.toString());
			
			BufferedWriter bw = null;
			try {
				String f = outpath + sdf.format(new Date()) + ".txt";
				bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(f)));
				bw.write(fmt.toString());
				System.out.println("out " + f);
			}catch(Exception e){
			}finally{
				if(bw != null)bw.close();
			}
			
		}else{
			Scanner sc = new Scanner(input);
			System.out.println(new CSmall(sc).call());
		}
		long end = System.currentTimeMillis();
		System.out.println((end - start) + "ms");
	}
	
	private static void p(Object o) { System.out.println(o); }
	
	private void pa(int[] a)
	{
		System.out.println(Arrays.toString(a));
	}
	
	private void pa(int[][] a)
	{
		for(int[] e : a){
			System.out.println(Arrays.toString(e));
		}
	}
	
}
