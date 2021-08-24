module Main where

import qualified Data.Set as Set
import Monad

main :: IO ()
main = do t <- liftM read getLine
          mapM_ oneCase [1..t]

oneCase :: Int -> IO ()
oneCase n =
    do bases <- liftM (map read . words) getLine
       putStrLn $ "Case #" ++ show n ++ ": " ++ show (solve bases)

solve :: [Int] -> Int
solve bases = head $ filter (\x -> and (map (flip happy x) bases)) [2 ..]

happy :: Int -> Int -> Bool
happy base =
    let f seen n
          | n == 1 = True
          | True = if Set.member n seen then False else f (Set.insert n seen) (step 0 n)
        step acc n
          | n == 0 = acc
          | True = step (acc + mod n base ^ 2) (div n base)
    in f Set.empty
