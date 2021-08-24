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

let _ =
  let sqr x = x * x in
  let check_happy n b =
    let k = ref 100 in
    let n = ref n in
      while !k > 0 && !n > 1 do
	k := !k - 1;
	let m = ref !n in
	  n := 0;
	  while !m > 0 do
	    n := !n + sqr (!m mod b);
	    m := !m / b;
	  done;
      done;
      !n = 1
  in
  let s = input_line stdin in
  let cases = Scanf.sscanf s "%d " (fun s -> s) in
    for ca = 1 to cases do
      let s = input_line stdin in
      let bases = List.map int_of_string (tokenize s) in
	try
	  for i = 2 to 100000 do
	    let b = ref true in
	      List.iter
		(fun d -> b := !b && check_happy i d) bases;
	      if !b then raise (Found i)
	  done;
	  assert false
	with
	  | Found res ->
	      Printf.printf "Case #%d: %d\n" ca res;
    done
