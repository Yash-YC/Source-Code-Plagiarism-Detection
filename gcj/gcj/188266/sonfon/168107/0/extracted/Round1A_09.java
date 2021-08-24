import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.*;

public class Round1A_09
{
	public void process(String srcfile, String targetfile)
	{
		try{
//			ArrayList<String> language=new ArrayList<String>();
			BufferedReader reader=new BufferedReader(new 
					InputStreamReader(new FileInputStream(srcfile), "utf-8"));
			BufferedWriter out = new BufferedWriter(new FileWriter(targetfile));
			
			Scanner sc = new Scanner(reader);
			String line=sc.nextLine();;
			int N = Integer.parseInt(line); //number of testcases
			for(int i=0; i<N; i++)
			{
				//load bases
				line = sc.nextLine();
				String[] split= line.split("\\s+");
				int[] base=new int[split.length];
				for(int j=0; j<split.length; j++)
				{
					base[j]=Integer.parseInt(split[j]);
				}
				//find 
				int happy=2;
				String target="0123456789";
				while(true)
				{
					int k=0;
					for( ; k<base.length; k++)
					{
						String basestr="";
						for(int j=0; j<base[k]; j++)
							basestr+=j;
						String str = AlienNumber.convertor(Integer.toString(happy), target, basestr );
						boolean r=testhappy(str, new ArrayList<String>(), base[k]);
						if(!r)
							break;
					}
					if(k==base.length)
					{
						break;
					}
					happy++;
				}
				out.write("Case #"+(i+1)+": "+happy+"\r\n");
			}
			out.close();
			reader.close();
			
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	public boolean testhappy(String src,ArrayList<String> mid, int base)
	{
		mid.add(src);
		String target="0123456789";
		String basestr="";
		for(int j=0; j<base; j++)
			basestr+=j;
		while(true)
		{
			char[]ch=src.toCharArray();
			int r=0;
			for(int i=0; i<ch.length; i++)
			{
				int t=ch[i]-'0';
				r+=t*t;
			}
			if(r==1) return true;
			else
			{
				String str = AlienNumber.convertor(Integer.toString(r), target, basestr);
				if(mid.contains(str))
					return false;
				return testhappy(str, mid, base);
			}
		}

	}
	public static void main(String[]args)
	{
		String indir="I:\\dataSet\\gcj\\";
		new Round1A_09().process(indir+"A-small-attempt0.in", indir+"result.in");
	}
}
