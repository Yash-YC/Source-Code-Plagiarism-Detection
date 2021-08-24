Module T
    Sub Main()
        Dim t = Convert.ToInt32(Console.ReadLine())
        For c = 1 To t
            Dim n = Convert.ToInt32(Console.ReadLine())
            Dim count(2501) As Int32
            For i = 1 To 2500
                count(i) = 0
            Next
            For i = 1 To 2 * n - 1
                Dim row = Console.ReadLine().Split().Select(
                Function(a) Convert.ToInt32(a)).ToArray()
                For j = 0 To n - 1
                    count(row(j)) = count(row(j)) + 1
                Next
            Next
            Dim mia = Enumerable.Range(1, 2500).Where(Function(q) count(q) Mod 2 > 0).
                Select(Function(q) String.Format("{0}", q))
            Console.WriteLine(String.Format("Case #{0}: {1}", c, String.Join(" ", mia)))
        Next
    End Sub
End Module
