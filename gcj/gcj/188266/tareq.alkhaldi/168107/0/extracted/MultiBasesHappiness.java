/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.*;
import java.util.*;
/**
 *
 * @author Tareq Alkhaldi
 *  tareq.alkhaldi@gmail.com
 */
public class MultiBasesHappiness {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String line;
        StringTokenizer st;
        int n,k=1;
        int bases[];
        try{
            BufferedReader reader = new BufferedReader(new FileReader("A1-small-attempt0.in"));
            PrintWriter pw = new PrintWriter(new FileOutputStream("happyBases-small.out"));
            n = Integer.parseInt(reader.readLine());
            while(k<=n)
            {
                st = new StringTokenizer(reader.readLine()," ");
                bases = new int[st.countTokens()];
                while(st.countTokens()>0)
                    bases[bases.length-st.countTokens()] = Integer.parseInt(st.nextToken());
                
                int count=2;
                boolean happy;
                while(true)
                {
                  //  boolean temp = isHappy(Integer.parseInt(""+count, bases[0]));
                    happy = true;
                    for(int i=0;i<bases.length;i++)
                    {
                     //   System.out.println("aha "+count+" "+bases[i]+" "+Integer.toString(count, bases[i]));
                        if(!isHappy(Integer.parseInt(Integer.toString(count, bases[i])),bases[i]))
                        {
                            happy = false;
                            break;
                        }
                      //  System.out.println("aha");
                    }
                    if(happy)
                        break;
                    count++;
                }
                System.out.println("Case #"+k+": "+count);
                pw.println("Case #"+k+": "+count);
                k++;
            }
            pw.close();
        }catch(Exception e){System.out.println("hmm "+e);}
    }
    public static boolean isHappy(int x,int base)
    {
        int sum=0;
        ArrayList<Integer> mem = new ArrayList<Integer>();
       // sum+= x%10*x%10;
        
        while(!(sum==1 && x==0))
        {
            sum+= (x%10)*(x%10);
            x/=10;
          //  System.out.println("hmm "+sum);
            if(x==0)
            {
                if(sum==1)
                    return true;
                
                if(mem.contains(sum))
                    return false;
                mem.add(sum);
                x=Integer.parseInt(Integer.toString(sum, base));
                sum=0;
            }            
        }
        return true;
    }

}
