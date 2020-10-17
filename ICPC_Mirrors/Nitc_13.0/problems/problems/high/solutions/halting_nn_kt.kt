import java.util.*
import java.io.*

val br = BufferedReader(InputStreamReader(System.`in`))
var st = StringTokenizer("")

fun nextInt(): Int {
  while (!st.hasMoreTokens()) {
    st = StringTokenizer(br.readLine())
  }
  return st.nextToken().toInt()
}

fun main(args: Array<String>) = PrintWriter(System.out).use { 
  with(it) {
    val n = nextInt()
    val a = IntArray(n) { nextInt() }
    val b = IntArray(n) { a[it] }
    for (i in 1 until n) {
      b[i] += b[i - 1]
    }
    val answer = IntArray(b[n - 1] + 1) { -1 }
    val maxBlock = a.max()!!
    val q = nextInt()
    for (iq in 0 until q) {
      val k = nextInt()
      if (k < maxBlock) {
        println("Impossible")
        continue
      }
      if (answer[k] < 0) {
        var cur = 0
        var curAnswer = 0
        var alreadyHave = 0
        while (cur < n) {
          var left = cur
          var right = n
          while (left < right - 1) {
            val mid = (left + right) shr 1
            if (b[mid] - alreadyHave > k) {
              right = mid
            } else {
              left = mid
            }
          }
          curAnswer++
          cur = left + 1
          alreadyHave = b[left]
        }
        answer[k] = curAnswer
      }
      println(answer[k])
    }
  }
}