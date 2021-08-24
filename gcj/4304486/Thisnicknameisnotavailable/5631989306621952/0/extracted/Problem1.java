package r1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Scanner;

public class Problem1 {

  public static void main(String[] args) throws FileNotFoundException {
    Problem1 t = new Problem1();
    t.run("t1.small");
//    t.run("t1.my");

    // t.run("t1.big");
  }

  private void run(String testSet) throws FileNotFoundException {
    File outFile = new File("src/main/resources/r1" + testSet + ".out");
    PrintStream out = new PrintStream(outFile);
    ClassLoader classloader = Thread.currentThread().getContextClassLoader();
    InputStream is = classloader.getResourceAsStream("r1/" + testSet + ".in");
    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(is)));
    int testcaseNumber = in.nextInt();
    in.nextLine();
    for (int testcase = 1; testcase <= testcaseNumber; ++testcase) {
      String result = solveTestCase(in, testcase);
      out.print(result);
      System.out.print(result);
    }
    in.close();
    out.close();
  }

  private static String solveTestCase(Scanner in, int testcase) {
    String resultString = "Case #" + testcase + ": ";
    String letters = in.next();
    in.nextLine();
    String result = letters.substring(0, 1);
    for (int i = 1; i < letters.length(); i++) {
      String cLetter = letters.substring(i, i + 1);
      if (result.substring(0, 1).compareTo(cLetter) > 0) {
        result = result + cLetter;
      } else {
        result = cLetter + result;
      }
    }
    resultString += result +"\r\n";
    return resultString;
  }
}
