package codejam.y2016.round1a;

import com.google.common.collect.Sets;

import java.io.File;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Set;

public class C {
    private static final String INPUT = "C-small-attempt0.in";
    private static final String OUTPUT = "C-small-attempt0.out";
    private static int answer = 0;

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new File(INPUT));
        StringBuilder sb = new StringBuilder();
        int cases = sc.nextInt();
        for (int c = 0; c < cases; c++) {
            int n = sc.nextInt();
            int[] bff = new int[n];
            for (int i = 0; i < n; i++) {
                bff[i] = sc.nextInt() - 1;
            }
            String line = "Case #" + (c + 1) + ": " + solve(bff);
            sb.append(line).append('\n');
            System.out.println(line);
        }
        Files.write(Paths.get(OUTPUT), sb.toString().getBytes());
    }

    private static int solve(int[] bff) {
        answer = 0;
        for (int i = 0; i < bff.length; i++) {
            LinkedList<Integer> list = new LinkedList<>();
            list.add(i);
            search(bff, list, Sets.newHashSet(i));
        }
        return answer;
    }

    private static void search(int[] bff, LinkedList<Integer> circle, Set<Integer> set) {
        if (isValid(bff, circle)) {
            answer = Math.max(answer, circle.size());
        }
        for (int i = 0; i < bff.length; i++) {
            if (!set.contains(i)) {
                circle.addLast(i);
                set.add(i);
                search(bff, circle, set);
                circle.removeLast();
                set.remove(i);
            }
        }
    }

    private static boolean isValid(int[] bff, LinkedList<Integer> circle) {
        ArrayList<Integer> list = new ArrayList<>(circle);
        if (list.size() == 1) {
            return true;
        }
        int n = list.size();
        for (int i = 0; i < n; i++) {
            int prev = list.get((i + 1) % n);
            int next = list.get((i - 1 + n) % n);
            if (bff[list.get(i)] != prev && bff[list.get(i)] != next) {
                return false;
            }
        }
        return true;
    }
}