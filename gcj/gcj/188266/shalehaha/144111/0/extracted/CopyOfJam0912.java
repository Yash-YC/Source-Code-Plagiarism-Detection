import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class CopyOfJam0912 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int cases = scanner.nextInt();
		for (int i = 0; i < cases; i++) {
			int rows = scanner.nextInt();
			int cols = scanner.nextInt();
			int[][][] array = new int[rows][cols][3];
			int[][][] timeArray = new int[rows][cols][4];
			for (int j = 0; j < rows; j++) {
				for (int k = 0; k < cols; k++) {
					array[j][k][0] = scanner.nextInt();
					array[j][k][1] = scanner.nextInt();
					array[j][k][2] = array[j][k][0] + array[j][k][1]
							- scanner.nextInt()
							% (array[j][k][0] + array[j][k][1]);
				}
			}
			timeArray[rows - 1][0][0] = 0;
			for (int j = rows - 1; j >= 0; j--) {
				for (int k = 0; k < cols; k++) {
					int one = 0, two = 0,wait=0;
					if (j < rows - 1)
						one = timeArray[j + 1][k][3] + 2;
					else{
						one=Integer.MAX_VALUE;
					}
					if (k > 0)
						two = timeArray[j][k - 1][1] + 2;
					else{
						two=Integer.MAX_VALUE;
					}
					if(!(j==rows - 1&&k==0))
						timeArray[j][k][0] = one > two ? two : one;

					one = 0;
					two = 0;
					if (j < rows - 1) {
						one = timeArray[j + 1][k][2] + 2;
					}else{
						one=Integer.MAX_VALUE;
					}

					 wait = (timeArray[j][k][0] + array[j][k][2])
							% (array[j][k][0] + array[j][k][1]);
					if (wait >= array[j][k][0]) {
						two = timeArray[j][k][0] + 1;
					} else {
						two = timeArray[j][k][0] + array[j][k][0] - wait
								+ 1;
					}
					timeArray[j][k][1] = one > two ? two : one;

					
					
					one = 0;
					two = 0;
					
					if(k>0)
						two = timeArray[j][k - 1][2] + 2;
					else{
						two=Integer.MAX_VALUE;
					}
					if (wait < array[j][k][0]) {
						one = timeArray[j][k][0] + 1;
					}else{
						one=timeArray[j][k][0]+array[j][k][0]+array[j][k][1]-wait+1;
					}
					
					timeArray[j][k][3] = one > two ? two : one;
					
					
					one = 0;
					two = 0;
					
					 wait = (timeArray[j][k][1] + array[j][k][2])
						% (array[j][k][0] + array[j][k][1]);
					 if (wait < array[j][k][0]) {
							one = timeArray[j][k][1] + 1;
						}else{
							one=timeArray[j][k][1]+array[j][k][0]+array[j][k][1]-wait+1;
						}
					 
					 wait = (timeArray[j][k][3] + array[j][k][2])
						% (array[j][k][0] + array[j][k][1]);
					 
					 if (wait >= array[j][k][0]) {
							two = timeArray[j][k][3] + 1;
						} else {
							two = timeArray[j][k][3] + array[j][k][0] - wait
									+ 1;
						}
					 timeArray[j][k][2] = one > two ? two : one;
					
					
				}
			}
			System.out.println(timeArray[0][cols-1][2]);
		}
	}
}
