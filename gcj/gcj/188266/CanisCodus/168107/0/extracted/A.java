import java.util.List;
import java.util.LinkedList;
import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int testCaseCount = Integer.parseInt(input.nextLine());
		for(int testCase=1; testCase <= testCaseCount; testCase++) {
			String[] bases = input.nextLine().split(" ");

			String result = "";
			for(int i=2; i < 100000; i++) {
				boolean numberIsHappy = true;

				for(int j=0; j < bases.length; j++) {
					int base = Integer.parseInt(bases[j]);

					List sums = new LinkedList();
					
					int num = i;
					while(num != 1) {
						int r = num % base;
						int a = num / base;
						int sum = r*r;
						while(a > 0) {
							r = a % base;
							a = a / base;
							sum += r*r;
						}
						
						if(sums.contains(sum)) {
							//we've already been here.
							break;
						}
						sums.add(Integer.valueOf(sum));
						
						num = sum;
					}
					
					if(num != 1) {
						numberIsHappy = false;
						break;
					}
				}

				if(numberIsHappy) {
					result += i;
					break;
				}
			}


			System.out.println("Case #"+testCase+": "+result);
		}
	}
}
