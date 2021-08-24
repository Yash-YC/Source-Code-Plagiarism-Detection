package r1a;

import java.util.*;

class Cache{
  Map<Integer, Boolean> cache;
  public Cache() {
    cache = new HashMap<Integer, Boolean>();
  }
  void add(int v , boolean b){
    cache.put(v, b);
  }
  
  boolean has(int v){
    return cache.containsKey(v);
  }
  
  boolean get(int v){
    return cache.get(v);
  }
}

public class A {
  static int next(int x , int base){
    int res = 0;
    while(x != 0){
      int rem = x % base;
      res += rem * rem;
      x /= base;
    }
    return res;
  }
  
  static boolean ishappy(int k , int base , Cache cache){
    if(cache.has(k)){
      return cache.get(k);
    }
    int cur = k;
    Set<Integer> visit = new HashSet<Integer>();
    visit.add(cur);
    while(cur != 1){
      cur = next(cur , base);
      if(visit.contains(cur)){
        cache.add(k, false);
        return false;
      }
      visit.add(cur);
    }
    for(int v : visit){
      cache.add(v, true);      
    }
    return true;
  }
  
  static boolean ishappy(int k , int base){
    int cur = k;
    Set<Integer> visit = new HashSet<Integer>();
    visit.add(cur);
    while(cur != 1){
      cur = next(cur , base);
      if(visit.contains(cur)){
        return false;
      }
      visit.add(cur);
    }
    return true;
  }

  static boolean ishappy(int k , int bases[]){
    for(int base : bases){   
      int nk = next(k , base);
      if(!memo[base][nk])return false;
    }
    return true;
  }
  static boolean memo[][];
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    sc.nextLine();
    memo = new boolean[11][10001];
    for(int i = 2 ; i <= 10 ; i++){
      for(int j = 1 ; j <= 10000 ; j++){
        if(ishappy(j, i)){
          memo[i][j] = true;
        }
      }
    }    
    for(int t = 1 ; t <= T ; t++){
      String line = sc.nextLine();
      String arr[] = line.split("\\s+");
      int bases[] = new int[arr.length];
      for(int i = 0 ; i < arr.length ; i++){
        bases[i] = Integer.parseInt(arr[i]);
      }
      
      for(int k = 2 ; ; k++){
        if(ishappy(k, bases)){
          System.out.printf("Case #%d: %d\n",t , k);
          break;
        }
      }
    }
  }
}
