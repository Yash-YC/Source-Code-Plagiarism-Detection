package Round1A;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Crossing {
	static int[][] s;
	static int[][] w;
	static int[][] t;

	public static int getNextGreen(int x, int y, int current_time, boolean vertical) {
		if (vertical) {
			int green = t[x][y]+((current_time - t[x][y]) / (s[x][y] + w[x][y])) * (s[x][y] + w[x][y]);
			if (current_time < t[x][y]) {
				return t[x][y];
			} else if (green + s[x][y] > current_time) {
				return current_time;
			} else {
				return green+s[x][y]+w[x][y];
			}
		} else {
			int green = t[x][y]+((current_time - t[x][y]) / (s[x][y] + w[x][y])) * (s[x][y] + w[x][y]);
			if (current_time < t[x][y]) {
				return current_time;
			} else if (green + s[x][y] > current_time) {
				return green + s[x][y];
			} else if (green+s[x][y]+w[x][y] > current_time) {
				return current_time;
			} else {
				Object o = null;
				o.equals(null);
				return 0;
			}
		}
	}

	public static void main(String [] args) {
		try {
			BufferedReader r = new BufferedReader(new FileReader(new File("C:\\B-small-attempt2.in")));
			BufferedWriter writer = new BufferedWriter(new FileWriter(new File("c:\\B-small.out")));

			int c = Integer.parseInt(r.readLine());

			for (int x = 0; x < c; ++x) {
				String [] str = r.readLine().split(" ");
				int n = Integer.parseInt(str[0]);
				int m = Integer.parseInt(str[1]);

				s = new int [n][m];
				w = new int [n][m];
				t = new int [n][m];
				for (int y = 0; y < n; ++y) {
					String[] line = r.readLine().split(" ");

					for (int z = 0; z < m; ++z) {
						s[y][z] = Integer.parseInt(line[z*3]);
						w[y][z] = Integer.parseInt(line[z*3+1]);
						t[y][z] = Integer.parseInt(line[z*3+2]) % (w[y][z] + s[y][z]);
					}
				}

				int [][] min_times = new int[n*2][m*2];
				for (int xpos = 0; xpos < n*2; ++xpos) {
					for (int ypos = 0; ypos < m*2; ++ ypos) {
						min_times[xpos][ypos] = -1;
					}
				}
				min_times[n*2-1][0] = 0;

				boolean changed = true;
				while (changed) {
					changed = false;
					for (int xpos = 0; xpos < n*2; ++xpos) {
						for (int ypos = 0; ypos < m*2; ++ ypos) {
							if (min_times[xpos][ypos] != -1) {
								if (xpos != 0) {
									if (xpos % 2 == 0) {
										if ((min_times[xpos-1][ypos] == -1) || (min_times[xpos][ypos] + 2 < min_times[xpos-1][ypos])) {
											min_times[xpos-1][ypos] = min_times[xpos][ypos] + 2;
											changed = true;
										}
									} else {
										int green = getNextGreen(xpos/2, ypos/2, min_times[xpos][ypos], true);

										if ((min_times[xpos-1][ypos] == -1) || (green + 1 < min_times[xpos-1][ypos])) {
											min_times[xpos-1][ypos] = green + 1;
											changed = true;
										}
									}
								} 

								if (xpos != n*2-1) {
									if (xpos % 2 == 1) {
										if ((min_times[xpos+1][ypos] == -1) || (min_times[xpos][ypos] + 2 < min_times[xpos+1][ypos])) {
											min_times[xpos+1][ypos] = min_times[xpos][ypos] + 2;
											changed = true;
										}
									} else {
										int green = getNextGreen(xpos/2, ypos/2, min_times[xpos][ypos], true);

										if ((min_times[xpos+1][ypos] == -1) || (green + 1 < min_times[xpos+1][ypos])) {
											min_times[xpos+1][ypos] = green + 1;
											changed = true;
										}
									}
								} 

								if (ypos != 0) {
									if (ypos % 2 == 0) {
										if ((min_times[xpos][ypos-1] == -1) || (min_times[xpos][ypos] + 2 < min_times[xpos][ypos-1])) {
											min_times[xpos][ypos-1] = min_times[xpos][ypos] + 2;
											changed = true;
										}
									} else {
										int green = getNextGreen(xpos/2, ypos/2, min_times[xpos][ypos], false);

										if ((min_times[xpos][ypos-1] == -1) || (green + 1 < min_times[xpos][ypos-1])) {
											min_times[xpos][ypos-1] = green + 1;
											changed = true;
										}
									}
								} 

								if (ypos != m*2-1) {
									if (ypos % 2 == 1) {
										if ((min_times[xpos][ypos+1] == -1) || (min_times[xpos][ypos] + 2 < min_times[xpos][ypos+1])) {
											min_times[xpos][ypos+1] = min_times[xpos][ypos] + 2;
											changed = true;
										}
									} else {
										int green = getNextGreen(xpos/2, ypos/2, min_times[xpos][ypos], false);

										if ((min_times[xpos][ypos+1] == -1) || (green + 1 < min_times[xpos][ypos+1])) {
											min_times[xpos][ypos+1] = green + 1;
											changed = true;
										}
									}
								}
							}
						}
					}
				}

				if (min_times[0][m*2-1] == 28) {
					//assert(false);
				}
				writer.write("Case #" + (x+1) + ": " + min_times[0][m*2-1] + "\n");
			}

			writer.flush();
			writer.close();
		} catch (IOException e) {
			System.err.println(e);
		}
	}
}
