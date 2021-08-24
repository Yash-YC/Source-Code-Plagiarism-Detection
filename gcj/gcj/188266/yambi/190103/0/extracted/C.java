import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;
import java.math.*;

public class C {
    public static void main(String[] args) {
        new C().run();
    }
    void run() {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int cases=1;cases<=T;++cases){
            int C = sc.nextInt();
            int N = sc.nextInt();
            double[] exp = new double[C+1];
            for(int i=1;i<=C;++i){
                for(int j=1;j<=N;++j)if(j<=i&&N-j<=C-i)exp[i]+=(choose(C-i,N-j).multiply(choose(i,j))).doubleValue()/(choose(C,N).doubleValue())*exp[i-j];
                exp[i]+=1.0;
                exp[i]*=1.0/(1.0-(choose(C-i,N).doubleValue()/(choose(C,N).doubleValue())));
            }
            //System.out.println(Arrays.toString(exp));
            System.out.println("Case #"+cases+": "+exp[C]);
        }
    }

    //factorial
    public static BigInteger factorial(int n){
        return perm(n,n);
    }

    //n P r
    public static BigInteger perm(int n, int r){
        BigInteger result = BigInteger.ONE;
        for(int i=0;i<r;++i){
            result=result.multiply(new BigInteger((n-i)+""));
        }
        return result;
    }

    //n C r
    public static BigInteger choose(int n, int r){
        if(n<r)return BigInteger.ZERO;
        if(2*r>n)return choose(n,n-r);
        return (perm(n,r).divide(factorial(r)));
    }

}

