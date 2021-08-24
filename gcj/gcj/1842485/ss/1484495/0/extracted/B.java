import java.io.PrintStream;
import java.io.File;
import java.util.Scanner;
import java.util.Comparator;
import java.util.Arrays;

class B {
    Scanner in;
    PrintStream out;
    PrintStream dout;

    public static void main(String[] args) {
        B p = new B();
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
	
	Comparator<P> rcomp = new Comparator<P>() {
	    public int compare(P a, P b) {
		    if (a.r>b.r) return -1;
			if (a.r<b.r) return 1;
			return 0;
		}
	};
	Comparator<P> icomp = new Comparator<P>() {
	    public int compare(P a, P b) {
		    if (a.index>b.index) return 1;
			if (a.index<b.index) return -1;
			return 0;
		}
	};
	
	class P {
	    public P (int _index, long _r) {
		    r = _r;
			index = _index;
		}
		long x;
		long y;
		long r;
		int index;
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

    void runOneCase(int cn) {
	    int N = in.nextInt();
		long W = in.nextLong();
		long L = in.nextLong();
		
		P[] ps = new P[N];
		
		boolean switched = false;
		
		if (W<L){
		    long temp = W;
			W = L;
			L = temp;
		    switched = true;
		}
		
		for (int i=0; i<N; i++) {
		    ps[i] = new P(i, in.nextLong());
		}
		
		Arrays.sort(ps, rcomp);

		boolean first = true;
		long offset = 0;
		
		for (int i=0; i<N; ) {
		    int put = 0;
			
			if (ps[i].r > L) put = 1;
			else if (ps[i].r * 2 > L) put = 2;
			else put = 1+ (int)(L / (ps[i].r * 2));
			
			put = Math.min(put, N-i);
			
			ps[i].x = first ? 0 : offset + ps[i].r ;
			ps[i].y = 0;
			
			if (put>1) {
			    ps[i+1].x = first ? 0 : offset + ps[i].r ;
				ps[i+1].y = L;
			}
			
			if (put>2) {
				for (int j=2; j<put; j++) {
					ps[i+j].x = first ? 0 : offset + ps[i].r ;
					ps[i+j].y = (j-1) * ps[i].r * 2;
				}
				
			}
			
			if (first) offset += ps[i].r;
			else offset += ps[i].r * 2;
			
			i += put ;

			first = false;
		}
		
		Arrays.sort(ps, icomp);
		
        out.print("Case #"+cn+":");
		
		for (int i=0; i<N; i++) {
		    if (!switched) {
		        out.print(" "+ps[i].x+" "+ps[i].y);
			} else {
		        out.print(" "+ps[i].y+" "+ps[i].x);
			}
		}
		out.println();
    }
}
