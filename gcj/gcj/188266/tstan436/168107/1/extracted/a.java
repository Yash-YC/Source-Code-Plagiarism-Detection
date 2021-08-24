import java.io.File;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class a {
    static HashMap<String, String> mem = new HashMap<String, String>();

    static boolean[][] happy = new boolean[11][];
    static {
        for (int i = 2; i <= 10; i++)
            happy[i] = new boolean[11814486];
    }

    private static void fill(int base) {
        for (int i = 2; i <= 11814485; i++) {
            happy[base][i] = happy(i, base);
        }
        System.err.println("base " + base + " done");
    }

    public static void main(String[] args) throws Exception {
        for (int i = 2; i <= 10; i++) {
            fill(i);
        }
        String fname = "a.in";
        if (args.length > 0)
            fname = args[0];
        Scanner sc = new Scanner(new File(fname));
        int T = sc.nextInt();
        sc.nextLine();
        for (int i = 1; i <= T; i++) {
            System.out.print("Case #" + i + ": ");
            String in = sc.nextLine();
            String out;
            if (mem.containsKey(in))
                out = mem.get(in);
            else
                out = new a().go(in);
            mem.put(in, out);
            System.out.println(out);
        }
    }

    private String go(String in) {
        Set<Integer> bases = new HashSet<Integer>();
        Scanner sc = new Scanner(in);
        while (sc.hasNext())
            bases.add(sc.nextInt());

        int[] b = new int[bases.size()];
        int idx = 0;
        for (Integer base : bases) {
            b[idx++] = base;
        }

        top: for (int i = 2;; i++) {
            for (int base : b) {
                if(!happy[base][i])
                    continue top;
            }
            return "" + i;
        }
    }

    static boolean happy(int num, int base) {
        String st = Integer.toString(num, base);
        Set<String> seen = new HashSet<String>();
        seen.add("1");
        while (!seen.contains(st)) {
            seen.add(st);
            int sum = 0;
            for (int i = 0; i < st.length(); i++) {
                int digit = st.charAt(i) - '0';
                sum += digit * digit;
            }
            if(happy[base][sum])
                return true;
            st = Integer.toString(sum, base);
        }
        return st.equals("1");
    }
}
