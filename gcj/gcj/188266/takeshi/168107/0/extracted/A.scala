package a

object A {
	
	import java.io._
	import java.util.Scanner
	import java.util.HashMap
 
	val scanner = new Scanner(System.in)
 
	val reader = new BufferedReader(new InputStreamReader(System.in))
 
	def longArray = reader.readLine.split(" ").map{ _.toLong }
	def l2 = (scanner.nextLong, scanner.nextLong)
	def l3 = (scanner.nextLong, scanner.nextLong, scanner.nextLong)

	def next = scanner.nextLong
 
	val happies = new HashMap[Long, HashMap[Long, Boolean]]
 
	def changeBase(n: Long, base: Long): List[Long] = {
		if(n < base) {
		  n :: Nil
		} else {
		  val d = n % base
		  changeBase(n / base, base) ::: (d :: Nil)
		}
	}
 
	def isHappy(n: Long, base: Long): Boolean = {
		var m = happies.get(n)
		if(m == null) {
		   m = new HashMap[Long, Boolean]
		   happies.put(n, m)
		}
		if(m.containsKey(n)) {
		  m.get(n)
		}
		val t = doCalculaHappy(n, base, new HashMap[Long, Boolean])
		t._1.foreach{ i => m.put(i, t._2)}
		t._2
	}
 
	def doCalculaHappy(n: Long, base: Long, m: HashMap[Long, Boolean]): (List[Long], Boolean) = {
	  if(m.containsKey(n)){
	    (m.keySet.toArray.toList.asInstanceOf[List[Long]], false)
	  } else {
		  m.put(n, true)
		  val chars = changeBase(n, base)
		  val sum = chars.map{ i => i * i}.foldLeft(0L){ _ + _}
		  if(sum == 1) {
			  (m.keySet.toArray.toList.asInstanceOf[List[Long]], true)
		  } else {
			  doCalculaHappy(sum, base, m)	
		  }	    
	  }
	}
 
	def findFor(list: List[Long]) = {
	  2.until(10000000).find {
	       j => list.forall{ base => isHappy(j, base)  }
	    }
	}
 
	def main(s: Array[String]): Unit = {
	  val n = reader.readLine.toInt
	  0.until(n).foreach { i =>
	    val l = longArray
	    val r = 2.until(java.lang.Integer.MAX_VALUE).find {
	       j => l.forall{ base => isHappy(j, base)  }
	    }
	    println("Case #" + (i + 1) + ": " + r.get)
	  }
	}
}
