import java.util.*;
import java.math.BigInteger;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  void eval(int times, int want, int gain) {

    long tot = pasc[want][gain].longValue();

    double table[] = new double[want+1];
    for(int has=want-1; has>=0; --has) {
      long sum = 0;
      for(int come=1; come<=gain; ++come) {
        if( has + come > want ) { break; }
        // contain already
        long already = pasc[has][gain-come].longValue();
        long notyet = pasc[want-has][come].longValue();
        table[has] += (table[has+come] * already * notyet / tot);
        sum += already * notyet;
      }
      table[has] += 1.0;
      table[has] = table[has] / sum * tot;
    }

    System.out.println("Case #" + times + ": " + table[0]);

  }

  BigInteger pasc[][];

  void init() {
    pasc = new BigInteger[41][41];
    for(int i=0; i<=40; ++i) {
      for(int j=0; j<=40; ++j) {
        pasc[i][j] = BigInteger.ZERO;
      }
    }
    for(int i=0; i<=40; ++i) {
      for(int j=0; j<=i; ++j) {
        if( i == j || j == 0 ) { pasc[i][j] = BigInteger.ONE; }
        else {
          pasc[i][j] = pasc[i-1][j].add(pasc[i-1][j-1]);
        }
      }
    }
  }

  void exec() {

    init();

    Scanner cin = new Scanner(System.in);
    int t = cin.nextInt();

    for(int i=0; i<t; ++i) {
      eval(i + 1, cin.nextInt(), cin.nextInt());
    }

  }

}
