(*
use "C:/Documents and Settings/xp/My Documents/Google Codejam/q1.sml";
*)
OS.FileSys.chDir "/Documents and Settings/xp/My Documents/Google Codejam";

(*
All of this was prepared in the few hours before google code jam 2009 round 
1A started. This may be submitted with more functions defined than are really 
necessary to solve the problem. I just wanted to write some basic functions fo
cover myself if they might be needed.
Anyway.
-dave
*)



val infile = "input.txt";



fun I x = (fn y => x = y);

fun strfilter valid str =
let
  val vls = explode valid
  val strls = explode str
in
  implode (List.filter (fn x => List.exists (I x) vls) strls)
end;


fun lsget (a::_) 0 = a
  | lsget (_::ls) n = lsget ls (n-1);
fun maget ls (row,col) = lsget (lsget ls row) col;

fun nextchar c = chr (ord(c) + 1);

exception notfound;

fun locate f ls =
  let
    fun help _ [] _ = raise notfound
      | help f (a::ls) n = if f a then n else help f ls (n+1)
  in help f ls 0 end;

fun findinmat f mat =
  let
    fun help _ [] _ = raise notfound
      | help f (a::ls) n = (n, locate f a) handle notfound => help f ls (n+1)
  in help f mat 0 end;

fun trim str =
  let
    val ls = String.explode str
    fun tr (#" "::ls) = tr ls
      | tr (#"\n"::ls) = tr ls
      | tr ls = ls
  in String.implode(rev (tr (rev (tr ls)))) end;
    
fun intls2str [] = ""
  | intls2str ln = trim(foldl (fn (new, old) => old ^ " " ^ (Int.toString new)) "" ln);
fun intmatrix2str ans = foldl (fn (new, old) => old ^ "\n" ^ (intls2str new)) "" ans;

fun charmatrix2str mat =
  let
    fun f ls = trim(foldl (fn (new, old) => old ^ " " ^ (String.str new)) "" ls);
  in
    foldl (fn (new, old) => old ^ "\n" ^ f(new)) "" mat
  end;

fun getInts str = map (fn num => getOpt(Int.fromString(num), 0)) 
                    (String.fields (fn x => x = #" ") str);



fun getInstance ins =
  let
    val ls = getInts (TextIO.inputLine ins)
  in
    (length ls, ls)
  end;


fun makeAnswerLine (max, current, answer) =
  let
    val preface = "Case #" ^ (Int.toString current) ^ ": "
    (* SET THIS FOR THE DETAILS OF THE PROBLEM*)
    val rest = Int.toString answer
  in
    preface ^ trim(rest) ^ (if max = current then "" else "\n")
  end;



fun digits base n =
let 
  fun dh base 0 = []
    | dh base n = (n mod base)::(dh base (n div base))
in rev(dh base n) end;

fun fromdigits base ls = foldl (fn (new, old) => base * old + new) 0 ls;

fun iterate base n = foldr (fn (new,old) => old + new*new) 0 (digits base n);

fun solveInstance (len, ls) = 
let
  val limit = 100000
  val memopad = Array2.array (len, limit, NONE)
  fun ishappy base n =
    let
      val indexinls = (locate (I base) ls)
      fun p' 1 _ = true
        | p' n allsame = let val next = iterate base n in
	                   if List.exists (I n) allsame then false else p next (n::allsame) end
      and p n allsame =
        if n < limit then
          case Array2.sub(memopad, indexinls, n) of
                SOME r => r
              | NONE =>
                let val r = (p' n allsame)
                in (map (fn n=> Array2.update(memopad, indexinls, n, SOME r)) (n::allsame); r) end
        else
          p' n allsame
    in 
       p n []
    end
  fun findleast ls n = if 
                         List.all (fn base => ishappy base n) ls 
		       then n 
		       else findleast ls (n+1)
in
  findleast ls 2
end;




fun solvenofile(infile: string) =
  let
    val ins = TextIO.openIn infile
    val numcases = getOpt(Int.fromString (TextIO.inputLine ins), 0)

    fun helper numcases current = 
       if numcases < current then (TextIO.closeIn ins)
       else let
              val data = getInstance ins
	      val answer = solveInstance data
	      val outline = makeAnswerLine(numcases, current, answer)
	    in 
	      (print outline; helper numcases (current + 1))
	    end
  in
    helper numcases 1
  end;


fun solvepuzzle(infile: string, outfile: string) =
  let
    val ins = TextIO.openIn infile
    val outs = TextIO.openOut outfile
    val numcases = getOpt(Int.fromString (TextIO.inputLine ins), 0)

    fun helper numcases current = 
       if numcases < current then (TextIO.closeIn ins; TextIO.closeOut outs)
       else let
              val data = getInstance ins
	      val answer = solveInstance data
	      val outline = makeAnswerLine(numcases, current, answer)
	    in 
	      (TextIO.output(outs, outline); helper numcases (current + 1))
	    end
  in
    helper numcases 1
  end;

(*val ans1 = solvenofile("input.txt");*)
val ans2 = solvepuzzle("input.txt", "out.txt");

