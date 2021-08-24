import Control.Monad
import qualified Data.Set as S
import qualified Data.Map as M
import Data.List
import Data.Maybe
import Text.Printf

main=do
    (n:cs)<-liftM lines getContents
    let csp=map (map read . words) $ take (read n) cs :: [[Int]]
    let ans=map (\(x:y:_)->solve x y) csp
    let x=zipWith (\n x->printf "Case #%d: %.7f" n x) [1::Int ..] ans
    mapM_ putStrLn x
    return ()



solve :: Int -> Int -> Double
solve k n=f k n k

-- rm. depth, kinds, #/pack, #remaining kinds
f :: Int -> Int -> Int -> Double
f k n r
    |r<=0      = 0
    |otherwise = (sps+sum cs)/sub_ps
    where
        sps=fromIntegral $ sum ps 
        sub_ps=sps-fromIntegral (head ps)
        
        cs=tail $ zipWith (\i x->f k n (r-i)*x) [0..n] (map fromIntegral ps)
        ps=map (\i->comb (k-r) (n-i)*comb r i) [0..n] :: [Integer]


-- cached pascal's triangle
comb :: Int -> Int -> Integer
comb n k
    |n<0 || k<0 || k>n = 0
    |otherwise   = m M.! (n,k)
    where m=M.fromList $ concat [[((n,k),aux n k)|k<-[0..n]]|n<-[0..40]]

aux n k
    |k==0 || k==n = 1
    |otherwise    = comb (n-1) (k-1)+comb (n-1) k

