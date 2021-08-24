package pedestrian;

public class Intersection {

	int v, h, s;
	public Intersection(int verticalTime, int horizontalTime, int startTime) {
		v = verticalTime; h = horizontalTime; s = startTime;
		while(s > 0){
			s -= (h+v); //one cycle back
		}
	}

	public int timeTillGreenVertical(int time) {
		//How long until we next have a full minute of green light?
		int nextStart = s, $=0;
		while(nextStart+v-1 < time){
			nextStart += v+h;
		}
		if(time < nextStart)
			$ = nextStart-time;
		return $;
	}

	public int timeTillGreenHorizontal(int time) {
		//How long until we next have a full minute of green light?
		int nextStart = s-h, $=0;
		while(nextStart+h-1 < time){
			nextStart += h+v;
		}
		if(time < nextStart)
			$ = nextStart-time;
		return $;
	}

}
