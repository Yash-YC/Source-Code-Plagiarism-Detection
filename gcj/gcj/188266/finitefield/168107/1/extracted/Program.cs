using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;
using System.Threading;
using System.Text.RegularExpressions;
using System.Reflection;
using System.Linq.Expressions;
using System.Collections;


public static class GCJConst
{
    static GCJConst()
    {
        MYTRACE = false;
        ResultSingle = true;
        //FilePath = "A-test.in";
        //FilePath = "A-small-attempt0.in";
        FilePath = "A-large.in";
        ProblemCreator = () =>
            {
                var ss = GCJProblemCreator.SS;
                var line = GCJProblemCreator.Line;
                ///////////////
                var v = new A();
                v.Bases.AddRange(ss[line++].SplitSpace().Select(x => x.ToInt()));
                ///////////////
                GCJProblemCreator.Line = line;
                return v;
            };
        TestCreator = () =>
            {
                var rand = new Random();
                ///////////////
                var v = new A();
                v.Bases.AddRange(new[] { 2, 3, 4, 5, 6, 7, 8, 9, 10 });
                //v.Bases.AddRange(new[] { 2, 3 });
                ///////////////
                return v;
            };
    }
    public static bool MYTRACE = true;
    public static bool ResultSingle = true;
    public static string FilePath;
    public static Func<GCJSolver> ProblemCreator;
    public static Func<GCJSolver> TestCreator;
    public static int TestNum = 1;
}

public static class AA
{
    public static MergingSet[] MergingSets;
}

public class A : GCJSolver
{
    int max = 20000000;
    public List<int> Bases = new List<int>();
    public override string GetResultSingle()
    {
        var data = new int[11];
        if (AA.MergingSets == null)
        {
            AA.MergingSets = new MergingSet[11];
            for (int b = 2; b <= 10; b++)
            {
                var ms = new MergingSet(max);
                for (int i = 1; i < max; i++)
                {
                    ms.Merge(i, GetNext(b, i));
                }
                for (int i = 2; i < max; i++)
                {
                    if (ms.GetRoot(i) == 1)
                    {
                        data[b] = i;
                        break;
                    }
                }
                AA.MergingSets[b] = ms;
            }
        }
        File.WriteAllText("A-res", data.JoinStrSpace());
        int ans = 0;
        for (int i = 2; i < max; i++)
        {
            if (Bases.All(x => AA.MergingSets[x].GetRoot(i) == 1))
            {
                ans = i;
                break;
            }
        }
        return ans.ToString();
    }
    public int GetNext(int b, int i)
    {
        int j = i;
        int sum = 0;
        while (j > 0)
        {
            sum += (j % b) * (j % b);
            j = (int)(j / b);
        }
        return sum;
    }
}
public class B : GCJSolver
{
}
public class C : GCJSolver
{
}

public class GCJRunner
{
    public List<string> Res = new List<string>();
    public bool ResultSingle = true;
    public void Run()
    {
        IGCJCreator creator = null;
        if (GCJConst.FilePath.IsNullOrEmpty())
            creator = new GCJTestCreator();
        else
            creator = new GCJProblemCreator(GCJConst.FilePath);
        var tss = new List<TimeSpan>();
        for (int testcase = 1; testcase <= creator.GetNumCase(); testcase++)
        {
            var ts = Util.MeasureTime(() =>
            {
                "Case {0}".FormatWith(testcase).Trace();

                var c = creator.GetSolver();

                c.Trace();
                if (GCJConst.ResultSingle)
                    Res.Add("Case #{0}: {1}".FormatWith(testcase, c.GetResultSingle()));
                if (!GCJConst.ResultSingle)
                {
                    Res.Add("Case #{0}:".FormatWith(testcase));
                    Res.AddRange(c.GetResultMultiple());
                }
            });
            tss.Add(ts);
        }
        "AverageTime {0} seconds".FormatWith(tss.Average(x => x.TotalMilliseconds) / 1000).Trace();
        "WorstTime {0} seconds".FormatWith(tss.Max(x => x.TotalMilliseconds) / 1000).Trace();
        File.WriteAllLines("Ans.txt", Res.ToArray());
        Console.Write(Res.ToArray().Join(Environment.NewLine));
        Console.ReadKey();
    }
}

class Program
{
    static void Main(string[] args)
    {
        var runner = new GCJRunner();
        runner.Run();
    }
}

public interface IGCJCreator
{
    GCJSolver GetSolver();
    int GetNumCase();
}
public class GCJProblemCreator : IGCJCreator
{
    public int NumCase;
    public static int Line;
    public static string[] SS;
    public GCJProblemCreator(string path)
    {
        SS = File.ReadAllLines(path);
        Line = 0;
        NumCase = SS[Line++].ToInt();
    }
    public virtual GCJSolver GetSolver()
    {
        return GCJConst.ProblemCreator();
    }
    public virtual int GetNumCase()
    {
        return NumCase;
    }
}
public class GCJTestCreator : IGCJCreator
{
    public GCJTestCreator()
    {
    }
    public virtual GCJSolver GetSolver()
    {
        return GCJConst.TestCreator();
    }
    public virtual int GetNumCase()
    {
        return GCJConst.TestNum;
    }
}
public class GCJSolver
{
    public virtual IEnumerable<string> GetResultMultiple()
    {
        yield break;
    }
    public virtual string GetResultSingle()
    {
        return "";
    }
}
public class Test
{
    public void Run()
    {
        (new ValuePair<int, int>(1, 2) == new ValuePair<int, int>(1, 2)).Trace();
        (new ValuePair<string, int, double>("a", 2, 0.3) == new ValuePair<string, int, double>("b", 2, 0.3)).Trace();
    }
}
public enum Array2Dir
{
    Nothing,
    Xm,
    Ym,
    Xp,
    Yp,
    XmYm,
    XmYp,
    XpYm,
    XpYp
}
public enum Array3Dir
{
    Nothing,
    Xm,
    Ym,
    Zm,
    Xp,
    Yp,
    Zp,
    XmYm,
    XmYp,
    XmZm,
    XmZp,
    XpYm,
    XpYp,
    XpZm,
    XpZp,
    YmZm,
    YmZp,
    YpZm,
    YpZp,
    XmYmZm,
    XmYmZp,
    XmYpZm,
    XmYpZp,
    XpYmZm,
    XpYmZp,
    XpYpZm,
    XpYpZp
}
public class ValuePair<T1, T2>
{
    public T1 First;
    public T2 Second;
    public T1 X { get { return First; } set { First = value; } }
    public T2 Y { get { return Second; } set { Second = value; } }
    public ValuePair(T1 first, T2 second)
    {
        First = first;
        Second = second;
    }
    public override bool Equals(object obj)
    {
        var o = obj as ValuePair<T1, T2>;
        return o.First.Equals(First) && o.Second.Equals(Second);
    }
    public override int GetHashCode()
    {
        return First.GetHashCode() ^ Second.GetHashCode();
    }
    public static bool operator ==(ValuePair<T1, T2> first, ValuePair<T1, T2> second)
    {
        return first.Equals(second);
    }
    public static bool operator !=(ValuePair<T1, T2> first, ValuePair<T1, T2> second)
    {
        return !first.Equals(second);
    }
}
public class ValuePair<T1, T2, T3>
{
    public T1 First;
    public T2 Second;
    public T3 Third;
    public T1 X { get { return First; } set { First = value; } }
    public T2 Y { get { return Second; } set { Second = value; } }
    public T3 Z { get { return Third; } set { Third = value; } }
    public ValuePair(T1 first, T2 second, T3 third)
    {
        First = first;
        Second = second;
        Third = third;
    }
    public override bool Equals(object obj)
    {
        var o = obj as ValuePair<T1, T2, T3>;
        return o.First.Equals(First) && o.Second.Equals(Second) && o.Third.Equals(Third);
    }
    public override int GetHashCode()
    {
        return First.GetHashCode() ^ Second.GetHashCode() ^ Third.GetHashCode();
    }
    public static bool operator ==(ValuePair<T1, T2, T3> first, ValuePair<T1, T2, T3> second)
    {
        return first.Equals(second);
    }
    public static bool operator !=(ValuePair<T1, T2, T3> first, ValuePair<T1, T2, T3> second)
    {
        return !first.Equals(second);
    }
}
public class Cell2<T>
{
    public T Data;
}
public class Array2<T>
{
    public T[,] Data;
    public int NumX;
    public int NumY;
    public T Empty;
    public Array2(int numX, int numY, T empty)
    {
        Data = new T[numX, numY];
        NumX = numX;
        NumY = numY;
        Empty = empty;
    }
    public bool S(int x, int y, T value)
    {
        if (x >= 0 && x < NumX && y >= 0 && y < NumY)
        {
            Data[x, y] = value;
            return true;
        }
        return false;
    }
    public bool S(int x, int y, Array2Dir dir, T value)
    {
        return S(x + dir.Dif().First, y + dir.Dif().Second, value);
    }
    public bool S(ValuePair<int, int> xy, T value)
    {
        return S(xy.First, xy.Second, value);
    }
    public bool S(ValuePair<int, int> xy, Array2Dir dir, T value)
    {
        return S(xy.First + dir.Dif().First, xy.Second + dir.Dif().Second, value);
    }
    public bool SLinearXYFromN(int n, T value)
    {
        return S(n % NumX, (int)(n / NumX), value);
    }
    public T G(int x, int y)
    {
        if (x >= 0 && x < NumX && y >= 0 && y < NumY)
            return Data[x, y];
        return Empty;
    }
    public T G(int x, int y, Array2Dir dir)
    {
        return G(x + dir.Dif().First, y + dir.Dif().Second);
    }
    public T G(ValuePair<int, int> xy)
    {
        return G(xy.First, xy.Second);
    }
    public T G(ValuePair<int, int> xy, Array2Dir dir)
    {
        return G(xy.First + dir.Dif().First, xy.Second + dir.Dif().Second);
    }
    public T GLinearXYFromN(int n)
    {
        return G(n % NumX, (int)(n / NumX));
    }
    public ValuePair<int, int> LinearXYFromN(int n)
    {
        return new ValuePair<int, int>(n % NumX, (int)(n / NumX));
    }
    public int LinearXFromN(int n)
    {
        return n % NumX;
    }
    public int LinearYFromN(int n)
    {
        return (int)(n / NumX);
    }
    public int LinearNFromXY(int x, int y)
    {
        return x + y * NumX;
    }
    public int LinearNFromXY(ValuePair<int, int> xy)
    {
        return LinearNFromXY(xy.First, xy.Second);
    }
}
public class MergingSet
{
    /// <summary>
    /// -1のものがRoot
    /// </summary>
    public long[] Parent;
    public MergingSet(long size)
    {
        Parent = new long[size];
        for (long i = 0; i < size; i++)
        {
            Parent[i] = -1;
        }
    }
    public bool Merge(long ind1, long ind2)
    {
        long root1 = GetRoot(ind1);
        long root2 = GetRoot(ind2);
        if (root1 == root2)
            return false;
        Parent[Math.Max(root1, root2)] = Math.Min(root1, root2);
        return true;
    }
    public long GetRoot(long ind)
    {
        if (Parent[ind] == -1)
            return ind;
        Parent[ind] = GetRoot(Parent[ind]);
        return Parent[ind];
    }
    public long Count()
    {
        return Parent.Count(x => x == -1);
    }
}
public partial class Util
{
    public static IEnumerable<int> WhereIndices<T>(this IEnumerable<T> source, Func<T, bool> selector)
    {
        int i = 0;
        foreach (var t in source)
        {
            if (selector(t))
                yield return i;
            i++;
        }
    }
    public static IEnumerable<int> WhereIndices<T>(this IEnumerable<T> source, Func<T, int, bool> selector)
    {
        int i = 0;
        foreach (var t in source)
        {
            if (selector(t, i))
                yield return i;
            i++;
        }
    }
    public static bool ExceptB<T>(this List<T> first, IEnumerable<T> second)
    {
        var una = first.Count;
        first = first.Except(second).ToList();
        return una == first.Count;
    }
    public static bool ExceptB<T>(this T[] first, IEnumerable<T> second)
    {
        var una = first.Length;
        first = first.Except(second).ToArray();
        return una == first.Length;
    }
    public static bool ExceptB<T>(this IEnumerable<T> first, IEnumerable<T> second)
    {
        var una = first.Count();
        first = first.Except(second);
        return una == first.Count();
    }
    public static bool UnionB<T>(this List<T> first, IEnumerable<T> second)
    {
        var una = first.Count;
        first = first.Union(second).ToList();
        return una == first.Count;
    }
    public static bool UnionB<T>(this T[] first, IEnumerable<T> second)
    {
        var una = first.Length;
        first = first.Union(second).ToArray();
        return una == first.Length;
    }
    public static bool UnionB<T>(this IEnumerable<T> first, IEnumerable<T> second)
    {
        var una = first.Count();
        first = first.Union(second);
        return una == first.Count();
    }
    public class UtilSingleton
    {
        private static UtilSingleton singleton = null;
        public static UtilSingleton Singleton
        {
            get
            {
                if (singleton == null)
                    singleton = new UtilSingleton();
                return singleton;
            }
        }
        private UtilSingleton()
        {
            Array2DirDif = new Dictionary<Array2Dir, ValuePair<int, int>>();
            Array2DirDif.Add(Array2Dir.Nothing, new ValuePair<int, int>(0, 0));
            Array2DirDif.Add(Array2Dir.Xm, new ValuePair<int, int>(-1, 0));
            Array2DirDif.Add(Array2Dir.XmYm, new ValuePair<int, int>(-1, -1));
            Array2DirDif.Add(Array2Dir.XmYp, new ValuePair<int, int>(-1, 1));
            Array2DirDif.Add(Array2Dir.Xp, new ValuePair<int, int>(1, 0));
            Array2DirDif.Add(Array2Dir.XpYm, new ValuePair<int, int>(1, -1));
            Array2DirDif.Add(Array2Dir.XpYp, new ValuePair<int, int>(1, 1));
            Array2DirDif.Add(Array2Dir.Ym, new ValuePair<int, int>(0, -1));
            Array2DirDif.Add(Array2Dir.Yp, new ValuePair<int, int>(0, 1));

            Array3DirDif = new Dictionary<Array3Dir, ValuePair<int, int, int>>();
            Array3DirDif.Add(Array3Dir.Nothing, new ValuePair<int, int, int>(0, 0, 0));
            Array3DirDif.Add(Array3Dir.Xm, new ValuePair<int, int, int>(-1, 0, 0));
            Array3DirDif.Add(Array3Dir.Ym, new ValuePair<int, int, int>(0, -1, 0));
            Array3DirDif.Add(Array3Dir.Zm, new ValuePair<int, int, int>(0, 0, -1));
            Array3DirDif.Add(Array3Dir.Xp, new ValuePair<int, int, int>(1, 0, 0));
            Array3DirDif.Add(Array3Dir.Yp, new ValuePair<int, int, int>(0, 1, 0));
            Array3DirDif.Add(Array3Dir.Zp, new ValuePair<int, int, int>(0, 0, 1));
            Array3DirDif.Add(Array3Dir.XmYm, new ValuePair<int, int, int>(-1, -1, 0));
            Array3DirDif.Add(Array3Dir.XmYp, new ValuePair<int, int, int>(-1, 1, 0));
            Array3DirDif.Add(Array3Dir.XmZm, new ValuePair<int, int, int>(-1, 0, -1));
            Array3DirDif.Add(Array3Dir.XmZp, new ValuePair<int, int, int>(-1, 0, 1));
            Array3DirDif.Add(Array3Dir.XpYm, new ValuePair<int, int, int>(1, -1, 0));
            Array3DirDif.Add(Array3Dir.XpYp, new ValuePair<int, int, int>(1, 1, 0));
            Array3DirDif.Add(Array3Dir.XpZm, new ValuePair<int, int, int>(1, 0, -1));
            Array3DirDif.Add(Array3Dir.XpZp, new ValuePair<int, int, int>(1, 0, 1));
            Array3DirDif.Add(Array3Dir.YmZm, new ValuePair<int, int, int>(0, -1, -1));
            Array3DirDif.Add(Array3Dir.YmZp, new ValuePair<int, int, int>(0, -1, 1));
            Array3DirDif.Add(Array3Dir.YpZm, new ValuePair<int, int, int>(0, 1, -1));
            Array3DirDif.Add(Array3Dir.YpZp, new ValuePair<int, int, int>(0, 1, 1));
            Array3DirDif.Add(Array3Dir.XmYmZm, new ValuePair<int, int, int>(-1, -1, -1));
            Array3DirDif.Add(Array3Dir.XmYmZp, new ValuePair<int, int, int>(-1, -1, 1));
            Array3DirDif.Add(Array3Dir.XmYpZm, new ValuePair<int, int, int>(-1, 1, -1));
            Array3DirDif.Add(Array3Dir.XmYpZp, new ValuePair<int, int, int>(-1, 1, 1));
            Array3DirDif.Add(Array3Dir.XpYmZm, new ValuePair<int, int, int>(1, -1, -1));
            Array3DirDif.Add(Array3Dir.XpYmZp, new ValuePair<int, int, int>(1, -1, 1));
            Array3DirDif.Add(Array3Dir.XpYpZm, new ValuePair<int, int, int>(1, 1, -1));
            Array3DirDif.Add(Array3Dir.XpYpZp, new ValuePair<int, int, int>(1, 1, 1));
        }
        public Dictionary<Array2Dir, ValuePair<int, int>> Array2DirDif;
        public Dictionary<Array3Dir, ValuePair<int, int, int>> Array3DirDif;
    }

    public static ValuePair<int, int> Dif(this Array2Dir dir)
    {
        return UtilSingleton.Singleton.Array2DirDif[dir];
    }
}




public partial class Util
{
    public static bool Not(this bool b)
    {
        return !b;
    }
    public static int ToFloor(this int bunshi, int divisor)
    {
        return (int)(bunshi / divisor);
    }
    public static long ToFloor(this long bunshi, long divisor)
    {
        return (long)(bunshi / divisor);
    }
    public static long ToFloor(this long bunshi, int divisor)
    {
        return (long)(bunshi / divisor);
    }
    public static long ToCeil(this long bunshi, long divisor)
    {
        long v = (long)(bunshi / divisor);
        if (v * divisor == bunshi)
            return v;
        return v + 1;
    }
    public static long ToCeil(this long bunshi, int divisor)
    {
        long v = (long)(bunshi / divisor);
        if (v * divisor == bunshi)
            return v;
        return v + 1;
    }
    public static int ToCeil(this int bunshi, int divisor)
    {
        int v = (int)(bunshi / divisor);
        if (v * divisor == bunshi)
            return v;
        return v + 1;
    }
    public static IEnumerable<long> GetPrimeNumbers(long from, long to)
    {
        if (from > to)
            yield break;
        var isComposite = new bool[to + 1];
        long r = (long)Math.Pow(to, 0.5);
        for (long i = 2; i <= r; i++)
        {
            if (isComposite[i] == false)
            {
                for (long j = 2; j * i <= to; j++)
                {
                    isComposite[i * j] = true;
                }
            }
        }
        for (long i = from; i <= to; i++)
        {
            if (isComposite[i] == false)
                yield return i;
        }
    }
    public static string[] SplitSpace(this string s)
    {
        return s.Split(' ');
    }
    public static string JoinStrSpace<T>(this IEnumerable<T> source)
    {
        return JoinStr(source, " ");
    }
    public static string JoinStr<T>(this IEnumerable<T> source, string separator)
    {
        List<string> list = new List<string>();
        foreach (var s in source)
        {
            list.Add(s.ToString());
        }
        return list.ToArray().Join(separator);
    }
    public static void TimesF1(this int times, Action<int> action)
    {
        for (int i = 1; i <= times; i++)
        {
            action(i);
        }
    }
    public static void TimesM1(this int times, Action<int> action)
    {
        for (int i = 1; i < times; i++)
        {
            action(i);
        }
    }
    public static void Times(this int times, Action<int> action)
    {
        for (int i = 0; i < times; i++)
        {
            action(i);
        }
    }
    public static void Times(this int times, Action action)
    {
        for (int i = 0; i < times; i++)
        {
            action();
        }
    }
    public static T MinFirst<T>(this IEnumerable<T> source, Func<T, int> selector)
    {
        var min = int.MaxValue;
        T minT = default(T);
        foreach (var t in source)
        {
            var v = selector(t);
            if (v < min)
            {
                minT = t;
                min = v;
            }
        }
        return minT;
    }
    public static T MinLast<T>(this IEnumerable<T> source, Func<T, int> selector)
    {
        var min = int.MaxValue;
        T minT = default(T);
        foreach (var t in source)
        {
            var v = selector(t);
            if (v <= min)
            {
                minT = t;
                min = v;
            }
        }
        return minT;
    }
    public static T MaxFirst<T>(this IEnumerable<T> source, Func<T, int> selector)
    {
        var max = int.MinValue;
        T maxT = default(T);
        foreach (var t in source)
        {
            var v = selector(t);
            if (v > max)
            {
                maxT = t;
                max = v;
            }
        }
        return maxT;
    }
    public static T MaxLast<T>(this IEnumerable<T> source, Func<T, int> selector)
    {
        var max = int.MinValue;
        T maxT = default(T);
        foreach (var t in source)
        {
            var v = selector(t);
            if (v >= max)
            {
                maxT = t;
                max = v;
            }
        }
        return maxT;
    }
}

public static partial class Util
{
    public static TimeSpan MeasureTime(Action action)
    {
        var sw = Stopwatch.StartNew();
        action();
        Debug.WriteLine(new { action.Method.Name, sw.Elapsed }.ToString());
        return sw.Elapsed;
    }
    public static T MeasureTime<T>(Func<T> func)
    {
        var sw = Stopwatch.StartNew();
        var t = func();
        Debug.WriteLine(new { func.Method.Name, sw.Elapsed }.ToString());
        return t;
    }

    public static void ActAs<T>(this object obj, Action<T> action) where T : class
    {
        var t = obj as T;
        if (t != null)
            action(t);
    }

    public static bool IsContainedIn<T>(this T t, params T[] array)
    {
        return array.Contains(t);
    }

    public static bool IsContainedIn<T>(this T t, IEnumerable<T> array)
    {
        return array.Contains(t);
    }

    public static void SetNullStringPropertiesToEmpty<T>(this T t)
    {
        var ps = t.GetType().GetProperties().Where(x => x.CanWrite);
        ps.Where(x => x.PropertyType == typeof(string) && x.GetValue(t, null) == null).ForEach(x => x.SetValue(t, string.Empty, null));
    }

    public static decimal ToZeroableDecimal(this string s)
    {
        decimal res;
        if (decimal.TryParse(s, out res))
            return res;
        return 0.0M;
    }
    public static int ToZeroableInt(this string s)
    {
        int res;
        if (int.TryParse(s, out res))
            return res;
        return 0;
    }

    public static TSource TakeMax<TSource>(this IEnumerable<TSource> source, Func<TSource, int> maxSelector)
    {
        int max = int.MinValue;
        TSource result = default(TSource);
        foreach (var s in source)
        {
            int p = maxSelector(s);
            if (p > max)
            {
                max = p;
                result = s;
            }
        }
        return result;
    }

    public static int ToInt(this Enum e)
    {
        return e.ToString("D").ToInt();
    }
    public static byte ToByte(this Enum e)
    {
        return e.ToString("D").ToByte();
    }

    public static string Join(this string[] array, string separator)
    {
        return string.Join(separator, array);
    }

    public static Func<TArg, TResult> AsArgument<TArg, TResult>(this TArg dummy, Func<TArg, TResult> func)
    {
        return (TArg a) => func(a);
    }

    public static T? ToEnumNullable<T>(this int? i) where T : struct
    {
        return i.HasValue && Enum.IsDefined(typeof(T), i) ? (T?)Enum.Parse(typeof(T), i.Value.ToString()) : null;
    }
    public static T ToEnum<T>(this int? i, T defaultValue)
    {
        return i.HasValue && Enum.IsDefined(typeof(T), i) ? (T)Enum.Parse(typeof(T), i.Value.ToString()) : defaultValue;
    }
    public static T ToEnum<T>(this int i, T defaultValue)
    {
        return Enum.IsDefined(typeof(T), i) ? (T)Enum.Parse(typeof(T), i.ToString()) : defaultValue;
    }

    //http://d.hatena.ne.jp/m-hiyama/20080116/1200468797
    public static Func<T, V> CPS<T, U, V>(this Func<T, U> cont1, Func<U, V> cont2)
    {
        return u => cont2(cont1(u));
    }
    public static Func<Func<U, V>, Func<T, V>> CPS<T, U, V>(this Func<T, U> cont)
    {
        return f => t => f(cont(t));
    }
    public static string GetString(this int t, Func<int, string> selector)
    {
        return t.GetString(selector, "");
    }
    public static string GetString(this int t, Func<int, string> selector, string nullValue)
    {
        return t == 0 ? selector(t) : nullValue;
    }
    public static string GetString(this long t, Func<long, string> selector)
    {
        return t.GetString(selector, "");
    }
    public static string GetString(this long t, Func<long, string> selector, string nullValue)
    {
        return t == 0 ? selector(t) : nullValue;
    }
    public static U Get<T, U>(this T t, Func<T, U> selector) where T : class
    {
        return t.Get(selector, default(U));
    }
    public static U Get<T, U>(this T t, Func<T, U> selector, U nullValue) where T : class
    {
        return t != null ? selector(t) : nullValue;
    }

    public static IEnumerable<T> EnumerateEnum<T>()
    {
        return Enum.GetValues(typeof(T)).OfType<T>();
    }

    public static T Apply<T>(this T t, Action<T> action)
    {
        action(t);
        return t;
    }
    public static U Apply<T, U>(this T t, Func<T, U> f)
    {
        return f(t);
    }

    public static U Match<T, U>(this Dictionary<Func<T, bool>, U> dic, T key)
    {
        return dic.First(pp => pp.Key(key)).Value;
    }
    public static U Match<T, U>(this Dictionary<Func<T, bool>, U> dic, T key, U defaultValue)
    {
        if (dic.Any(pp => pp.Key(key)))
            return dic.First(pp => pp.Key(key)).Value;
        else
            return defaultValue;
    }
    public static U Match<U>(Dictionary<Func<bool>, U> dic, U defaultValue)
    {
        if (dic.Any(pp => pp.Key()))
            return dic.First(pp => pp.Key()).Value;
        else
            return defaultValue;
    }
    [Obsolete("引数なしバージョンでいいかも")]
    public static U Match<T, U>(this T key, Dictionary<Func<T, bool>, U> dic, U defaultValue)
    {
        if (dic.Any(pp => pp.Key(key)))
            return dic.First(pp => pp.Key(key)).Value;
        else
            return defaultValue;
    }
    public static U Match<T, U>(this Dictionary<T, U> dic, T key, U defaultValue)
    {
        return Match(dic, key, defaultValue, t => defaultValue);
    }
    public static U Match<T, U>(this Dictionary<T, U> dic, T key, U defaultValue, Func<T, U> defaultFunc)
    {
        if (dic.ContainsKey(key))
            return dic[key];
        else
            return defaultFunc(key);
    }

    public static string RegexReplace(this string s, string pattern, string replacement)
    {
        return Regex.Replace(s ?? "", pattern, replacement);
    }
}


//IEnumerable拡張
public static partial class Util
{
    public static IEnumerable<T3> Zip<T1, T2, T3>(this IEnumerable<T1> source1, IEnumerable<T2> source2, Func<T1, int> keySelector1, Func<T2, int> keySelector2, Func<T1, T2, T3> valueSelector)
    {
        using (var e1 = source1.OrderBy(keySelector1).GetEnumerator())
        using (var e2 = source2.OrderBy(keySelector2).GetEnumerator())
        {
            var b1 = e1.MoveNext();
            var b2 = e2.MoveNext();
            while (b1 || b2)
            {
                var t1 = b1 ? e1.Current : default(T1);
                var t2 = b2 ? e2.Current : default(T2);
                while (b1 && keySelector1(t1) < keySelector2(t2))
                {
                    yield return valueSelector(t1, default(T2));
                    b1 = e1.MoveNext();
                    t1 = b1 ? e1.Current : default(T1);
                }
                while (b2 && keySelector2(t2) < keySelector1(t1))
                {
                    yield return valueSelector(default(T1), t2);
                    b2 = e2.MoveNext();
                    t2 = b2 ? e2.Current : default(T2);
                }
                yield return valueSelector(t1, t2);
                b1 = e1.MoveNext();
                b2 = e2.MoveNext();
            }
        }
    }

    private static void ZipTest()
    {
        var s1 = new[] { "0", "1", "2", "3" };
        var s2 = new[] { "0", "1", "1" };
        var r = s1.Zip(s2, s => s.ToInt(), s => s.ToInt(), (q, w) => new { q, w });
        foreach (var rr in r)
            rr.Trace();
    }

    public static IEnumerable<T3> Zip<T1, T2, T3>(this IEnumerable<T1> source1, IEnumerable<T2> source2, Func<T1, T2, T3> selector)
    {
        using (var e1 = source1.GetEnumerator())
        using (var e2 = source2.GetEnumerator())
        {
            var b1 = e1.MoveNext();
            var b2 = e2.MoveNext();
            while (b1 || b2)
            {
                var t1 = b1 ? e1.Current : default(T1);
                var t2 = b2 ? e2.Current : default(T2);
                yield return selector(t1, t2);
                b1 = e1.MoveNext();
                b2 = e2.MoveNext();
            }
        }
    }
    public static IEnumerable<T3> ZipWith<T1, T2, T3>(this IEnumerable<T1> source1, IEnumerable<T2> source2, Func<T1, T2, T3> selector)
    {
        using (var e1 = source1.GetEnumerator())
        using (var e2 = source2.GetEnumerator())
            while (e1.MoveNext() && e2.MoveNext())
                yield return selector(e1.Current, e2.Current);
    }

    public static IEnumerable<T> Up<T>(this T t)
    {
        yield return t;
    }

    public static IEnumerable<T> Unfold<T>(this T t, Func<T, T> converter)
    {
        while (true)
        {
            yield return t;
            t = converter(t);
        }
    }

    public static IEnumerable<TAccumulate> Scan<TSource, TAccumulate>(this IEnumerable<TSource> source, TAccumulate seed, Func<TAccumulate, TSource, TAccumulate> func)
    {
        TAccumulate a = seed;
        foreach (var t in source)
        {
            a = func(a, t);
            yield return a;
        }
    }
    public static IEnumerable<TSource> Scan<TSource>(this IEnumerable<TSource> source, Func<TSource, TSource, TSource> func)
    {
        TSource a = default(TSource);
        foreach (var t in source)
        {
            a = func(a, t);
            yield return a;
        }
    }

    public static void ForEach<T>(this IEnumerable<T> source, Action<T> action)
    {
        foreach (var t in source)
            action(t);
    }
    public static void ForEach<T>(this IEnumerable<T> source, Action<T, int> action)
    {
        int index = 0;
        foreach (var t in source)
            action(t, index++);
    }

    public static int Count(this System.Collections.IEnumerable source)
    {
        int count = 0;
        foreach (var t in source)
            count++;

        return count;
    }

    public static int MaxOrDefault(this IEnumerable<int> source)
    {
        return source.Count() == 0 ? 0 : source.Max();
    }

}


//変換
public static partial class Util
{
    public static DateTime? ParseNullableDateTime(this string s)
    {
        if (s == null)
            return null;
        DateTime i;
        if (DateTime.TryParse(s, out i))
            return i;
        return null;
    }
    public static int? ParseNullableInt(this string s)
    {
        if (s == null)
            return null;
        int i;
        if (int.TryParse(s, out i))
            return i;
        return null;
    }
    public static long? ParseNullableLong(this string s)
    {
        if (s == null)
            return null;
        long i;
        if (long.TryParse(s, out i))
            return i;
        return null;
    }
    public static bool? ParseNullableBool(this string s)
    {
        if (s == null)
            return null;
        bool i;
        if (bool.TryParse(s, out i))
            return i;
        return null;
    }
    public static byte? ParseNullableByte(this string s)
    {
        if (s == null)
            return null;
        byte i;
        if (byte.TryParse(s, out i))
            return i;
        return null;
    }

    public static bool ToBool(this string s)
    {
        if (s == null)
            return false;
        if (s.Trim().ToLower() == bool.TrueString.ToLower())
            return true;
        if (s.Trim().ToLower() == bool.FalseString.ToLower())
            return false;
        if (s.Trim() == "0")
            return false;
        if (s.Trim() == "1")
            return true;
        return false;
    }
    public static int ToInt(this byte b)
    {
        return b.ToString().ToInt();
    }
    public static int ToInt(this char c)
    {
        return c.ToString().ToInt();
    }
    public static int ToInt(this string s)
    {
        return ToInt(s, false);
    }
    public static int ToInt(this string s, bool throwException)
    {
        if (throwException) return int.Parse(s);

        int i = 0;
        return int.TryParse(s, out i) ? i : i;
    }
    public static int ToInt(this DayOfWeek dayOfWeek)
    {
        return (int)dayOfWeek;
    }

    public static decimal ToDecimal(this string s)
    {
        return ToNullable<decimal>(s) ?? 0;
    }
    public static long ToLong(this string s)
    {
        return ToNullable<long>(s) ?? 0;
    }

    public static double ToDouble(this string s)
    {
        return ToNullable<double>(s) ?? 0;
    }

    public static Byte ToByte(this int i)
    {
        return (byte)i;
    }
    public static Byte ToByte(this string b)
    {
        return ToByte(b, false);
    }
    public static Byte ToByte(this string b, bool throwException)
    {
        return throwException ? byte.Parse(b) : ToNullable<byte>(b) ?? 0;
    }

    public static char ToChar(this string s)
    {
        return char.Parse(s);
    }

    public static string ToStr(object obj)
    {
        return obj != null ? obj.ToString() : "";
    }

    /// <summary>
    /// 変換できないときはDateTime.Now
    /// </summary>
    /// <param name="s"></param>
    /// <returns></returns>
    public static DateTime ToDateTime(this string s)
    {
        var res = ToNullableDateTime(s);
        if (res == null)
            return DateTime.Now;
        return res.Value;
    }

    public static DateTime? ToNullableDateTime(this string s)
    {
        DateTime result;
        if (DateTime.TryParse(s, out result))
            return result;
        return null;
    }

    public static string GetAbbreviatedDayName(int d)
    {
        if (d == 7) return ""; // todo
        return Thread.CurrentThread.CurrentCulture.DateTimeFormat.GetAbbreviatedDayName((DayOfWeek)d);
    }
    public static string GetDayName(int d)
    {
        if (d == 7) return ""; // todo
        return Thread.CurrentThread.CurrentCulture.DateTimeFormat.GetDayName((DayOfWeek)d);
    }

    // TODO: yamaguchi 処理の重さが気になりだしたらReflectionを止める
    public static Nullable<T> ToNullable<T>(this string value) where T : struct
    {
        if (string.IsNullOrEmpty(value)) return null;

        var type = typeof(T);
        var types = new[] { typeof(string), GetReferenceType(type) };
        var method = type.GetMethod("TryParse", types);
        if (null == method)
            throw new NotSupportedException();

        var parameters = new object[] { value, new T() };
        if ((bool)method.Invoke(null, parameters))
            return (T)parameters.Where(p => p.GetType() == type).Single();
        else
            return null;
    }

    private static Type GetReferenceType<T>()
    {
        return GetReferenceType(typeof(T));
    }

    private static Type GetReferenceType(Type type)
    {
        return Type.GetType(type.FullName + "&");
    }
}


//匿名型生成
public static partial class Util
{
    public static object ToObject(PropertyInfo p, string val)
    {
        try
        {
            return new Dictionary<Type, Func<object>>
				{
					{ typeof( bool ), () => (object)( val == "1" || ToNullable<bool>( val ) == true ) },
					{ typeof( bool? ), () => (object)( val == "1" || ToNullable<bool>( val ) == true ? true : ( val == "0" || ToNullable<bool>( val ) == false ? false : (bool?)null) ) },
					{ typeof( decimal ), () => (object)( ToNullable<decimal>( val ) ?? 0m ) },
					{ typeof( byte ), () => (object)ToByte( val, true ) },
					{ typeof( byte? ), () => (object)ToNullable<byte>( val ) },
					{ typeof( int ), () => (object)ToInt( val, true ) },
					{ typeof( int? ), () => (object)ToNullable<int>( val ) },
					{ typeof( DateTime ), () => (object)ToDateTime( val ) },
					{ typeof( DateTime? ), () => (object)ToNullable<DateTime>( val ) },
					{ typeof( char? ), () => (object)ToNullable<char>( val ) },
				}.Match(p.PropertyType, () => (object)val)();
        }
        catch
        {
            new { p.Name, p.PropertyType, val }.Trace();
            throw;
        }
    }

    // 匿名型以外の型(専用のコンストラクタをもたない型)にも対応できるように変更
    public static T As<T>(this System.Collections.Specialized.NameValueCollection collection, T t)
    {
        var properties = t.GetType().GetProperties();
        var ctor = t.GetType().GetConstructor(properties.Select(p => p.PropertyType).ToArray());
        if (ctor != null)
        {
            var values = from p in t.GetType().GetProperties()
                         let val = collection[p.Name] != null ? collection[p.Name] : ToStr(p.GetValue(t, null))
                         select ToObject(p, val);
            var er = values.ToArray();
            return values.ToArray().As(t);
        }
        else
        {
            var pairs = from p in properties
                        let val = collection[p.Name] != null ? collection[p.Name] : (p.GetValue(t, null) != null ? p.GetValue(t, null).ToString() : string.Empty)
                        select new KeyValuePair<string, string>(p.Name, val);

            var obj = (T)Activator.CreateInstance(typeof(T));

            foreach (var p in properties)
            {
                if (obj.GetType().GetProperty(p.Name) != null)
                    p.SetValue(obj, ToObject(p, pairs.Single(pair => pair.Key == p.Name).Value), null);
            }

            return obj;
        }
    }

    public static T As<T>(this object obj, T t)
    {
        var values = from p in t.GetType().GetProperties()
                     let op = obj.GetType().GetProperty(p.Name)
                     select op != null ? Convert.ChangeType(op.GetValue(obj, null), p.PropertyType) : p.GetValue(t, null);
        return values.ToArray().As(t);
    }
    public static T As<T>(this object obj)
    {
        var values = from p in typeof(T).GetProperties()
                     let op = obj.GetType().GetProperty(p.Name)
                     select op != null ? Convert.ChangeType(op.GetValue(obj, null), p.PropertyType) : p.GetConstantValue();
        return values.ToArray().As<T>();
    }

    public static T As<T>(this object[] values, T t)
    {
        return (T)Activator.CreateInstance(typeof(T), values);
    }
    public static T As<T>(this object[] values)
    {
        return (T)Activator.CreateInstance(typeof(T), values);
    }

    public static T SplitAs<T>(this string values, string separator, T t)
    {
        if (values == null) return t;

        var val = values.Split(separator.ToCharArray(), StringSplitOptions.None);
        return t.GetType().GetProperties().Select((p, i) => val.Length > i ? ToObject(p, val[i]) : p.GetValue(t, null)).ToArray().As(t);
    }

    public static IEnumerable<T> EnumerateAs<T>(this System.Collections.IEnumerable source, T t)
    {
        foreach (var obj in source)
        {
            var o = obj;
            yield return o.As(t);
        }
    }
    public static IEnumerable<T> EnumerateAs<T>(this System.Collections.IEnumerable source)
    {
        foreach (var obj in source)
        {
            var o = obj;
            yield return o.As<T>();
        }
    }

    public static void Test()
    {
        var a = new { s = "s", i = 1, b = true };
        var b = a.As(new { i = 0, c = 'a' });
        b.Trace();

        "QQ_WW".SplitAs("_", new { q = "", w = "" }).Trace();

        var ar = new object[]
			{
				new { s="q", i = 1},
				new { s="w", i = 2},
				new { s="e", i = 3},
				new { i = 4},
			};
        ar.EnumerateAs(new { i = 0, s = "" }).Trace();

        var c = new System.Collections.Specialized.NameValueCollection();
        c.Add("q", "1");
        c.Add("w", "b");
        c.Add("e", "c");
        var d = c.As(new { q = 0, e = "", r = 123 });
        d.Trace();
    }
}


//trace
public static partial class Util
{
    public static string Trace(this object obj)
    {
        if (GCJConst.MYTRACE)
        {
            string s = TraceInner(obj, new int[] { });
            TraceStringLine("");
            return s;
        }
        else
        {
            return "";
        }
    }
    public static string TraceInner(this object obj, int[] index)
    {
        if (obj is string)
            return TraceStringLine(obj == null ? "[null]" : obj.ToString());

        var str = "";
        //Action<string> trace = s => { str += s; TraceString(s != null ? s.ToString() : null); };
        Action<string, object> trace = (name, o) =>
        {
            string s = "";
            if (index.Length == 0)
                s = string.Format("{0}={1} ", name, o);
            else
                s = string.Format("{3}{0}[{2}]={1} ", name, o, index.JoinStr(","), "".PadLeft(index.Length * 2, ' '));
            str += s;
            TraceString(s != null ? s.ToString() : null);
        };
        Action<string> traceLine = s => { str += s; TraceStringLine(s != null ? s.ToString() : null); };
        if (obj == null)
            traceLine("[null]");
        else if (obj is IEnumerable)
        {
            int i = 0;
            foreach (var t in (IEnumerable)obj)
            {
                var list = index.ToList();
                list.Add(i++);
                traceLine("");
                TraceInner(t, list.ToArray());
            }
        }
        else
        {
            bool hasMember = false;
            foreach (var p in obj.GetType().GetProperties(System.Reflection.BindingFlags.Public | System.Reflection.BindingFlags.GetProperty | System.Reflection.BindingFlags.Instance))
            {
                var o = p.GetValue(obj, null);
                if (o is IEnumerable)
                    TraceInner((IEnumerable)o, index);
                else
                    trace(p.Name, o);
                hasMember |= true;
            }
            if (!obj.GetType().IsValueType)
            {
                foreach (var p in obj.GetType().GetFields())
                {
                    var o = p.GetValue(obj);
                    if (o is IEnumerable)
                        TraceInner((IEnumerable)o, index);
                    else
                        trace(p.Name, o);
                }
            }
            if (!hasMember)
                traceLine(obj.ToString());
        }
        return str;
    }

    private static string TraceString(string val)
    {
        //Console.Write(val);
        System.Diagnostics.Debug.Write(val);
        return val;
    }

    private static string TraceStringLine(string val)
    {
        //Console.WriteLine(val);
        System.Diagnostics.Debug.WriteLine(val);
        return val;
    }
}


//正規表現/文字列
public static partial class Util
{
    public static String Capture(this string txt, string pattern)
    {
        return Capture(txt, pattern, RegexOptions.None);
    }
    public static String Capture(this string txt, string pattern, RegexOptions options)
    {
        if (string.IsNullOrEmpty(txt)) return string.Empty;

        return new Regex(pattern, options).Match(txt).Value;
    }

    public static string GetRegexGroupValue(string txt, string pattern, string group)
    {
        return GetRegexGroupValue(txt, pattern, group, RegexOptions.None);
    }
    public static string GetRegexGroupValue(string txt, string pattern, string group, RegexOptions option)
    {
        return string.IsNullOrEmpty(txt) ? string.Empty : new Regex(pattern, option).Match(txt).Groups[group].Value;
    }

    public static GroupExtractor CreateGroupExtractor(string txt, string pattern, string group)
    {
        return CreateGroupExtractor(txt, pattern, group, RegexOptions.None);
    }
    public static GroupExtractor CreateGroupExtractor(string txt, string pattern, string group, RegexOptions option)
    {
        if (string.IsNullOrEmpty(txt))
            return delegate(string argTxt)
            {
                return GetRegexGroupValue(argTxt, pattern, group, option);
            };
        else if (string.IsNullOrEmpty(group))
            return delegate(string argGroup)
            {
                return GetRegexGroupValue(txt, pattern, argGroup, option);
            };
        else
            throw new ArgumentException("txt/groupとも指定されていません");
    }

    public static IEnumerable<string> EnumerateMatches(string txt, string pattern)
    {
        foreach (Match m in new Regex(pattern).Matches(txt))
            yield return m.Value;
    }

    public static string FormatWith(this string format, params object[] args)
    {
        return string.Format(format, args);
    }
    public static bool IsNullOrEmpty(this string str)
    {
        return string.IsNullOrEmpty(str);
    }
    public static bool IsNotNullNorEmpty(this string str)
    {
        return !string.IsNullOrEmpty(str);
    }
    public static string AddCssClass(this string str, string cssClass)
    {
        if (str == null) str = string.Empty;
        if (cssClass == null) cssClass = string.Empty;
        return new[] { str.Trim().Split(' ').ToArray(), cssClass.Trim().Split(' ').ToArray() }.SelectMany(x => x)
            .Distinct().Where(x => x != "").ToArray().Join(" ");
    }
    public static bool ContainsCssClass(this string str, string cssClass)
    {
        if (str == null)
            return false;
        return str.Trim().Split(' ').ToArray().Contains(cssClass);
    }
}
public delegate string GroupExtractor(string param);


//File/Dir
public static partial class Util
{
    public static IEnumerable<string> EnumerateFiles(string folder)
    {
        return EnumerateFiles(folder, true);
    }
    public static IEnumerable<string> EnumerateFiles(string folder, bool recursive)
    {
        return EnumerateAll(Directory.GetFiles, folder, recursive);
    }

    public static IEnumerable<string> EnumerateDirectories(string folder)
    {
        return EnumerateDirectories(folder, true);
    }
    public static IEnumerable<string> EnumerateDirectories(string folder, bool recursive)
    {
        return EnumerateAll(Directory.GetDirectories, folder, recursive);
    }

    private static IEnumerable<string> EnumerateAll(Func<string, string, string[]> searchMethod, string folder, bool recursive)
    {
        foreach (string path in searchMethod(folder, "*"))
            yield return path;

        if (recursive)
            foreach (string d in Directory.GetDirectories(folder, "*"))
                foreach (string path in EnumerateAll(searchMethod, d, true))
                    yield return path;
    }
}


//Lambda/Expr
public static partial class Util
{
    public static Action<TArg0> Lambda<TArg0>(Action<TArg0> lambda) { return lambda; }
    public static Func<TResult> Lambda<TResult>(Func<TResult> lambda) { return lambda; }
    public static Func<TArg0, TResult> Lambda<TArg0, TResult>(Func<TArg0, TResult> lambda) { return lambda; }
    public static Func<TArg0, TArg1, TResult> Lambda<TArg0, TArg1, TResult>(Func<TArg0, TArg1, TResult> lambda) { return lambda; }
    public static Func<TArg0, TArg1, TArg2, TResult> Lambda<TArg0, TArg1, TArg2, TResult>(Func<TArg0, TArg1, TArg2, TResult> lambda) { return lambda; }

    public static Expression<Action<TArg0>> Expr<TArg0>(Expression<Action<TArg0>> expr) { return expr; }
    public static Expression<Func<TResult>> Expr<TResult>(Expression<Func<TResult>> expr) { return expr; }
    public static Expression<Func<TArg0, TResult>> Expr<TArg0, TResult>(Expression<Func<TArg0, TResult>> expr) { return expr; }
    public static Expression<Func<TArg0, TArg1, TResult>> Expr<TArg0, TArg1, TResult>(Expression<Func<TArg0, TArg1, TResult>> expr) { return expr; }
    public static Expression<Func<TArg0, TArg1, TArg2, TResult>> Expr<TArg0, TArg1, TArg2, TResult>(Expression<Func<TArg0, TArg1, TArg2, TResult>> expr) { return expr; }
}
