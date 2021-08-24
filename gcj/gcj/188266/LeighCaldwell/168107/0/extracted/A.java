import java.io.*;
import java.util.Set;
import java.util.HashSet;

public class A {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String tries = br.readLine();
            int cases = Integer.parseInt(tries);

            int cs = 0;
            while (cs < cases) {
                cs++;
                String r = br.readLine();
                String[] bases = r.split(" ");
if (bases.length == 9) {
	System.out.println("Case #" + cs + ": 11814485");
} else {
                System.out.println("Case #" + cs + ": " + findLowest(bases));
}
            }
        } catch (IOException ioe) {
            ioe.printStackTrace();
        }
    }

    public static int findLowest(String[] bases) {
	if (bases.length == 9) {
		return 11814485;
	}
	if (bases.length == 8) {
		Set baseset = new HashSet();
		for (int c=0; c<8; c++) {
			baseset.add(bases[c]);
		}
		if (!baseset.contains("2")) {
			return 11814485;
		} else if (!baseset.contains("3")) {
			return 11814485;
		} else if (!baseset.contains("4")) {
			return 11814485;
		} else if (!baseset.contains("5")) {
			return 4817803;
		} else if (!baseset.contains("6")) {
			return 346719;
		} else if (!baseset.contains("7")) {
			return 28099;
		} else if (!baseset.contains("8")) {
			return 711725;
		} else if (!baseset.contains("9")) {
			return 2688153;
		} else if (!baseset.contains("10")) {
			return 569669;
		}
	}
        int i=2;
        boolean happy = false;
        Set[] happies = new Set[bases.length];
        while (true) {
            boolean basehappy = true;
            for (int b=0; b<bases.length && basehappy; b++) {
                if (happies[b] == null) {
                    happies[b] = new HashSet();
                }
                Set visited = new HashSet();
                if (!happy(i, Integer.parseInt(bases[b]), visited, happies[b])) {
                    basehappy = false;
                } else {
                    happies[b].addAll(visited);
                }
            }
            if (basehappy) {
                happy = true;
                return i;
            }
            i++;
        }
    }

    public static boolean happy(int i, int base, Set visited, Set happies) {
        // First represent i in base:
        int[] digits = new int[100];
        int j = 0;
        int rebase = i;
        while (rebase > 0) {
            digits[j] = rebase%base;
            // System.out.print("" + digits[j]);
            j++;
            rebase /= base;
        }
        int sum = 0;
        while (j >= 0) {
            sum += digits[j] * digits[j];
            j--;
        }

        // System.out.println(" happy[" + i + "/" + base + "] = " + sum);

        if (sum == 1) {
            return true;
        }
        if (happies.contains(sum)) {
            return true;
        }
        /*
        if (sum < i) {
            // we know that nothing less than rebase is happy, otherwise
            // it would be in happies
            return false;
        }
        */
        if (visited.contains(sum)) {
            return false;
        }
        // how else can we determine if it is _not_ happy?
        visited.add(sum);
        return happy(sum, base, visited, happies);
    }
}
