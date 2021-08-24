package round1a;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class ProblemA {

    private static final String INPUT_FILE = "c:\\temp\\A-small.in";
    private static final String OUTPUT_FILE = "c:\\temp\\A-small.out";

    private static Map<String,Boolean> map = new HashMap<String,Boolean>(1000000); 
    
    static boolean happyBase(long value, final long base)
    {
             Set<Long> handledValues = new HashSet<Long>();
        while (!handledValues.contains(value))
        {
            final String key = value + "," + base;

            if (map.containsKey(key))
            {
                return map.get(key);
            }
            if (value == 1)
            {
                return true;
            }
            long sum = sumSquares(value, base);
            handledValues.add(value);
            if (sum == 1)
            {
                map.put(key, true);
                return true;
            }
            if (handledValues.contains(sum))
            {
                map.put(key, false);
                return false;
            }
            value = sum;
        }
        throw new IllegalStateException();
    }
    
    static long sumSquares(long value, long base)
    {
        long result = 0;
        while (value > 0)
        {
            long unidade = value % base;
            result = result + unidade * unidade;
            value = value / base;
        }
        return result;
    }
    
    
    
    private static int handle(int[] bases) {
        int guess = 1;
        
        _out:
        while (true)
        {
            guess++;
            for(int base : bases)
            {
                if (!happyBase(guess, base))
                {
                    continue _out;
                }
            }
            return guess;
        }        
    }
    
    private static int minGuess(int[] bases) {
        int max = Integer.MIN_VALUE;
        
        for(int b : bases)
        {
            if (b > max)
            {
                max = b;
            }
        }
        
        return max;
        
    }

    private static long convertToBase(int guess, int base) {

        String s = Long.toString(guess, base);
        return Long.parseLong(s);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(INPUT_FILE));
        BufferedWriter writer = new BufferedWriter(new FileWriter(OUTPUT_FILE));

        int testcases = Integer.parseInt(reader.readLine());

        for (int caseNumber = 1; caseNumber <= testcases; caseNumber++) {
            String[] basesstr = reader.readLine().split(" ");
            int[] bases = new int[basesstr.length];
            int i = 0;
            for(String s: basesstr)
            {
                bases[i++] = Integer.parseInt(s);
            }
            int result = handle(bases);
            System.err.println("Case #" + caseNumber + ": " + result);
            writer.write("Case #" + caseNumber + ": " + result);
            writer.newLine();
        }

        reader.close();
        writer.close();
    }


    
}
