import java.util.*;
import java.io.*;
import java.math.*;
import javax.script.*;
import java.awt.*;

public class C {

	public static void main(String[] args) throws Exception {
		Scanner sc=new Scanner(new File("C-small-attempt1.in"));
		int size=sc.nextInt();
		for(int w=0;w<size;w++)
		{
			double comb=sc.nextInt();
			double pack=sc.nextInt();
			int tot=0;
			
			double cur=pack;
			double packs=1;
			while(cur<comb)
			{
				for(int x=0;x<pack;x++)
				{
					cur+=1/comb;
					packs+=1/pack;
				
					if(cur>=comb)break;
				}
			}
			System.out.println("Case #"+(w+1)+": "+packs);
			
		}
	}
}
