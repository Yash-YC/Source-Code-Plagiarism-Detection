import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class lastWord {
	public static void main(String[] args) throws IOException {
		FileWriter output = new FileWriter("D:\\Desktop\\jam\\word.txt");
		BufferedWriter buffOut = new BufferedWriter(output);
		BufferedReader reader = new BufferedReader(new FileReader("D:\\Desktop\\jam\\in.txt"));
		
		String line;
		String done = "";
		ArrayList<Character> last = new ArrayList<>();
		char[] chList;
		line = reader.readLine();
		int caseNum = 0;
		
		while ((line = reader.readLine()) != null) {
			caseNum++;
			chList = line.toCharArray();
			last.add(chList[0]);
			
			for (int i = 1; i <chList.length;i++) {
				if (chList[i] >= last.get(0)) {
					last.add(0, chList[i]);
				}
				else {
					last.add(chList[i]);
				}
			}
			for (char ch : last) {
				done +=ch;
			}
			System.out.println(done);
			buffOut.write("Case #" + caseNum + ": ");
			buffOut.write(done);
			buffOut.newLine();
			last.clear();
			done = "";
		}
		reader.close();
		buffOut.close();
	}
}
