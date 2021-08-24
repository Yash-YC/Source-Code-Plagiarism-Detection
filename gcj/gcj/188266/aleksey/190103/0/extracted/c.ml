let _ =
  let binomial = Array.make_matrix 11 11 0 in
  let _ =
    binomial.(0).(0) <- 1;
    for i = 1 to 10 do
      binomial.(i).(0) <- 1;
      for j = 1 to 10 do
	binomial.(i).(j) <- binomial.(i - 1).(j - 1) + binomial.(i - 1).(j)
      done
    done
  in
  let popcount n =
    let n = ref n in
    let res = ref 0 in
      while !n <> 0 do
	n := !n land (!n - 1);
	incr res;
      done;
      !res
  in
  let sb = Scanf.Scanning.stdib in
  let cases = Scanf.bscanf sb "%d " (fun s -> s) in
    for ca = 1 to cases do
      let n = Scanf.bscanf sb "%d " (fun s -> s) in
      let c = Scanf.bscanf sb "%d " (fun s -> s) in
      let a = Array.make (1 lsl n) 0.0 in
      let b = Array.make (1 lsl n) 0.0 in
      let r = Array.make (1 lsl n) false in
      let _ =
	for j = 0 to 1 lsl n - 1 do
	  if popcount j = c then (
	    r.(j) <- true;
	  )
	done
      in
      let aa = ref a
      and bb = ref b in
      let p = 1.0 /. (float_of_int binomial.(n).(c)) in
      let res = ref 0.0 in
	a.(0) <- 1.0;
	for k = 1 to 250 do
	  let a = !aa
	  and b = !bb in
	    Array.fill b 0 (Array.length b) 0.0;
	    for i = 0 to 1 lsl n - 1 do
	      for j = 0 to 1 lsl n - 1 do
		if r.(j) then (
		  let ij = i lor j in
		    b.(ij) <- b.(ij) +. a.(i) *. p;
		)
	      done
	    done;
	    (*Printf.printf "asd %.10f\n" b.(1 lsl n - 1);*)
	    res := !res +. float_of_int k *. b.(1 lsl n - 1);
	    b.(1 lsl n - 1) <- 0.0;
	    bb := a;
	    aa := b;
	done;
	Printf.printf "Case #%d: %f\n" ca !res;
    done
