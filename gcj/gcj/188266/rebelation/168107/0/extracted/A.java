import java.util.*;
import static java.lang.Math.*;

public class A{
  public static void main(String[] args){
    new A().run();
  }
  void run(){
    Scanner sc = new Scanner(System.in);
    int T = Integer.parseInt(sc.nextLine());
    for(int o = 1; o <= T; o++){
      String line = sc.nextLine();
      String[] ls = line.split(" ");
      int n = ls.length;
      int[] base = new int[n];
      for(int i = 0; i < n; i++)base[i] = Integer.parseInt(ls[i]);
      int[][] memo = new int[n][500000];
      int a = 2;
      for(;;a++){
        int j;
        for(j = n-1; j >= 0; j--)if(!happy(base[j], memo[j], a))break;
        if(j < 0)break;
      }
      System.out.printf("Case #%d: %d\n", o, a);
    }
  }
  
  boolean happy(int b, int[] m, int v){
    if(m[v] > 0 || v == 1)return true;
    if(m[v] < 0)return false;
    m[v] = -1;
    int nv = calc(b, v);
    //System.out.print(nv + " ");
    boolean f = happy(b, m, nv);
    m[v] = f ? 1 : -2;
    return f;
  }
  
  int calc(int b, int v){
    int ret = 0;
    while(v > 0){
      int mod = v % b;
      ret += mod * mod;
      v /= b;
    }
    return ret;
  }
}
