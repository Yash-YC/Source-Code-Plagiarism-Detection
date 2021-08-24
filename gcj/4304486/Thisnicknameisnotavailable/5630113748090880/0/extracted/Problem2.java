package r1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Problem2 {

  public static void main(String[] args) throws FileNotFoundException {
    Problem2 t = new Problem2();
     t.run("t2.small");
//    t.run("t2.my");
    // t.run("t2.big");
  }

  private void run(String testSet) throws FileNotFoundException {
    File outFile = new File("src/main/resources/r1/" + testSet + ".out");
    PrintStream out = new PrintStream(outFile);
    ClassLoader classloader = Thread.currentThread().getContextClassLoader();
    InputStream is = classloader.getResourceAsStream("r1/" + testSet + ".in");
    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(is)));
    int testcaseNumber = in.nextInt();
    in.nextLine();
    for (int testcase = 1; testcase <= testcaseNumber; ++testcase) {
      String result = solveTestCase(in, testcase);
      out.println(result);
      System.out.println(result);
    }
    in.close();
    out.close();
  }

  static class Row implements Comparable<Row> {
    private int[] row;

    Row(int n) {
      row = new int[n];
    }

    Row(int[] row) {
      this.row = row;
    }

    @Override
    public int compareTo(Row o) {
      for (int i = 0; i < o.row.length; i++) {
        int res = Integer.compare(o.row[i], row[i]);
        if (res != 0) {
          return res;
        }
      }
      return 0;
    }

    @Override
    public String toString() {
      return "Row [row=" + Arrays.toString(row) + "]";
    }

  }

  private String solveTestCase(Scanner in, int testcase) {
    String resultString = "Case #" + testcase + ": ";
    int n = in.nextInt();
    int[][] field = new int[n][n];
    Row[] rows = new Row[2 * n - 1];
    for (int i = 0; i < 2 * n - 1; i++) {
      int[] bRow = new int[n];
      for (int j = 0; j < n; j++) {
        bRow[j] = in.nextInt();
      }
      rows[i] = new Row(bRow);
      in.nextLine();
    }
    boolean[] aRows = new boolean[n];
    boolean[] aCols = new boolean[n];

    Arrays.sort(rows, Collections.reverseOrder());
    int colindex = 0;
    for (int i = 0; i < rows.length; i++) {
      int p = rows[i].row[0];
      boolean inserted = false;
      for (int j = 0; j < n; j++) {
        if (field[0][j] == p && !aCols[j]) {
          // insertVertically
          insertCol(field, j, rows[i]);
          aCols[j] = true;
          inserted = true;
        }
      }
      if (!inserted) {
        // search hori
        for (int j = 0; j < n; j++) {
          if (field[j][0] == p && !aRows[j]) {
            inserted = true;
            aRows[j] = true;
            insertRow(field, j, rows[i]);
          }
        }
        if (!inserted) {
          // insert hori
          aRows[colindex] = true;
          insertRow(field, colindex++, rows[i]);
        }
      }
    }
    for (int i = 0; i < aRows.length; i++) {
      if (aRows[i] == false) {
        for (int j = 0; j < field.length; j++) {
          resultString += field[i][j] + " ";
        }
      }
    }
    for (int i = 0; i < aCols.length; i++) {
      if (aCols[i] == false) {
        for (int j = 0; j < field.length; j++) {
          resultString += field[j][i] + " ";
        }
      }
    }

    System.out.println("rows "+ Arrays.toString(aRows));
    System.out.println("cols "+ Arrays.toString(aCols));

    return resultString;
  }

  private void insertRow(int[][] field, int colindex, Row row) {
    System.out.println("insert Row" + colindex);
    for (int i = 0; i < field.length; i++) {
      field[colindex][i] = row.row[i];
    }
  }

  private void insertCol(int[][] field, int rowindex, Row row) {
    System.out.println("insert Col" + rowindex);
    for (int i = 0; i < field.length; i++) {
      field[i][rowindex] = row.row[i];
    }
  }
}
