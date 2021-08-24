import java.awt.*;
import java.io.*;
import java.util.*;

public class TheLastWord
{
  public static void main (String[]args)
  {
    try
    {
      BufferedReader in= new BufferedReader(new FileReader("A-small-attempt0.in"));
      PrintWriter out=new PrintWriter(new FileWriter("output.txt"));
      int testCases=Integer.parseInt(in.readLine());
      for (int z=1;z<=testCases;z++){
        String word=in.readLine();
        int [] value=new int [word.length()];
        String answer=word.charAt(0)+"";
        for (int x=1;x<word.length();x++){
          char curr=word.charAt(x);
          if ((int)curr<(int)answer.charAt(0))
            answer+=curr;
          else
            answer=curr+answer;
        }
        out.println("Case #"+z+": "+answer);
     }
      out.close();
    }
    catch (IOException e){}
  }
}