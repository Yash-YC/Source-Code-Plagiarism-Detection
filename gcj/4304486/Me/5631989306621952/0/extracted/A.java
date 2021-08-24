import java.util.*;

public class A {

    static Scanner in;

    public static void main(String[] args) {
        in = new Scanner(System.in);
        int T = in.nextInt();
        for (int C = 1; C <= T; C++) {
            System.out.println("Case #" + C + ": " + solve());
        }
    }

    static String solve() {
        String s = in.next();
        String out = "";
        boolean first = true;

        for (char c : s.toCharArray()) {
            if (first || c >= out.charAt(0)) {
                out = c + out;
                first = false;
            } else {
                out = out + c;
            }
        }

        return out;
    }
}
