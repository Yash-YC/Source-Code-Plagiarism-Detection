val sc = new java.util.Scanner(System.in)

val n = sc.nextLine().toInt

for (caseno <- 1 to n){
  val bases = sc.nextLine().split(" +").map(_.toInt)

  def check(i: Int, base: Int): Boolean = {
    def p(n: Int): Int = {
      if (n==0) 0
      else{
	val c=n%base
	c*c+p(n/base)
      }
    }
    val arr = Array.make(base*base*10+1, false)

    def l(c: Int): Boolean = {
      if (arr(c)) false
      else if (c==1) true
      else{
	arr(c)=true
	l(p(c))
      }
    }

    l(p(i))
  }

  def find(i: Int): Int = {
    if (bases.forall(check(i, _)))
      i
    else
      find(i+1)
  }

  val ans = find(2)
  
  printf("Case #%d: %d\n", caseno, ans)
}
