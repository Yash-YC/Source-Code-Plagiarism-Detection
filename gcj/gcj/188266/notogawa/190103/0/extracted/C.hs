import Text.Printf

main = do
  n <- readLn
  mapM_ solve [1..n::Int]

solve n = do
  [c,d] <- fmap (map read.words) getLine
  printf "Case #%d: %.7f\n"n(1+c/d::Double)
