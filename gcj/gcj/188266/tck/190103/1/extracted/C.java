import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.RoundingMode;


public class C {

    static BigDecimal d[] = new BigDecimal[40];
    
    static BigDecimal nways;
    static BigDecimal p;
    
    static BigDecimal cc[][] = new BigDecimal[100][100];
    static {
        for (int i=0; i<100; i++) for (int j=0; j<100; j++) cc[i][j]=null;
    }
    static BigDecimal choose(int a, int b) {
        if (b>a) return new BigDecimal(0);
        if (cc[a][b]!=null) return cc[a][b];
        cc[a][b]=new BigDecimal(1);
        for (int i=a; i>a-b; i--) {
            cc[a][b] = cc[a][b].multiply(new BigDecimal(i));
        }
        for (int i=1; i<=b; i++) {
            cc[a][b] = cc[a][b].divide(new BigDecimal(i));
        }
        return cc[a][b];
    }
    
    
    static BigDecimal helper(int c, int n, int nt) {
        if (nt>=c) return new BigDecimal(0);
        if (d[nt]!=null) return d[nt];
        
        d[nt] = new BigDecimal(0);
        
        BigDecimal nstay = new BigDecimal(0);
        for (int i=0; i<=Math.min(n,nt); i++) {
            BigDecimal nch = choose(nt, i).multiply(choose(c-nt, n-i));
            if (i==n) {
                nstay = nstay.add(nch);
            }
            else {
                d[nt] = d[nt].add(
                        nch.multiply(new BigDecimal(1).add(helper(c,n,nt+(n-i)))).multiply(p));
            }
        }
        d[nt] = (d[nt].add(nstay.multiply(p))).divide(
                new BigDecimal(1).subtract(nstay.multiply(p)), 100, RoundingMode.HALF_UP);
        
        return d[nt];
    }
    
    static double solve(int c, int n) {
        nways = choose(c,n);
        p = new BigDecimal(1).divide(nways,100,RoundingMode.HALF_UP);
        for (int i=0; i<c; i++) d[i]=null;
        return helper(c,n,0).doubleValue();
    }
    
    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int nc = Integer.parseInt(br.readLine());
        for (int i=0; i<nc; i++) {
            String s[] = br.readLine().split(" ");
            int c = Integer.parseInt(s[0]);
            int n = Integer.parseInt(s[1]);
            System.out.println("Case #"+(i+1)+": "+solve(c,n));
        }
    }
    
}
