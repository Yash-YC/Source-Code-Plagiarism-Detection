import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  void eval(int times, int want, int gain) {

    int max = 1 << want;
    double table[] = new double[max];
    for(int state=max-2; state>=0; --state) {
      int count = 0;
      int me = 0;
      for(int i=0; i<max; ++i) {
        if( Integer.bitCount(i) != gain ) { continue; }
        ++count;
        if( (state | i) == state ) {
          ++me;
          continue;
        }
        table[state] += table[(state | i)];
      }
      table[state] = (table[state] / count + 1) / (count - me) * count;
    }

    System.out.println("Case #" + times + ": " + table[0]);

  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int t = cin.nextInt();

    for(int i=0; i<t; ++i) {
      eval(i + 1, cin.nextInt(), cin.nextInt());
    }

  }

}
