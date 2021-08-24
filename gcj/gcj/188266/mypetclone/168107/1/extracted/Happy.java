import java.util.*;
import java.io.*;
public class Happy {
  public static void main(String[] args) {
    Scanner in;
    PrintWriter out;
    try {
      in = new Scanner(new File(args[0]));
      out = new PrintWriter(new FileWriter(new File(args[1])));
    } catch (IOException e) {
      System.err.println("Fail.");
      System.exit(-1);
      return;
    }

    int t = in.nextInt();
    in.nextLine();
    HashMap results = new HashMap();
    for(int i=0;i<t;i++) {
      Scanner line = new Scanner(in.nextLine());
      Set<Integer> nums = new HashSet<Integer>();
      while(line.hasNextInt()) {
        nums.add(line.nextInt());
      }
      int n=1;
      while(!satisfactory(++n, nums));
      out.println("Case #" + (i+1) + ": " + n);
    }
    out.close();
  }

  public static boolean satisfactory(int n, Set<Integer> bases) {
    for(int base : bases) {
      if(!happy(n, base)) return false;
    }
    return true;
  }

  public static int[] digits(int number, int radix) {
    String s = Integer.toString(number, radix);
    int[] nums = new int[s.length()];
    for(int i=0;i<s.length();i++) {
      nums[i] = s.charAt(i)-'0';
    }
    return nums;
  }

  public static int sumSquares(int[] list) {
    int sum = 0;
    for(int i:list) {
      sum += i*i;
    }
    return sum;
  }

  public static boolean happy(int number, int base) {
    int[] digits = digits(number, base);
    int sumSquares = sumSquares(digits);
    Set<Integer> encountered = new HashSet<Integer>();
    while(!encountered.contains(sumSquares)) {
      if(sumSquares==1) return true;
      encountered.add(sumSquares);
      digits = digits(sumSquares,base);
      sumSquares = sumSquares(digits);
    }
    return false;
  }
}
