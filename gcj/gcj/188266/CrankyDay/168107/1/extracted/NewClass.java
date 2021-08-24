
package codejam;

import java.io.*;
import java.util.*;

public class NewClass {

    public static void main (String[] args) throws IOException {

        int range = 200;

        Scanner in = new Scanner(new File("A-large.in"));
        FileOutputStream out = new FileOutputStream(new File("blah.txt"));

        int[][] happy = new int[8][range];

        for(int b = 3; b < 11; b++)
        {
            int o = b-3;
            happy[o][1] = 1;

            for(int x  = 1; x < range; x++)
            {
                if(happy[o][x] == 0)
                {
                    ArrayList<Integer> cycle = new ArrayList<Integer>();
                    cycle.add(x);
                    int y = check(x,b);
                    while(happy[o][y] == 0 && !cycle.contains(y))
                    {
                        cycle.add(y);
                        y = check(y,b);
                    }
                    if(happy[o][y] == 1)
                    {
                        for(int i = 0; i < cycle.size(); i++)
                        {
                            happy[o][cycle.get(i).intValue()] = 1;
                        }
                    }
                    else
                    {
                        for(int i = 0; i < cycle.size(); i++)
                        {
                            happy[o][cycle.get(i).intValue()] = -1;
                        }
                    }
                }
            }
        }

        int T = in.nextInt();
        in.nextLine();
        for(int t = 1; t <= T; t++)
        {
            String line = in.nextLine();
            Scanner parse = new Scanner(line);
            boolean[] on = new boolean[11];

            while(parse.hasNextInt())
            {
                int b = parse.nextInt();
                on[b] = true;
            }

            boolean found = false;
            int x = 2;
            while(!found)
            {
                boolean good = true;
                for(int b = 3; good && b < 11; b++)
                {
                    if(on[b]) //&& happy[b-3][x] < 0)
                    {
                        int y = x;
                        while(y >= 200) y = check(y,b);

                        if(happy[b-3][y] < 0)
                        {
                            good = false;
                            break;
                        }
                    }
                }
                if(good)
                {
                    System.out.println("Case #"+t+": "+x);
                    found = true;
                }
                else x++;
            }
        }
    }

    public static int check(int x, int b)
    {
        int sum = (x%b)*(x%b);

        while((x = x/b) > 0)
        {
            sum += (x%b)*(x%b);
        }
        return sum;
    }

}
