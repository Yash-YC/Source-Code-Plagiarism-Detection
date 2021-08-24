









package com;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.ArrayList;
public class test{
	static ArrayList<File> result = new ArrayList<File>();
public static void isFile(File file) {
	for(File f : file.listFiles()) {
		if (f.isDirectory()) {
			isFile(f);
		}

		if (f.isFile()) {
			result.add(f);
		}
	}

}
public static String getName(File file){
	File f1 = new File(file.getParent());
	File f2 = new File(f1.getParent());
	File f3 = new File(f2.getParent());
	File f4 = new File(f3.getParent());
	return f4.getName();
}
public static void main(String args[])throws Exception{
	isFile(new File("dataset"));
	for(int i=0;i<result.size();i++){
		String name = getName(result.get(i));
		FileInputStream fin = new FileInputStream(result.get(i));
		byte b[] = new byte[fin.available()];
		fin.read(b,0,b.length);
		fin.close();
		File temp = new File("train/"+name);
		if(!temp.exists())
			temp.mkdir();
		FileOutputStream fout = new FileOutputStream("train/"+name+"/"+result.get(i).getName());
		fout.write(b,0,b.length);
		fout.close();
	}
}
}