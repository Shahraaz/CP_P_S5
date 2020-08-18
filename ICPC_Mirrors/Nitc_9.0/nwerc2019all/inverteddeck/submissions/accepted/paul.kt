fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map { it.toInt() }
    val b = a.sorted()
    val i = a.zip(b).indexOfFirst { it -> it.first != it.second }
    val j = a.zip(b).indexOfLast { it -> it.first != it.second }
    when {
        a == b -> println("1 1")
        a.subList(i,j+1) == b.subList(i,j+1).reversed() -> println("%d %d".format(i+1,j+1))
        else -> println("impossible")
    }
}