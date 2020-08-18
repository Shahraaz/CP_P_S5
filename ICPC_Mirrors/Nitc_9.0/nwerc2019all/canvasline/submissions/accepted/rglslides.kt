import java.util.*

data class Rect(val l: Int, val r: Int)

fun main(args: Array<String>) {
  val scan = Scanner(System.`in`)

  val n = scan.nextInt()
  val rects = Array<Rect>(n, {_ -> Rect(scan.nextInt(), scan.nextInt())})
  val existing = Array<Int>(scan.nextInt(), {_ -> scan.nextInt()}).toSet()
  val have = Array<Int>(n, {_ -> 0})

  val interesting:MutableList<Int> = ArrayList()
  rects.map{interesting.add(it.r)}
  rects.map{interesting.add(it.l+1)}
  rects.map{interesting.add(it.l+2)}

  val added:MutableSet<Int> = HashSet()
  fun check(i: Int, x: Int): Boolean {
    return (i < n && rects[i].l <= x && x <= rects[i].r)
  }
  fun attempt(x: Int): Boolean {
    var l: Int = 0
    var r: Int = n
    while (l + 1 < r) {
      val m = (l + r) / 2
      if (rects[m].r <= x) l = m else r = m
    }
    if (check(l,x) && have[l] >= 2 || check(r,x) && have[r] >= 2) return false
    if (check(l,x)) have[l] += 1
    if (check(r,x)) have[r] += 1
    return true
  }

  if (existing.filter{!attempt(it)}.size > 0) return System.`out`.println("impossible")
  interesting.map{if (!existing.contains(it) && !added.contains(it) && attempt(it)) added.add(it)}
  if (have.filter{it != 2}.size > 0) return System.`out`.println("impossible")

  System.`out`.println(added.size)
  System.`out`.println(added.joinToString(separator = " "))
}
