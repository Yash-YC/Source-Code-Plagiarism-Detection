import java.io.*;
import java.text.DecimalFormat;
import java.util.*;
public class a
{
	double[][]prob;
	void pr(int[]v)
	{
		for(int i=0; i<v.length; i++) System.err.print(v[i]+" ");
		System.err.println();
	}
	void pr(String x){ System.err.println(x); }
	void pr(int x){ System.err.println(x); }
	void pr(double x){ System.err.println(x); }
	void pr(long x){ System.err.println(x); }
	String prDouble(double x)
	{
		DecimalFormat df = new DecimalFormat("0.0000000000");
		String rs = df.format(x);
		rs=rs.charAt(0)+"."+rs.substring(2);
		return rs;
	}
    int limit = 1000000;
    int[][] hap = new int[limit][11];
    int limic = 1000;
    boolean[] viz = new boolean[limic];
    boolean happy(int x, int base)
    {
        //System.out.println(x+" "+base);
        if( x<limit )
            if( hap[x][base]!=-1)
                return hap[x][base] == 1;
        if( x==1 ) return true;
        if( x<limic ){
                if( viz[x] ) return false;
                viz[x] = true;
            }
        int sum = 0;
        while( x!=0 ){
            sum += (x%base)*(x%base);
            x/=base;
        }
        boolean aux = happy(sum,base);
        hap[x][base] = aux?1:0;
        return aux;
    }
	a(){
        for(int i=0; i<hap.length; i++)
                    Arrays.fill( hap[i] , -1);
        Arrays.fill(viz,false);
        //System.out.println(happy(3,3));
        try{
			File f = new File("A-small-attempt0.in");
			BufferedReader input =  new BufferedReader(new FileReader(f));
			BufferedWriter out = new BufferedWriter(new FileWriter("small.out"));
			int nrtests = Integer.parseInt(input.readLine());
			for(int nrt=0;nrt<nrtests;nrt++){
                String[]spl=input.readLine().split(" ");
                int n = spl.length;
                int[] bases = new int[n];
                for(int i=0; i<n; i++)
                    bases[i] = Integer.parseInt(spl[i]);
                boolean found = false;
                int rez = 1;
                while( !found ){
                    rez++;
                    found = true; 
                    for(int i=0; i<n; i++){
                        Arrays.fill(viz,false);
                        if( !happy(rez,bases[i]) )
                            found = false;
                        }
                    
                }
				out.write("Case #"+(nrt+1)+": "+rez+"\n");
			}
			out.close();
		}catch(IOException e){}
	}
	public static void main(String[]args){
		new a();
	}

}