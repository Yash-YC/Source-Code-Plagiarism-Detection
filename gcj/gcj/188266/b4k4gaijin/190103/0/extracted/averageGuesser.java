import java.util.*;
public class averageGuesser
{
    static double choose(int n, int k)
    {
        return factorial(n) / (factorial(n-k) * factorial(k));
    }
    static double factorial(int n)
    {
        double mult = 1.0;
        for(int i = n; i >1; i--)
            mult *= i;
        
        return mult;
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int numProbs = sc.nextInt();
        for(int prob = 1; prob <= numProbs; prob++)
        {
            int c = sc.nextInt();
            int n = sc.nextInt();
            double[] evHere = new double[c+1];
            evHere[n] = 1;
            
            for(int i = n; i < c; i++)
            {
                double currentP = 1.0;
                double currentLen = evHere[i];
                while(currentP > 1e-20)
                {
                    currentLen++;
                    int target = Math.min(c, i+n);
                    for(int j = i+1; j <= target; j++)
                    {
                        double pToLandThere = choose(c-i, j-i) * choose(i, n-(j-i)) / choose(c, n);
                        evHere[j] += currentP * pToLandThere * currentLen;
                    }
                    currentP *= choose(i, n) / choose(c, n);
                }
            }
            System.out.println("Case #"+prob+": "+evHere[c]);
        }
    }
}