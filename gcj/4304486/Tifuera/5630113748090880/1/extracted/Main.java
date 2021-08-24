import java.io.FileInputStream;
import java.util.Arrays;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.File;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Tifuera
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "B-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("b.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt();
        int[][] lines = new int[2 * N - 1][N];
        for (int i = 0; i < lines.length; i++) {
            for (int j = 0; j < lines[i].length; j++) {
                lines[i][j] = in.nextInt();
            }
        }

        int[] diagIdxs = new int[2 * N - 1];
        Arrays.fill(diagIdxs, -1);
        int pairLineIdx = -1;
        int pairDiagIdx = -1;

        for (int i = 0; i < N; i++) {
            int minVal = Integer.MAX_VALUE;

            //find min val
            for (int lnIdx = 0; lnIdx < lines.length; lnIdx++) {
                if (diagIdxs[lnIdx] == -1) {
                    int cur = lines[lnIdx][i];
                    if (cur < minVal) {
                        minVal = cur;
                    }
                }
            }

            int numFind = 0;
            int lastFound = -1;
            //set idx
            for (int lnIdx = 0; lnIdx < lines.length; lnIdx++) {
                if (diagIdxs[lnIdx] == -1) {
                    int cur = lines[lnIdx][i];
                    if (cur == minVal) {
                        numFind++;
                        diagIdxs[lnIdx] = i;
                        lastFound = lnIdx;
                    }
                }
            }

            if (numFind > 2) {
                throw new RuntimeException();
            }

            if (numFind == 1) {
                pairDiagIdx = i;
                pairLineIdx = lastFound;
            }
        }


        int[] result = new int[N];

        for (int i = 0; i < N; i++) {
            if (i == pairDiagIdx) {
                result[i] = lines[pairLineIdx][pairDiagIdx];
                continue;
            }

            int v1 = -1;
            int v2 = -1;
            for (int lnIdx = 0; lnIdx < lines.length; lnIdx++) {
                if (diagIdxs[lnIdx] == i) {
                    if (v1 == -1) {
                        v1 = lines[lnIdx][pairDiagIdx];
                    } else {
                        v2 = lines[lnIdx][pairDiagIdx];
                    }
                }
            }

            if (v1 == lines[pairLineIdx][i]) {
                result[i] = v2;
            } else {
                result[i] = v1;
            }
        }

        out.print("Case #" + testNumber + ":");

        for (int r : result) {
            out.print(" " + r);
        }

        out.println();
    }

}

class InputReader {
    private BufferedReader reader;
    private String[] currentArray;
    private int curPointer;

    public InputReader(InputStream inputStream) {
        reader = new BufferedReader(new InputStreamReader(inputStream));
    }


    public String next() {
        try {
            currentArray = null;
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public int nextInt() {
        if ((currentArray == null) || (curPointer >= currentArray.length)) {
            try {
                currentArray = reader.readLine().split(" ");
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            curPointer = 0;
        }
        return Integer.parseInt(currentArray[curPointer++]);
    }

}

