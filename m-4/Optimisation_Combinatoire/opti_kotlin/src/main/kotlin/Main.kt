fun main(args: Array<String>) {
    var opti = Optimisation(Pair(20, 10), 0.7, 0.01, 10000).run()
    println(" Final state [result: ${opti.second}, element: ${opti.first}]")
}

fun Boolean.toInt() = if (this) 1 else 0
fun Boolean.opposite() = (this.toInt() + 1 ).mod(2).toBool()

fun Int.toBool() = this > 0
