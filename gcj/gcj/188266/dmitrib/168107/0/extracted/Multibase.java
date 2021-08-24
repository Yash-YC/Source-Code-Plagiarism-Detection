package dmitrib.gcj.multibase;

import java.io.*;
import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;

/**
 * Created by IntelliJ IDEA.
 * Date: 12.09.2009
 * Time: 4:17:11
 * To change this template use File | Settings | File Templates.
 */
public class Multibase {


    public static void main(String[] args) throws IOException {
        long start = System.currentTimeMillis();

        String[][] items = GcjInputReader.readItems("input-multibase.txt");

        FileWriter wr = new FileWriter("out-multibase.txt");


        int cases = Integer.valueOf(items[0][0]);

        for (int i=0; i<cases; i++) {

            boolean isAllMagic = true;

            int candidate = 2;

            do {

                isAllMagic = true;

                for(int j=0; j<items[i+1].length; j++) {

                    System.out.println("candidate = " + candidate);
                    
                    isAllMagic &= isMagic(candidate, Integer.parseInt(items[i+1][j]), new HashSet<Long>());
                }

                candidate++;

            } while (!isAllMagic);

            System.out.println("magic = " + (candidate-1));

            wr.write("Case #" + (i+1) + ": " + (candidate - 1) + "\n");


        }

        wr.close();

    }


    static boolean isMagic(long number, int base, Set<Long> alreadyExists) {

        List<Long> digits = split(number, base);

        //System.out.println("digits = " + digits);

        long sum = 0;

        for (int i=0; i<digits.size(); i++) {
           sum += (digits.get(i) * digits.get(i));
        }

        if (sum == 1) {
            return true;
        }
        else if (alreadyExists.contains(sum)) {
            System.out.println("not a magic = " + number + " in " + base);
            return false;
        }
        else {
            //System.out.println("sum = " + sum);
            alreadyExists.add(sum);
            return isMagic(sum, base, alreadyExists);
        }
        
    }

    static List<Long> split(long number, int base) {
        ArrayList<Long> representation = new ArrayList<Long>();

        long  fullPart = number;

        long remain = 0;

        do {

            remain = fullPart % base;

            fullPart = fullPart / base;

            representation.add(remain);
            

        } while (fullPart > 0);

        return representation;

    }

}


class GcjInputReader {

  //private static String items[][];

  static String[][] readItems(String file) {

    String items[][];

    FileInputStream stream = null;

    try {

      stream = new FileInputStream(file);
      BufferedReader input = new BufferedReader(new InputStreamReader(stream));

      List<String> lines = new ArrayList<String>();

      String line;

      while((line = input.readLine()) != null) {
        lines.add(line);
      }


      items = new String[lines.size()][];

      int i=0;
      for (String l : lines) {
        items[i++] = l.split("\\s");
      }

      return items;

    }
    catch (FileNotFoundException e) {
      throw new RuntimeException(e);
    }
    catch (IOException e) {
      throw new RuntimeException(e);
    }
    finally {
      if (stream != null) {
        try {
          stream.close();
        }
        catch (IOException e) {
          e.printStackTrace();
        }
      }
    }

  }

}
