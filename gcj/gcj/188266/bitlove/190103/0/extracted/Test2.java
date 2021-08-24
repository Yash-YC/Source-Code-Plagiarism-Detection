import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Test2 {
	
	public static double test(int n , int c){
		
		int num = 0;
		int N = 100000;
		for(int i = 0 ; i < N; i ++){
			boolean tags[] = new boolean[n];
			for(int j = 0 ; j < n ; j ++){
				tags[j] = false;
			}
			
			while(true){
				num = num + 1;
				for(int j = 0 ; j < c ; j ++){
					int r = (int)(Math.random() * (double)n) ;
					tags[r] = true;
				}
				boolean match = true;
				for(int j = 0 ; j < n ; j ++){
					if(!tags[j]){
						match = false;
						break;
					}
				}
				if(match)
					break;
			}
		}
		
		System.out.println(num);
		double num2 = (double)num / (double)N;
		double left = num2 % 1;
		int tmp = (int) num2;
		
		if(left < 0.2)
			left = 0;
		else if(left > 0.8)
			left = 1.00000;
		else if(left >= 0.40 || left <= 0.5)
			left = 0.50000;
		else if(left >= 0.2 && left <= 0.3)
			left = 0.25000;
		else if(left >= 0.7 && left <= 0.8)
			left = 0.75000;
		else if(left > 3 && left < 0.4)
			left = 0.33333333333;
		else
			left = 0.6666666666667;
		num2 = (double)tmp + left;
		return num2;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		/*System.out.println(change(3 , 3));
		Test test = new Test();
		int[] base = {5, 6 , 7 , 8 , 9, 10};
		int value = test.test(base);*/
		
		System.out.println(test(3 , 2));
		
		
		String input = "C-small-attempt0.in.txt";
		String output = "output.txt";
		Test test = new Test();
		try{
			BufferedReader reader = new BufferedReader(new FileReader(new File(input)));
			BufferedWriter writer = new BufferedWriter(new FileWriter(new File(output)));
			String line = reader.readLine();
			int id = Integer.parseInt(line);
			for(int i = 0 ; i < id ; i ++){
				line = reader.readLine();
				String tokens[] = line.split("[ \t]+");
				int n = Integer.parseInt(tokens[0]);
				int c = Integer.parseInt(tokens[1]);
				writer.write("Case #" + (i+1) + ": " + test(n , c) + "\r\n");

			}
			reader.close();
			writer.close();
		}catch(IOException e){
			e.printStackTrace();
		}

	}

}
