module Main where
import Data.Array
import Data.Ix
import Text.Printf

memoizedByArr :: Ix i => ((i -> a) -> i -> a) -> (i, i) -> i -> a
memoizedByArr recFun bounds idx = table!idx where
  table = listArray bounds $ map (recFun (table!)) $ range bounds

labelCases :: [IO ()] -> IO ()
labelCases = sequence_ . map (\(n,io) -> printLabel n >> io) . zip [1..] 
  where
    printLabel :: Int -> IO ()
    printLabel = printf "Case #%d: " 

computeEach line = printf "%.7g\n" $ rec c
  where 
    c:n:_ = map read $ words line
    rec :: Double -> Double
    rec cardsLeft
      | cardsLeft <= n  = c * cardsLeft / (cardsLeft * n)
      | otherwise       = c / cardsLeft + rec (cardsLeft - n)

compute (caseCt:cases) = let caseCount = read caseCt in
  labelCases $ map computeEach $ take caseCount cases

main = getContents >>= compute . lines
