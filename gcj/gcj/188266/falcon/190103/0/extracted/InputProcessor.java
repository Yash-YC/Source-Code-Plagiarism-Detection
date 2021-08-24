

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class InputProcessor 
{
	private BufferedReader reader;
	public InputProcessor()
	{
		this.reader=new BufferedReader(new InputStreamReader(System.in));
	}
	public String getNextLine()
	{
		String ret=null;
		try
		{
			ret=reader.readLine();
		}
		catch(IOException ie)
		{
			ie.printStackTrace();
		}
		return ret;
	}
	public String[] getNextLines(int next)
	{
		String[] ret=new String[next];
		for(int i=0;i<next;++i)
		{
			ret[i]=getNextLine();
		}
		return ret;
	}
	public int getNextInteger()
	{
		String t=getNextLine();
		int ret=Integer.valueOf(t);
		return ret;
	}
	public long getNextLong()
	{
		String t=getNextLine();
		long ret=Long.valueOf(t);
		return ret;
	}
	public long[] getNextLongs(int next)
	{
		String[] t=getNextLines(next);
		long[] ret=new long[t.length];
		for(int i=0;i<ret.length;++i)
			ret[i]=Long.valueOf(t[i]);
		return ret;
	}
	public int[] getNextIntegers(int next)
	{
		String[] t=getNextLines(next);
		int[] ret=new int[t.length];
		for(int i=0;i<ret.length;++i)
			ret[i]=Integer.valueOf(t[i]);
		return ret;
	}
	public int[] getIntegers(String inpLine)
	{
		return getIntegers(inpLine," ");
	}
	public long[] getLongs(String inpLine)
	{
		return getLongs(inpLine," ");
	}
	public int[] getIntegers(String inpLine,String delim)
	{
		String[] tokens=inpLine.split(delim);
		int[] ret=new int[tokens.length];
		for(int i=0;i<ret.length;++i)
			ret[i]=Integer.valueOf(tokens[i]);
		return ret;
	}
	public long[] getLongs(String inpLine,String delim)
	{
		String[] tokens=inpLine.split(delim);
		long[] ret=new long[tokens.length];
		for(int i=0;i<ret.length;++i)
			ret[i]=Long.valueOf(tokens[i]);
		return ret;
	}	
	public void skip()
	{
		getNextLine();
		return;
	}
	public void output(int testCase,Object output)
	{
		System.out.println("Case #"+testCase+": "+output);
	}
}
