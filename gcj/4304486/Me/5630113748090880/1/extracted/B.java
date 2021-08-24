import java.util.*;

public class B {

    static Scanner in;

    public static void main(String[] args) {
        in = new Scanner(System.in);
        int T = in.nextInt();
        for (int C = 1; C <= T; C++) {
            System.out.println("Case #" + C + ":" + solve());
        }
    }

    static String solve() {
        int N = in.nextInt();

        int[] count = new int[2600];
        for (int i = 0; i < N + N - 1; i++) {
            for (int j = 0; j < N; j++) {
                count[in.nextInt()]++;
            }
        }

        String out = "";

        for (int i = 0; i < count.length; i++) {
            if (count[i] % 2 == 1) {
                out += " " + i;
            }
        }


        return out;
    }
}
