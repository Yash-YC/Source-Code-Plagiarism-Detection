package questiona;

import java.io.File;

import java.io.FileWriter;
import java.io.PrintWriter;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class QuestionA {
    public QuestionA() {
        super();
    }

    public static void main(String[] args) {
        String inputFile = "A-small-attempt0.in";
        String outputFile = "output.txt";

        PrintWriter out = null;
        //System.out.println(convertToBase(64,4));
        

        try {
            // Create Scanner to read file
            Scanner scanner = new Scanner(new File(inputFile));

            // Create PrintWriter to write file
            out = new PrintWriter(new FileWriter(outputFile));

            // Get number of test cases from first line
            int testCaseCount = scanner.nextInt();
            System.out.println("Test Cases:" + testCaseCount);

            scanner.nextLine();

            for (int i = 0; i < testCaseCount; i++) {
                String line = scanner.nextLine();
                
                int[] bases = new int[3];
                Scanner lineScanner = new Scanner(line);
                
                int x = 0;
                while(lineScanner.hasNextInt()) {
                    bases[x] = lineScanner.nextInt();
                    x++;
                }
                
                
                int num = 1;
                
                while(true){
                    boolean result = false;
                    int temp ;
                    num++;
                    for (int j = 0; j < x; j++) {
                        temp = convertToBase(num, bases[j]);
                           
                        if(!isHappy(temp, new HashSet<Integer>(), bases[j])){
                            result = false;
                            break;
                        }
                        
                        result = true;
                    }
                    
                    if(result){
                        break;
                    }
                    
                    
                }
                



                out.println("Case #" + (i + 1) + ": " + num);
            }


        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (out != null) {
                out.close();
            }
        }
    }
    
    public static boolean isHappy(int x, Set<Integer> used, int base){
        
        int sum = 0;
        if(x == 1){
            return true;
        }
        
        int digit;
        while(x>0){
            digit = x%10;
            
            sum += (digit*digit);
            
            x /= 10;
        }
        
        sum = convertToBase(sum, base);
        
        if(sum == 1){
            return true;
        }else{
            if(used.contains(sum)){
                return false;
            }else{
                used.add(sum);
                return isHappy(sum, used, base);
            }
        }
        
    }
    
    public static int convertToBase(int x, int base){
        
        int originalBase = base;
        int current = 1;
        while(x >= base){
            
            base *= originalBase;
            current++;
        }
        
        base /= originalBase;
        
        
        int converted = 0;
        
        int digit = 0;
        
        while(current>0){
            converted *= 10;
            digit = x/base;
            
            x -= base *digit;
            base/=originalBase;
            converted += digit;
            
            
            current--;
        }
        
        return converted;
    }
    
}
