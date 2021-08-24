import java.util.*;
import java.text.*;

class Card {
   double dp[] = new double[1<<10];
   boolean seen[] = new boolean[1<<10];

   int C, N;
   double den;

   public Card(int C, int N) {
      den = choose(C,N);
      this.C = C; this.N = N;
      clean();
   }

   public int bitCount(int mask) {
      return mask == 0 ? 0 : 1 + bitCount(mask&(mask-1));
   }

   public double solve(int mask) {
      if (bitCount(mask) == C) return 0.0;
      if (seen[mask]) return dp[mask];
      seen[mask] = true;
      dp[mask] = 0.0;
      int cnt = 0;

      for (int n = 0; n < 1<<C; n++) {
         if (bitCount(n) != N) continue;
         if ((n|mask) == mask) {
            cnt++;
         } else 
            dp[mask] += (1.0 + solve(mask|n)) / den;
      }
      dp[mask] *= den;
      dp[mask] += cnt;
      dp[mask] /= (den-cnt);

      return dp[mask];
   }

   public double choose(int N, int K) {
      if (2*K > N) K = N-K;
      double res = 1.0;
      for (int i = 1; i <= K; i++)
         res *= (double) (N-K+i) / i;
      return res;
   }

   public void clean() {
      Arrays.fill(seen, false);
   }

   public static void main(String []arg) {
      Scanner sc = new Scanner(System.in);
      // DecimalFormat df = new DecimalFormat("0.0000000");
      int T = sc.nextInt();
      for (int i = 0; i < T; i++) {
         int N = sc.nextInt();
         int K = sc.nextInt();
         Card c = new Card(N,K);
         System.out.println("Case #" + (i+1) + ": " + c.solve(0));
      }
   }
}
