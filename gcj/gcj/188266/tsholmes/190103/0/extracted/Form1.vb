Public Class Form1

    Dim smallinput As Boolean = True

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Dim fin As IO.StreamReader
        Dim fout As IO.StreamWriter
        If smallinput Then
            fin = New IO.StreamReader("C-small.in")
            fout = New IO.StreamWriter("C-small.out")
        Else
            fin = New IO.StreamReader("C-large.in")
            fout = New IO.StreamWriter("C-large.out")
        End If

        Dim T As Integer = Integer.Parse(fin.ReadLine)

        For casenum As Integer = 1 To T
            Dim line() As String = fin.ReadLine().Split(" ")
            Dim C As ULong = Integer.Parse(line(0))
            Dim N As ULong = Integer.Parse(line(1))
            Dim ncr As Decimal = Factorial(C) / (Math.Max((Factorial(C - N)), 1) * Factorial(N))
            ncr = ncr / N
            fout.WriteLine("Case #" & casenum.ToString & ": " & ncr.ToString())
        Next

        fin.Close()
        fout.Close()
    End Sub

    Public Function Factorial(ByVal num As ULong) As ULong
        Dim i As ULong = num
        While num > 1
            num -= 1
            i *= num
        End While
        Return i
    End Function
End Class
