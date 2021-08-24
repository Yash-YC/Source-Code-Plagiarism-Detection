import java.util.*;
import java.math.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  long cache[];
  ArrayList lists[];

  void init() {
    for(long i=2; i<100000L; ++i) { eval(i); }
  }

  long sqsum(String s) {
    long ret = 0;
    for(int i=0; i<s.length(); ++i) {
      int dig = s.charAt(i) - '0';
      ret += dig * dig;
    }
    return ret;
  }

  void eval(long cur) {
    for(int b=2; b<=10; ++b) {
      long prev = cur;
      HashSet<Long> hist = new HashSet<Long>();
      while( true ) {
        hist.add(prev);
        String bexp = (new BigInteger("" + prev)).toString(b);
        long next = sqsum(bexp);
        if( next == 1 ) {
          lists[b].add(cur);
          break;
        }
        if( next <= cur ) {
          if( lists[b].contains(next) ) { lists[b].add(cur); }
          break;
        }
        if( hist.contains(next) ) { break; }
        prev = next;
      }
    }
  }

  ArrayList<Long> union(ArrayList<Long> a, ArrayList<Long> b) {
    ArrayList<Long> u = new ArrayList<Long>();
    int p = 0;
    int q = 0;
    while( p < a.size() && q < b.size() ) {
      long x = a.get(p);
      long y = b.get(q);
      if( x == y ) { u.add(x); ++p; ++q; }
      if( x < y ) { ++p; }
      if( x > y ) { ++q; }
    }
    return u;
  }

  void exec() {

    cache = new long[1 << 11];
    lists = new ArrayList[11];
    for(int i=2; i<=10; ++i) { lists[i] = new ArrayList<Long>(); }
    init();

    Scanner cin = new Scanner(System.in);

    int t = Integer.parseInt(cin.nextLine());
    for(int i=0; i<t; ++i) {
      String tmp[] = cin.nextLine().split(" ");
      ArrayList<Long> all = null;
      for(String s : tmp) {
        if( s.equals("") ) { continue; }
        if(all == null) { all = lists[Integer.parseInt(s)]; }
        else { all = union(all, lists[Integer.parseInt(s)]); }
      }
      System.out.println("Case #" + (i + 1) + ": " + all.get(0));
    }

  }

}
