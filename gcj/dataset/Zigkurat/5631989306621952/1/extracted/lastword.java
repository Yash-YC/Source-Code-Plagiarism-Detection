import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;

public class lastword{

    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

		boolean leftToRight = true;
		boolean rightToLeft = true;

		int count = in.nextInt();
		ArrayList<String> strings = new ArrayList<>();
		char[] s;

		for (int j= 0; j < count; j++) {
			s = in.next().toCharArray();
			String lastWord = "";

			lastWord = s[0] + "";
			for (int i = 1; i < s.length; i++) {
				if (s[i] <= lastWord.charAt(0)) {
					lastWord = s[i] + lastWord;
				} else {
					lastWord = lastWord + s[i];
				}
			}

			char[] ss = lastWord.toCharArray();
			for (int i = 1; i < ss.length; i++) {
				if (ss[i] < ss[i - 1]) {
					leftToRight = false;
					break;
				}
			}

			for (int i = 1; i < ss.length; i++) {
				if (ss[i] > ss[i - 1]) {
					rightToLeft = false;
					break;
				}
			}

			if (!(leftToRight || rightToLeft)) {
				lastWord = s[0] + "";
				for (int i = 1; i < s.length; i++) {
					if (s[i] >= lastWord.charAt(0)) {
						lastWord = s[i] + lastWord;
					} else {
						lastWord = lastWord + s[i];
					}
				}
			}
			strings.add(lastWord);
		}
		for (int i = 0; i < strings.size(); i++) {
			System.out.println("Case #" + (i+1) +": " + strings.get(i));
		}
	}
}
