import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;



public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		String[] output = new String[T];
		for (int i = 0; i < T; i++){
			String word = br.readLine();
			String result = word.substring(0, 1);
			for (int c = 1; c < word.length(); c++){
				char front = result.charAt(0);
				if (word.charAt(c) >= front){
					result = word.charAt(c) + result;
				}
				else{
					result = result + word.charAt(c);
				}
			}
			output[i] = result;
		}
		
		for (int i = 0; i < T; i++){
			System.out.println("Case #" + (i + 1) + ": " + output[i]);
		}
	}
}
