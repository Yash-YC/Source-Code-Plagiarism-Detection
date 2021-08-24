import java.util.Scanner;
import java.util.List;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.io.PrintWriter;
import java.io.File;

/**
 * Created by IntelliJ IDEA.
 * User: Anton
 * Date: 12.09.2009
 * Time: 5:54:26
 */
public class A {
    public static void main( String args[] ) throws Exception{
        new A ().run( );
    }
    
    Scanner sc;
    PrintWriter pw;
    int n, curCase;
    List<Integer> bs;
    int d[][] = new int[1000005][11];
    
    public void run( ) throws Exception{
        sc = new Scanner( new File( "a.in"));
        pw = new PrintWriter(new File( "a.out"));
        //pw = new PrintWriter(System.out);
        int t = sc.nextInt();
        sc.nextLine();
        for ( int i = 0;i < t; ++ i ){
            curCase = i + 1;
            readData();
            solve( );
        }
        pw.close();
    }
    
    public void readData( ) throws Exception{        
        StringTokenizer st = new StringTokenizer(sc.nextLine());
        bs = new ArrayList<Integer>( );
        while ( st.hasMoreTokens() ){
            bs.add( Integer.valueOf(st.nextToken()) );
        }
    }
    
    public void solve( ) throws Exception {
        for ( int i = 2; ; ++ i ){
            boolean ok = true;
            for ( int j = 0;j < bs.size( ); ++ j ){
                if ( !check( i, bs.get(j))){
                    ok = false;
                    break;
                }
            }
            if ( ok ){
                pw.println("Case #" + curCase + ": " + i);
                break;
            }
        }
    }
    
    boolean check( int num, int base ){
        if ( num >= d.length ){
            return false;
        }
        int cnum = num;
        if ( d[num][base] != 0){
            return d[num][base] == 1;
        }
        d[num][base] = -1;
        boolean ret = false;
        
        int val = 0;
        while ( cnum > 0 ){
            int c = (cnum % base);
            val += c * c;
            cnum /= base;
        }
        
        if ( val == 1) {
            ret = true;
        } else {
            ret = check( val, base );
        }
        if ( ret ){
            d[num][base] = 1;
        } else {
            d[num][base] = -1;
        }
        return ret;
    }
}
