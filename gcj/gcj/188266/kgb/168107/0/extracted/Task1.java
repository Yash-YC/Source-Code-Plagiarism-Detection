package round1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

/**
 *
 * @author Constantine Bozhkov
 */
public class Task1 {

public static class DatasetReader {
    BufferedReader reader;
    int testCaseCount;
    public DatasetReader(String fileName, boolean readCount) throws Exception {
        reader = new BufferedReader(new FileReader(fileName));
        if (readCount)
            testCaseCount = Integer.parseInt(reader.readLine());
    }

    public void close() throws Exception {
        reader.close();
    }

    public int getTestCount() {
        return testCaseCount;
    }

    public long readNumber() throws Exception {
        return Long.parseLong(reader.readLine().trim());
    }

    public BigInteger readBigInt() throws Exception {
        return new BigInteger(reader.readLine());
    }

    public String readString() throws Exception {
        return reader.readLine();
    }

    public String[] readStringArray(String delims) throws Exception {
        String line = reader.readLine();
        StringTokenizer st = new StringTokenizer(line, delims);
        String[] result = new String[st.countTokens()];
        for (int i = 0; i < result.length; i++) {
            result[i] = st.nextToken();
        }
        return result;
    }

    public long[] readNumberArray(String delims) throws Exception {
        String[] raw = readStringArray(delims);
        long[] result = new long[raw.length];
        for (int i = 0; i < raw.length; i++) {
            result[i] = Long.parseLong(raw[i]);
        }
        return result;
    }
}
public static class OutputWriter extends PrintWriter {
    private static final Set<OutputWriter> activeWriters =
            new HashSet<OutputWriter>();
    private static final Thread hookThread = new Thread() {
        @Override
        public void run() {
            for (OutputWriter w: activeWriters) {
                try {w.close();} catch (Exception e) {}
            }
        }

    };

    private int answerIdx;

    static {
        Runtime.getRuntime().addShutdownHook(hookThread);
    }

    public OutputWriter(String fileName) throws Exception {
        super(fileName);
        activeWriters.add(this);
    }

    public void printAnswer(String s) {
        println("Case #" + ++answerIdx + ": " + s);
    }

    @Override
    public void close() {
        super.close();
        activeWriters.remove(this);
    }
}

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        DatasetReader dr = new DatasetReader("input.in", true);
        OutputWriter ow = new OutputWriter("output");

        for (int i = 0; i < dr.getTestCount(); i++) {
            ow.printAnswer(String.valueOf(solve(dr.readNumberArray(" "))));
        }
    }

    private static int solve(long[] bases) {
        int[][] digits = new int[bases.length][];

        for (int i = 0; i < bases.length; i++) {
            int base = (int) bases[i];
            int sqc = base * base;
            digits[i] = new int[sqc];
            digits[i][1] = 1;
            for (int j = 2; j < sqc; j++) {
                int a = transform(j, base);
                for (int k = 0; k < sqc && a > j; k++) {
                    a = transform(a, base);
                }
                if (a < j) {
                    digits[i][j] = digits[i][a];
                } else {
                    digits[i][j] = j;
                }
            }
        }

        int i = 1;
        boolean happy;
        do {
            i++;
            happy = true;
            for (int j = 0; j < bases.length; j++) {
                int a = i;
                int base = (int) bases[j];
                int sqc = base * base;
                while (a >= sqc) {
                    a = transform(a, base);
                }
                if (digits[j][a] != 1) {
                    happy = false;
                    break;
                }
            }
        } while (!happy);
        return i;
    }

    private static int transform(int x, int base) {
        int result = 0;
        while (x > 0) {
            result += (x % base) * (x % base);
            x = x / base;
        }
        return result;
    }
}
