import java.io.*;
import java.util.*;
 
public class One
{    
    public static void main(String[] args)
    {
        // IO variables
        File file = new File("A-small-attempt0.in");
        FileInputStream fis = null;
        BufferedInputStream bis = null;
        DataInputStream dis = null;
        
        try
        {
            fis = new FileInputStream(file);
            bis = new BufferedInputStream(fis);
            dis = new DataInputStream(bis);
            
            int cases = Integer.parseInt( dis.readLine() );
            
            for(int i = 0; i < cases; i++)
            {
                String input = dis.readLine();
                
                // Getting input
                StringTokenizer st = new StringTokenizer(input);
                int bases[] = new int[10];
                int numBases = 0;
                while( st.hasMoreTokens() )
                {
                    bases[numBases] = Integer.parseInt( st.nextToken() );
                    numBases++;
                }
                
                // Do it
                
                boolean found = false;
                int testNum = 2;
                while(!found)
                {
                    boolean testIsHappy = false;
                    for(int j = 0; j < numBases; j++)
                    {
                        boolean res = isHappy(testNum, bases[j]);
                        
                        if(!res)
                        {
                            break;
                        }
                        else if(res && j == numBases-1)
                        {
                            found = true;
                        }
                    }
                    testNum++;
                }
                
                System.out.println("Case #" + (i+1) + ": " + (testNum-1));
            }
            //System.out.println( )
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }
    
    public static boolean isHappy(int testNum, int base)
    {
        Vector v = new Vector();
        String asString;
        
        while(true)
        {
            asString = Integer.toString(testNum, base);
            v.add(asString);
            
            testNum = 0;
            
            for(int k = 0; k < asString.length(); k++)
            {
                testNum = testNum + (Integer.parseInt(""+asString.charAt(k)) * Integer.parseInt(""+asString.charAt(k)));
            }
                        
            if( testNum == 1 )
            {
                return true;
            }
            else if(v.contains("" + Integer.toString(testNum, base)))
            {
                return false;
            }
            //System.out.println(testNum);
        }
    }
}