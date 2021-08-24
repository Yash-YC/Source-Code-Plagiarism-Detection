import Control.Monad
import qualified Data.Set as S
import Data.List
import Data.Maybe

main=do
    (n:cs)<-liftM lines getContents
    let csp=map (map read . words) $ take (read n) cs :: [[Int]]
    let ans=map solve csp
    let x=zipWith (\n x->"Case #"++show n++": "++show x) [1..] ans
    mapM_ putStrLn x



solve bs=fromJust $ find f [2..]
    where
        f x=all (flip isHappy x) bs


isHappy b n=loop S.empty n
    where
        loop s x|S.member x s = False
                |x==1         = True
                |otherwise    = loop (S.insert x s) (f b x)

f b n=sum $ map (^2) $ aux b n

aux _ 0=[]
aux b n=d:aux b r
    where (r,d)=divMod n b

