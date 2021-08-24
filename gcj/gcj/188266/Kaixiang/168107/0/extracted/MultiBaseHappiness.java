package com.CodeJam2009.A1;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Scanner;

public class MultiBaseHappiness
{
	private int total;
	private String[] sBases;
	private int[] iBases;
	private int iHappyNum;
	private boolean flag;

	public static void main(String[] args)
	{
		try
		{
			new MultiBaseHappiness();
		} catch (FileNotFoundException e)
		{
			e.printStackTrace();
		}
	}

	public MultiBaseHappiness() throws FileNotFoundException
	{
		Scanner in = new Scanner(new File("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new File("C-small.out"));
		total = in.nextInt();
		in.nextLine();
		for (int j = 0; j < total; j++)
		{
			sBases = in.nextLine().split(" ");
			iBases = new int[sBases.length];
			for (int i = 0; i < sBases.length; i++)
			{
				iBases[i] = Integer.parseInt(sBases[i]);
			}
			iHappyNum = 2;
			flag = true;
			while (true)
			{
				for (int i = 0; i < iBases.length; i++)
				{
					if (isHappy(iHappyNum, iBases[i]))
						continue;
					else
					{
						flag = false;
						break;
					}
				}
				if (flag)
				{
					out.println("Case #" + (j + 1) + ": " + iHappyNum);
					out.flush();
					break;
				} else
				{
					flag = true;
					iHappyNum++;
				}
			}
		}
	}

	private boolean isHappy(int HappyNum, int base)
	{
		LinkedList<Integer> happen = new LinkedList<Integer>();
		int repeat = Integer.parseInt(Integer.toString(HappyNum, base));
		boolean flag2;
		happen.add(new Integer(repeat));
		while (true)
		{
			flag2 = false;
			repeat = NextRepeat(repeat, base);
			if (repeat == 1)
				return true;
			for (Integer i : happen)
			{
				if (i.intValue() == repeat)
				{
					flag2 = true;
				}
				if (flag2)
					return false;
			}
			happen.addFirst(new Integer(repeat));
		}
	}

	private int NextRepeat(int happyNum, int base)
	{
		String baseNum;
		int sum = 0;
		baseNum = Integer.toString(happyNum);
		for (int i = 0; i < baseNum.length(); i++)
		{
			System.out.println(sum);
			int num = Integer.parseInt(baseNum.substring(i, i + 1));
			sum += num * num;
		}
		return Integer.parseInt(Integer.toString(sum, base));
	}
}
