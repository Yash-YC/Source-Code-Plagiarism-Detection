import java.util.*;
import java.io.File;
class A
{
  static void pr(String s)
  {
    System.out.println(s);
  }
  static void pr1(String s)
  {
    System.out.print(s + "  ");
  }
  static String squareSum(String num, String base)
  {
    int b = new Integer(base);
    int sum = 0;
    for(int i=0; i<num.length(); i++)
    {
      int digit = new Integer("" + num.charAt(i));
      sum += (digit * digit);
    }
    return(Integer.toString(sum, b));
  }
  static boolean isHappy(long test, String base)
  {
    int b = new Integer(base);
    String tb = Long.toString(test, b);
    HashSet<String> set1 = new HashSet<String>();
    while(true)
    {
      tb = squareSum(tb, base);
      if(tb.equals("1"))
        return true;
      if(set1.contains(tb))
        return false;
      set1.add(tb);
    }
    //return false;
  }
  public static void main(String args[])
  {
    Scanner sc = null;
    File f1 = null;
    if(args.length == 0)
    {
      pr("Input file name not given.");
      System.exit(0);
    }
    try
    {
      f1 = new File(args[0]);
      sc = new Scanner(f1);
    }
    catch(Exception e)
    { 
      pr("Problem with input file opening.");
      System.exit(0);
    }
    int T = sc.nextInt();
    sc.nextLine();

    for(int i=0; i<T; i++)
    {
      String temp = sc.nextLine();
      String tokens[] = temp.split(" ");
      long test = 2;
      boolean isHappyInAll;
      while(true)
      {
        isHappyInAll = true;
        for(int j=0; j<tokens.length; ++j)
        {
          isHappyInAll = isHappy(test, tokens[j]);
          if(!isHappyInAll)
	    break;
        }
	if(isHappyInAll)
	  break;
	test++;
      }
      pr("Case #" + (i+1) + ": " + test);
    }
  }
}

