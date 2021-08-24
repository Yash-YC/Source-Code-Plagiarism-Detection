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
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class ASmall {
	private static final SimpleDateFormat sdf = new SimpleDateFormat("_yyMMdd_hhmmss");
	
	private static final String outpath = "x:\\gcj\\r1a\\a";
//	private static final String inpath = "x:\\gcj\\r1a\\a.in";
	private static final String inpath = "x:\\gcj\\r1a\\A-small-attempt0.in";
//	private static final String inpath = "x:\\gcj\\A-large-attempt0.in";
	
	private static String input = "40 41 42";
	private static int mode = 1; // 0:test, 1:single thread
	
	public String call() throws Exception
	{
		String line = sc.nextLine();
		String[] sp = line.split(" ");
		int[] a = new int[sp.length];
		for(int i = 0;i < sp.length;i++){
			a[i] = Integer.parseInt(sp[i]);
		}
		pa(a);
		
		int x;
		for(x = 3;;x++){
//			p(x);
			boolean flag = true;
			for(int v : a){
				if(!fh(x, v)){
					flag = false;
					break;
				}
			}
			if(flag){
				break;
			}
		}
		
		return String.format("%d", x);
	}
	
	Set<Integer> his;
	
	private boolean fh(int x, int d)
	{
		his = new HashSet<Integer>();
		while(true){
			if(x == 1)return true;
			int ret = 0;
			for(;x > 0;x /= d)ret += (x % d) * (x % d);
			if(his.contains(ret))return false;
			his.add(ret);
			x = ret;
		}
	}
	
	private Scanner sc;
	
	public ASmall(Scanner sc) throws IOException
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
				String result = new ASmall(sc).call();
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
			System.out.println(new ASmall(sc).call());
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
