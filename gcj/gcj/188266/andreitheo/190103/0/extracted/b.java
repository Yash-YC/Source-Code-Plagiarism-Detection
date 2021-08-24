import java.io.*;
import java.util.*;
import java.text.DecimalFormat;
public class b{
    String prDouble(double x)
	{
		DecimalFormat df = new DecimalFormat("0.0000000000");
		String rs = df.format(x);
		rs=rs.charAt(0)+"."+rs.substring(2);
        rs = rs.replaceAll(",","");
		return rs;
	}
	b(){
		try{
			File f = new File("C-small-attempt1.in");
			BufferedReader input =  new BufferedReader(new FileReader(f));
			BufferedWriter out = new BufferedWriter(new FileWriter("small.out"));
			int nrtests = Integer.parseInt(input.readLine());
            //nrtests = 1;
			for(int nrt=0;nrt<nrtests;nrt++){
				String[]spl=input.readLine().split(" ");
                int c = Integer.parseInt(spl[0]);
                int n = Integer.parseInt(spl[1]);
                double[] expe = new double[c+1];
                //expe[n] = 1;
                Arrays.fill(expe,0);
                double total = 0;
                for(int conf=0; conf<1<<c; conf++)
                    if( Integer.bitCount(conf)==n ) total++;
                int steps = 100;
             
                double[][] proba = new double[steps][c+1];
                for(int i=0; i<steps; i++)
                    Arrays.fill(proba[i],0);
                Arrays.fill(proba[1],0);
                proba[1][n] = 1;
                double rez = 0;
                for(int st=1; st<steps-1; st++){
                    //System.out.println(proba[st][0]+" "+proba[st][1]);
                    //System.out.println(rez);
                    for(int i=0; i<=c; i++){
                        for(int conf=0; conf<1<<c; conf++)
                            if( Integer.bitCount(conf)==n ){
                                int j = Integer.bitCount(conf&(1<<(c-i)-1));
                                //System.out.println(i+" "+j+" "+n+" "+c+" "+1/total);
                                if( i+j==c && j==0 ) continue;
                                if( i+j<=c ){
                                        proba[st+1][i+j] += (proba[st][i])/(double)total;
                                        if( i+j==c )
                                            if( j!=0 ){
                                                rez = rez + proba[st][i]/total*(st+1);
                                                if( proba[st][i]/total*(st+1)<0 )
                                                    System.out.println("sfjskfjdl "+st+" "+i);
                                                //System.out.println("add "+i+" "+j+" "+(st+1)+" "+proba[st][i]/total);
                                                }
                                    }
                            }
                    }
                }
                if( c==n ) rez = 1;
                System.out.println(rez);
				out.write("Case #"+(nrt+1)+": "+rez+"\n");
			}
			out.close();
		}catch(IOException e){}
	}
	public static void main(String[]args){
		new b();
	}

}
