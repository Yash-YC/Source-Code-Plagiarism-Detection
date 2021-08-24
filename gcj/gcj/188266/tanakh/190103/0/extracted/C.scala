val sc = new java.util.Scanner(System.in)

for (caseno <- 1 to sc.nextInt()){
  val c, n = sc.nextInt()

  val tbl = Array.fromFunction(_ => -1.0)(1<<c)

  def bcnt(p: Int) = {
    var ret=0
    for (i <- 0 until c; if ((p&(1<<i))!=0)) ret+=1
    ret
  }

  def solve(b: Int): Double = {
    if (tbl(b)> -0.5) return tbl(b)

    if (bcnt(b)==c) return 0

    var self, oth, cnt = 0.0

    for (i <- 0 until 1<<c; if bcnt(i)==n){
      cnt+=1
      if ((b&i)==i) self+=1
      else oth+=solve(b|i)+1
    }

    val ret = ((oth+self)/cnt)/(1-self/cnt)
    tbl(b)=ret
    ret
  }

  printf("Case #%d: %.10f\n", caseno, solve(0))
}
