module Main where

import Data.List
import System.IO.Unsafe
import qualified Data.Set as Set

main = do
  t <- readLn
  mapM (\n -> do { putStr $ "Case #" ++ show n ++ ": "; runCase } ) [1..t]

runCase :: IO ()
runCase = do
  s     <- getLine
  let bases = map read $ words s
  putStrLn $ show $ head $ filter (\n -> and $ map (isHappy n) bases) [2..]

isHappy :: Integer -> Integer -> Bool
isHappy n b = iterateTillSmall b n Set.empty

iterateTillSmall :: Integer -> Integer -> Set.Set Integer -> Bool
iterateTillSmall b x seen =
  case Set.member x seen of
    True  -> False
    False ->
      let
        xs = toBase x b
        x' = sum $ map (^2) xs
        doItAgain = iterateTillSmall b x' $ Set.insert x seen
      in
        case length xs == 1 of
          True  ->
            case head xs == 1 of
              True  -> True
              False -> doItAgain
          False -> doItAgain

toBase :: Integer -> Integer -> [Integer]
toBase n b = unfoldr (stripDigit b) n 

stripDigit :: Integer -> Integer -> Maybe (Integer,Integer)
stripDigit b n =
  case n == 0 of
    True -> Nothing
    False -> Just (n `mod` b,n `div` b)
