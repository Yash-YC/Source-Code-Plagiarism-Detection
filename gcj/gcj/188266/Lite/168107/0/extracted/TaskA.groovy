def inputFileName = args[0]
def inputFile = new File(inputFileName)
def input = inputFile.readLines()
int tests = input[0].toInteger()
int currentLine = 1
new File(inputFileName + ".out").withWriter {w ->
  tests.times {
    println "Test $it"
    String[] bases = input[currentLine++].split(" ")
    int bestFit = 0
    a: for (int i = 2; ; i++) {
      println "Testing value $i"
      def ok = bases.every {String baseString ->
//        println "Testing base $baseString"
        int base = baseString.toInteger()
        int result = i
        Set olds = new HashSet()
        while (result != 1 && !olds.contains(result)) {
          olds.add(result)
//          println result
          int newResult = 0;
          while (result > 0) {
            int mod = result % base
            newResult += mod * mod
            result = result / base
          }
          result = newResult
        }
        return result == 1
      }
      if (ok) {
        println "Hit: $i"
        bestFit = i
        break;
      }
    }
    w.write "Case #${it+1}: $bestFit\n"
  }
}