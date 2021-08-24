package gcjr1;

/**
 *
 * @author yiTaN!
 */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;

public class Main {

    public static boolean happyNum(String num, int radix)
    {
        int res;
        ArrayList searches = new ArrayList();
        do
        {
            res = 0;
            searches.add(num);
            int[] digits = new int[num.length()];

            for (int i=0; i < num.length(); i++)
            {
                digits[i] = Integer.parseInt(Character.toString(num.charAt(i)));
            }

            for (int i=0; i< digits.length; i++)
            {
                res += digits[i] * digits[i];
            }

            num = Integer.toString(res, radix);
            if (searches.contains(num)) break;
        } while (res > 1);

        return (res == 1);
    }

    public static boolean happyNumber(int num, int[] radix)
    {
        int i=0;
        for (; i < radix.length; i++)
        {
            if ( !happyNum(Integer.toString(num, radix[i]), radix[i]) ) break;
        }

        return (i >= radix.length);
    }

    public static void main(String[] args) {
          File input = null;
          File output = null;
          FileReader fr = null;
          BufferedReader br = null;
          FileWriter fw = null;
          BufferedWriter bw = null;

        try {
            input = new File ("input.in");
            fr = new FileReader (input);
            br = new BufferedReader(fr);

            output = new File ("output.out");
            fw = new FileWriter(output);
            bw = new BufferedWriter(fw);

            int numCases = Integer.parseInt(br.readLine());

            for (int count = 0; count < numCases; count++)
            {
                String line = br.readLine();
                
                String bases[] = line.split(" ");
                int[] radix = new int[bases.length];
                
                for (int i=0; i < bases.length; i++)
                    radix[i] = Integer.parseInt(bases[i]);

                boolean notFound = true;
                int num = 2;
                
                while (notFound)
                {
                    if (happyNumber(num, radix)) notFound = false;
                    else num++;
                }


                // Show output
                String out = String.format("Case #%d: %d\n", count+1, num);
                System.out.print(out);
                bw.write(out);
            }


          }

          catch(Exception e){
             e.printStackTrace();
          }finally{
             try{
                if( fr != null ){
                   fr.close();
                }
                if (fw != null){
                    bw.close();
                }
             }catch (Exception e2){
                e2.printStackTrace();
             }
          }
    }

}
