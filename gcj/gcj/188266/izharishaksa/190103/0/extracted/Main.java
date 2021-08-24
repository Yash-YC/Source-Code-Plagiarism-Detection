import java.util.*;
/**
 *
 * @author Izhari Ishak Aksa
 */
public class Main {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            int a = sc.nextInt(), b = sc.nextInt();
            double x = (1. / b * a) + 1;
            System.out.printf("Case #%d: %.7f\n", i, x);
        }
    }

}
