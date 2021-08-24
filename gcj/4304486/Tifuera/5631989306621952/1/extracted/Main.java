import java.io.FileInputStream;
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
			final String regex = "A-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("a.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    private int[] result;
    private int[] numbers;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        String str = in.next();

        numbers = new int[str.length()];
        for (int i = 0; i < str.length(); i++) {
            numbers[i] = str.charAt(i) - 'A';
        }

        result = new int[numbers.length];

        solve(0, numbers.length, 0);

        out.print("Case #" + testNumber + ": ");
        for (int r : result) {
            char ch = (char) (r + 'A');
            out.print(ch);
        }
        out.println();
    }

    private void solve(int start, int end, int resStart) {
        if (start >= end) {
            return;
        }
        int maxIdx = getMaxIdx(start, end);
        result[resStart] = numbers[maxIdx];

        for (int i = maxIdx + 1; i < end; i++) {
            result[resStart + (i - start)] = numbers[i];
        }

        solve(start, maxIdx, resStart + 1);
    }

    private int getMaxIdx(int start, int end) {
        int maxIdx = -1;
        int maxVal = Integer.MIN_VALUE;
        for (int i = start; i < end; i++) {
            if (numbers[i] >= maxVal) {
                maxVal = numbers[i];
                maxIdx = i;
            }
        }

        return maxIdx;
    }

}

class InputReader {
    private BufferedReader reader;
    private String[] currentArray;

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

}

