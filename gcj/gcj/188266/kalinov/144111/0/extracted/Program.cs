using System;
using System.Collections.Generic;
using System.Text;

namespace B
{
    class Crossing
    {
        public int r, c;
        int NS, EW;
        int t0;
        public Crossing(int R, int C, string aa, string bb, string cc)
        {
            r = R;
            c = C;
            t0 = Int32.Parse(cc);
            NS = Int32.Parse(aa);
            EW = Int32.Parse(bb);
            if (t0 > 0) t0 -= ( 5 + t0 / (NS + EW) ) * (NS + EW);            
        }

        public int next_NS(int t)
        {
            int proslo = t - t0;
            int k = proslo / (NS + EW);
            int mod = proslo - k * (NS + EW);
            if (mod >= NS)
            {
                return t0 + (k + 1) * (NS + EW);
            }
            else return t;
        }
        public int next_EW(int t)
        {
            int proslo = t - t0;
            int k = proslo / (NS + EW);
            int mod =proslo - k * (NS + EW);
            if (mod < NS)            
            {
                return t0 + k * (NS + EW) + NS;
            }
            else return t;
        }        
    }

    class State
    {
        Crossing cross;
        int corner;
        int dist;
        bool done;

        static int[] dr = new int[4] { 0, 1, 0, -1 };
        static int[] dc = new int[4] { -1, 0, 1, 0 };

        static int[,] next_corner = new int[4, 4] { { 1, 3, 1, 3 },
                                                    { 0, 2, 0, 2 },
                                                    { 3, 1, 3, 1 },
                                                    { 2, 0, 2, 0 } };

        public bool IsDone() { return done; }
        public void Done() { done = true; }

        public int R() { return cross.r; }
        public int C() { return cross.c; }
        public int Corner() { return corner; }
        public Crossing Cross() { return cross; }
        public int MoveR(int direction) { return cross.r + dr[direction]; }
        public int MoveC(int direction) { return cross.c + dc[direction]; }
        public int MoveCorner(int direction) { return next_corner[corner,direction]; }

        public int Dist() { return dist; }

        public State(Crossing C, int Corner) { 
            cross = C; 
            corner = Corner;
            dist = 1000000000;
            done = false;
        }

        public void Update(int d) 
        {
            if (dist > d)dist = d;            
        }

        public bool CanCross(int direction)
        {
            return (direction + 2) % 4 == corner || (direction + 1) % 4 == corner;
        }
        public bool CanWalk(int direction, int R, int C)
        {
            bool ret = direction == corner || (direction + 3) % 4 == corner;
            ret &= cross.r + dr[direction] >= 0 && cross.r + dr[direction] < R;
            ret &= cross.c + dc[direction] >= 0 && cross.c + dc[direction] < C;
            return ret;
        }

        public static bool operator < (State a, State b) {
            return a.dist < b.dist;
        }
        
        public static bool operator > (State a, State b)
        {
            return a.dist > b.dist;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int T = Int32.Parse(Console.ReadLine());
            for (int tt = 1; tt <= T; ++tt)
            {
                string[] tmp = Console.ReadLine().Split(' ');
                int R = Int32.Parse(tmp[0]);
                int C = Int32.Parse(tmp[1]);

                Crossing[,] a = new Crossing[R, C];

                State[, ,] states = new State[R, C, 4];

                for (int r = 0; r < R; ++r)
                {
                    tmp = Console.ReadLine().Split(' ');
                    for (int c = 0; c < C; ++c)
                    {                        
                        a[r, c] = new Crossing(r, c, tmp[c * 3 + 0], tmp[c * 3 + 1], tmp[c * 3 + 2]);
                        for (int d = 0; d < 4; ++d)
                            states[r, c, d] = new State(a[r, c], d);
                    }
                }
                states[0, 0, 0].Update(0);

                for (int iter = 0; iter < R * C * 4; ++iter)
                {
                    State best = null;
                    for( int r = 0; r < R; ++r )
                        for( int c = 0; c < C; ++c ) 
                            for( int d = 0; d < 4; ++d ) {
                                if( states[r,c,d].IsDone() ) continue;
                                if( best == null ) best = states[r,c,d];
                                if( states[r,c,d] < best ) best = states[r,c,d];
                            }
                    
                    best.Done();

                    for (int d = 0; d < 4; ++d)
                        if (best.CanWalk(d, R, C))
                        {                            
                            states[best.MoveR(d), best.MoveC(d), best.MoveCorner(d)].Update(best.Dist() + 2);
                        }
                        else if (d % 2 == 0)
                        {
                            states[best.R(), best.C(), best.MoveCorner(d)].Update(best.Cross().next_EW(best.Dist()) + 1);
                        }
                        else
                        {
                            states[best.R(), best.C(), best.MoveCorner(d)].Update(best.Cross().next_NS(best.Dist()) + 1);
                        }
                }

                Console.WriteLine("Case #{0}: {1}", tt, states[R - 1, C - 1, 2].Dist());
            }
        }
    }
}
