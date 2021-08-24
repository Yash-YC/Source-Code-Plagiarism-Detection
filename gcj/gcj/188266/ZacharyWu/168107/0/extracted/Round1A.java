package codejam2009;

import java.io.*;
import java.util.*;

public class Round1A {


	public static void main(String[] args) throws IOException{
		Scanner in = new Scanner(new FileReader("A.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"A.out")));
		int t = in.nextInt();
		in.nextLine();
		for (int caseNum = 1;caseNum<=t;caseNum++){
			String str = in.nextLine();
			String numstr[] = str.split(" ");
			int[] nums = new int[numstr.length];
			for (int i = 0; i<nums.length;i++){
				nums[i] = Integer.parseInt(numstr[i]);				
			}			
			int num = 2;
			boolean flag;
			do{
				flag = true;
				for (int i = 0; i<nums.length;i++){
					if (!isHappy(num,nums[i])){
						flag = false;
						break;
					}
				}
				if (!flag)
					num++;
			}while (!flag);
			out.write("Case #" + caseNum + ": " + num + "\n");
		}
		in.close();
		out.close();
	}

	public static ArrayList<Integer> getBase(int num, int base){
		ArrayList<Integer> array = new ArrayList<Integer>();
		int number= num;
		while (number >= base){
			array.add(number%base);
			number = number/base;
		}
		array.add(number);
		return array;
	}
	
	public static boolean isHappy(int num, int base){		
		ArrayList<Integer> array = getBase(num, base);
		int counts = 10;
		int count = 0;
		while (true){
			if (count > counts) break;
			int number = 0;
			for (Integer integer:array){
				number+=integer*integer;
			}
			array = getBase(number, base);
			count ++;
		}			
		if (array.size()>1)
			return false;
		return 1 == array.get(0);
	}
	
	public static boolean isEnd(ArrayList<Integer> list){
		return list.size() ==1;
	}
}
