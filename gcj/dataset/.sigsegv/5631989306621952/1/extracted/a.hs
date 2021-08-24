import Control.Monad
import Data.Function
import Data.List

----------------
--] TEMPLATE [--
----------------

printCase :: Int -> String -> IO ()
printCase probi solution = putStrLn $ "Case #" ++ (show probi) ++ ": " ++ solution

solveAll :: Int -> IO ()
solveAll probc = mapM_ solve [1..probc]

main = do
	probc <- readLn :: IO Int
	solveAll probc

--------------------
--] END TEMPLATE [--
--------------------

splitAtMaximum :: String -> (Char, String, String)
splitAtMaximum s = 
	let
		m = maximum s
		(h,mt) = break (\x -> x == m) s
		t = tail mt
	in
		(m, h, t)

lastWord :: String -> String -> String
lastWord [] word = word
lastWord (c:cs) [] = lastWord cs [c]
lastWord (c:cs) word =
	if (c >= head word)
	then lastWord cs (c:word)
	else lastWord cs (word ++ [c])

solve :: Int -> IO ()
solve probi = do
	s <- getLine
	printCase probi $ lastWord s []
