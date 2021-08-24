/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.* ;
/******************************************************
 * Lab         Andrew Henrey          ajh5@sfu.ca     *
 *             301055616                              *
 *                                                    *
 ******************************************************/
public class ImAProgram {
    static double DPARRAY[] ;
    
    static long nint(double x) {
      if (x < 0.0) return (long) Math.ceil(x - 0.5);
      return (long) Math.floor(x + 0.5);
    }

    // return log n!
    static double logFactorial(int n) {
      double ans = 0.0;
      for (int i = 1; i <= n; i++)
         ans += Math.log(i);
      return ans;
    }

    // return the binomial coefficient n choose k.
    static long binomial(int n, int k) {
      return nint(Math.exp(logFactorial(n) - logFactorial(k) - logFactorial(n-k)));
    }
    
    public static double DP(int r, int c, int NUMBER)
    {
        if (c == 0)
        {
            DPARRAY[c] = 1 + DP(r,c+NUMBER,NUMBER) ;
            return DPARRAY[c] ;
        }
        if (c >= r)
            return 0 ;
        if (DPARRAY[c] != -1)
        {
            return DPARRAY[c] ;
        }
        double SUM = 0 ;
        double check = 0 ;
        //if (1 == r-c)
        //    SUM = 1 ;
        for (int k = 1 ; k <= Math.min(NUMBER,r-c) ; k ++)
        {
            double prob = (double)binomial(r-c,k)*(double)binomial(c,NUMBER-k)/(double)binomial(r,NUMBER) ;
            //System.out.println("ZOMG : " + r + " " + c + " " + k + " " + prob);
            //check += prob ;
            SUM += prob*(1+DP(r,c+k,NUMBER)) ;
        }
        double wtf = (double)binomial(c,NUMBER)/(double)binomial(r,NUMBER) ;
        //System.out.println("CHECK:" +(check+wtf));
        //System.out.println(wtf);
        SUM = (SUM+wtf) * 1/(1-wtf) ;
        DPARRAY[c] = SUM ;
        return SUM ;
    }
    
    public static void main(String[] args)
    {
        DPARRAY = new double[40] ;
        
        Scanner input = new Scanner(System.in) ;
        //System.out.println(binomial(4,0));
        int T = input.nextInt() ;
        for (int i = 0 ; i < T ; i ++)
        {
            for (int jj = 0 ; jj < 40 ; jj ++)
            {
                DPARRAY[jj] = -1 ;
            }
            int R = input.nextInt() ;
            int C = input.nextInt() ;
            
            double hax =  DP(R,0,C) ;
            
            
            
            System.out.println("Case #" + (i+1) + ": " + hax);
            
            
            
        }
        
        
        
        
    }
}
