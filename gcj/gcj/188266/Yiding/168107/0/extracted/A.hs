module Main where
import qualified Data.IntSet as IS
import qualified Data.IntMap as IM
import Data.Array
import Data.List
import Data.Ix
import Text.Printf

labelCases :: [IO ()] -> IO ()
labelCases = sequence_ . map (\(n,io) -> printLabel n >> io) . zip [1..] 
  where
    printLabel :: Int -> IO ()
    printLabel = printf "Case #%d: " 

toBase :: Int -> Int -> [Int]
toBase b v = toBase' [] v where
  toBase' a 0 = a
  toBase' a v = toBase' (r:a) q where (q,r) = v `divMod` b

compute (caseCt:cases) = let caseCount = read caseCt in
  labelCases $ map computeEach $ take caseCount cases

happyForBase b = happySet
  where
    happySet = IS.fromList $ map fst $ filter (id . snd) $ IM.toList happyMap
    happyMap = foldl' rrec IM.empty [1..maxValue]
    rrec happy n = rec happy IS.empty n
    rec happy seen n
      | rv == 1           = IM.union happy $ seenAsMap True
      | IS.member rv seen = IM.union happy $ seenAsMap False
      | IM.member rv happy = IM.union happy $ seenAsMap (happy IM.! rv)
      | otherwise = rec happy seen' rv
      where 
        sqr x = x * x
        rv = foldl' (+) 0 $ map sqr $ toBase b n
        seen' = IS.insert n seen
        seenAsMap bool = IM.fromList $ map (flip (,) bool) $ IS.toList seen' 

happySets = IM.fromList $ map (\b -> (b, happyForBase b)) [2..500]

maxValue = 100000

computeEach line = 
  case find matches [2..maxValue] of
    Just a -> putStrLn $ show a
    Nothing -> putStrLn $ "exhausted"
  where
    bases = map read $ words line
    matches n = foldl (&&) True $ map (IS.member n . (happySets IM.!)) bases

main = getContents >>= compute . lines
