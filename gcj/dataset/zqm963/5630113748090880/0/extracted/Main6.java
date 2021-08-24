import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main6 {
	private void Argus(int times, int total , int[] input) {
		int[] ans = new int[times];
		Set<Integer> set = new HashSet<Integer>();
		for (int i = 0; i < input.length; i++) {
			if(set.contains(input[i])){
				set.remove(input[i]);
			}else{
				set.add(input[i]);
			}
		}
		int t = 0;
		for(int s : set){
			ans[t] = s;
			t++;
		}
		Arrays.sort(ans);
		for (int i = 0; i < ans.length; i++) {
			System.out.print(ans[i]);
			System.out.print(" ");
		}
	}

	public static void main(String[] args) {
		Main6 m = new Main6();
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(
				System.in)));
		int t = in.nextInt(); // Scanner has functions to read ints, longs,
								// strings, chars, etc.
		for (int i = 1; i <= t; ++i) {
			int times = in.nextInt();
			int total = 2*times*times-times;
			int[] input = new int[total];
			for (int j = 0; j < total; j++) {
				input[j] = in.nextInt();
			}
			System.out.print("Case #" + i + ": ");
			m.Argus(times, total, input);
			System.out.println();
		}
	}
}