package come.google.codejam.round1A;

import come.google.codejam.utils.FileUtils;

import java.io.BufferedWriter;
import java.util.ArrayList;

/**
 * Created by qsang on 4/15/16.
 */
public class RoundOneA {
    public static void main(String[] args) {

        new RoundOneA();
    }

    private static final String SAMPLE_FILE = "round1A.sample.in";
    private static final String SMALL_FILE = "round1A.small.in";
    private static final String LARGE_FILE = "round1A.large.in";

    private String problemFileName;
    private ArrayList<String> answers;

    public RoundOneA() {
        problemFileName = SMALL_FILE;
        try {
            ArrayList<String> inputContentLines = (ArrayList) FileUtils.readInputFile(this.problemFileName);
            BufferedWriter writer = FileUtils.createOutputFileBufferedWriter(this.problemFileName);

            int T, lineIndex = 0;
            T = Integer.parseInt(inputContentLines.get(lineIndex));

            int currentTest;
            String output;
            String detail;
            for (currentTest = 1; currentTest <= T; currentTest++) {
                detail = inputContentLines.get(++lineIndex);
                answers = new ArrayList<String>();
                solveProblem(detail, null, 0);
                output = "Case #" + currentTest + ": " + findLast() + "\n";
//                System.out.println(output);
                writer.write(output);
            }
            writer.flush();
            writer.close();
        } catch (Exception exception) {
            System.out.println(exception.getMessage());
        }
    }

    public void solveProblem(String word, String previousWord,  int currentIndex) {
        if (currentIndex >= word.length()) {
            answers.add(previousWord);
            return;
        }

        if (previousWord == null) {
            char c = word.toCharArray()[0];
            solveProblem(word, String.valueOf(c), ++currentIndex);
        } else {
            char c = word.toCharArray()[currentIndex];
            solveProblem(word, previousWord + c, ++currentIndex);
            solveProblem(word, c + previousWord, currentIndex);
        }
    }

    public String findLast() {
        String answer = "";
        for (String s : answers) {
            if (answer.compareTo(s) < 0) {
                answer = s;
            }
        }

        return answer;
    }
}
