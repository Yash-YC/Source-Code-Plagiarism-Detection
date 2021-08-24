import jam.JamIO;

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;


public class CrossingTheRoad {

	public static void main(String[] args) throws Exception {
		int C = JamIO.readNextInt();
		for (int i = 0; i < C; i++) {
			N = JamIO.readNextInt();
			M = JamIO.readNextInt();
			trafficLights = new TrafficLight[N][M];
			for (int n = 0; n < N; n++) {
				for (int m = 0; m < M; m++) {
					int S = JamIO.readNextInt();
					int W = JamIO.readNextInt();
					int T = JamIO.readNextInt();
					trafficLights[n][m] = new TrafficLight(S, W, T);
				}
			}
			times = new int[N][M][4];
			for (int n = 0; n < N; n++)
				for (int m = 0; m < M; m++)
					for (int x = 0; x < 4; x++) {
						times [n][m][x] = Integer.MAX_VALUE;
					}
			times[N-1][0][0] = 0;
			open = new LinkedList<Position>();
			open.add(new Position(N-1, 0, 0));
			while (! open.isEmpty()) {
				Collections.sort(open);
				Position current = open.remove(0);
				// System.out.println(current.debug());
				current.spread();
			}
			JamIO.printCase(i, times[0][M-1][3]);
		}
	}

	private static int N, M;
	private static List<Position> open;
	private static int[][][] times;
	private static TrafficLight[][] trafficLights;

	private static class TrafficLight {
		public TrafficLight(int s, int w, int t) {
			S = s;
			W = w;
			cycle = w+s;
			t %= cycle; t -= cycle;
			T = t;
		}
		public int S, W, T, cycle;
		public int getNextVerticalStep(int time) {
			int offset = (time - T) % cycle;
			if (offset < S)
				return time;
			else
				return time + (cycle - offset);
		}
		public int getNextHorizontalStep(int time) {
			int offset = (time - T) % cycle;
			if (offset < S)
				return time + (S - offset);
			else
				return time;
		}
	}

	private static class Position implements Comparable<Position> {

		public Position(int n, int m, int x) {
			this.n = n;
			this.m = m;
			this.x = x;
		}

		public int n, m, x;

		public String debug() {
			return n + "," + m + "," + x;
		}

		@Override
		public int compareTo(Position o) {
			return getTime() - o.getTime();
		}
	
		public int getTime() {
			return times[n][m][x];
		}

		public void spread() {
			// cross N-S
			{
				int newTime = trafficLights[n][m].getNextVerticalStep(getTime()) + 1;
				int newX = (x+2) % 4;
				int oldTime = times[n][m][newX];
				// System.out.println("can get to " + n + "," + m + "," + newX + " at " + newTime);
				if (newTime < oldTime) {
					times[n][m][newX] = newTime;
					if (oldTime == Integer.MAX_VALUE) {
						open.add(new Position(n, m, newX));
					}
				}
			}
			// cross W-E
			{
				int newTime = trafficLights[n][m].getNextHorizontalStep(getTime()) + 1;
				int newX = ((x%2) == 0) ? (x+1) : (x-1);
				int oldTime = times[n][m][newX];
				// ystem.out.println("can get to " + n + "," + m + "," + newX + " at " + newTime);
				if (newTime < oldTime) {
					times[n][m][newX] = newTime;
					if (oldTime == Integer.MAX_VALUE) {
						open.add(new Position(n, m, newX));
					}
				}
			}
			// block N-S
			{
				int newTime = getTime() + 2;
				int newX = (x+2) % 4;
				int newN = (x<=1) ? n+1 : n-1;
				if (newN >= 0 && newN < N) {
					int oldTime = times[newN][m][newX];
					// System.out.println("can get to " + newN + "," + m + "," + newX + " at " + newTime);
					if (newTime < oldTime) {
						times[newN][m][newX] = newTime;
						if (oldTime == Integer.MAX_VALUE) {
							open.add(new Position(newN, m, newX));
						}
					}
				}
			}
			// block E-W
			{
				int newTime = getTime() + 2;
				int newX = ((x%2) == 0) ? (x+1) : (x-1);
				int newM = ((x%2) == 0) ? m-1 : m+1;
				if (newM >= 0 && newM < M) {
					int oldTime = times[n][newM][newX];
					// System.out.println("can get to " + n + "," + newM + "," + newX + " at " + newTime);
					if (newTime < oldTime) {
						times[n][newM][newX] = newTime;
						if (oldTime == Integer.MAX_VALUE) {
							open.add(new Position(n, newM, newX));
						}
					}
				}
			}
		}
		
	}

}
