import java.io.BufferedReader;
import java.io.InputStreamReader;


public class C {

    static double d[] = new double[1<<10];
    
    static long nways;
    static double p;
    
    private static int countbits(int i) {
        int t=0;
        for (int j=0; j<20; j++) {
            if ((i&(1<<j))!=0) {
                t++;
            }
        }
        return t;
    }
    
    static double helper(int c, int n, int conf) {
        if (conf==(1<<c)-1) return 0;
        if (d[conf]>=-0.5) return d[conf];
        d[conf]=0;
        long nstay=0,ngo=0;
        for (int i=0; i<(1<<c); i++) {
            if (countbits(i)==n) {
                if ((conf|i)==conf) {
                    nstay++;
                }
                else {
                    d[conf] += (1+helper(c,n,conf|i))*p;
                    ngo++;
                }
            }
        }
        d[conf] = (p*nstay+d[conf]) / (1 - nstay*p);
        return d[conf];
    }
    
    static double solve(int c, int n) {
        nways=0;
        for (int i=0; i<(1<<c); i++) {
            if (countbits(i)==n) nways++;
        }
        p = ((double)1)/nways;
        for (int i=0; i<(1<<c); i++) d[i]=-1;
        return helper(c,n,0);
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
