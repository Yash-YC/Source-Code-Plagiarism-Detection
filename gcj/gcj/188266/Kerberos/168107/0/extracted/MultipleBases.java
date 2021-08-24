package main;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

/**
 *
 * @author kerberos
 */
public class MultipleBases {

    public static boolean sumInRadix(BigInteger n, int radix,Set<BigInteger> accumulator)
    {
        if (accumulator==null){
            accumulator = new HashSet<BigInteger>();
        }
        if (accumulator.contains(n))
        {
            return false;
        }
        accumulator.add(n);

        String s = n.toString(radix);
        int sum = 0;

        for (int i=0;i<s.length();i++)
        {
            int localNum = s.getBytes()[i]-'0';
            sum+= (localNum*localNum);
        }
        n=new BigInteger((Integer.toString(sum)));
        s = n.toString(radix);
        if (sum==1){
            return true;
        }
        return sumInRadix(n, radix,accumulator);
    }

    private static int lowestNum(List<Integer> bases)
    {
        int i =1;
        boolean result;
        do{
            i++;
            result = true;
            BigInteger input = new BigInteger(Integer.toString(i));
            for (Integer base : bases){
                result &= sumInRadix(input,base,null);
            }
        }while(!result);

        return i;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader(new File("/tmp/input.in")));
        long count = Long.parseLong(br.readLine());
        for (int i = 0; i < count; i++) {
            final String[] bases = br.readLine().split(" ");
            final List<Integer> basesInt = new LinkedList<Integer>();
            for (String base: bases)
            {
                basesInt.add(Integer.parseInt(base));
            }
                        
            System.out.println("Case #" + (i + 1) + ": " + lowestNum(basesInt));
        }
    }
}
