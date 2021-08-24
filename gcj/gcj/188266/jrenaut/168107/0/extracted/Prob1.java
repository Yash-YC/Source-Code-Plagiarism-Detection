import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Prob1 {

    public static void main(String[] args) throws FileNotFoundException {
        File file = new File("small");
        Scanner scan = new Scanner(file);

        int numTests = scan.nextInt();
        scan.nextLine();

        for (int t = 1; t <= numTests; t++) {
            String line = scan.nextLine();
            String[] split = line.split(" ");
            int[] bases = getBases(split);

            int i = 2;
            for (; i < Integer.MAX_VALUE; i++) {
                boolean happy = true;
                for (int b = 0; b < bases.length; b++) {
                    happy = isHappy(i, bases[b], new HashSet<Integer>());
                    if (!happy)
                        break;
                }

                if (happy) {
                    break;
                }
            }

            System.out.println(String.format("Case #%d: %d", t, i));
        }

        // System.out.println(isHappy(91, 9, new HashSet<Integer>()));
    }

    private static int[] getBases(String[] split) {
        int[] bases = new int[split.length];
        for (int i = 0; i < bases.length; i++) {
            bases[i] = Integer.parseInt(split[i]);
        }
        return bases;
    }

    static boolean isHappy(int num, int base, Set<Integer> tries) {
        if (tries.contains(num)) {
            return false;
        }
        tries.add(num);

        String numbase = Integer.toString(num, base);
        int sum = 0;
        for (char c : numbase.toCharArray()) {
            int intc = Integer.parseInt("" + c);
            sum += (intc * intc);
        }

        if (sum == 1) {
            return true;
        }

        return isHappy(sum, base, tries);
    }
}
