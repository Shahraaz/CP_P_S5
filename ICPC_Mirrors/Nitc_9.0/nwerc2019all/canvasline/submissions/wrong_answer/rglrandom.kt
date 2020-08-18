import java.util.*

data class Rect(val l: Int, val r: Int)

fun main(args: Array<String>) {
  val scan = Scanner(System.`in`)

  val n = scan.nextInt()
  val rects = Array<Rect>(n, {_ -> Rect(scan.nextInt(), scan.nextInt())})
  val existing = Array<Int>(scan.nextInt(), {_ -> scan.nextInt()}).toSet()
  val have = Array<Int>(n, {_ -> 0})

  val added:MutableSet<Int> = HashSet()
  fun check(i: Int, x: Int): Boolean {
    return (i < n && rects[i].l <= x && x <= rects[i].r)
  }
  fun attempt(x: Int): Int {
    var l: Int = 0
    var r: Int = n
    while (l + 1 < r) {
      val m = (l + r) / 2
      if (rects[m].r <= x) l = m else r = m
    }
    if (check(l,x) && have[l] >= 2 || check(r,x) && have[r] >= 2) return -1
    if (!check(l,x) && !check(r,x)) return 0
    if (check(l,x)) have[l] += 1
    if (check(r,x)) have[r] += 1
    return +1
  }

  if (existing.filter{attempt(it) == -1}.size > 0) {
    return System.`out`.println("impossible")
  }
  val rand = Random(2)
  for (i in 0..10000) {
    val x = rand.nextInt(rects[rects.size-1].r + 1 - rects[0].l) + rects[0].l
    if (!existing.contains(x) && !added.contains(x) && attempt(x) == 1) {
      added.add(x)
    }
  }
  if (have.filter{it != 2}.size > 0) return System.`out`.println("impossible")

  System.`out`.println(added.size)
  System.`out`.println(added.joinToString(separator = " "))
}
