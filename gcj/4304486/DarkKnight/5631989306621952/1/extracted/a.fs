open System

let t = int <| Console.ReadLine ()

for c in 1..t do
    let s = Console.ReadLine ()

    let rec write (a : string) (r : string) =
        if r.Length < 1 then a
        else
            let h = r.[0..0]
            let b = max (h + a) (a + h)
            if r.Length > 1 then
                write b r.[1..]
            else
                b
        
    let b = s.Length
    printfn "Case #%d: %s" c <| write s.[0..0] s.[1..]
