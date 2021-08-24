import java.io.*;
import java.util.*;

public class Round1A
{
	protected BufferedWriter out;
	protected BufferedReader in;
	protected int testCaseNumber; // Number of testcase
	protected ArrayList happyNumber[];
	
	protected Round1A(String input, String output)
	{
		long start = System.currentTimeMillis();
		setInputFile(input);
		setOutputFile(output);
		solve();
		System.out.println((System.currentTimeMillis() - start)/60000);
	}
	
	/**
	 * Solve all the testcase
	 */
	protected void solve()
	{
		try
		{
			happyNumber = new ArrayList[11];
			for(int i=0; i<11; i++)
			{
				happyNumber[i] = new ArrayList<Integer>();
				happyNumber[i].add(0);
				happyNumber[i].add(0); //for index 0 and 1.
			}
			testCaseNumber = Integer.parseInt(in.readLine());
			for (int i=0; i<testCaseNumber; i++)
			{
				readTestCase();
				calculateTestCase();
				writeSolution(i + 1);
			}
		}
		catch (Exception ex)
		{
			System.out.println(ex);
		}
	}

	/**
	 * Set the output file for the result
	 * @param fileName file path and name
	 */
	protected void setOutputFile(String fileName)
	{
		try
		{
			out = new BufferedWriter (new OutputStreamWriter (new FileOutputStream(fileName)));
		}
		catch (Exception ex)
		{
			System.out.println(ex);
		}
	}
	
	/**
	 * Set the input file for the test cases
	 * @param fileName file path and name
	 */
	protected void setInputFile(String fileName)
	{
		try
		{
			in = new BufferedReader(new InputStreamReader(new FileInputStream(fileName)));
		}
		catch (Exception ex)
		{
			System.out.println(ex);
		}
	}
	
	/**
	 * Write a String to the output file
	 * @param content String
	 */
	protected void write(String content)
	{
		try
		{
			out.write(content,0,content.length());
			out.flush();
		}
		catch (Exception ex)
		{
			System.out.println(ex);
		}
	}


/****************************
 * Customisation Start Here *
 ****************************/
	public int[] bases;
	public int xnumber;
	
	/**
	 * process a test case input
	 */
	public void readTestCase()
	{
		try
		{
			String line[] = in.readLine().split(" ");
			bases = new int[line.length];
			for(int i=0; i<line.length; i++)
			{
				bases[i] = Integer.parseInt(line[i]);
			}
		}
		catch (Exception ex)
		{
			ex.printStackTrace();
		}
	}

	/**
	 * calculate the result for the test case
	 */
	public void calculateTestCase()
	{
		int ctr = 2;
		xnumber = 0;
//		isHappyNumber(82,3);
		while (xnumber==0)
		{
			boolean stillHappy = true;
			for(int i = 0; i<bases.length && stillHappy; i++)
			{
				stillHappy = isHappyNumber(ctr,bases[i]);
			}
			if (stillHappy)
				xnumber = ctr;
			else
				ctr++;
		}
		// Calculation Here */
	}
	
	
	public boolean isHappyNumber(int startNumber, int base)
	{
		while(startNumber >= happyNumber[base].size())
			happyNumber[base].add(0);
		int flagNumber = (Integer)(happyNumber[base].get(startNumber)) ;
		if(flagNumber != 0)
		{
			return flagNumber==1;
		}
		else
		{
			try
			{
				ArrayList<Integer> checked = new ArrayList<Integer>(); // In Decimal
				int flag = 0; // 1 happy, -1 not;
				String startNumberString = Integer.toString(startNumber,base);
				int number = Integer.parseInt(startNumberString);
				checked.add(startNumber);
				while(flag==0)
				{
					String temp = number + "";
					int total = 0;
					for(int i =0; i<temp.length(); i++)
					{
						int anumber = Integer.parseInt(temp.charAt(i) + "");
						total += anumber * anumber;
					}
					if (total == 1)
					{
						flag =1;
						break;
					}
					else
					{
						String totalString = Integer.toString(total, base);
						if (checked.contains(total))
						{
							flag=-1;
						}
						else
						{
							number = Integer.parseInt(totalString);
							checked.add(total);
						}
					}
				}
				
				if (flag == -1)
				{
					for(int tempNumber : checked)
					{
						while(tempNumber >= happyNumber[base].size())
							happyNumber[base].add(0);
						happyNumber[base].set(tempNumber, new Integer(-1));
					}
				}
				else
				{
					for(int tempNumber : checked)
					{
						while(tempNumber >= happyNumber[base].size())
							happyNumber[base].add(0);
						happyNumber[base].set(tempNumber, new Integer(1));
					}
				}
				return (flag==1);
			}
			catch (Exception ex)
			{
				return false;
			}
		}
	}
	
	/**
	 * write the result for the test case to file
	 * @param currentTestCase n-Th test case
	 */
	public void writeSolution(int currentTestCase) throws IOException
	{
		out.write("Case #" + currentTestCase + ": " + xnumber +"\n");
		out.flush();
	}	
	
	public static void main(String[] args)
	{
		new Round1A(args[0],args[1]);
	}
}

class CustomString
{
	String value;
	CustomString(String b)
	{
		value = b;
	}
	
	public String getValue()
	{
		return value;
	}
	
	public int compareTo(String b)
	{
		for(int i =0; i< 10; i++)
			if(value.split(i + "").length != b.split(i + "").length)
				return -1;
		return 0;
	}
}