import java.text.*;
import java.util.*;
import java.io.*;
public class A 
{
    public static void main(String[] args) throws IOException
    {
        PrintWriter out= new PrintWriter(new BufferedWriter(new FileWriter("A-small.out")));
        Scanner s=new Scanner(new File("A-small-attempt0.in"));
        int sets=s.nextInt();
        s.nextLine();
        for(int yyy=1;yyy<=sets;yyy++)
        {
        	Scanner sc=new Scanner(s.nextLine());
        	ArrayList<Integer> bases=new ArrayList<Integer>();
        	while(sc.hasNextInt())
        	{
        		bases.add(sc.nextInt());
        	}
        	Collections.sort(bases);
        	int[]lowHappy=new int[11];
        	int highHap=2;
        	boolean done=false;
        	while(!done)
        	{
        		done=true;
        		for(int t=bases.size()-1;t>=0&&done;t--)
        		{
        			int tester=bases.get(t);
        			if(lowHappy[tester]!=highHap)
        			{
        				while(lowHappy[tester]<highHap)
        				{
        					lowHappy[tester]=findNextHappy(highHap,tester);
        				}
        					
        				if(lowHappy[tester]>highHap)
        				{
        					done=false;
        					highHap=lowHappy[tester];
        				}
        				
        			}
        		}
        	}
        	String outing="Case #"+yyy+": "+highHap+"\n";
        	out.write(outing,0,outing.length());
        }
        out.close();
    }
    public static int findNextHappy(int start, int base)
    {
    	int y=start;
    	while(!isHap(y,base))
		{
			y++;
		}
		return y;
    }
    public static boolean isHap(int test,int base)
    {
    	int j=test;
		TreeSet<Integer>done=new TreeSet<Integer>();
		while(j>1&&done.add(j))
		{
			int work=0;
			while(j>0)
			{
				String kk=Integer.toString(j,base);
				work+=Math.pow(kk.charAt(kk.length()-1)-48,2);
				j/=base;
			}
			j=work;
		}
		return j==1;
	}
}
