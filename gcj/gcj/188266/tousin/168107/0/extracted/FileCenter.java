package Round1A.Num;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class FileCenter {
	public static InputData read(String path) throws IOException{
		InputData data = new InputData();
		
		File f = new File(path);
		FileReader fr = new FileReader(f);
		BufferedReader bfr = new BufferedReader(fr);
		
		String tmp = "";
		if((tmp = bfr.readLine()) != null){
			data.num = Integer.parseInt(tmp);
		}
		
		data.testcase = new TestCase[data.num];
		for(int n = 0 ; n < data.num ; n++){	
			data.testcase[n] = new TestCase();
			tmp = bfr.readLine();
			data.testcase[n].base = tmp.split(" ");
					
			System.out.println(data.testcase[n]);
		}
		
		bfr.close();
		fr.close();
		return data;
	}
	
	public static void write(String path,String data) throws IOException{
		File f = new File(path);
		FileWriter fw = new FileWriter(f);
		
		BufferedWriter bfw = new BufferedWriter(fw);	
		bfw.write(data);
		bfw.flush();
		bfw.close();
	}
}
