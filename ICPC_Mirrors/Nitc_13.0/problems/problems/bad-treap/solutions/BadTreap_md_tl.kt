import java.util.Collections
import kotlin.math.sin

fun main() {
	val n = readLine()!!.toInt()
	data class Node(val x: Int, val y: Double, val next: Node?) : Comparable<Node> {
		override fun compareTo(other: Node): Int {
			return y.compareTo(other.y)
		}

		fun output() {
			println(x)
			next?.output()
		}
	}
	val stack = mutableListOf<Node>()
	var x = 0
	while (stack.size < n) {
		val y = sin(x.toDouble())
		val temp = Node(x, y, null)
		val binarySearch = Collections.binarySearch(stack, temp).let { if (it >= 0) it else -1 - it }
		val newNode = Node(x, y, stack.getOrNull(binarySearch - 1))
		if (binarySearch == stack.size) {
			stack.add(newNode)
		} else {
			stack[binarySearch] = newNode
		}
		x++
	}
	stack.last().output()
}
