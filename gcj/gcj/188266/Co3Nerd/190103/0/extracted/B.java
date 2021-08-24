import java.text.*;
import java.util.*;
import java.io.*;
public class B 
{
    public static void main(String[] args) throws IOException
    {
        PrintWriter out= new PrintWriter(new BufferedWriter(new FileWriter("B-small.out")));
        Scanner s=new Scanner(new File("C-small-attempt4.in"));
        int sets=s.nextInt();
        s.nextLine();
        for(int yyy=1;yyy<=sets;yyy++)
        {
        	int n=s.nextInt();
        	int c=s.nextInt();
        	int p5=0;
        	double p=0;
        	int ex=0;
        	ArrayList<Double> percents=new ArrayList<Double>();
        	while(p5<Integer.MAX_VALUE-1)
        	{
        		//System.out.println("1:"+c+":"+p5);
        		double acum=1;
        		for(int cc=0;cc<c;cc++)
        		{
        			acum*=(double)(n-1.0-cc)/(n-cc);
        			//System.out.println("2:"+acum);
        		}
        		acum=Math.pow(acum,ex);
        		acum=1-acum;
        		p=Math.pow(acum,n-c);
        		p5=(int)Math.round(p*((double)Integer.MAX_VALUE-1));
        		percents.add(p);
        		ex++;
        	}
        	double totalPercent=0;
        	double weightedPercent=0;
        	for(int h=1;h<=percents.size();h++)
        	{
        		double work=1-percents.get(h-1);
        		totalPercent+=work;
        		weightedPercent+=h*work;
        	}
        	double outp=weightedPercent/totalPercent+1;
        	if(c>=n)
        	{
        		outp=1;
        	}
        	DecimalFormat f=new DecimalFormat("0.0000000");
        	String outing="Case #"+yyy+": "+f.format(outp)+"\n";
        	out.write(outing,0,outing.length());
        }
        out.close();
    }
}
