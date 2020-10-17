fun main() {
	readLn()
	val a = readInts().toMutableList()
	val b = readInts().toMutableList()
	if (a == b) return println(0)
	if (b.toSet().minus(a).isNotEmpty() || b.toSet().size == a.size) return println(-1)
	while (true) {
		val unneeded = a.toSet().minus(b).firstOrNull() ?: break
		a.setLeftmost(unneeded, b[0])
	}
	while (true) {
		val i = (0..a.size - 2).firstOrNull { a[it + 1] != a[it] && a.drop(it + 1).contains(a[it]) } ?: break
		while (a[i] != a[i + 1]) a.setLeftmost(a[i], a[i + 1])
	}
	while (true) {
		val i = (1..a.size - 2).firstOrNull { a[it - 1] != a[it] && a[it] == a[it + 1] } ?: break
		a.setLeftmost(a[i], a[i - 1])
	}

	while (true) {
		val i = (0..a.size - 2).firstOrNull { b[it + 1] != b[it] && b.drop(it + 1).contains(b[it]) } ?: break
		b.propagate(i)
	}
	while (true) {
		val i = (1..a.size - 2).firstOrNull { b[it - 1] == b[it] && b[it] != b[it + 1] } ?: break
		b.propagate(i)
	}

	val m = a.toSet().size
	val aa = a.takeLast(m).toMutableList()
	val bb = b.take(m).toMutableList()
	fun swap(k: Int) {
		if (k == m - 1) return
		if (k !in 0..m - 2) error("")
		a.setLeftmost(aa[0], aa[m - 1])
		a.setLast(aa[k])
		a.setLeftmost(aa[k], aa[m - 1])
		a.setLeftmost(aa[m - 1], aa[0])
		if (k == 0) repeat(a.size - m) { a.setLeftmost(aa[0], aa[m - 1]) }
		val t = aa[m - 1]
		aa[m - 1] = aa[k]
		aa[k] = t
	}
	for (i in aa.indices) {
		if (aa[i] == bb[i]) continue
		swap(aa.indexOf(bb[i]))
		swap(i)
	}
	for (i in 0..m - 2) {
		val cur = aa[i]
		val last = aa.last()
		repeat(a.size - m) { a.setLeftmost(cur, last) }
		a.setLast(cur)
		a.setLeftmost(cur, last)
		a.setLeftmost(last, cur)
		a.setLast(last)
		repeat(a.size - m) { a.setLeftmost(last, aa[i + 1]) }
	}
	val answer = answerForward.plus(answerBackward.reversed())
	println("${answer.size}\n${answer.joinToString("\n")}")
}

private fun MutableList<Int>.setAfterPointing(index: Int, value: Int, forward: Boolean) {
	if (!this.contains(value)) error("")
	printForeach(value, false, forward)
	this[index] = value
}

private fun MutableList<Int>.setLast(value: Int) {
	printForeach((1..this.size + 1).first { !this.contains(it) }, true, true)
	this.setAfterPointing(this.lastIndex, value, true)
}

private fun MutableList<Int>.setLeftmost(searched: Int, value: Int) {
	printForeach(searched, true, true)
	this.setAfterPointing(indexOf(searched), value, true)
}

private fun MutableList<Int>.propagate(i: Int) {
	if (this.take(i + 1).contains(this[i + 1])) error("")
	printForeach(this[i], false, false)
	printForeach(this[i + 1], true, false)
	this[i] = this[i + 1]
}

private val answerForward = mutableListOf<String>()
private val answerBackward = mutableListOf<String>()

private fun printForeach(value: Int, reference: Boolean, forward: Boolean) {
	val answer = if (forward) answerForward else answerBackward
	answer.add("foreach (\$a as ${if (reference) "&" else " "}\$x) if (\$x == $value) break;")
}

private fun readLn() = readLine()!!
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
