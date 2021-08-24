package google2009.round1;

public class Cell implements Comparable<Cell> {
	int b[] = new int[9];
	long v;

	public Cell(int bases[]) {
		for (int base : bases) {
			b[base-2] = 1;
		}
	}
	
	@Override
	public int compareTo(Cell o) {
		return (int)(o.v-v);
	}
	@Override
	public boolean equals(Object obj) {
		Cell o = (Cell)obj;
		if (compareTo(o)!=0) return false;
		for (int i = 0; i < b.length; i++) {
			if (b[i]!=(o).b[i]) return false;
		}
		return true;
	}
	
	public boolean useThis (Cell c) {
		for (int i = 0; i < b.length; i++) {
			if (b[i]==1 && b[i]!=c.b[i]) return false;
		}
		return true;
		/*for (int base : bases) {
			if (b[base-2] == 0) return false;
		}
		return true;*/
	}
}
