import java.io.*;
import java.util.*;

public class road {
	public static int[][][] info;
	public static void main (String[] args) throws IOException{
		BufferedReader in=new BufferedReader(new FileReader("road.in"));
		PrintWriter out=new PrintWriter (new FileWriter("roadout"));
		int cases=Integer.parseInt(in.readLine());
		for (int i=1; i<=cases; i++){
			StringTokenizer st=new StringTokenizer(in.readLine());
			int rows=Integer.parseInt(st.nextToken());
			int cols=Integer.parseInt(st.nextToken());
			info=new int[rows][cols][3];
			int[][] dist=new int[2*rows][2*cols];
			for (int j=0; j<rows; j++){
				st=new StringTokenizer(in.readLine());
				for (int k=0; k<cols; k++){
					dist[2*j][2*k]=Integer.MAX_VALUE;
					dist[2*j+1][2*k]=Integer.MAX_VALUE;
					dist[2*j+1][2*k+1]=Integer.MAX_VALUE;
					dist[2*j][2*k+1]=Integer.MAX_VALUE;
					info[j][k][0]=Integer.parseInt(st.nextToken());
					info[j][k][1]=Integer.parseInt(st.nextToken());
					info[j][k][2]=Integer.parseInt(st.nextToken());
					info[j][k][2]%=(info[j][k][1]+info[j][k][0]);
					info[j][k][2]-=(info[j][k][1]+info[j][k][0]);
				}
			}
			boolean[][] visited=new boolean[2*rows][2*cols];
			dist[0][0]=0;
			int currx=0, curry=0, currdist=0;
			while (currx!=2*rows-1 || curry!=2*cols-1){
				if (currx%2==1){
					if (currx+1<rows*2)
						dist[currx+1][curry]=Math.min(dist[currx+1][curry], currdist+2);
					dist[currx-1][curry]=Math.min(dist[currx-1][curry], calc(currdist, currx/2, curry/2, false));
					//get dist[currx-1][curry]
				}
				if (currx%2==0){
					if (currx!=0)
						dist[currx-1][curry]=Math.min(dist[currx-1][curry], currdist+2);
					dist[currx+1][curry]=Math.min(dist[currx+1][curry], calc(currdist, currx/2, curry/2, false));
					//get dist[currx+1][curry];
				}
				if (curry%2==1){
					if (curry+1<cols*2)
						dist[currx][curry+1]=Math.min(dist[currx][curry+1], currdist+2);
					dist[currx][curry-1]=Math.min(dist[currx][curry-1], calc(currdist, currx/2, curry/2, true));
					//get dist[currx][curry-1];
				}
				if (curry%2==0){
					if (curry!=0)
						dist[currx][curry-1]=Math.min(dist[currx][curry-1], currdist+2);
					dist[currx][curry+1]=Math.min(dist[currx][curry+1], calc(currdist, currx/2, curry/2, true));
				}
				//get disttance updating
				
				visited[currx][curry]=true;
				int mindist=Integer.MAX_VALUE, minx=0, miny=0;
				for (int j=0; j<dist.length; j++)
					for (int k=0; k<dist[j].length; k++){
						if (visited[j][k])
							continue;
						if (dist[j][k]<mindist){
							mindist=dist[j][k];
							minx=j;
							miny=k;
						}
					}
				currx=minx;
				curry=miny;
				currdist=mindist;
			}
			int ans=dist[rows*2-1][cols*2-1];
			out.println("Case #"+i+": "+ans);
		}
		out.close();
		System.exit(0);
	}
	
	public static int calc (int sofar, int xint, int yint, boolean NW){
		int north=info[xint][yint][0];
		int east=info[xint][yint][1];
		int reset=info[xint][yint][2];
		int time=sofar;
		if (NW){ //change x, going east
			if (sofar>=reset){
				time-=reset;
				time%=north+east;
				if (time>=north)
					return sofar+1;
				else
					return north-time+sofar+1;
			}
			else{
				time%=north+east;
				if (time>=north)
					return sofar+1;
				else{
					int change=north-time;
					if (sofar+change>=reset)
						return reset+north+1;
					else
						return sofar+change+1;
				}
			}
		}
		else{ //change y, going north
			if (sofar>=reset){
				time-=reset;
				time%=north+east;
				if (time<north)
					return sofar+1;
				else
					return north+east-time+sofar+1;
			}
			else{
				time%=north+east;
				if (time<north)
					return sofar+1;
				else{
					int change=north+east-time;
					if (sofar+change>=reset)
						return reset+1;
					else
						return sofar+change+1;
				}
			}
		}
	}
}
