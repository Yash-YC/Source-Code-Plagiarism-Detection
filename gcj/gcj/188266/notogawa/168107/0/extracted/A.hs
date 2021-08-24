import Text.Printf
import Numeric
import Control.Monad.State

main = do
  n <- readLn
  mapM_ solve [1..n::Int]

solve n = do
  r <- solve'
  printf"Case #%d: %d\n"n(r::Integer)

solve' = do
  bases <- fmap (map read.words) getLine
  return $ head $ filter (bases#) [2..]

bs#n=bs==[b|b<-bs,evalState(b%n)[]]

b%n=do
  m <- gets $ elem n
  if m
    then return False
    else let n' = sum[read[a]^2|a<-showIntAtBase b(['0'..'9']!!) n""]
         in if n' == 1
              then return True
              else modify (n:) >> b%n'
