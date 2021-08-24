-- Multi-base happiness
-- Round 1A - Problem A
-- Grant Glouser <gglouser@gmail.com>

module Main where

import Control.Monad.State
import Data.Array
import Data.List
import qualified Test.HUnit as T


data Problem = Problem [Int]
    deriving (Eq, Show)

readProblem :: Reader Problem
readProblem = do
    ns <- readNums
    return $ Problem ns

-- -------

data Result = Result Int
    deriving Eq

instance Show Result where
    show (Result n) = show n

-- -------

happ b 0 = 0
happ b n = let (q,r) = n `divMod` b in r*r + happ b q

happy b n = h n []
    where
        h 1 _ = True
        h n t = let n' = happ b n
                in if elem n' t
                    then False
                    else h n' (n':t)

allhappy bs = [x | x <- [2..], all (\b -> happy b x) bs]

solve :: Problem -> Result
solve (Problem ns) = Result . head . allhappy $ ns

-- -------
-- Sample test cases

sample = Problem [2, 3]
sample2 = Problem [2, 3, 7]
sample3 = Problem [9, 10]
allSamples = [sample, sample2, sample3]

sampleResult = Result 3
sampleResult2 = Result 143
sampleResult3 = Result 91
allSampleResults = [sampleResult, sampleResult2, sampleResult3]

qtest = do
    sampleIn <- readFile "sample.in"
    sampleOut <- readFile "sample.out"
    T.runTestTT . T.TestList $ (
        [   assertEq "parse" allSamples (parseInput sampleIn)
        ,   assertEq "format" sampleOut (formatOutput allSampleResults)
        ] ++ (zipWith solveTest allSamples allSampleResults))

solveTest s r = assertEq "solve" r (solve s)
assertEq name expect actual = T.TestCase (T.assertEqual name expect actual)

-- -------

parseInput :: String -> [Problem]
parseInput = evalState readProbs . lines
    where readProbs = do { n <- readNum; replicateM n readProblem }

formatOutput :: [Result] -> String
formatOutput = unlines . map f . zip [1..]
    where f (n, r) = "Case #" ++ (show n) ++ ": " ++ (show r)

run :: String -> String
run = formatOutput . map solve . parseInput

doCheck :: String -> IO ()
doCheck infile = do
    s <- readFile infile
    putStr . run $ s

doFile :: String -> String -> IO ()
doFile infile outfile = do
    s <- readFile infile
    writeFile outfile . run $ s

main :: IO ()
main = interact run

-- -------
-- Input helpers

type Reader a = State [String] a

readLine :: Reader String
readLine = do { (l:ll) <- get; put ll; return l}

readNums :: Reader [Int]
readNums = do { ns <- readLine; return . map read . words $ ns }

readNum :: Reader Int
readNum = do { [n] <- readNums; return n }
