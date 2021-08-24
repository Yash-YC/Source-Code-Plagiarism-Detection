import java.util.Scanner;

/**
 * Created by SID on 4/15/2016.
 */

public class LastWord {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = Integer.parseInt(in.nextLine());

        for (int j = 1; j <= t; j++) {
            String s = in.nextLine();
            String result = "" + s.charAt(0);

            for (int i = 1; i < s.length(); i++) {
                if (s.charAt(i) >= result.charAt(0)) result = s.charAt(i) + result;
                else result += s.charAt(i);
            }

            System.out.println("Case #" + j + ": " + result);
        }
    }
}