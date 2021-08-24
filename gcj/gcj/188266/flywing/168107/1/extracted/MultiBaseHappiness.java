import java.io.FileInputStream;
import java.io.IOException;
import java.util.Iterator;
import java.util.Scanner;
import java.util.TreeSet;

/**
 * @author Shixiong Zhu
 */
public class MultiBaseHappiness {

    // private boolean[][] temp;

    private int minHappiness(int[] bases) {
        int i = 2;
        // temp=new int[bases.length][]
        TreeSet<Integer> save = new TreeSet<Integer>();
        while (true) {
            boolean flag = false;

            for (int base: bases) {
                save.clear();
                if (!test(i, base, save)) {
                    // if (i == 91) {
                    // System.out.println("lll" + base);
                    // }
                    flag = true;
                    break;
                }
            }
            if (flag) {
                i++;
                continue;
            }
            break;
        }

        return i;
    }

    private void print(TreeSet<Integer> save) {
        Iterator i = save.iterator();
        System.out.print("begin:");
        while (i.hasNext()) {
            System.out.print(i.next() + " ");
        }
        System.out.println();
    }

    private boolean test(int i, int base, TreeSet<Integer> save) {

        if (save.contains(i)) {
            // if (base == 9)
            // print(save);
            return false;
        }

        save.add(i);

        int sum = 0;
        while (i > 0) {
            int mod = i % base;
            sum += mod * mod;
            i /= base;
        }
        if (sum > 1) {
            return test(sum, base, save);
        }
        return true;
    }

    public static void main(String[] args) {
        try {
            MultiBaseHappiness happy = new MultiBaseHappiness();

            Scanner in = new Scanner(new FileInputStream("data.txt"));

            int n = Integer.valueOf(in.nextLine());

            for (int i = 0; i < n; i++) {
                String[] line = in.nextLine().split(" ");
                int[] bases = new int[line.length];
                for (int j = 0; j < line.length; j++) {
                    bases[j] = Integer.valueOf(line[j]);
                }
                System.out.println("Case #" + (i + 1) + ": "
                        + happy.minHappiness(bases));
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
