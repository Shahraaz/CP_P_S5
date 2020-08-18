fun main() {
    val times = readLine()!!.split(" ").map { it.toDouble() }.sorted()
    val opp = readLine()!!.toDouble()
    when {
        times.subList(0,3).average() > opp+1e-3 -> println("impossible")
        times.subList(1,4).average() < opp+1e-3 -> println("infinite")
        else -> println("%.2f".format(3*opp - times[1] - times[2]))
    }
}
