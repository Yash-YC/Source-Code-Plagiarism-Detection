/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package a;

/**
 * Created By: Sami Ghawi
 *
 */
import java.io.*;
import java.text.NumberFormat;
import java.util.*;
public class Main {

    private static int numberOfCases;
    public static String output [];

	private static String [] readInput (String fileName)
	{
                String openFileName=fileName;
		File file = new File (openFileName);
		String lines []= new String [1];
		try
		{

			BufferedReader reader = new BufferedReader (new FileReader (file));
			if (file.exists()==true)
			{
				String temp= new String();
				String tLines[]=new String[1];
				temp=reader.readLine();
				for(int i=0;temp!=null ; i++)
				{
					lines[i]=temp;
					System.arraycopy(lines, 0, tLines, 0, lines.length);
					lines= new String [i+2];
					System.arraycopy(tLines, 0, lines, 0, tLines.length);
					tLines= new String [i+2];
					temp=reader.readLine();
				}

				System.arraycopy(lines, 0, tLines, 0, lines.length);
				lines= new String [tLines.length-1];
				System.arraycopy(tLines, 0, lines, 0, lines.length);
			}
		}
		catch (FileNotFoundException ex)
		{
			System.out.println("File not found");
		}
		catch (IOException ex)
		{
			System.out.println("Error reading data");

                }
                return lines;
	}

    private static void token(String [] data)
    {
        StringTokenizer token;
        numberOfCases= Integer.parseInt(data[0]);
        output=new String[numberOfCases];
        int inCount=0;

        
        int s,q;
        String engine [];
        String query [];
        for (int i=1;i<data.length;i++)
        {
            


            output[inCount]=problem(data[i]);
            inCount++;
        }
    }


   ArrayList<Integer> array=new ArrayList();
    public static String problem(String data)
    {
        ArrayList<Integer> array=new ArrayList();

        StringTokenizer token=new StringTokenizer(data);
        while(token.hasMoreElements()==true)
            array.add(Integer.parseInt(token.nextToken()));
        int i=0;
        boolean ok=true;
        for ( i=2;;i++)
        {
            
            ok=true;
            for (int j=0;j<array.size();j++)
            {
                int t=array.remove(0);
                array.add(t);
                int ii=decimalToBase(i,t);
                while (true)
                {
                        if (ok==false) break;
                        if (ii==1){ok=true; break;}
                        if (t==2)
                        {ok=true; break;}
                        if (t==3 && (ii==12 || ii==22 || ii==2))
                           {ok=false; break;}
                        if (t==4) {ok=true; break;}
                        if (t==5 && (ii==4 || ii==23 || ii==33 || ii==31 || ii==20))
                            {ok=false; break;}
                        if (t==6 && ii==32) {ok=false; break;}
                        if (t==7 &&(ii==2 || ii==34 || ii==13 || ii==23 || ii==63 || ii==44))
                            {ok=false; break;}
                        if (t==8 && (ii==4 || ii==5 || ii==32 || ii==24 ||ii==64))
                            {ok=false; break;}
                        if (t==9 && (ii==55 || ii==58 || ii==45 || ii==75))
                           {ok=false; break;}

                        if (t==10 && (ii==1 || ii==7 || ii==10))
                            {ok=true; break;}
                        if (t==10 && (ii<10))
                            {ok=false; break;}

                        
                       String x= Integer.toString(ii);
                       int sum=0;
                       for (int k=0;k<x.length();k++)
                       {
                           int temp=x.charAt(k)-'0';
                           temp=temp*temp;
                           sum+=temp;
                       }
                       ii=decimalToBase(sum,t);
                }

            }
            if (ok==true)
                break;
        }

        return Integer.toString(i);
        

    }

    public static boolean isHappy(int i,int j)
    {
        
        if (j==2)
            return true;
        if (j==3 && (i==12 || i==22 || i==2))
            return false;
        if (j==4) return true;
        if (j==5 && (i==4 || i==23 || i==33))
            return false;
        if (j==6 && i==32) return false;
        if (j==7 &&(i==2 || i==34 || i==13 || i==23 || i==63 || i==44))
            return false;
        if (j==8 && (i==4 || i==5 || i==32 || i==24 ||i==64))
            return false;
        if (j==9 && (i==55 || i==58 || i==45 || i==75))
            return false;

        if (j==10 && (i==1 || i==7 || i==10))
            return true;
        if (j==10 && (i<10))
            return false;
        
       String x= Integer.toString(i);
       int sum=0;
       for (int k=0;k<x.length();k++)
       {
           int temp=x.charAt(k)-'0';
           temp=temp*temp;
           sum+=temp;
       }
       return isHappy(decimalToBase(sum,j),j);


    }
    public static int decimalToBase(int dec, int b)
{
	int result=0;
	int multiplier=1;
	int tempDec=dec;
	while (tempDec>0)
	{
		result+=(tempDec%b)*multiplier;
		multiplier*=10;
		tempDec/=b;
	}
	return result;
}




        public static void writeOutput(String data[],String fileName)
        {
            try
            {
            File file = new File (fileName);
            writeFile(data,file);
            }
            catch (Exception e)
            {
                System.out.println("Error writing file");
            }
         }
    	public static void writeFile(String data[],File file) throws FileNotFoundException{

		FileOutputStream out = new FileOutputStream(file);
		// Declare a print stream object
		PrintStream p;
		p = new PrintStream( out );

		try
                {
            for (int i=0;i<data.length;i++)
                p.println("Case #"+(i+1)+": "+data[i]);
		}
		catch (Exception e){
			System.err.println ("Error writing to file");
			}
		finally
		{
			p.close();
		}

	}


        public static void main(String[] args)
        {
            token(readInput("A-small-attempt1.in"));
            writeOutput(output,"output.txt");

        }

}
