import kotlin.math.abs
import kotlin.random.Random

class Optimisation(
    popSizeDef: Pair<Int, Int>,
    /* Crossover probability */
    private var cP: Double,
    /* Mutation probability */
    private var mP: Double,
    private var maxGen: Int,
) {

    private var population: MutableList<MutableList<Boolean>> = mutableListOf()

    init {
        for(i in 0 until popSizeDef.first){
            this.population.add(mutableListOf())
            for(p in 0 until popSizeDef.second){
                this.population[i].add((0..1).random().toBool())
            }
        }
        println("End")
    }

    private fun evaluatePopulation(p: MutableList<MutableList<Boolean>>): Pair<MutableList<Boolean>, Int>{
        var t: Pair<MutableList<Boolean>, Int>? = null
        for(x in p){
            var sum = 0
            var prod = 1
            for(i in 0 until x.size){
                if(!x[i]){
                    sum += i+1
                }else{
                    prod *= i+1
                }
            }
            val result = abs(sum-36) + abs(prod-360)
            if(t == null || result < t.second){
                t = Pair(x, result)
            }
        }
        return t!!
    }

    private fun crossover(e: Pair<MutableList<Boolean>, MutableList<Boolean>>): Pair<MutableList<Boolean>, MutableList<Boolean>>{

        val p = Random.nextDouble(0.toDouble(), 1.toDouble())
        if(p < this.cP){
            val r = e.first.size/2
            val f = e.first.slice(r until e.first.size)
            val s =  e.second.slice(r until e.second.size)

            e.first.subList(r, e.first.size).clear()
            e.first.addAll(s)
            e.second.subList(r, e.second.size).clear()
            e.second.addAll(f)
        }

        return e
    }

    private fun mutation(e: MutableList<Boolean>): MutableList<Boolean>{
        val p = Random.nextDouble(0.toDouble(), 1.toDouble())
        if(p < this.mP){
            val pos = (0 until e.size).random()
            e[pos] = e[pos].opposite()
        }
        return e
    }

    fun run(): Pair<MutableList<Boolean>, Int>{
        var best: Pair<MutableList<Boolean>, Int> = evaluatePopulation(this.population)
        var gen = 1
        while(gen <= maxGen && best.second != 0 ){
            val pNew: MutableList<MutableList<Boolean>> = mutableListOf()
            for(i in 0 until population.size/2){
                val (i1, i2) = this.population.asSequence().shuffled().take(2).toList()
                var e = Pair(i1, i2)
                e = this.crossover(e)
                pNew.add(this.mutation(e.first))
                pNew.add(this.mutation(e.second))
            }
            val t = evaluatePopulation(pNew)
            if(t.second < best.second){
                best = t
                println("result: ${t.second}, element: ${t.first}")
            }
            this.population = pNew
            gen++
        }
        return best
    }
}
