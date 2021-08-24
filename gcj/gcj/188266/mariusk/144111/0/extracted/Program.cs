using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace Marius.CodeJam.A
{
    public class Program
    {
        public static void Main(string[] args)
        {
            if (args.Length == 2)
            {
                Console.SetIn(new StreamReader(args[0]));
                Console.SetOut(new StreamWriter(args[1]));
            }

            int numCases = int.Parse(Console.ReadLine().Trim());
            for (int currentCase = 1; currentCase <= numCases; currentCase++)
            {

                var input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                var n = input[0];
                var m = input[1];

                RoadNode[,] map = new RoadNode[n, m];
                for (int i = 0; i < n; i++)
                {
                    var traf = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();

                    for (int k = 0; k < m; k++)
                    {
                        var s = traf[3 * k];
                        var w = traf[3 * k + 1];
                        var t = traf[3 * k + 2];

                        map[i, k] = new RoadNode(i, k, s, w, t);
                    }
                }

                Queue<RoadNode> q = new Queue<RoadNode>();
                q.Enqueue(map[n - 1, 0]);

                map[n - 1, 0].Values[0] = 0;

                while (q.Count > 0)
                {
                    RoadNode r = q.Dequeue();

                    if (r.Values[0] != null)
                        Go(q, map, r, 0, new[] { 1, 3 });
                    if (r.Values[1] != null)
                        Go(q, map, r, 1, new[] { 0, 2 });
                    if (r.Values[2] != null)
                        Go(q, map, r, 2, new[] { 3, 1 });
                    if (r.Values[3] != null)
                        Go(q, map, r, 3, new[] { 2, 0 });
                }

                Console.Write("Case #{0}: ", currentCase);
                Console.WriteLine(map[0, m - 1].Values[2]);
            }

            if (args.Length == 2)
            {
                Console.In.Close();
                Console.Out.Close();

                Console.SetIn(new StreamReader(Console.OpenStandardInput()));
                Console.SetOut(new StreamWriter(Console.OpenStandardOutput()));
            }
        }

        private static void Go(Queue<RoadNode> q, RoadNode[,] map, RoadNode current, int vindex, int[] dir)
        {
            Debug.Assert(current.Values[vindex] != null);

            int time = current.Values[vindex].Value;
            int tlight = (time - current.T) % (current.S + current.W);

            if (tlight < 0)
                tlight += (current.S + current.W);

            switch (vindex)
            {
                case 0:
                    if (tlight < current.S)
                        Set(current, 1, time + 1, q);
                    else
                        Set(current, 1, time + 1 + (current.W - (tlight - current.S)), q);

                    if (tlight >= current.S)
                        Set(current, 3, time + 1, q);
                    else
                        Set(current, 3, time + current.S - tlight + 1, q);

                    if (current.Row < map.GetLength(0) - 1)
                        Set(map[current.Row + 1, current.Col], 1, time + 2, q);

                    if (current.Col > 0)
                        Set(map[current.Row, current.Col - 1], 3, time + 2, q);

                    break;
                case 1:
                    if (tlight < current.S)
                        Set(current, 0, time + 1, q);
                    else
                        Set(current, 0, time + 1 + (current.W - (tlight - current.S)), q);

                    if (tlight >= current.S)
                        Set(current, 2, time + 1, q);
                    else
                        Set(current, 2, time + current.S - tlight + 1, q);

                    if (current.Row > 0)
                        Set(map[current.Row - 1, current.Col], 0, time + 2, q);

                    if (current.Col > 0)
                        Set(map[current.Row, current.Col - 1], 2, time + 2, q);

                    break;
                case 2:
                    if (tlight < current.S)
                        Set(current, 3, time + 1, q);
                    else
                        Set(current, 3, time + 1 + (current.W - (tlight - current.S)), q);

                    if (tlight >= current.S)
                        Set(current, 1, time + 1, q);
                    else
                        Set(current, 1, time + current.S - tlight + 1, q);

                    if (current.Row > 0)
                        Set(map[current.Row - 1, current.Col], 3, time + 2, q);

                    if (current.Col < map.GetLength(1) - 1)
                        Set(map[current.Row, current.Col + 1], 1, time + 2, q);

                    break;
                case 3:
                    if (tlight < current.S)
                        Set(current, 2, time + 1, q);
                    else
                        Set(current, 2, time + 1 + (current.W - (tlight - current.S)), q);

                    if (tlight >= current.S)
                        Set(current, 0, time + 1, q);
                    else
                        Set(current, 0, time + current.S - tlight + 1, q);

                    if (current.Row < map.GetLength(0) - 1)
                        Set(map[current.Row + 1, current.Col], 2, time + 2, q);

                    if (current.Col < map.GetLength(1) - 1)
                        Set(map[current.Row, current.Col + 1], 0, time + 2, q);

                    break;
            }
        }

        private static void Set(RoadNode current, int vindex, int value, Queue<RoadNode> q)
        {
            if (current.Values[vindex] == null)
            {
                current.Values[vindex] = value;
                q.Enqueue(current);
            }

            if (current.Values[vindex] > value)
            {
                current.Values[vindex] = value;
                q.Enqueue(current);
            }
        }
    }

    public class RoadNode
    {
        public int?[] Values { get; private set; }

        public int Row { get; private set; }
        public int Col { get; private set; }

        public int S { get; private set; }
        public int W { get; private set; }
        public int T { get; private set; }

        public RoadNode(int row, int col, int s, int w, int t)
        {
            Values = new int?[4];

            Row = row;
            Col = col;

            S = s;
            W = w;
            T = t;
        }
    }
}
