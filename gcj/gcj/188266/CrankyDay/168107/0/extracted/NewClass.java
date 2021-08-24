
package codejam;

import java.io.*;
import java.util.*;

public class NewClass {

    public static void main (String[] args) throws IOException {

        int range = 1000000;

        Scanner in = new Scanner(new File("A-small.in"));
        FileOutputStream out = new FileOutputStream(new File("blah.txt"));

        int[][] happy = new int[11][range];

        Arrays.fill(happy[2], 1);

        for(int b = 3; b < 11; b++)
        {
            happy[b][1] = 1;

            for(int x  = 1; x < range; x++)
            {
                if(happy[b][x] == 0)
                {
                    ArrayList<Integer> cycle = new ArrayList<Integer>();
                    cycle.add(x);
                    int y = check(x,b);
                    while(happy[b][y] == 0 && !cycle.contains(y))
                    {
                        cycle.add(y);
                        y = check(y,b);
                    }
                    if(happy[b][y] == 1)
                    {
                        for(int i = 0; i < cycle.size(); i++)
                        {
                            happy[b][cycle.get(i).intValue()] = 1;
                        }
                    }
                    else
                    {
                        for(int i = 0; i < cycle.size(); i++)
                        {
                            happy[b][cycle.get(i).intValue()] = -1;
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
            
            for(int x = 2; x < range; x++)
            {
                boolean good = true;
                for(int b = 3; good && b < 11; b++)
                {
                    if(on[b] && happy[b][x] < 0)
                    {
                        good = false;
                        break;
                    }

                }
                if(good)
                {
                    System.out.println("Case #"+t+": "+x);
                    break;
                }
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
