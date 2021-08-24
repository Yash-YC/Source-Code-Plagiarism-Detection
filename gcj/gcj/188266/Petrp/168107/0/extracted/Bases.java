/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package round1;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.LineNumberReader;
import java.io.Writer;
import java.util.Arrays;
import java.util.BitSet;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

/**
 *
 * @author polakp
 */
public class Bases {
    final static int N=100000;
    Scanner s;
    Writer writer;
    int cases = 0;
    int caseNumber;

    HashMap<Integer,BitSet> precomp=new HashMap();

    long check(long n, int base) {
        String r = Long.toString(n, base);
        long sum = 0;
        for (char x : r.toCharArray()) {
            final long parseLong = Long.parseLong("" + x, base);
            sum += parseLong * parseLong;
        }
        return sum;
    }

    boolean checkNum(long n, int base) {
        HashSet<Long> visited = new HashSet<Long>();
        while (true) {
            final long num = check(n, base);
            if (num == 1) {
                return true;
            }
            if (visited.contains(num)) {
                return false;
            } else {
                visited.add(num);
            }
            n = num;
        }
    }

    void solve() throws IOException {

        String x=s.nextLine();
        String data[]=x.split(" ");
        //HashMap map=new HashMap();
        int l[] = new int[data.length];
        for (int i = 0; i < l.length; i++) {
            l[i] = Integer.parseInt(data[i]);
        }
        //System.out.println(Arrays.toString(l));
        //println(l.toString());

        BitSet bs=new BitSet();
        bs.set(0, N);
        for (int b:l) {
            //System.out.println(b+":"+precomp.get(b));
            bs.and(precomp.get(b));            
        }
        final int nextSetBit = bs.nextSetBit(0);
        //System.out.println(bs);
        //System.out.println("First="+nextSetBit);
        if (nextSetBit<1) {
            throw new RuntimeException("Chyba");
        }
        println("Case #"+(caseNumber)+": "+nextSetBit);

    }

    Bases(Scanner r, FileWriter fw) {
        s = r;
        writer = fw;
    }

    public void readCases() throws IOException {
        int N=s.nextInt();
        s.nextLine();
        for (caseNumber=1;caseNumber<=N;caseNumber++) {
            solve();
        }
    }

    public void prepare() {
        for (int j = 2; j < 11; j++) {
            precomp.put(j, new BitSet());
            for (int i = 2; i < N; i++) {
                if (checkNum(i, j)) {
                    //System.out.print(i + ",");
                     precomp.get(j).set(i);
                }
               
            }
            //System.out.println("");
        }
        //System.out.println(precomp);
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {

       FileWriter wf=new FileWriter(args[0]+".out");
       LineNumberReader r=new LineNumberReader(new FileReader(args[0]));
        final Bases bases = new Bases(new Scanner(r), wf);
        bases.prepare();
        bases.readCases();
       wf.close();
    }

    String getCaseName() {
        return Integer.toString(caseNumber + 1);
    }

    void println(String string) throws IOException {
        writer.write(string + "\n");
        System.out.println(string);
    }
}
