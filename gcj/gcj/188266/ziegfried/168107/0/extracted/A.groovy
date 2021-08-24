void debug(msg) {
    //System.err.println msg
}

boolean isHappy(int number, int radix) {
    def done = [] as TreeSet
    def next = number //Integer.toString(number, radix)
    while(!done.contains(next)) {
        done << next
        def no = Integer.toString(next, radix)
        debug "no=$no"
        next = no.collect { Integer.parseInt(it) }.sum { it*it } 
        if(next == 1) return true
        debug "next=$next (done=$done)"
        
    }                            
    return false
}

def allHappy(int no, def radixes) {
    debug "allHappy $no $radixes"
    for(r in radixes) {
        if(!isHappy(no, r)) return false
    }
    return true
}

new File(args[0]).withReader { reader ->
    (1..reader.readLine().toInteger()).each { caseNo ->
        def radixes = reader.readLine().split(/\s+/)*.toInteger()
        def i = 2
        while(!allHappy(i, radixes)) i++
        println "Case #$caseNo: $i"
    }    
}