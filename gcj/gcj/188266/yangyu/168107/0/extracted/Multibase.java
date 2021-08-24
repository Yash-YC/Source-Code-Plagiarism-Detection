/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Administrator
 */
import java.io.InputStream;
import java.util.Scanner;
import java.util.Vector;

public class Multibase {

    Vector<Input> inputs = new Vector<Input>();
    Vector<String> results = new Vector<String>();

    private void ABaseNum(Vector<Integer> vecseq, int basenum, int min) {
        do {
            vecseq.add(min%basenum);
            min = min/basenum;
        } while (min != 0); //

    }

    private boolean isHappy(int basenum, Input input, int j, int min) {
        Vector<Integer> vecseq = new Vector<Integer>();
        Vector<Integer> veccicle = new Vector<Integer>();
        
        int sum = 0;
        do {
            sum = 0;
            vecseq.clear();
            ABaseNum(vecseq, basenum,min);
            for (Integer num : vecseq) {
                sum += num * num;
            }
            if (sum == 1) {
                return true;
            } else {
                if (veccicle.contains(sum)) {
                    return false;
                }
                veccicle.add(sum);
                min = sum;
            }
        } while (sum != 1);
        return false;
    }

    class Input {

        Vector<Integer> vecbase = new Vector<Integer>();

        public Input() {
        }
    }

    public Multibase() {
        scan();
//    analisisy();
        getResult();
        output();
    }

    private void output() {
        for (String result : results) {

            System.out.println(result);
        }
    }

    public static void main(String[] args) {

        new Multibase();
    }

    private void getResult() {
        //analisis input to results
        for (int i = 0; i < inputs.size(); i++) {
            String result = "Case #";
            Input input = inputs.get(i);


            int size = input.vecbase.size();
            int min = input.vecbase.get(size - 1);
            do {
                int basenum = min;
                for (int j = 0; j < size; j++) {
                    if (!isHappy(input.vecbase.get(j), input, size - 1, min)) {
                        min++;
                    }

                }
                if (min == basenum) {
                    break;
                }
            } while (true);
            int number = i + 1;
            result = result + number + ": " + min;
            results.add(result);
        }
    }

    private void scan() {
        InputStream is = System.in;
        Scanner scan = new Scanner(is);
        int num = scan.nextInt();
        scan.nextLine();

        for (int i = 0; i < num; i++) {
            Input input = new Input();
            //input.turnaround = scan.nextInt();
            //scan.nextLine();
            //use scan
            //use collictions to do
            Integer vec[] = Tool.toInt(scan.nextLine().split(" "));
            input.vecbase = Tool.toVec(vec);
            inputs.add(input);
        }
    }
}