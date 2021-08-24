import java.util.*;

public class A {
    static int BASES = 11;
    static int NUMS = 3000000;

    static boolean[][] cache_isHappy = new boolean[BASES][NUMS];
    static boolean[][] cache_isSet = new boolean[BASES][NUMS];

    public static void main(String[] args) throws Exception{
        final Scanner s = new Scanner(System.in);
        final int T = s.nextInt();
        s.nextLine();
        for(int i = 0; i < T; ++i){
            int n = findIt(s);
            System.out.println("Case #" + (i+1) + ": " + n);
        }
    }
    
    static int findIt(Scanner s){
        final String ln = s.nextLine();
        final String[] ls = ln.split(" ");
        
        final int[] bs = new int[ls.length];
        for(int lsi = 0; lsi < ls.length; ++lsi)
            bs[lsi] = Integer.parseInt(ls[lsi]);
        for(int n = 2;; ++n){
            boolean ok = true;
            for(int bi = 0; bi < bs.length; ++bi){
                int b = bs[bi];
                if(!isHappy(n, b, new HashSet<Integer>())){
                    ok = false;
                    break;
                }
            }
            if(ok) return n;
        }
    }
    
    static boolean isHappy(int n, int b, HashSet<Integer> seen){
        if(b < BASES && n < NUMS && cache_isSet[b][n]){
            return cache_isHappy[b][n];
        }
        
        boolean res = isHappy_(n, b, seen);
        
        if(b < BASES && n < NUMS){
            cache_isSet[b][n] = true;
            cache_isHappy[b][n] = res;
        }
        
        return res;
    }
    
    static boolean isHappy_(int n, int b, HashSet<Integer> seen){
        if (n == 1) return true;
        if(seen.contains(n)) return false;
        seen.add(n);
        return isHappy(getNext(n, b), b, seen);
    }
    
    static int getNext(int n, int b){
        final String s = Integer.toString(n, b);
        final int slen = s.length();
        int sum = 0;
        for(int i = 0; i < slen; ++i){
            final char c = s.charAt(i);
            final int d = Character.digit(c, 10);
            sum += d*d;
        }
        return sum;
    }

}
