import java.util.*;
import java.io.*;
public class bases
{
    static int digitSquareSum(int i, int base)
    {
        int sum = 0;
        while(i >0)
        {
            int lastDigit = i % base;
            sum += lastDigit*lastDigit;
            i /= base;
        }
        return sum;
    }
    static boolean works(int val, int base)
    {
        HashSet<Integer> visited = new HashSet<Integer>();
        while(!visited.contains(val))
        {
            if(val == 1)
            {
                 return true;
            }
            visited.add(val);
            val = digitSquareSum(val, base);
        }
        return false;
    }
    static void doStuff(int[] bases, int prob)
    {
        int i = 2;
        while(true)
        {
			boolean good = true;
            for(int j = 0; j < bases.length && good; j++)
            {
                if(!works(i, bases[j]))
                {
                    good = false;
                }
            }
			if(good)
			{
				System.out.println("Case #"+prob+": "+i);
				return;
			}
            i++;
        }
    }
    public static void main(String[] args) throws java.io.IOException
    {
        BufferedReader bin = new BufferedReader(new InputStreamReader(System.in));
        int numCases = Integer.parseInt(bin.readLine());
        for(int prob = 1; prob <= numCases; prob++)
        {
            String[] nums = bin.readLine().split(" ");
            int[] bases = new int[nums.length];
            for(int i =0; i < nums.length; i++)
                bases[i] = Integer.parseInt(nums[i]);
            doStuff(bases, prob);
        }
    }
}