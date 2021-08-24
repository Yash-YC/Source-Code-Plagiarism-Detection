import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;


public class Test {
	
	public static int[] change(int num , int base){
		int result[] = new int[base];
		for(int i = 0 ; i < base ; i ++){
			result[i] = 0;
		}
		while(num != 0){
			int left = num % base;
			num = num / base;
			if(left != 0)
				result[left] ++;
		}
		return result;
	}
	
	public static int getNum(int[] list){
		int result = 0;
		for(int i = 0 ; i < list.length ; i ++){
			int tmp = list[i];
			result = result + i * i * tmp;
		}
		return result;
	}
	

	
	          
	public boolean check(int num , int base , HashSet<Integer> set , HashSet<Integer> bad){
		int tmp = num;
		int count = 0;
		while(true){
			count ++;
			if(set.contains(tmp) || bad.contains(tmp) || (tmp == num && count != 1))
				return false;
			bad.add(tmp);
			int[] digits = change(tmp , base);
		/*	if(set.contains(num)){
				return false;
			}
			set.add(num);*/
			tmp = getNum(digits);
			if(tmp == 1){
				return true;
			}
		}
	}
	
	public int test(int[] base){
		int num = 2;
		ArrayList<HashSet<Integer>> list = new ArrayList<HashSet<Integer>>();
		for(int i = 0 ; i < base.length ; i ++){
			list.add(new HashSet<Integer>());
		}
		
		while(true){
			System.out.println(num);
			if(num == 3){
				System.out.println(num);
			}
			boolean result = true;
			for(int i = base.length - 1 ; i >= 0 ; i --){
				HashSet<Integer> set = list.get(i);
				HashSet<Integer> tmp = new HashSet<Integer>();
				if(!check(num , base[i] , set , tmp)){
					result = false;
					set.addAll(tmp);
					break;
				}
			}
			if(result)
				return num;
			num ++;
		}
	}
	
	

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		/*System.out.println(change(3 , 3));
		Test test = new Test();
		int[] base = {5, 6 , 7 , 8 , 9, 10};
		int value = test.test(base);*/
		
		String input = "A-small-attempt0.in.txt";
		String output = "output.txt";
		Test test = new Test();
		try{
			BufferedReader reader = new BufferedReader(new FileReader(new File(input)));
			BufferedWriter writer = new BufferedWriter(new FileWriter(new File(output)));
			String line = reader.readLine();
			int id = Integer.parseInt(line);
			for(int i = 0 ; i < id ; i ++){
				line = reader.readLine();
				String[] tokens = line.split("[ \t]+");
				int[] bases = new int[tokens.length];
				for(int j = 0 ; j < tokens.length ; j ++){
					bases[j] = Integer.parseInt(tokens[j]);
				}
				int result = test.test(bases);
				writer.write("Case #" + (i+1) + ": " + result + "\r\n");
			}
			reader.close();
			writer.close();
		}catch(IOException e){
			e.printStackTrace();
		}

	}

}
