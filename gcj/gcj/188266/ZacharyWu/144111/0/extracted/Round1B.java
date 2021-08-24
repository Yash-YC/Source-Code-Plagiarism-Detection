package codejam2009;

import java.io.*;
import java.util.*;

public class Round1B {

	public static void main(String[] args) throws IOException{
		Scanner in = new Scanner(new FileReader("B.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"B.out")));
		int c = in.nextInt();
		for (int caseNum = 1; caseNum<=c; caseNum++){
			int n = in.nextInt();
			int m = in.nextInt();
			
			int[][][] map = new int[n][m][3];
			for (int i = 0;i<n;i++)
				for (int j = 0;j<m;j++){
					map[i][j][0] = in.nextInt();
					map[i][j][1] = in.nextInt();
					map[i][j][2] = in.nextInt();
				}
			int n2=2*n;
			int m2=2*m;
			//System.out.println(n+" "+m+" "+n2+" "+m2);
			int[][] time = new int[n2][m2];			
			time[n2-1][0] = 0;
			for (int i = n2-1; i>=0; i--)
				for (int j = 0;j<m2;j++){
					int fromLeft = 99999;
					if (j>0){
						if (j%2==0){
							fromLeft = time[i][j-1]+2;
						}
						else{
							fromLeft = time[i][j-1]+1+
							waitTime(map[i/2][(j-1)/2][0],
									map[i/2][(j-1)/2][1],
									map[i/2][(j-1)/2][2],
									time[i][j-1],1);
						}
					}
					int fromBottom = 99999;
					if (i<n2-1){
						if (i%2==1)
							fromBottom = time[i+1][j]+2;
						else{
							fromBottom = time[i+1][j]+1+waitTime(map[(i+1)/2][j/2][0],map[(i+1)/2][j/2][1],map[(i+1)/2][j/2][2],time[i+1][j],0);
						}
					}
					if (fromLeft == 99999 && fromBottom == 99999)
						time[i][j] = 0;
					else{
					if (fromLeft < fromBottom)
						time[i][j] = fromLeft;
					else
						time[i][j] = fromBottom;					
					}
					//System.out.println(i+" "+j+" "+time[i][j]);
				}
			out.write("Case #" + caseNum + ": " + time[0][m2-1]+"\n");
		}
		
		in.close();
		out.close();
	}
	private static int waitTime(int s, int w, int t, int t1, int flag){
		t = t%(s+w)-(s+w);
		if (t1 >= t){
			int cycle = (t1-t)%(s+w);
			if (flag == 0){
				if (cycle<s)
					return 0;
				else
					return s+w-cycle;
			}else{
				if (cycle<s)
					return s-cycle;
				else
					return 0;
			}
		}else{
			int cycle = (t-t1)%(s+w);
			if (cycle == 0)
				cycle = s+w;
			if (flag == 0){
				if (cycle<=w)
					return cycle;
				else
					return 0;
			}else{
				if (cycle<=w)
					return 0;
				else 
					return cycle-w;
			}
		}
		
	}
}
