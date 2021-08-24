
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class LastWord {

	public static void main(String[] args) throws IOException {
		FileInputStream fstream = new FileInputStream("A-small-attempt0.in");
		BufferedReader br = new BufferedReader(new InputStreamReader(fstream));
		
		File fout = new File("out.txt");
		FileOutputStream fos = new FileOutputStream(fout);
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(fos));
		
		int count = Integer.parseInt(br.readLine());
		for (int i = 1; i <= count; i++) {
			String word = br.readLine();
			String answer = getLastWord(word);
			bw.write("Case #" + i + ": " + answer);
			bw.newLine();
		}
		br.close();
		bw.close();
	}
	private static String getLastWord(String word) {
		if (word.equals("")) {
			return "";
		}
		String result = "" + word.charAt(0);
		for (int i = 1; i < word.length(); i++) {
			char c = word.charAt(i);
			if (c < result.charAt(0)) {
				result = result + c;
			} else {
				result = c + result;
			}
		}
		return result;
	}
}
