
import java.io.*;


public class MultiBase {
            static int happy[][] = new int[12][100000];
            static int checked_to[] = new int[12];
        public static void main(String[] args) {
        try {
            FileReader inFR = new FileReader("multi_base.in");
            BufferedReader inBR = new BufferedReader(inFR);

            FileWriter outFR = new FileWriter("multi_base.out");
            BufferedWriter outBR = new BufferedWriter(outFR);

            int n = Integer.parseInt(inBR.readLine());
            
            for(int i=0; i<12; i++){
                checked_to[i] = 1;
                happy[i][1] = 1;
            }
            
            for(int t=0; t<n; t++){
                // Test case t
               String line = inBR.readLine();
               String[] nums = line.split(" ");
               int m = nums.length;
               int base[] = new int[m];
               for(int i=0; i<m; i++)
                   base[i] = Integer.parseInt(nums[i]);

               int d = 2;
               String res = "";
               while (true){
                   // check if d is the number
                   boolean all_happy = true;
                   for(int b=0; b<m; b++){
                       // check if it is in base b
                       if (is_happy(d, base[b])){
                           continue;
                       }
                       else{
                           all_happy = false;
                           break;
                       }
                   }
                   if (all_happy){
                       res = "" + d;
                       break;
                   }
                   else{
                       d++;
                   }
               }               
               outBR.write("Case #" + (t+1) + ": " + res);
               outBR.newLine();
            }

            inBR.close();
            inFR.close();
            outBR.close();
            outFR.close();

        }
        catch(Exception e){
            e.printStackTrace();
        }
    }


   public static String convert(int inputDec, int base)
   {
    if (inputDec !=0){
        return convert(inputDec/base,base) + (inputDec%base);
    }
    else
       return "0";
   }

    public static boolean is_happy(int dNumber, int base){
        if (happy[base][dNumber] == 1)
            return true;
        else
            if (happy[base][dNumber] == -1)
                return false;
            else{
                // not checked
                String s = convert(dNumber, base);
                int new_num = 0;
                for(int i=0; i<s.length(); i++){
                    int digit = Integer.parseInt("" + s.charAt(i));
                    new_num += digit*digit;
                }
                if (happy[base][dNumber] == 2){
                    happy[base][dNumber] = -1;
                    return false;
                }
                happy[base][dNumber] = 2;
                if (is_happy(new_num, base)){
                    happy[base][dNumber] = 1;
                    return true;
                }
                else
                {
                    happy[base][dNumber] = -1;
                    return false;
                }
                
            }
    }


}
