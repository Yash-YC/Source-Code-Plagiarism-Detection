import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

public class Problem1 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static Map<String, Boolean> happy = new HashMap<String, Boolean>();

    List<Integer> basesList = new ArrayList<Integer>();

    public void solve(int caseId) throws Exception {

        String line = br.readLine();
        String exploded[] = line.split(" ");

        for (String e : exploded) {
            Integer i = Integer.parseInt(e);
            basesList.add(i);
        }

        Integer happyNumber = 1;
        for (int i = 2; i < 1000000; i++) {
            if (isHappyInAllBases(i)) {
                happyNumber = i;
                break;
            }
        }

        System.out.println(String.format("Case #%d: %d", caseId, happyNumber));


    }

    private boolean isHappyInAllBases(int i) {

        for (Integer base : basesList) {
            if (!isHappy(i, base, new ArrayList<Integer>())) {
                return false;
            }
        }

        return true;
    }


    private boolean isHappy(Integer number, Integer base, List<Integer> tail) {

        String key = "" + number + "," + base;

        if (happy.containsKey(key)) {
            return happy.get(key);
        }

        String str = Integer.toString(number, base);

        int newNumber = 0;

        for (char c : str.toCharArray()) {
            int i = Integer.parseInt("" + c, base);
            newNumber += i * i;
        }
       
        if (newNumber == 1) {
            happy.put(key, Boolean.TRUE);
            return true;
        }

        if (newNumber == 0 || tail.contains(newNumber)) {
            happy.put(key, Boolean.FALSE);
            return false;
        }

        tail.add(newNumber);
        return isHappy(newNumber, base, tail);

    }


    public static void main(String[] args) throws Exception {

        String line = br.readLine();
        Integer t = Integer.parseInt(line);

        for (int i = 1; i <= t; i++)
            new Problem1().solve(i);


          //  System.out.println(new Problem1().isHappy(3, 2, new ArrayList<Integer>()));

    }

}
