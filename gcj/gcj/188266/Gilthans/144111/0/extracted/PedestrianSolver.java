package pedestrian;

import java.io.BufferedReader;

public class PedestrianSolver extends Solver {

	Intersection[][] inter;
	int width, height;
	PedestrianSolver(BufferedReader input_stream){
		super(input_stream);
	}
	@Override
	public String solve() throws Exception {
		String l = input.readLine();
		String[] spl = l.split(" ");
		height = Integer.parseInt(spl[0]);
		width = Integer.parseInt(spl[1]);
		inter = new Intersection[height][width];
		for(int i=0;i<height;i++){
			l = input.readLine();
			spl = l.split(" ");
			for(int j=0;j<width;j++){
				inter[i][j] = new Intersection(Integer.parseInt(spl[3*j]), Integer.parseInt(spl[3*j+1]), Integer.parseInt(spl[3*j+2]));
			}
		}
		
		return calcBestRoute(0, 0, 0).toString();
	}

	private Integer calcBestRoute(int posx, int posy, int time) {
		//greedy algorithm?
		if(posx == 2*width-1 && posy == 2*height-1)
			return time;

		Integer $1=Integer.MAX_VALUE, $2=Integer.MAX_VALUE;
		if(posy < 2*height-1){
			//Try going north
			if(posy%2 == 0){
				//Crossing an intersection
				Intersection relevant = inter[posy/2][posx/2];
				$1 = 1 + time + relevant.timeTillGreenVertical(time);
				$1 = calcBestRoute(posx, posy+1, $1);
			}
			else{
				$1 = calcBestRoute(posx, posy+1, time+2);
			}
		}
		if(posx < 2*width-1){
			//Try going East
			if(posx%2 == 0){
				//Crossing an intersection
				Intersection relevant = inter[posy/2][posx/2];
				$2 = 1 + time + relevant.timeTillGreenHorizontal(time);
				$2 = calcBestRoute(posx+1, posy, $2);
			}
			else{
				$2 = calcBestRoute(posx+1, posy, time+2);
			}
		}
		return $1 > $2 ? $2 : $1;
	}

}
