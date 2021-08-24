import java.io.*;
import java.util.StringTokenizer;
import java.util.List;
import java.util.ArrayList;

/**
 * Created by IntelliJ IDEA.
 * User: vinoth
 * Date: Sep 12, 2009
 * Time: 6:31:14 AM
 * To change this template use File | Settings | File Templates.
 */
public class MultiBaseHappiness {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
//        BufferedReader reader = new BufferedReader(new FileReader("c:\\tmp\\input.txt"));
        StringTokenizer tokenizer = null;
        int numProblems = Integer.valueOf(reader.readLine());
        for(int i=0; i < numProblems; ++i){
            tokenizer = new StringTokenizer(reader.readLine()," ");
            int bases[] = new int[tokenizer.countTokens()];
            int j = 0;
            while(tokenizer.hasMoreTokens()){
                bases[j++] = Integer.valueOf(tokenizer.nextToken());
            }

            int number = 2;
            boolean flag = true;
            do{
                for(int k=0; k < bases.length; ++k){
                    if(isHappyNumber(number, bases[k])){
                        flag = true;
                        continue;
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
                number++;
            }while(flag != true);
            System.out.println("Case #" + (i+1) + ": " + (number-1));
        }
    }

    public static boolean isHappyNumber(long number, int radix){
        long sum = 0;
        String str = Integer.toString((int)number, radix);
        long currentsum = 0;
        List<Long> prevSums = new ArrayList<Long>();
        while(true){
            sum = 0;
            for(int j=0; j < str.length(); ++j){
                long lastDigit = (long) (str.charAt(j) - '0');
                sum += (lastDigit * lastDigit);
            }
            if(sum == 1)
                return true;
            if(prevSums.contains(sum)) return false;
            prevSums.add(sum);
            str = Integer.toString((int)sum, radix);
        }
    }
}
