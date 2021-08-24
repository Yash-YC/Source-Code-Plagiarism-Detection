import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.IOException;


public class LastWord{
    public static String solve(String s){
        if(s.length() == 0){
            return s;
        }
        String res = "";
        char first = s.charAt(0);
        res += first;
        for(int i = 1; i < s.length(); i++){
            if(s.charAt(i) < first){
                res = res + s.charAt(i);
            }else{
                res = s.charAt(i) + res;
                first = s.charAt(i);
            }
        }
        return res;
    }

    public static void main(String[] arges){
        try{
            File inputFile = new File("A-large.in");
            FileInputStream streamin = new FileInputStream(inputFile);
            BufferedReader br = new BufferedReader(new InputStreamReader(streamin));
            String line = br.readLine();
            int numTests = Integer.parseInt(line);
            int testNum = 0;
            File outputFile = new File("A-solution-large.txt");
            PrintWriter writer = new PrintWriter(outputFile);
            while ((line = br.readLine()) != null){
                testNum++;
                String s = line;
                String res = solve(s);
                String out;
                out = "Case #" + testNum + ": " + res;
                writer.println(out);
            }
            writer.close();
        }catch (IOException e){
            System.out.println("IOException");
        }
    }
}
