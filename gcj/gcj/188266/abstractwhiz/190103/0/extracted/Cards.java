import java.util.*;
import java.io.*;

public class Cards
{
    boolean FILE = true;
    public static void main(String[] args) throws Exception
    {
        new Cards();
    }

    public Cards() throws Exception
    {
        if(!FILE)
            System.out.println("DON'T FORGET TO REDIRECT TO FILE!");
        Scanner sc = new Scanner(System.in);
//        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        if(FILE)
        {
            sc = new Scanner(new File("GCJ.in"));
//            in = new BufferedReader(new FileReader("GCJ.in"));
            out = new PrintWriter(new BufferedWriter(new FileWriter("GCJ.out")));
        }

        int T = sc.nextInt();
        for(int t = 1; t <= T; t++)
        {
            C = sc.nextInt();
            N = sc.nextInt();
            memo = new double[1 << C][501];
            for(int i = 0; i < memo.length; i++)
                Arrays.fill(memo[i], -1);

            out.printf("Case #%d: %f\n", t, go(0, 0) + 1e-9);
        }

        out.close();
        if(!FILE)
            System.out.println("DON'T FORGET TO REDIRECT TO FILE!");
    }

    int C, N;
    double[][] memo;
    double go(int have, int depth)
    {
        if(have+1 == (1 << C) || depth == 500)
            return 0;
        if(memo[have][depth] >= 0)
            return memo[have][depth];
        double ret = 0;
        long cnt = 0;
        for(int mask = 0; mask < (1 << C); mask++)
            if(Integer.bitCount(mask) == N)
            {
                cnt++;
                ret += (1 + go(have | mask, depth+1));
            }
        return memo[have][depth] = ret / (cnt);
    }
}
