import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;

public class Problem1 {
    public static HashMap<String, Boolean> memo = new HashMap<String,Boolean>();

    public static void main(String args[]) throws NumberFormatException,
            IOException {
        String name = "A-small-attempt0";
        BufferedReader reader = new BufferedReader(new InputStreamReader(
                new FileInputStream(new File(name + ".in"))));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(
                new FileOutputStream(new File(name + ".out"))));

        int n = Integer.parseInt(reader.readLine());

        for (int i = 0; i < n; i++) {
            String[] basesStr = reader.readLine().split(" ");
            int[] bases = new int[basesStr.length];
            for (int ii = 0; ii < bases.length; ii++) {
                bases[ii] = Integer.parseInt(basesStr[ii]);
            }
            boolean found = false;
            int j = 1;
            while (!found) {
                j++;
                found = true;
                for (int b : bases) {
                    if (!happyInBase(j, b)) {
                        found = false;
                        break;
                    }
                }
            }
            System.out.println("Case #" + (i+1) + ": " + j);
            writer.write("Case #" + (i+1) + ": " + j + "\n");
        }

        writer.flush();
        writer.close();
    }

    public static boolean happyInBase(int n, int b) {
        //System.out.println("Is " + n + " happy in base " + b + "?");
        
        int j = n;
        
        if(memo.containsKey(j+","+b)) return memo.get(j+","+b);
        
        HashMap<Integer, Boolean> seen = new HashMap<Integer,Boolean>();
        while (j != 1) {
            if(seen.containsKey(j)) {
                //System.out.println("  No!");
                return false;
            }
            String num = Integer.toString(j, b);
            int count = 0;
            for (int i = 0; i < num.length(); i++) {
                count += Math.pow(Integer.parseInt(num.charAt(i)+""), 2);
            }
            //System.out.println("  " + j + " -> " + count);
            seen.put(j, true);
            j = count;
        }
        //System.out.println("  Yes!");
        return true;
    }
}
