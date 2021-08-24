/**
 * @(#)Text1.java
 *
 *
 * @author 
 * @version 1.00 2009/9/12
 */

import java.io.*;
public class HappyNumbers {

    public static void main(String args[]) throws IOException
    {
    	BufferedReader scan=null;
    	PrintWriter writer=null;	
    	try
    	{
    		scan=new BufferedReader(new InputStreamReader(new FileInputStream("c:/cases/A-small-attempt0.in")));
    		writer=new PrintWriter(new File("c:/cases/mySmallA.txt"));	
    		int tc=Integer.parseInt(scan.readLine().trim());
    		
    		for(int i=1;i<=tc;i++)
    		{
    			String bases[]=scan.readLine().trim().split(" ");    			
    			boolean hn=true;
    			int no=2;
    			while(true)
    			{ 
    			hn=true;	   			
    			for(int j=0;j<bases.length;j++)
    			{
    				if(!isNumberHappy(no,Integer.parseInt(bases[j])))
    				{
    					hn=false;	
    					break;	
    				}     				    					  				
    			} 
    			if(hn)
    			{
    				writer.println("Case #"+i+": "+no);
    				break;
    			}
    			else
    				no=no+1;	   		
    			}
    			writer.flush();
    		}    		
    			
    	}
    	catch(IOException io)
    	{
    		if(scan!=null)
    			scan.close();
    		if(writer!=null)
    			writer.close();	
    		io.printStackTrace();
    	}
    }    
    public static int compuetSquareSum(int no,int base)
    {
    	int newno = 0,m;
		while(no!=0)
		{
			m = no % base;   
			no = no / base;
			newno += m*m;
		}
		return newno;
    }	
    
    public static boolean isNumberHappy(int no,int base)
    {
    	int temp=no,iter=10;
    	boolean repeat=false;
    	while(true)
    	{
    		temp=no;
    		for(int x=iter;x>0;x--)
    			if((no=compuetSquareSum(no,base))==temp)
    			{
    				break;
    			}
    		if(no==temp)break;	    		
    		iter+=10;			    		
    	}
    	return no == 1 ? true : false;
    }
}