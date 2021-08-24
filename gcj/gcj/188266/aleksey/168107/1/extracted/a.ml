let tokenize str =
  let rec aux str from res =
    if from >= String.length str
    then List.rev res
    else 
      try
	let idx = String.index_from str from ' ' in
	let token = String.sub str from (idx - from) in
	  match token with
	    | "" -> aux str (idx + 1) res
	    | _ -> aux str (idx + 1) (token :: res)
      with
	| Not_found ->
	    let str = String.sub str from (String.length str - from) in
	      aux "" 0 (str :: res)
  in
    aux str 0 []

exception Found of int

(*11814485*)

let _ =
  let sqr x = x * x in
  let maxn = 12569669 in
  let a = Array.make (maxn + 1) false in
  let aa = Array.make_matrix 11 (maxn + 1) false in
  let check_happy nn b =
    let n = nn in
    let k = ref 1 in
    let p = ref 0 in
    let n = ref n in
      while !p <> !n && !n >= nn do
	incr k;
	if !k land (!k - 1) = 0 then (
	  p := !n
	);
	let m = ref !n in
	  n := 0;
	  while !m > 0 do
	    n := !n + sqr (!m mod b);
	    m := !m / b;
	  done;
      done;
      !p <> !n && aa.(b).(!n)
  in
  let s = input_line stdin in
  let cases = Scanf.sscanf s "%d " (fun s -> s) in
    for d = 2 to 10 do
      aa.(d).(1) <- true;
      for i = 2 to maxn do
	if check_happy i d then (
	  (*Printf.printf "asd %d %d\n" d i;*)
	  a.(i) <- true;
	  aa.(d).(i) <- true;
	)
      done;
    done;
    for ca = 1 to cases do
      let s = input_line stdin in
      let bases = List.map int_of_string (tokenize s) in
	try
	  if List.length bases = 9 then raise (Found 11814485);
	  for i = 2 to maxn do
	    if a.(i) then (
	      let b = ref true in
		List.iter
		  (fun d -> b := !b && (*check_happy i d*)aa.(d).(i)) bases;
		if !b then raise (Found i)
	    )
	  done;
	  raise (Found 11814485);
	  assert false
	with
	  | Found res ->
	      Printf.printf "Case #%d: %d\n" ca res;
    done
