import java.io.PrintStream;
import java.io.File;
import java.util.Scanner;

class A {
    Scanner in;
    PrintStream out;
    PrintStream dout;

    public static void main(String[] args) {
        A p = new A();
        p.prepareIO();
        p.run();
    }

    void prepareIO() {
        try {
            in = new Scanner(System.in);
            out = new PrintStream(new File("out.txt"));
            dout = System.out;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    void run() {
        int nCases = in.nextInt();
        dout.println("nCases: "+nCases);

        for (int i=0; i<nCases; i++) {
            dout.println("running #"+(i+1));
            runOneCase(i+1);
        }

        if (in.hasNext()) {
            dout.println("WARNING: has next");
        }
    }

	int N = 0;
	long D = 0;
	
	long[][] dl = null;
	boolean[][] checked = null;
	boolean[][] isok = null;
	
    void runOneCase(int cn) {
		N = in.nextInt();
	
	    dl = new long[N+1][2];
		checked = new boolean[N+1][N+1];
		isok = new boolean[N+1][N+1];
		
		dl[0][0] = 0;
		dl[0][1] = 0;
		
		
		for (int i=1; i<=N; i++) {
		    dl[i][0] = in.nextLong();
		    dl[i][1] = in.nextLong();
		}
	
	    D = in.nextLong();
	
        out.println("Case #"+cn+": "+(ok(0, 1, dl[1][0])?"YES":"NO"));
    }
	
	boolean ok(int current, int next, long canUse) {
	    if (checked[current][next]) return isok[current][next];

		boolean pass = false;
		
		long np = dl[next][0];
		
		if (D-np <= canUse) pass = true;
	
	    for (int i = next+1; i<=N && !pass && dl[i][0]<=np+canUse; i++) {
		    pass = ok(next, i, Math.min(dl[i][1], dl[i][0]-np));
		}
	
	    checked[current][next] = true;
		isok[current][next] = pass;
		
		return pass;
	}
}
