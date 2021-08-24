import java.util.*;
/**
 *
 * @author Izhari Ishak Aksa
 */
public class Main {

    static boolean isHappy(String s, int base) {
        Hashtable<String, Integer> hi = new Hashtable<String, Integer>();
        hi.put(s, 1);
        while (s.compareTo("1") != 0) {
            String temp = "";
            int tot = 0;
            for (int i = 0; i < s.length(); i++) {
                int x = s.charAt(i) - '0';
                tot += (x * x);
            }
            temp = Integer.toString(tot, base);
            if (hi.containsKey(temp)) return false;
            else hi.put(temp, 1);
            s = temp;
        }
        return true;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        String s = sc.nextLine();
        for (int i = 1; i <= t; i++) {
            String[] temp = sc.nextLine().split("[ ]");
            int[] arr = new int[temp.length];
            for (int j = 0; j < temp.length; j++)
                arr[j] = Integer.parseInt(temp[j]);
            
            for (int j = 2; ; j++) {
                boolean benar = true;
                for (int k = 0; k < arr.length; k++) {
                    String ss = Integer.toString(j, arr[k]);
                    if (!isHappy(ss, arr[k])) {
                        benar = false;
                        break;
                    }
                }
                if (benar) {
                    System.out.println("Case #" + i + ": " + j);
                    break;
                }
            }
        }
    }

}
