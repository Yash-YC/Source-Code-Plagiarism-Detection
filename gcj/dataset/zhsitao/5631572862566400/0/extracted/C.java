import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class C {
    
    private static String fn = "C-small-attempt0";
    private static boolean isSubmit = true;
    
    public static void main(String[] args) throws FileNotFoundException {
        if (isSubmit) {
            System.setIn(new FileInputStream("test/" + fn + ".in"));
            System.setOut(new PrintStream("test/" + fn + ".out"));
        }
        
        Scanner in = new Scanner(System.in);
        int t0 = in.nextInt();
        for (int i0 = 1; i0 <= t0; i0++) {
            int n = in.nextInt();
            List<Integer>[] nb = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                nb[i] = new ArrayList<Integer>();
            }
            
            for (int i = 0; i < n; i++) {
                int t = in.nextInt();
                nb[i].add(t - 1);
            }
            
            System.out.print("Case #" + i0 + ": ");
            for (int i = n; i >= 2; i--) {
                int[] a = new int[i];
                boolean[] used = new boolean[n];
                if (perm(a, used, n, i - 1, 0, nb, false)) {
                    break;
                }
            }
        }
        
        in.close();
    }
    
    private static boolean perm(int[] a, boolean[] used, int n, int r, int t, List<Integer>[] nb, boolean success) {
        if (success) {
            return true;
        }
        for (int i = 0; i < n & !success; i++) {
            if (!used[i]) {
                used[i] = true;
                a[t] = i;
                if (t == r) {
                    success = output(a, nb);
                } else {
                    success = perm(a, used, n, r, t + 1, nb, success);
                }
                used[i] = false;
            }
        }
        return success;
    }
    
    private static boolean output(int[] res, List<Integer>[] nb) {
        for (int i = 0; i < res.length; i++) {
            int il = (i + res.length - 1) % res.length;
            int ir = (i + 1) % res.length;
            if (!nb[res[i]].contains(res[il]) && !nb[res[i]].contains(res[ir])) {
                return false;
            }
        }
//        for (int i = 0; i < res.length; i++) {
//            System.out.print(" " + res[i]);
//        }
        System.out.println(res.length);
        return true;
    }
}
