import java.util.*;
import java.io.*;

public class ProblemMain {
    
    public static void solution(int i_test, long n)
    {
        // solution:
        HashSet <Long> digits_unseen = new HashSet<Long>();
        for( long i_digit=0; i_digit <= 9; i_digit++ )
        {
            digits_unseen.add(i_digit);
        }

        if( n == 0 )
        {
            System.out.println("Case #" + i_test + ": INSOMNIA");
            return;
        }
        
        long i_multiplier = 1;
        long next_value = 0;
        while(digits_unseen.size() > 0)
        {
            next_value = n*i_multiplier;
            i_multiplier++;
            long next_value_digits = next_value;
            // check digits in next_value
            do
            {
                long digit = next_value_digits % 10;
                
                digits_unseen.remove(digit);
                
                if( digits_unseen.isEmpty() )
                {
                    break;
                }
                
                next_value_digits /= 10;
            }
            while(next_value_digits > 0);
            
        }
        System.out.println("Case #" + i_test + ": " + (next_value) );
    }

    public static void main(String[] args) {
        try {
//            System.setIn(new FileInputStream("sample.txt"));
            System.setIn(new FileInputStream("A-small-attempt0.in"));
//            System.setIn(new FileInputStream("A-large.in"));
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int test_cases = in.nextInt(); // Scanner has functions to read ints,
                                       // longs, strings, chars, etc.
        
        // test code
//        for( int i_test_code = 1; i_test_code <= 200; i_test_code++ )
//        {
//            solution(i_test_code, i_test_code);
//        }
//        
//      
        in.nextLine();
        // actual code
        for (int i_test = 1; i_test <= test_cases; ++i_test) {
            String s_string = in.nextLine().trim();
            
            StringBuffer result = new StringBuffer();
            // algo - if next letter is bigger than cur first letter, put first, 
            //        otherwise put last
            int max_first_letter_value = -1;

            for( int i_letter = 0; i_letter < s_string.length(); i_letter++ )
            {
                char next_char = s_string.charAt(i_letter);
                int next_char_value = next_char - 'A';
                if( next_char_value >= max_first_letter_value )
                {
                    result.insert(0, next_char);
                    max_first_letter_value = next_char_value;
                }
                else
                {
                    result.append(next_char);
                }
            }
            
            //solution(i_test, n);
            System.out.println("Case #" + i_test + ": " + (result) );
        }

        in.close();
    }

}
