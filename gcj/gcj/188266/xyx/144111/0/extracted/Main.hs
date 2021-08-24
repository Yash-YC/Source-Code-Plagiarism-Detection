import Control.Monad
import qualified Data.Map as M
import qualified Data.Set as S
import Data.List
import Debug.Trace

main=do
    (n:cs)<-liftM lines getContents
    let csp=pCase (read n) $ map (map read . words) cs
    let ans=map solve csp
    let x=zipWith (\n x->"Case #"++show n++": "++show x) [1..] ans
    mapM_ putStrLn x

solve :: [[(Int,Int,Int)]] -> Int
solve rs= ti M.!(xmax,ymax)
    where
        bestT 0 0=0
        bestT 0 y=fCOY 0 (y-1)
        bestT x 0=fCOX (x-1) 0
        bestT x y=min (fCOX (x-1) y) (fCOY x (y-1))
        ti=M.fromList [((x,y),bestT x y)|x<-[0..xmax],y<-[0..ymax]]

        fCOX x y=
            let (s,w,ofs)=m M.! (div x 2,div y 2)
                t0=ti M.!(x,y)
                tcy=s+w
            in if odd x then t0+2 else 1+
                if (t0-ofs+tcy*1000) `mod` tcy>=s then t0 else tcy*((t0-ofs) `div` tcy)+ofs+s
        fCOY x y=
            let (s,w,ofs)=m M.! (div x 2,div y 2)
                t0=ti M.!(x,y)
                tcy=s+w
            in if odd y then t0+2 else 1+
                if (t0-ofs+tcy*1000) `mod` tcy<s then t0 else tcy*(1+(t0-ofs) `div` tcy)+ofs
        
        xmax=wi*2-1
        ymax=he*2-1
        
        wi=length $ head rs
        he=length rs
        m=M.fromList $ concat $ zipWith (\y cs->zipWith (\x v->((x,y),v)) [0..] cs) [0..] rs



pCase :: Int -> [[Int]] -> [[[(Int,Int,Int)]]]
pCase 0 _=[]
pCase nc ([n,m]:xs)=(map pLine $ take n xs):pCase (nc-1) (drop n xs)

pLine :: [Int] -> [(Int,Int,Int)]
pLine []=[]
pLine (x:y:z:r)=(x,y,z):pLine r
    



