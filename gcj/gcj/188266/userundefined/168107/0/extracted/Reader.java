package ca.missine.utils;
import java.io.BufferedReader;
import java.io.IOException;


public class Reader {
	public static BufferedReader reader;
	
	public static final Integer getInteger() throws IOException {
		String s = reader.readLine();
		if(s == null) return null;
		return Integer.parseInt(s);
	}
	
	public static final String getLine() throws IOException {
		return reader.readLine();
	}
	
	public static final Integer getTimeInMinutes(String hoursMinutes) throws IOException {
		String s[] = hoursMinutes.split(":");
		return Integer.parseInt(s[0]) * 60 + Integer.parseInt(s[1]);
	}
}
