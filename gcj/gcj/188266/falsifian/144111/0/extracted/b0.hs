module Main (main) where

import Array
import qualified Data.Map as Map
import qualified Data.Set as Set
import Monad

data Position = P { row, column, iRow, iColumn :: Int } deriving (Eq, Ord)

data Intersection = I { iS, iW, iT :: Integer }

data State =
  S { upByPos :: Map.Map Position Integer
    , upByTime :: Set.Set (Integer, Position)
    }

main :: IO ()
main = do c <- liftM read getLine
          mapM_ oneCase [1..c]

oneCase :: Int -> IO ()
oneCase caseNum =
    do [n,m] <- liftM (map read . words) getLine
       desc <- liftM (listArray ((0, 0), (n - 1, m - 1)) . concat) $ sequence $ replicate n $ liftM (getIntersections . map read . words) getLine
       putStrLn $ "Case #" ++ show caseNum ++ ": " ++ show (solve desc)

getIntersections :: [Integer] -> [Intersection]
getIntersections =
    let f acc [] = reverse acc
        f acc (hs : hw : ht : t) = f (I hs hw ht : acc) t
    in f []

solve :: Array (Int, Int) Intersection -> Integer
solve desc =
    let ((0, 0), (n', m')) = bounds desc
        n = n' + 1
        m = m' + 1
        f state =
            let ((nextTime, nextPos@(P r c ir ic)), newByTime) = Set.deleteFindMin (upByTime state)
            in  if nextPos == P 0 m' (- 1) 1
                    then nextTime
                    else let I is iw it = desc ! (r, c)
                             crossNS = (nextCrossTime nextTime is iw it + 1, P r c (- ir) ic)
                             crossEW = (nextCrossTime nextTime iw is (it+is) + 1, P r c ir (- ic))
                             blockNS = (nextTime + 2, P (r + ir) c (- ir) ic)
                             blockEW = (nextTime + 2, P r (c + ic) ir (- ic))
                         in f (foldl scheduleUpdate (S (upByPos state) newByTime) (filter (isGoodState . snd) [crossNS, crossEW, blockNS, blockEW]))
        isGoodState (P r c _ _) = r >= 0 && r < n && c >= 0 && c < m
        nextCrossTime curTime is iw it =
            let nextCycleStart = curTime + mod (it - curTime) (is + iw)
            in if curTime >= nextCycleStart - iw then nextCycleStart else curTime
        scheduleUpdate state (time, pos) =
            if Map.member pos (upByPos state)
                then let oldTime = (Map.!) (upByPos state) pos in
                     if oldTime > time
                         then S (Map.insert pos time (upByPos state)) (Set.insert (time, pos) (Set.delete (oldTime, pos) (upByTime state)))
                         else state
                else S (Map.insert pos time (upByPos state)) (Set.insert (time, pos) (upByTime state))
    in f (scheduleUpdate (S Map.empty Set.empty) (0, P n' 0 1 (- 1)))
