let main =
  let t = Scanf.scanf "%d\n" (fun t -> t) in
  for case = 1 to t do
    (* input *)
    let (c, n) = Scanf.scanf "%d %d\n" (fun c n -> (c, n)) in
    (* calculate *)
    let comb n m =
      let rec walk k p =
        if k > 0 then
          walk (k-1) (p *. float_of_int (n - m + k) /. float_of_int k)
        else
          p in
      walk m 1.0 in
    let a m d =
      comb (c-m) (n-d) /. comb c n *. comb m d in
    let rec cc m =
      if m > 0 then
        let rec walk d s =
          if d > 0 then
            walk (d-1) (s +. a m d *. (1.0 +. cc (m-d)))
          else
            s in
        walk n (a m 0) /. (1.0 -. a m 0)
      else 
        0.0 in
    (* output *)
    Printf.printf "Case #%d: %f\n" case (cc c)
  done
