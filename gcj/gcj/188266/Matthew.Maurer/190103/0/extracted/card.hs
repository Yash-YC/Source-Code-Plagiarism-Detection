module Main where
import IO
import Control.Monad
import qualified Data.MemoCombinators as Memo
import Data.Maybe
import Data.List
import Data.IORef
import System.IO.Unsafe
import qualified Data.Map as Map

main :: IO ()
main = do
   input <- fmap ((map ((map read) . words)) . lines) getContents
   printer $ map solve (tail input)

solve :: [Int] -> Double
solve [cards, packSize] = stepHave 0
   where stepHave = Memo.integral stepHave'
            where stepHave' held = if held == cards
                                      then 0
                                      else let maxNext  = min (cards - held) packSize
                                               possible = [1..maxNext]
                                               pFail    = prob held 0
                                           in (pFail + (sum $ zipWith (*) (map (prob held) possible) (map (\x -> 1 + stepHave (held + x)) possible))) / (1 - pFail)
         prob held num =
            let total = fromIntegral (choose packSize cards)
                goods = choose num (cards - held)
                bads  = choose (packSize - num) held
            in (fromIntegral (goods * bads)) / total
choose :: Int -> Int -> Int
choose = Memo.memo2 Memo.integral Memo.integral choose'
   where choose' 0 _ = 1
         choose' k n = if k == n
                          then 1
                          else if k > n
                                  then 0
                                  else (choose (k - 1) (n - 1)) + (choose k (n - 1))


printer :: (Show a) => [a] -> IO ()
printer ans = zipWithM_ printsub ans [1..]
printsub x y = putStrLn $ "Case #" ++ (show y) ++ ": " ++ (show x)
--All libraries used either come with a standard installation of GHC 6.10.2 (the haskell compiler I am using, available from http://haskell.org/ghc) or are available from http://hackage.haskell.org (via manual installation or cabal install)
