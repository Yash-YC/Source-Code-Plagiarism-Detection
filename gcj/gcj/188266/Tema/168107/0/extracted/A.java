package codejam.c2009.r1;

import utils.codejam.IProblem;

import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;
import java.io.PrintStream;

public class A implements IProblem {

    public void solve(Scanner sc, PrintStream out) {
        int minHappyNamber = 2;
        String[] baseList = sc.nextLine().split(" ");
        for (int iBase = 0; iBase < baseList.length; iBase++) {
            int base = Integer.parseInt(baseList[iBase]);
            while (!checkNumber(minHappyNamber, base, new HashSet<Integer>())){
                minHappyNamber ++;
                iBase = -1;
            }
        }
        out.print(minHappyNamber);
    }

    private boolean checkNumber(int i, int base, Set<Integer> was){
        String n = Integer.toString(i, base);
        int sum = 0;
        for (int index = 0; index < n.length(); index++){
            int digit = Integer.parseInt(n.charAt(index) + "", base);
            sum += digit*digit;
        }
        if (sum == 1) {
            return true;
        }
        if (was.contains(sum)) {
            return false;
        }
        was.add(sum);
        return checkNumber(sum, base, was);
    }
}
