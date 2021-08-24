import java.io.*;
import java.util.*;

public class a1 {
	public static void main(String[] args) throws IOException {
		//Scanner sc = new Scanner (new File("test.in"));
		Scanner sc = new Scanner (new File("A-small-attempt0.in"));
		int xx = sc.nextInt();
		sc.nextLine();
		for(int yy = 0;yy<xx;yy++)
		{
			String s = sc.nextLine();
			Scanner ss = new Scanner(s);
			ArrayList<Integer> list = new ArrayList<Integer>();
			while(ss.hasNext())
			{
				list.add(ss.nextInt());
			}
			boolean found = false;
			int num = 1;
			while(!found)
			{
				num++;
				found = true;
				for(int i:list)
				{
					if(!happy(num,i,1))
					{
						found = false;
					}
				}
			}
			System.out.println("Case #" + (yy+1) + ": " + num);
		}
	}
	public static boolean happy(int num, int b, int count)
	{
		num = Integer.parseInt(Integer.toString(num,b));
		while(count<100)
		{
			int sum = 0;
			for(int i = 0;i<(""+num).length();i++)
			{
				sum+=Math.pow(Integer.parseInt((""+num).charAt(i)+""),2);
			}
			if(sum==1)
				return true;
			num = sum;
			num = Integer.parseInt(Integer.toString(num,b));
			count++;
		}
		return false;
	}
}