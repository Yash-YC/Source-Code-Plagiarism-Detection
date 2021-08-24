import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class MultiBaseHappiness
{
    public static void main(String args[])
    {
	Scanner in = null;
	try
	{
	    in = new Scanner(new File("C:/Sandbox/JavaProjects/GoogleCodeJam/src/testCases/TestCasesMilkshake"));
	} catch (FileNotFoundException e)
	{
	    // TODO Auto-generated catch block
	    e.printStackTrace();
	}
	int numCases = in.nextInt();
	in.nextLine();
	for (int i = 0; i < numCases; i++)
	{
	    int ctr = 0;
	    String input = in.nextLine();
	    String[] t = input.split(" ");
	    int arr[] = new int[t.length];
	    int j = 0;
	    while (j < t.length)
	    {
		arr[j] = Integer.parseInt(t[j]);
		j++;
	    }
	    int a = 1;
	    while (true)
	    {
		a++;
		boolean found = false;
		for (int k = 0; k < j; k++)
		{
		    if (isHappy(a, arr[k]) == false)
		    {
			found = false;
			break;
		    } else
			found = true;
		}
		if (found == true)
		{
		    break;
		}
	    }
	    System.out.println("Case #" + (i + 1) + ": " + a);
	}
    }

    static String fromIntToBase(int n, int base)
    {
	String digits = "0123456789";
	String s = "";
	while (n > 0)
	{
	    int d = n % base;
	    s = digits.charAt(d) + s;
	    n = n / base;
	}
	return s;
    }

    static int fromBaseToInt(String s, int b)
    {
	int result = 0;
	int digit = 0;
	for (int i = 0; i < s.length(); i++)
	{
	    char c = s.charAt(i);
	    if (c >= '0' && c <= '9')
		digit = c - '0';
	    else if (c >= 'A' && c <= 'Z')
		digit = 10 + c - 'A';

	    if (digit < b)
		result = b * result + digit;
	}
	return result;
    }

    static boolean isHappy(int n, int base)
    {
	boolean result = false;
	ArrayList<String> nums = new ArrayList<String>();
	while (true)
	{
	    String temp = fromIntToBase(n, base);
	    if (nums.contains(temp))
	    {
		result = false;
		break;
	    } else
		nums.add(temp);
	    int sums = 0;
	    for (int i = 0; i < temp.length(); i++)
	    {
		sums = sums + (temp.charAt(i) - 48) * (temp.charAt(i) - 48);
	    }
	    if (sums == 1)
	    {
		result = true;
		break;
	    }
	    n = sums;
	}
	return result;
    }

}
