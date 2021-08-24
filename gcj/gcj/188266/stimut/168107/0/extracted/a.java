import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.HashMap;


class a
{
    static BufferedReader stdin = new BufferedReader(
            new InputStreamReader(System.in));

    public static void main(String[] args)
            throws NumberFormatException, IOException {
        int testCases = Integer.parseInt(stdin.readLine());

        for (int caseNum=1; caseNum<=testCases; caseNum++) {
            String[] strBases = stdin.readLine().split("\\s");

            int num = 1;
            boolean allHappy = false;
            while (!allHappy) {
                num++;
                boolean unhappy = false;
                for (int ii=0; ii<strBases.length; ii++) {
                    int base = Integer.parseInt(strBases[ii]);
                    //System.out.println("Testing base " + base + " on number " + num);
                    HashMap<Integer, Integer> seenNums = new HashMap<Integer, Integer>();
                    String strNum = Integer.toString(num, base);
                    // perform the sum of squares
                    while (strNum.length() > 1 || !strNum.equals("1")) {
                        int newNum = 0;
                        for (int jj=0; jj<strNum.length(); jj++) {
                            int singleVal = Integer.parseInt(strNum.substring(jj, jj+1));
                            newNum += singleVal * singleVal;
                        }
                        //System.out.println("\tFound new num of " + newNum);
                        Integer objNum = new Integer(newNum);
                        if (seenNums.containsKey(objNum)) {
                            // we've repeated - unhappy :(
                            unhappy = true;
                            break;
                        } else {
                            seenNums.put(objNum, objNum);
                            strNum = Integer.toString(newNum, base);
                        }
                    }
                    if (unhappy)
                        break;
                }
                if (!unhappy)
                    allHappy = true;
            }

            System.out.println("Case #" + caseNum + ": " + num);
        }
    }
}
