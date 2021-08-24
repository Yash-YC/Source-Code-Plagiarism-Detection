import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class A {
    
    private static String fn = "A-small-attempt0";
    private static boolean isSubmit = true;
    
    public static void main(String[] args) throws FileNotFoundException {
        if (isSubmit) {
            System.setIn(new FileInputStream("test/" + fn + ".in"));
            System.setOut(new PrintStream("test/" + fn + ".out"));
        }
        
        Scanner in = new Scanner(System.in);
        int t0 = in.nextInt();
        in.nextLine();
        for (int i0 = 1; i0 <= t0; i0++) {
            char[] chars = in.nextLine().toCharArray();
            StringBuffer sb = new StringBuffer();
            
            for (int i = 0; i < chars.length; i++) {
                if (i == 0 || chars[i] < sb.charAt(0)) {
                    sb.append(chars[i]);
                } else {
                    sb.insert(0, chars[i]);
                }
            }
            
            System.out.println("Case #" + i0 + ": " + sb.toString());
        }
        
        in.close();
    }
}
