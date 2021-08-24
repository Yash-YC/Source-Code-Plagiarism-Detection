namespace ZT.Contests.GCJ2016.Round_1A
{
    using System.Linq;
    using System.Text;
    using ZT.Common.Contest.GCJ;
    using ZT.Common.InputHelper;

    internal class TheLastWord : GcjSolverBase
    {
        public TheLastWord(GcjContestMain gcjMain) : base(gcjMain, "A", "Round 1A") { }

        public override void Solve(InputHelper input)
        {
            var st = input.ReadString();
            var n = st.Length;
            var c = st.Max();
            var result = new StringBuilder();
            var removed = new bool[n];
            for (int i = n - 1; i >= 0; --i)
            {
                if (st[i] == c)
                {
                    result.Append(c);
                    removed[i] = true;
                    if (i > 0) c = st.Take(i).Max();
                }
            }
            for (int i = 0; i < n; ++i) if (!removed[i]) result.Append(st[i]);
            this.SetResult(result);
        }
    }
}
