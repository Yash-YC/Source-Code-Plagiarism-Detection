-- -- Quaalification Round 2009 A.AlienLanguage
import Control.Monad
import qualified Data.ByteString.Char8 as S
import Data.List
import Data.Array.MArray (newArray, readArray, writeArray)
import Data.Array.IO (IOUArray)
import qualified Foreign as F
import GHC.Prim
import GHC.Exts

--------------------------------------------------
-- IO 
type SString = S.ByteString
infinity :: Int
infinity = 1000000000

getInt1 :: SString -> (Int, SString)
getInt1 cs
 | cs == S.empty = (-1, S.empty)
 | otherwise     = 
     case S.readInt cs of
       Just (i, cs') -> (i, S.tail cs')
       Nothing -> getInt1 (S.tail cs)

{-# INLINE getInts #-}
getInts :: Int -> SString -> ([Int], SString) 
getInts n cs
 | n == 0        = ([], cs)
 | cs == S.empty = ([], cs)
 | otherwise     =
     case S.readInt cs of
       Just (i, cs') -> (i:l, cs'') where (l, cs'') = getInts (n-1) (S.tail cs')
       Nothing -> getInts n (S.tail cs)

{-# INLINE getInteger1 #-}
getInteger1 :: SString -> (Integer, SString)
getInteger1 cs
 | cs == S.empty = (-1, S.empty)
 | otherwise     = 
     case S.readInteger cs of
       Just (i, cs') -> (i, S.tail cs')
       Nothing -> getInteger1 (S.tail cs)

{-# INLINE getIntegers #-}
getIntegers :: Int -> SString -> ([Integer], SString) 
getIntegers n cs
 | n == 0        = ([], cs)
 | cs == S.empty = ([], cs)
 | otherwise     = 
     case S.readInteger cs of
       Just (i, cs') -> (i:l, cs'') 
           where (l, cs'') = getIntegers (n-1) (S.tail cs')
       Nothing -> getIntegers n (S.tail cs) 

getLine1 :: SString -> (SString, SString)
getLine1 cs
 | cs == S.empty = (S.empty, S.empty)
 | otherwise     = (l, S.tail cs')
     where (l, cs') = S.break (== '\n') cs

getLines :: Int -> SString -> ([SString], SString)
getLines n cs
 | n == 0        = ([], cs)
 | cs == S.empty = ([], S.empty)
 | otherwise     = (l:ls, cs'')
    where (l, cs') = S.break (== '\n') cs
          (ls, cs'') = getLines (n-1) (S.tail cs')

--------------------------------------------------
type Vector = IOUArray Int Int
{-# INLINE makeVector #-}
makeVector:: Int -> IO Vector
makeVector n = do newArray (0, n) 0 :: IO Vector

{-# INLINE ref #-}
ref:: Vector -> Int -> IO Int
ref vec ix = readArray vec ix

{-# INLINE ref2D #-}
ref2D:: Vector -> Int -> Int -> Int -> IO Int
ref2D vec n x y = readArray vec (y * n + x) 

{-# INLINE set #-}
set:: Vector -> Int -> Int -> IO ()
set vec ix val = writeArray vec ix val

{-# INLINE set2D #-}
set2D:: Vector -> Int -> Int -> Int -> Int -> IO ()
set2D vec n x y val = writeArray vec (y * n + x)  val

--------------------------------------------------
-- 組合せ論
-- p n m = nPm
-- c n m = nCm
-- h n m = nHm :: n個の中から重複を許してm個取る組合せ
-- p n m = product [n-m+1..n]
-- c n m = div (p n m) (product [1..m])
-- h n m = div (product [n..n+m-1]) (product [2..m])

column :: Int -> Int -> String
column n x = drop (length filler - n) filler
    where
        filler = (take n$repeat '0') ++ (show x)


dotimes :: (Int, SString) -> (Int -> SString -> IO SString) -> IO ()
dotimes (n, cs) act = ((iterate f$ return (1, cs)) !! n) >> return ()
    where 
      f :: IO (Int, SString) ->  IO (Int, SString)
      f x = do
            (i, s) <- x
            rest <- act i s
            return (i+1, rest)

main :: IO ()
main = do
  cs0 <- S.getContents
  dotimes (getInt1 cs0) processor

processor :: Int ->SString -> IO SString
processor pid cs = do
  let
      (regex, cs') = getLine1 cs
      cands :: [Int]
      cands = map read $words (S.unpack regex)
  putStr $ "Case #" ++ show pid ++ ": "
  putStrLn $ show $ findN cands
  return cs'

data BasedInt = BasedInt Int [Int] deriving (Show, Eq, Ord)

toInt :: BasedInt -> Int
toInt (BasedInt base []) = 0
toInt (BasedInt base (x:xs)) = base * x + toInt (BasedInt base xs)

toBaseNfromInt :: Int -> Int -> BasedInt
toBaseNfromInt n x = BasedInt n $ reverse$ toBaseNfromInt' n x
toBaseNfromInt' :: Int -> Int -> [Int]
toBaseNfromInt' n x
    | n > x     = [x]
    | otherwise = l
    where 
      l = m:toBaseNfromInt' n y
      m = mod x n
      y = div x n

gatherColumn :: BasedInt -> Int
gatherColumn (BasedInt base l) = sum [x*x|x<-l]

check :: Int -> Int -> Bool
check base x = check' (toBaseNfromInt base x) []

check' :: BasedInt -> [Int] -> Bool
check' x@(BasedInt base l) checked
    | val == 1         = True
    | elem val checked = False
    | otherwise        = check' (toBaseNfromInt base val) (val:checked)
    where
      val = gatherColumn x

findN :: [Int] -> Int
findN bases = head $ filter (allPassed bases) [2..]

allPassed :: [Int] -> Int -> Bool
allPassed bases x = all (\base -> check base x) bases
