module MultiBase where
import IO
import List

isHappy :: [Int] -> Bool
isHappy [1] = True
isHappy _ = False

changeBase :: Int -> Int -> [Int]
changeBase base n = reverse $ unfoldr (changeBase' base) n
  where changeBase' base n
          | n == 0 = Nothing
          | otherwise = Just (n `mod` base, n `div` base)

sumSquares :: Int -> [Int] -> [Int]
sumSquares base ns = changeBase base $ sum $ map (\n -> n*n) ns

reduce :: Int -> Int -> Bool
reduce base n = reduce' [] $ iterate (sumSquares base) $ changeBase base n

reduce' seen (first:rest)
  | isHappy first = True
  | first `elem` seen = False
  | otherwise = reduce' (first:seen) rest

happyChain base = map fst $ filter isOk $ zip [2..] $ map (reduce base) [2..]
  where isOk (_,b) = b

headsEqual :: Int -> [[Int]] -> [[Int]]
headsEqual _ [] = []
headsEqual n [list] = [dropWhile (\x -> x < n) list]
headsEqual n (list@(x:xs):lists)
  | (n == x) = if n' > n then headsEqual n' (list:nextN) else (list:nextN)
  | (x > n)  = if x' > x then headsEqual x' (list:nextX) else (list:nextX)
  | otherwise = headsEqual n (xs:lists)
  where nextN@((n':_):_) = headsEqual n lists
        nextX@((x':_):_) = headsEqual x lists

topHead :: [[Int]] -> Int
topHead = head.head

solve :: [[Int]] -> [Int] -> String
solve happyChains bases = show $ topHead $ headsEqual 2 $ map (\i -> happyChains!!i) bases

process :: [[Int]] -> [String] -> Maybe (String, [String])
process _ [] = Nothing
process happyChains (first:rest) = Just (solve happyChains bases, rest)
  where bases = map read $ words first

run :: String -> IO ()
run infile
  = do hIn <- openFile infile ReadMode
       hOut <- openFile outfile WriteMode
       (top:body) <- hGetContents hIn >>= return.lines
       let count = read top :: Int
       let happyChains = map happyChain [0..10]
       sequence_ [ (hPutStrLn hOut result) >> (putStrLn result) | result <- map showResult $ zip [1..count] (unfoldr (process happyChains) body) ]
  where outfile = (takeWhile ((/=) '.') infile) ++ ".out"
        showResult (n,result) = concat ["Case #", show n, ": ", result ]

sample = run "sample.in"
