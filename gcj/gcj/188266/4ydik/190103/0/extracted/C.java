import java.util.Scanner;
import java.util.Arrays;
import java.io.PrintWriter;
import java.io.File;

/**
 * Created by IntelliJ IDEA.
 * User: Anton
 * Date: 12.09.2009
 * Time: 6:40:35
 */
public class C {
        public static void main( String args[] ) throws Exception{
        new C().run( );
    }

    Scanner sc;
    PrintWriter pw;
    int n, curCase, c;
    double d[] = new double[41];
    int w[][] = new int[41][100005];
    double cc[][] = new double[41][41];
    double sumH = 0.0;
    int sumCnt = 0;

    static final double eps = 1e-6;

    public void run( ) throws Exception{
        sc = new Scanner( new File( "c.in"));
        pw = new PrintWriter(new File( "c.out"));
        //pw = new PrintWriter(System.out);
        precalc();
        int t = sc.nextInt();

        for ( int tt = 0;tt < t; ++ tt ){
            curCase = tt + 1;
            readData();
            solve( );
        }
        pw.close();
    }

    public void readData( ) throws Exception{
        c = sc.nextInt();
        n = sc.nextInt();
    }

    public void solve( ) throws Exception {
        int it = 0;
        for ( int i = 0;i < 41; ++i )
            d[i] = 0;
        d[0] = 1.0;
        while ( it < 10000 ){
            ++it;
            for ( int ost = c; ost > 0; -- ost ){
                double cur = 0;
               for ( int i = 0; i < n + 1; ++ i ){
                    double p = cc[c][n];
                    p = cc[ost][i] * cc[c - ost][n -  i] / p;
                    if ( ost - i > 0 )
                        cur += (d[ost - i] + 1) * p;
                }
                d[ost] = cur;
            }
        }
        //System.out.println(d[c] + 1.0);
        pw.println("Case #" + curCase + ": " + (d[c] + 1.0) );
    }

    void precalc( ) {
        cc[0][0] = 1;
        for ( int i = 1;i < 41; ++i ){
            for ( int j = 0;j < i + 1; ++ j){
                cc[i][j] = cc[i - 1][j];
                if ( j > 0 )
                    cc[i][j] += cc[i - 1][j - 1];
            }
        }
    }

    double calc( int ost ) {
        if ( ost < 0 ){
            return 0.0;
        }
        if ( ost == 0 ){
            return 1.0;
        }
        double ret = 0;
        for ( int i = 0; i < n + 1; ++ i ){
            double p = cc[c][n];
            p = cc[ost][i] * cc[c - ost][n -  i] / p;
            ret += (calc( ost - i) + 1) * p;
        }
        return ret;
    }
}

