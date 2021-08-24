def inputFileName = args[0]
def inputFile = new File(inputFileName)
def input = inputFile.readLines()
int tests = input[0].toInteger()
int currentLine = 1

new File(inputFileName + ".out").withWriter {w ->
  tests.times {
    println "Test $it"
    def dims = input[currentLine++].split(" ").collect { it.toInteger() }
    println dims
    int yy = dims[0]
    int xx = dims[1]
    def S = new int[yy * 2][xx * 2]
    def W = new int[yy * 2][xx * 2]
    def T = new int[yy * 2][xx * 2]
    def bestTimes = new int[yy * 2][xx * 2]
    for (int y = 0; y < yy; y++) {
      def swt = input[currentLine++].split(" ")
      println swt
      for (int x = 0; x < swt.length / 3; x++) {
        S[y * 2][x * 2] = swt[x * 3].toInteger()
        W[y * 2][x * 2] = swt[x * 3 + 1].toInteger()
        T[y * 2][x * 2] = swt[x * 3 + 2].toInteger()
      }
    }
    println S
    println W
    println T
    visit(yy, xx, S, W, T, bestTimes, 0, 0, 0)
    w.write "Case #${it + 1}: ${bestTimes[yy * 2 - 1][xx * 2 - 1]}\n"
  }
}

def visit(int yy, int xx, int[][] S, int[][] W, int[][] T, int[][] bestTimes, int x, int y, int t) {
  if (bestTimes[y][x] > 0 && bestTimes[y][x] <= t) {
    return
  }
  bestTimes[y][x] = t
  println "Visiting: ($y, $x): $t"
  // try N
  if (y < yy * 2 - 1) {
    if (y % 2 == 1) {
      println "Going N (block)"
      visit(yy, xx, S, W, T, bestTimes, x, y + 1, t + 2)
    }
    else {
      println "Going N"
      visit(yy, xx, S, W, T, bestTimes, x, y + 1, t + timeUntilOnNS(S, W, T, x, y, t) + 1)
    }
  }
  // try E
  if (x < xx * 2 - 1) {
    if (x % 2 == 1) {
      println "Going E (block)"
      visit(yy, xx, S, W, T, bestTimes, x + 1, y, t + 2)
    }
    else {
      println "Going E"
      visit(yy, xx, S, W, T, bestTimes, x + 1, y, t + timeUntilOnEW(S, W, T, x, y, t) + 1)
    }
  }
  // try S
  if (y > 0) {
    if (y % 2 == 0) {
      println "Going S (block)"
      visit(yy, xx, S, W, T, bestTimes, x, y - 1, t + 2)
    }
    else {
      println "Going S"
      visit(yy, xx, S, W, T, bestTimes, x, y - 1, t + timeUntilOnNS(S, W, T, x, y, t) + 1)
    }
  }
  // try W
  if (x > 0) {
    if (x % 2 == 0) {
      println "Going W (block)"
      visit(yy, xx, S, W, T, bestTimes, x - 1, y, t + 2)
    }
    else {
      println "Going W"
      visit(yy, xx, S, W, T, bestTimes, x - 1, y, t + timeUntilOnEW(S, W, T, x, y, t) + 1)
    }
  }
}

def timeUntilOnNS(int[][] S, int[][] W, int[][] T, int x, int y, int currentTime) {
  int t = T[y - (y % 2)][x - (x % 2)]
  int s = S[y - (y % 2)][x - (x % 2)]
  int w = W[y - (y % 2)][x - (x % 2)]
  int d = (currentTime - t) % (s + w)
  if (d < 0) {
    d += s + w
  }
  if (d < s) {
    return 0
  }
  return s + w - d
}

def timeUntilOnEW(S, W, T, int x, int y, int currentTime) {
  int t = T[y - (y % 2)][x - (x % 2)]
  int s = S[y - (y % 2)][x - (x % 2)]
  int w = W[y - (y % 2)][x - (x % 2)]
  int d = (currentTime - t) % (s + w)
  if (d < 0) {
    d += s + w
  }
  if (d > s) {
    return 0
  }
  return s - d
}

