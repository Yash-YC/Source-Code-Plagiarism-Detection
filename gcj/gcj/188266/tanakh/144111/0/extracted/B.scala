val sc = new java.util.Scanner(System.in)

for (caseno <- 1 to sc.nextInt()){
  val n, m = sc.nextInt()

  val mat = Array.fromFunction((_,_)=>(sc.nextLong(), sc.nextLong(), sc.nextLong()))(n, m)

  def time(ai:Int, aj:Int, bi:Int, bj:Int, tm: Long)={
    if (ai==bi){
      if (aj/2!=bj/2) tm+2
      else{
	val (s, w, t) = mat(ai/2)(aj/2)
	val ini = t
	val fr = s+w
	val ph = ((tm-ini)%fr+fr)%fr
	if (ph>=s) tm+1
	else tm+s-ph+1
      }
    }
    else{
      if (ai/2!=bi/2) tm+2
      else{
	val (s, w, t) = mat(ai/2)(aj/2)
	val ini = t
	val fr = s+w
	val ph = ((tm-ini)%fr+fr)%fr
	if (ph<s) tm+1
	else tm+fr-ph+1
      }
    }
  }

  def solve(): Long = {
    val tbl = Array.fromFunction((_, _)=> -1l)(n*2, m*2)
    
    val pq = new scala.collection.mutable.PriorityQueue[(Long, Int, Int)]()
    pq+=((0, 0, 0))
    
    val vect=Array((1, 0), (0, 1), (-1, 0), (0, -1))
    
    while(!pq.isEmpty){
      val (dist, i, j) = pq.dequeue()
      if (i==n*2-1 && j==m*2-1) return -dist
      if (tbl(i)(j)<0){
	tbl(i)(j)= -dist
	//println(i, j, dist)
	for ((di, dj) <- vect;
	     val (ni, nj) = (i+di, j+dj);
	     if ni>=0 && ni<2*n && nj>=0 && nj<2*m;
	     if tbl(ni)(nj)<0){
	  val nt = time(i, j, ni, nj, -dist)
	  pq+=((-nt, ni, nj))
	}
      }
    }
    -1
  }

  val ans = solve()

  printf("Case #%d: %d\n", caseno, ans)
}
