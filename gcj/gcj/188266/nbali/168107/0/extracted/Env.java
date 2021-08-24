package google.code.jam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;

/**
 * @author NB4L1
 */
public final class Env
{
	public static BufferedReader init(boolean small) throws ClassNotFoundException, IOException
	{
		final Class<?> callerClazz = Class.forName(new Throwable().getStackTrace()[1].getClassName());
		
		final String folderName = "./data/" + callerClazz.getPackage().getName().replace('.', '/');
		
		final String fileName = folderName + '/' + callerClazz.getSimpleName() + (small ? "-small" : "-large");
		
		final String inputFileName = fileName + ".in";
		final String outputFileName = fileName + ".out";
		
		// creates the folder
		new File(folderName).mkdirs();
		
		// creates files if required
		new File(inputFileName).createNewFile();
		new File(outputFileName).createNewFile();
		
		// opens the input file to read
		BufferedReader br = new BufferedReader(new FileReader(inputFileName));
		
		// writes output to a file (for uploading), and to the console as well (to be visible during execution)
		System.setOut(new PrintStream(new OutputStream() {
			
			private final PrintStream _sysout = System.out;
			private final FileOutputStream _fos = new FileOutputStream(outputFileName);
			
			@Override
			public void flush() throws IOException
			{
				_sysout.flush();
				_fos.flush();
			}
			
			@Override
			public void write(int b) throws IOException
			{
				_sysout.write(b);
				_fos.write(b);
			}
		}));
		
		return br;
	}
}
