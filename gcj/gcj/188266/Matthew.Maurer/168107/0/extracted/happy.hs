module Main where
import IO
import Control.Monad
import qualified Data.MemoCombinators as Memo
import Data.Maybe
import Data.List

main :: IO ()
main = do
   input <- fmap ((map ((map read) . words)) . lines) getContents
   printer $ map solve (tail input)

solve :: [Int] -> Int
solve baseList =
   let happies = map and (transpose $ map happySolve baseList)
   in (fromJust $ (elemIndex True happies)) + 2

memoStupid :: Memo.Memo [Int]
memoStupid = Memo.wrap (\_ -> []) (\_ -> ()) Memo.unit

happySolve :: Int -> [Bool]
happySolve base = map ((\f -> f []) . (happy base)) [2..]
happy :: Int -> Int -> [Int] -> Bool
happy =  happy'
   where
   happy' base num xs =
      let num' = happyStep base num
      in if num' == 1
            then True
            else if num' `elem` xs
                    then False
                    else happy base num' (num':xs)

--Assumption: happyStepping will either hit 1 or loop, as above a certain value it will always be driven downwards

happyStep :: Int -> Int -> Int
happyStep base num = sum $ map (^2) (splitBase base num)

splitBase :: Int -> Int -> [Int]
splitBase base num = splitBase' [] num where
    splitBase' digits 0 = digits
    splitBase' digits num =
       let (rest, digit) = divMod num base
       in splitBase' (digit:digits) rest

printer :: (Show a) => [a] -> IO ()
printer ans = zipWithM_ printsub ans [1..]
printsub x y = putStrLn $ "Case #" ++ (show y) ++ ": " ++ (show x)
--All libraries used either come with a standard installation of GHC 6.10.2 (the haskell compiler I am using, available from http://haskell.org/ghc) or are available from http://hackage.haskell.org (via manual installation or cabal install)
