package pedestrian;

import java.io.BufferedReader;
import java.io.IOException;

abstract public class Solver {
	protected BufferedReader input;
	Solver(BufferedReader input_stream){
		input = input_stream;
	}
	
	abstract public String solve() throws Exception;
}
