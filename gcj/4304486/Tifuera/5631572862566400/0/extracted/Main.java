import java.io.FileInputStream;
import java.util.Arrays;
import java.util.ArrayList;
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
			final String regex = "C-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("c.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    private int[] bff;
    private int[] pair;
    private int[] height;
    private ArrayList<Integer>[] graph;

    private boolean[] usedVert;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt();
        bff = new int[N];

        for (int i = 0; i < N; i++) {
            bff[i] = in.nextInt() - 1;
        }

        height = new int[N];
        usedVert = new boolean[N];

        pair = new int[N];
        Arrays.fill(pair, -1);
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (bff[i] == j && bff[j] == i) {
                    pair[i] = j;
                    pair[j] = i;
                }
            }
        }

        int res = getSimpleRes();
        //simple cycle
        res = Math.max(res, getCycleRes());

        out.println("Case #" + testNumber + ": " + res);
    }

    private int getCycleRes() {
        graph = new ArrayList[bff.length];
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < bff.length; i++) {
            if (bff[i] != pair[i]) {
                graph[bff[i]].add(i);
            }
        }

        for (int i = 0; i < bff.length; i++) {
            Arrays.fill(usedVert, false);
            height[i] = dfs(i);
        }

        int res = 0;

        for (int i = 0; i < pair.length; i++) {
            if (pair[i] != -1 && i < pair[i]) {
                res += height[i] + height[pair[i]] + 2;
            }
        }

        return res;
    }

    private int dfs(int root) {
        usedVert[root] = true;
        int cur = 0;
        for (int next : graph[root]) {
            if (!usedVert[next]) {
                cur = Math.max(cur, 1 + dfs(next));
            }

        }

        return cur;
    }

    private int getSimpleRes() {
        int res = 1;

        boolean[] used = new boolean[bff.length];
        for (int start = 0; start < bff.length; start++) {
            Arrays.fill(used, false);
            used[start] = true;
            int len = 1;
            int next = bff[start];
            while (!used[next]) {
                used[next] = true;
                next = bff[next];
                len++;
            }

            if (next == start) {
                res = Math.max(res, len);
            }
        }

        return res;
    }

//        int res = 1;
//
//        for (int mask = 1; mask < (1 << N); mask++) {
//            if (Integer.bitCount(mask) > res) {
//                for (int firstF = 0; firstF < N; firstF++) {
//                    if (isBitSet(mask, firstF)) {
//                        for (int secondF = firstF + 1; secondF < N; secondF++) {
//                            if (isBitSet(mask, secondF) && bff[firstF] == secondF) {
//                                if (isPossible(mask, firstF, secondF, bff)) {
//                                    res = Integer.bitCount(mask);
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//        }
//
//        out.println("Case #" + testNumber + ": " + res);

//    private boolean isPossible(int mask, int firstF, int secondF, int[] bff) {
//        int cnt = Integer.bitCount(mask);
//        if(cnt)
//    }
//
//    private boolean isBitSet(int mask, int bit) {
//        return ((mask >> bit) % 2) == 0;
//    }

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

