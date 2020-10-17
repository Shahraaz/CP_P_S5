import java.util.Collections
import kotlin.math.sin

fun main() {
	val n = readLine()!!.toInt()
	val xs = mutableListOf<Int>()
	val ys = mutableListOf<Double>()
	var x = 0
	while (xs.size < n) {
		val y = sin(x.toDouble())
		val binarySearch = Collections.binarySearch(ys, y).let { if (it >= 0) it else -1 - it }
		if (binarySearch == xs.size) {
			xs.add(x)
			ys.add(y)
		} else {
			xs[binarySearch] = x
			ys[binarySearch] = y
		}
		x++
	}
	xs.forEach { println(it) }
}
