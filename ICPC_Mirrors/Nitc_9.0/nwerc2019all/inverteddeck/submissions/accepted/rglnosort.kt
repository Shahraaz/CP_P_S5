import java.util.*

fun main(args: Array<String>) {
  val n = readLine()!!.toInt()
  val x = readLine()!!.split(' ').map(String::toInt).toTypedArray()

  var i:Int = 0
  var j:Int = n-1
  while (i<j && x[i] <= x[i+1]) ++i
  while (i>0 && x[i] <= x[i-1]) --i
  while (i<j && x[j] >= x[j-1]) --j
  while (j<n-1 && x[j] >= x[j+1]) ++j

  for (a in 0 until (j-i+1)/2) {
    val tmp = x[i+a]; x[i+a] = x[j-a]; x[j-a] = tmp
  }
  for (a in 1 until n) {
    if (x[a] < x[a-1]) {
      println("impossible")
      return
    }
  }
  println("" + (i+1) + " " + (j+1))
}
