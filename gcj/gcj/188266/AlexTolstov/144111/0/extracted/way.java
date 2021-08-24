import java.io.*;
import java.util.*;


public class Txxxx {
	
	Scanner in;
	PrintWriter out;
	
	static final String problem = "way";
	
	static class Cross {
		Node bottomLeft;
		Node topLeft;
		Node bottomRight;
		Node topRight;
		int startTime;
		int timeNS;
		int timeWE;
		int line;
		int col;
		
		Cross (Scanner in, int line, int col){
			this.line = line;
			this.col = col;
			timeNS = in.nextInt();
			timeWE = in.nextInt();
			
			startTime = in.nextInt();
			bottomLeft = new Node(this,1);
			topLeft = new Node(this,2);
			bottomRight = new Node(this,3);
			topRight = new Node(this,4);
			
			bottomLeft.rl = bottomRight;
			bottomLeft.ud = topLeft;
			
			topLeft.rl = topRight;
			topLeft.ud = bottomLeft;
			
			bottomRight.rl = bottomLeft;
			bottomRight.ud = topRight;
			
			topRight.rl = topLeft;
			topRight.ud = bottomRight;
		}
		
	}
	
	static class Node {
		List <Node> next2 = new ArrayList<Node>();
		Node rl;
		Node ud;
		Cross cross;
		int time;
		boolean used;
		int idx;
		
		Node(Cross cross, int idx){
			this.idx = idx;
			this.cross = cross;
			time = Integer.MAX_VALUE/2;
		}
		
		void add(Node n){
			next2.add(n);
			n.next2.add(this);
		}
		
		int getRLTime(){
			int low = -100000;
			int high = 100000;
			while (high - low > 1){
				int mid = (low + high)/ 2;
				int time = cross.startTime + mid * (cross.timeNS+cross.timeWE) + cross.timeNS;
				if (time >= this.time) {
					high = mid;
				} else {
					low = mid;
				}
			}
			int prev = cross.startTime + (high-1)* (cross.timeNS+cross.timeWE) + cross.timeNS;
			if (prev + cross.timeWE <= this.time + 1) {
				return this.time;
			}
			return cross.startTime + high * (cross.timeNS+cross.timeWE) + cross.timeNS;
		}
		
		int getUDTime(){
			int low = -100000;
			int high = 100000;
			while (high - low > 1){
				int mid = (low + high)/ 2;
				int time = cross.startTime + mid * (cross.timeNS+cross.timeWE);
				if (time >= this.time) {
					high = mid;
				} else {
					low = mid;
				}
			}
			int prev = cross.startTime + (high-1)* (cross.timeNS+cross.timeWE);
			if (prev + cross.timeNS <= this.time + 1) {
				return this.time;
			}
			return cross.startTime + high * (cross.timeNS+cross.timeWE);
		}
		
		void update(){
			this.used = true;
			for (Node n : next2){
				if (!n.used && n.time > this.time + 2) {
					n.time = this.time + 2;
				}
			}
			if (!rl.used && rl.time > getRLTime() + 1 ) {
				rl.time = getRLTime() + 1;
			}
			if (!ud.used && ud.time > getUDTime() + 1 ) {
				ud.time = getUDTime() + 1;
			}
		}
	}
	
	Cross[][] cross;
	
	Node extractMin() {
		Node ans = null;
		int minTime = Integer.MAX_VALUE;
		for (int i=0; i<cross.length; i++){
			for (int j=0; j<cross[i].length; j++){
				Cross c = cross[i][j];
				if (!c.bottomLeft.used) {
					if (c.bottomLeft.time < minTime) {
						minTime = c.bottomLeft.time;
						ans = c.bottomLeft;
					}
				}
				if (!c.topLeft.used) {
					if (c.topLeft.time < minTime) {
						minTime = c.topLeft.time;
						ans = c.topLeft;
					}
				}
				if (!c.bottomRight.used) {
					if (c.bottomRight.time < minTime) {
						minTime = c.bottomRight.time;
						ans = c.bottomRight;
					}
				}
				if (!c.topRight.used) {
					if (c.topRight.time < minTime) {
						minTime = c.topRight.time;
						ans = c.topRight;
					}
				}
			}
		}		
		return ans;
	}
	
	void dijkstra(Node start){
		start.time = 0;
		start.update();
		while (true){
			Node curr = extractMin();
			if (curr == null){
				return;
			}
			curr.update();
		}
	}
	
	void solveOne(){
		int nLines = in.nextInt();
		int nCols = in.nextInt();
		cross = new Cross[nLines][nCols];
		for (int i=0; i<nLines; i++){
			for (int j=0; j<nCols; j++){
				cross[i][j] = new Cross(in, i, j);
			}
		}
		for (int i=0; i<nLines; i++){
			for (int j=0; j<nCols; j++){
				Cross c = cross[i][j];
				if (i + 1 < nLines){
					c.topLeft.add(cross[i + 1][j].bottomLeft);
					c.topRight.add(cross[i + 1][j].bottomRight);										
				}
				if (j + 1 < nCols){					
					c.bottomRight.add(cross[i][j + 1].bottomLeft);
					c.topRight.add(cross[i][j + 1].topLeft);
				}
			}
		}
		dijkstra(cross[0][0].bottomLeft);
		asserT(cross[nLines-1][nCols-1].topRight.used);
		out.println(cross[nLines-1][nCols-1].topRight.time);
	}
	
	void asserT(boolean e){
		if (!e){
			throw new Error();
		}
	}
			
	void solve(){
		int t = in.nextInt();
		in.nextLine();
		for (int i=1; i<=t; i++){
			out.print("Case #"+i+": ");
			solveOne();			
		}
	}
	
	void run() {
	/*
		try {
			in = new Scanner(new FileReader("C:\\"+problem + ".in"));
			out = new PrintWriter("C:\\"+problem + ".out");
		} catch (IOException e) {
			throw new Error();
		}
	*/
		in = new Scanner(System.in);
		out = new PrintWriter(System.out);
		try {
			solve();					
		} finally {
			out.close();
		}
	}
	
	public static void main(String []args) {
		new Txxxx().run();
	}
}