import java.util.Scanner;

/**
 * Created by Tor on 16.04.2016.
 */
public class LastWord {

    public static void main(String[] args) {
        new LastWord().go();
    }

    private void go() {
        Scanner s = new Scanner(System.in);
        int numCases = s.nextInt();

        for(int c=1;c<=numCases;c++) {
            String originalWord = s.next();

            String output = originalWord.charAt(0)+"";
            for(int i=1;i<originalWord.length();i++) {
                if((originalWord.charAt(i)+output).compareTo(output+originalWord.charAt(i)) < 0) {
                    output = output+originalWord.charAt(i);
                } else {
                    output = originalWord.charAt(i)+output;
                }
            }
            System.out.format("Case #%d: %s\n", c, output);
        }

    }
}
