using System;
using System.Linq;

class T
{
    static void Main(string[] args)
    {
        var t = int.Parse(Console.ReadLine());
        for (var c = 1; c <= t; c++)
        {
            var n = int.Parse(Console.ReadLine());
            var lists = Enumerable.Range(0, 2 * n - 1).Select(x =>
            Console.ReadLine().Split().Select(a => int.Parse(a)).ToArray())
            .ToList();
            var count = new int[2501];
            foreach(var list in lists)
            {
                foreach (var x in list)
                    count[x]++;
            }
            var ans = string.Join(" ", Enumerable.Range(0, 2501).Where(x => count[x] % 2 > 0)
                .Select(x => string.Format("{0}", x)));
            Console.WriteLine("Case #{0}: {1}", c, ans);
        }
    }
}
