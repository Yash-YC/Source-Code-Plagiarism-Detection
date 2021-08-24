import java.util.*;
import java.io.*;
import java.math.*;
import javax.script.*;
import java.awt.*;

public class A {

	public static void main(String[] args) throws Exception {
		Scanner sc=new Scanner(new File("A-small-attempt1.in"));
		int size=sc.nextInt();sc.nextLine();
		for(int w=0;w<size;w++)
		{
			String str=sc.nextLine();
			String[] li=str.split(" ");
			ArrayList<Integer> i=new ArrayList<Integer>();
			for(String s:li)i.add(Integer.parseInt(s));
			
			int num=2;

			while(true)
			{
				//System.out.println(Arrays.toString(li));
				boolean yes=true;
				for(String s:li)
					if(!isHappy(num+"",Integer.parseInt(s),0))
					{
						yes=false;
						break;
					}
				if(yes)break;
				num++;
				//System.out.println(num);
			}
			System.out.println("Case #"+(w+1)+": "+num);
		}
	}
	public static boolean isHappy(String num,int base, int count)
	{
		if(count==10)return false;
		
		String a=Integer.toString(Integer.parseInt(num), base);

		int occ=0;
		int others=0;
		for(int w=0;w<a.length();w++)
			if(a.charAt(w)=='1')occ++;
			else if(a.charAt(w)!='0')others++;
		
		if(occ==1 && others==0)return true;
		
		
		String s=a+"";

		int tot=0;
		for(int x=0;x<s.length();x++)
			tot+=Math.pow(Integer.parseInt(s.charAt(x)+""), 2);
		return isHappy(tot+"",base,count+1);
	}
}
