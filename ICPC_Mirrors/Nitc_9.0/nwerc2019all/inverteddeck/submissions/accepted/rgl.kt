import java.util.*

fun main(args: Array<String>) {
  val n = readLine()!!.toInt()
  val x = readLine()!!.split(' ').map(String::toInt).toTypedArray()
  val y = x.copyOf().sorted()

  var i:Int = 0
  var j:Int = n-1
  while (i<j && x[i] == y[i]) ++i
  while (i<j && x[j] == y[j]) --j

  for (a in 0 until j-i+1) {
    if (x[i+a] != y[j-a]) {
      println("impossible")
      return
    }
  }
  println("" + (i+1) + " " + (j+1))
}
