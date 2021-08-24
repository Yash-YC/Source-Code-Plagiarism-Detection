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

public class BSmall {
	private static final SimpleDateFormat sdf = new SimpleDateFormat("_yyMMdd_hhmmss");
	
	private static final String outpath = "x:\\gcj\\r1a\\b";
//	private static final String inpath = "x:\\gcj\\b.in";
	private static final String inpath = "x:\\gcj\\r1a\\B-small-attempt4.in";
//	private static final String inpath = "x:\\gcj\\B-large-attempt0.in";
	
//	private static String input = "1 1 3 2 10";
	private static String input = "1 2 1 5 3 1 5 2";
	private static int mode = 1; // 0:test, 1:single thread
	
	public String call() throws Exception
	{
		int[][] s, w, t;
		int n = sc.nextInt();
		int m = sc.nextInt();
		s = new int[n][m];
		w = new int[n][m];
		t = new int[n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				s[n - 1 - i][j] = sc.nextInt();
				w[n - 1 - i][j] = sc.nextInt();
				t[n - 1 - i][j] = sc.nextInt();
			}
		}
		
		int[][] ds = new int[n * 2][m * 2];
		
		while(true){
			int minr = Integer.MAX_VALUE;
			int mingr = -1;
			int mingc = -1;
			for(int fr = 0;fr < n * 2;fr++){
				for(int fc = 0;fc < m * 2;fc++){
					if(ds[fr][fc] > 0 || (fr == 0 && fc == 0)){
						if(fr < n * 2 - 1 && ds[fr + 1][fc] == 0){
							if(fr % 2 == 1){
								int v = ds[fr][fc] + 2;
								if(v < minr){
									minr = v;
									mingr = fr + 1;
									mingc = fc;
								}
							}else{
								int fr2 = fr / 2;
								int fc2 = fc / 2;
								int tt = (ds[fr][fc] - t[fr2][fc2]) % (s[fr2][fc2] + w[fr2][fc2]);
								if(tt < 0)tt += s[fr2][fc2] + w[fr2][fc2];
								
								int uu = tt < s[fr2][fc2] ? 0 : (s[fr2][fc2] + w[fr2][fc2] - tt); // n-s
								int v = ds[fr][fc] + uu + 1;
								if(v < minr){
									minr = v;
									mingr = fr + 1;
									mingc = fc;
								}
							}
						}
						if(fc < m * 2 - 1 && ds[fr][fc + 1] == 0){
							if(fc % 2 == 1){
								int v = ds[fr][fc] + 2;
								if(v < minr){
									minr = v;
									mingr = fr;
									mingc = fc + 1;
								}
							}else{
								int fr2 = fr / 2;
								int fc2 = fc / 2;
								int tt = (ds[fr][fc] - t[fr2][fc2]) % (s[fr2][fc2] + w[fr2][fc2]);
								if(tt < 0)tt += s[fr2][fc2] + w[fr2][fc2];
								
								int uu = tt >= s[fr2][fc2] ? 0 : (s[fr2][fc2] - tt); // w-e
								int v = ds[fr][fc] + uu + 1;
//								p(tt + "\t" + uu + "\t" + v);
								if(v < minr){
									minr = v;
									mingr = fr;
									mingc = fc + 1;
								}
							}
						}
					}
				}
			}
			if(mingr == -1)break;
			
			ds[mingr][mingc] = minr;
			if(mingr == 2 * n - 1 && mingc == 2 * m - 1)break;
		}
		
//		pa(ds);
		return String.format("%d", ds[2 * n - 1][2 * m - 1]);
	}

	private Scanner sc;
	
	public BSmall(Scanner sc) throws IOException
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
				String result = new BSmall(sc).call();
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
			System.out.println(new BSmall(sc).call());
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
