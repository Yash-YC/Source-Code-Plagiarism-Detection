package come.google.codejam.round1A;

import come.google.codejam.utils.FileUtils;

import java.io.BufferedWriter;
import java.util.ArrayList;
import java.util.HashSet;

/**
 * Created by qsang on 4/15/16.
 */
public class RoundOneAThree {
    public static void main(String[] args) {

        new RoundOneAThree();
    }

    private static final String SAMPLE_FILE = "round1A.sample.in";
    private static final String SMALL_FILE = "round1A.small.in";
    private static final String LARGE_FILE = "round1A.large.in";

    private String problemFileName;
    private ArrayList<String> answers;

    public RoundOneAThree() {
        problemFileName = SMALL_FILE;
        try {
            ArrayList<String> inputContentLines = (ArrayList) FileUtils.readInputFile(this.problemFileName);
            BufferedWriter writer = FileUtils.createOutputFileBufferedWriter(this.problemFileName);

            int T, lineIndex = 0;
            T = Integer.parseInt(inputContentLines.get(lineIndex));

            int currentTest, N;
            String output;
            String detail;
            for (currentTest = 1; currentTest <= T; currentTest++) {
                N = Integer.parseInt(inputContentLines.get(++lineIndex));
                detail = inputContentLines.get(++lineIndex);
                output = "Case #" + currentTest + ": " + solveProblem(detail, N) + "\n";
//                System.out.println(output);
                writer.write(output);
            }
            writer.flush();
            writer.close();
        } catch (Exception exception) {
            System.out.println(exception.getMessage());
        }
    }

    public int solveProblem(String detail, int N) {
        String[] bffs = detail.split("\\ ");
        HashSet<Integer> kids;
        HashSet<Integer> startingBffs = new HashSet<Integer>();
        int answer = 0;
        int kid, kidBff, previousKid;

        for (int i=0; i < N; i++) {
            kids = new HashSet<Integer>();
            kid = i;
            if (startingBffs.contains(Integer.valueOf(bffs[kid]))) {
                continue;
            } else {
                startingBffs.add(Integer.valueOf(bffs[kid]));
            }

            do {
                kidBff = Integer.valueOf(bffs[kid]);
                kids.add(kid);
                previousKid = kid;
                kid = kidBff - 1;
            } while (!kids.contains(kid));

            if (kid != i) {
                for (int j = 0; j < N; j++) {
                    if (Integer.valueOf(bffs[j]) == previousKid + 1 && !kids.contains(j)) {
                        kids.add(j);
                        break;
                    }
                }
            }

            if (kids.size() > answer) {
                answer = kids.size();
            }

            if (answer == N) {
                return N;
            }
        }
        return answer;
    }
}
