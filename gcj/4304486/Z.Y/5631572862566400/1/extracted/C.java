package codejam.y2016.round1a;

import java.io.File;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Scanner;

public class C {
    private static final String INPUT = "C-large.in";
    private static final String OUTPUT = "C-large.out";
    private static int n;
    private static int[] bff;
    private static boolean[] expanded;

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new File(INPUT));
        StringBuilder sb = new StringBuilder();
        int cases = sc.nextInt();
        for (int c = 0; c < cases; c++) {
            n = sc.nextInt();
            bff = new int[n];
            expanded = new boolean[n];
            for (int i = 0; i < n; i++) {
                bff[i] = sc.nextInt() - 1;
            }
            String line = "Case #" + (c + 1) + ": " + solve();
            sb.append(line).append('\n');
            System.out.println(line);
        }
        Files.write(Paths.get(OUTPUT), sb.toString().getBytes());
    }

    private static int findCircle(int node) {
        int[] step = new int[n];
        for (int i = 0; i < n; ++i) {
            step[i] = -1;
        }
        step[node] = 0;
        int last = node;
        int current = bff[last];
        while (!expanded[current] && step[current] == -1) {
            step[current] = step[last] + 1;
            last = current;
            current = bff[last];
        }
        for (int i = 0; i < n; ++i) {
            if (step[i] != -1) {
                expanded[i] = true;
            }
        }
        return (step[current] != -1) ? step[last] - step[current] + 1 : 0;
    }

    private static String solve() {
        int answer = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i < j && bff[i] == j && bff[j] == i) {
                    expanded[i] = true;
                    expanded[j] = true;
                    answer += expand(i) + expand(j);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!expanded[i]) {
                answer = Math.max(answer, findCircle(i));
            }
        }
        return String.valueOf(answer);
    }

    private static int expand(int node) {
        int answer = 1;
        for (int i = 0; i < n; ++i) {
            if (!expanded[i] && bff[i] == node) {
                expanded[i] = true;
                answer = Math.max(answer, expand(i) + 1);
            }
        }
        return answer;
    }
}
