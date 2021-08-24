Public Class Form1

    Dim smallinput As Boolean = True

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Dim fin As IO.StreamReader
        Dim fout As IO.StreamWriter
        If smallinput Then
            fin = New IO.StreamReader("A-small.in")
            fout = New IO.StreamWriter("A-small.out")
        Else
            fin = New IO.StreamReader("A-large.in")
            fout = New IO.StreamWriter("A-small.out")
        End If

        Dim T As Integer = Integer.Parse(fin.ReadLine())

        For casenum As Integer = 1 To T
            Dim numstr() As String = fin.ReadLine().Split(" ")
            Dim bases(numstr.Length - 1) As Integer
            For i As Integer = 0 To numstr.Length - 1
                bases(i) = Integer.Parse(numstr(i))
            Next

            Dim startnum As Integer = 2

            While 1
                Dim ishappy As Boolean = True
                For Each b As Integer In bases
                    Dim loopcount As Integer = 0
                    Dim num As Integer = GetNum(ToStringBase(startnum, b))
                    Dim sums As New Collections.ObjectModel.Collection(Of Integer)
                    While Not sums.Contains(num) And num <> 1
                        sums.Add(num)
                        num = GetNum(ToStringBase(num, b))
                    End While
                    If num <> 1 Then
                        ishappy = False
                        Exit For
                    End If
                Next
                If ishappy Then
                    Exit While
                End If
                startnum += 1
            End While
            fout.WriteLine("Case #" & casenum.ToString() & ": " & startnum.ToString())
        Next

        fin.Close()
        fout.Close()
    End Sub

    Public Function ToStringBase(ByVal num As Integer, ByVal base As Integer) As String
        Dim start As Integer = 1
        While base * start <= num
            start *= base
        End While
        Dim str As String = ""
        While start > 1
            Dim i As Integer = (num - (num Mod start)) / start
            str &= i.ToString()
            num -= i * start
            start /= base
        End While
        str &= num.ToString()
        Return str
    End Function

    Public Function GetNum(ByVal num As String) As Integer
        Dim digits(num.Length - 1) As Integer
        For i As Integer = 0 To num.Length - 1
            digits(i) = Asc(num(i)) - Asc("0")
        Next
        Dim sum As Integer = 0
        For Each i As Integer In digits
            sum += i * i
        Next
        Return sum
    End Function

End Class
