namespace ZT.Contests.GCJ2016.Round_1A
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using ZT.Common;
    using ZT.Common.Contest.GCJ;
    using ZT.Common.Extensions;
    using ZT.Common.InputHelper;

    internal class RankAndFile : GcjSolverBase
    {
        public RankAndFile(GcjContestMain gcjMain) : base(gcjMain, "B", "Round 1A") { }

        public override void Solve(InputHelper input)
        {
            this.n = input.ReadInt();
            this.groups = new List<List<int>>();
            for (var i = 0; i < n*2 - 1; ++i)
            {
                var cur = new List<int>();
                for (var j = 0; j < n; ++j) cur.Add(input.ReadInt());
                this.groups.Add(cur);
            }

            var min = this.groups.Select(x => x.First()).Min();
            var value = min;

            if (this.groups.Count(x => x.First() == min) == 1)
            {
                this.reverse = true;
                this.dic = Misc.GetNaturalNumber().Take(n * 2 - 1).GroupBy(i => this.groups[i].Last()).ToDictionary(p => p.Key, p => p.Select(i => i).ToList());
                value = this.dic.Keys.Max();
            }
            else
            {
                this.reverse = false;
                this.dic = Misc.GetNaturalNumber().Take(n * 2 - 1).GroupBy(i => this.groups[i].First()).ToDictionary(p => p.Key, p => p.Select(i => i).ToList());
            }

            var firstRow = groups[dic[value].First()];
            var firstCol = groups[dic[value].Last()];
            var heads = firstRow.Concat(firstCol).OrderBy(c => c);
            var missing =
                this.groups.Select(s => this.reverse ? s.Last() : s.First())
                    .OrderBy(c => c)
                    .Concat(new[] {int.MaxValue})
                    .Zip(heads, (x, y) => new {x, y})
                    .First(p => p.x != p.y)
                    .y;

            var list = new List<int>();
            for (int i = 0; i < n; ++i) list.Add(0);
            list[R(0)] = missing;
            this.groups.Add(list);
            (dic.ContainsKey(missing) ? dic[missing] : dic[missing] = new List<int>()).Add(n*2 - 1);

            this.matrix = new int[n,n];
            for (var j = 0; j < n; ++j)
            {
                this.SetElement(0, j, firstRow[R(j)], true);
                this.SetElement(0, j, firstCol[R(j)], false);
            }
            this.used = new bool[n*2];
            this.Search(1, false);
        }

        private int n;
        private List<List<int>> groups;
        private Dictionary<int, List<int>> dic;
        private int[,] matrix;
        private bool[] used;
        private int resultCur;
        private bool resultDir;
        private bool reverse;

        private int R(int i) { return reverse ? this.n - 1 - i : i; }

        private int GetElement(int i, int j, bool isRow)
        {
            return isRow ? this.matrix[R(i), R(j)] : this.matrix[R(j), R(i)];
        }

        private void SetElement(int i, int j, int d, bool isRow)
        {
            if (isRow) this.matrix[R(i), R(j)] = d;
            else this.matrix[R(j), R(i)] = d;
        }

        private bool Search(int cur, bool isRow)
        {
            Func<int, int, int> getElement = (i, j) => this.GetElement(i, j, isRow);

            if (cur == this.n)
            {
                cur = this.resultCur;
                isRow = this.resultDir;
                this.SetResult(string.Join(" ", Misc.GetNaturalNumber().Take(n).Select(i => getElement(cur, R(i)))));
                return true;
            }

            Func<int, int, bool> check = (i, d) =>
            {
                var e = getElement(cur, i);
                return e == 0 || d == 0 || e == d;
            };

            var start = getElement(cur, 0);

            var nextCur = isRow ? cur + 1 : cur;

            List<int> list;
            if (this.dic.TryGetValue(start, out list))
            {
                var set = new bool[n];
                foreach (var c in list.Where(c => !this.used[c]))
                {
                    if (Misc.GetNaturalNumber().Take(n).All(i => check(i, groups[c][R(i)])))
                    {
                        this.used[c] = true;
                        Misc.GetNaturalNumber().Take(n).Where(i => getElement(cur, i) == 0).ForEach(
                            i =>
                            {
                                set[i] = true;
                                this.SetElement(cur, i, groups[c][R(i)], isRow);
                            });
                        //this.Output();
                        if (c == this.n*2 - 1)
                        {
                            this.resultCur = cur;
                            this.resultDir = isRow;
                        }
                        if (this.Search(nextCur, !isRow)) return true;
                        Misc.GetNaturalNumber().Take(n).Where(i => set[i]).ForEach(
                            i =>
                            {
                                this.SetElement(cur, i, 0, isRow);
                                set[i] = false;
                            });
                        this.used[c] = false;
                        //this.Output();
                    }
                }
            }

            return false;
        }

        private void Output()
        {
            Console.WriteLine(
                string.Join(
                    Environment.NewLine,
                    Misc.GetNaturalNumber(0, n - 1).Select(i => string.Join(" ", Misc.GetNaturalNumber(0, n - 1).Select(j => this.matrix[i, j])))));
        }
    }
}
