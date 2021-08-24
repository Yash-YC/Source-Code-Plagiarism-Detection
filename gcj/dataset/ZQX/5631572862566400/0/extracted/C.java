/**
 * Created by qixinzhu on 4/8/16.
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {

    public static void genLargeP () throws FileNotFoundException {
        File inputFile = new File("C-small-attempt0.in");
        PrintWriter out = new PrintWriter("test_b.txt");
        Scanner in = new Scanner(inputFile);
        int T = in.nextInt();
        out.println(T);
        for (int i=0; i<T; i++) {
            out.printf("%d\n",(int) (Math.random()*100000));
        }
        in.close();
        out.close();
    }

    public static void main(String[] args) throws FileNotFoundException{
        // test case
//        genLargeP();
//        File inputFile = new File("test.txt");
//        PrintWriter out = new PrintWriter("test_out.txt");

        // real case
//        File inputFile = new File("C-large.in");
        File inputFile = new File("C-small-attempt0.in");
        PrintWriter out = new PrintWriter("C_out.txt");

        Scanner in = new Scanner(inputFile);

        int T = in.nextInt();
        int N;
        for (int i=0;i<T;i++) {
            N= in.nextInt();
            int[] bff = new int[N+1];
            for (int j=1;j<N+1;j++) {
                bff[j] = in.nextInt();
            }
            // build map
            int[][] map = new int[N+1][N+1];
            for (int j=1;j<N+1;j++) {
                int dist = 0;
                int cur = j;
                boolean[] visited = new boolean[N+1];
                while (!visited[bff[cur]]) {
                    dist++;
                    cur = bff[cur];
                    map[j][cur] = dist;
                    visited[cur] = true;
                }
            }
            // check diagonal for: max-length loop; mutual bff
            int maxLoop = 0;
            boolean[] mutualBFF = new boolean[N+1];

            for (int j=1;j<N+1;j++) {
                if (map[j][j] > maxLoop) {
                    maxLoop = map[j][j];
                }
                if (map[j][j] == 2) {
                    mutualBFF[j] = true;
                }
            }
            // mutual bff case
            int maxPath = 0;
            for (int j=1;j<N+1;j++) {
                if (mutualBFF[j]) {
                    int maxDist1 = 0;
                    int maxDist2 = 0;
                    for (int k=1;k<N+1;k++) {
                        if (k!=j && k!=bff[j]) {
                            if (map[k][j] < map[k][bff[j]] && map[k][j] > maxDist1) {
                                maxDist1 = map[k][j];
                            }
                            if (map[k][bff[j]] < map[k][j] && map[k][bff[j]] > maxDist2) {
                                maxDist2 = map[k][bff[j]];
                            }
                        }
                    }
                    mutualBFF[j] = false;
                    mutualBFF[bff[j]] = false;
                    maxPath += maxDist1+maxDist2+2;
                }
            }
            int ans = Math.max(maxLoop,maxPath);
            out.printf("Case #%d: %s\n", i + 1, ans);
        }

        in.close();
        out.close();
    }
}
