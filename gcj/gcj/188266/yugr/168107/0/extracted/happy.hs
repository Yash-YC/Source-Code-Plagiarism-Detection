module Main
    where

import Text.ParserCombinators.Parsec
import IO hiding (try)
import System.Environment

-- PROBLEM-SPECIFIC IMPORTS --
import Data.Array
import Data.List
import Control.Arrow
import Control.Monad
------------------------------

defInput = "3\n2 3\n2 3 7\n9 10\n"

-- the input file will be parsed into a list of some type representing
-- individual cases to be solved by our algorithm:
type Input = [Case] 

-- our algorithms will produce a list of some type SolutionCase:
type Solution = [SolvedCase] 

-- we convert each solved case into a String, which is zipped with
--  the standard "Case #x: " strings for the final output
type Output = [String]





-- --------------- BEGIN EDITING --------------- --



-- DEFINE A TYPE TO REPRESENT A SINGLE UNSOLVED TEST CASE: --
type Case = [Integer]


-- DEFINE A TYPE TO REPRESENT A SINGLE SOLVED TEST CASE: --
type SolvedCase = Integer


     -- -- -- ALGORITHMS -- -- --


-- SOLVE A TEST CASE HERE:
algorithm :: Case -> SolvedCase
algorithm bs = head $ filter (\n -> all (isHappy n) bs) $ [2..]

baseSplit :: Integer -> Integer -> [Integer]
baseSplit b n
  | n < b = [n]
  | otherwise = let r = rem n b in r:(baseSplit b $ n `div` b) 

baseJoin :: Integer -> [Integer] -> Integer
baseJoin b [n] = n
baseJoin b ns =
  foldr1 (\d x -> x * b + d) ns

sumOfSquares b = sum . map (\n -> n * n) . baseSplit b

isHappy n b = isHappy' n b []

isHappy' 1 b _ = True
isHappy' n b past = if elem n past then False else isHappy' (sumOfSquares b n) b (n:past)

    -- -- -- PARSING INPUT -- -- --


-- DEFINE PARSER FOR A TEST CASE: --
caseParser :: Parser Case
caseParser = do
    ws <- whiteSepLine
    return $ map read ws



     -- -- -- FORMAT OUTPUT -- -- --


-- DEFINE A FUNCTION FROM AN INDIVIDUAL SolvedCase -> String. 
formatCase :: SolvedCase -> String
formatCase sol = 
    -- EXAMPLE: nothing to speak of here:
    show sol
    
   

-- --------------- STOP EDITING --------------- --



    --------------------
    -- IO BOILERPLATE --
    --------------------


main = do
     
     -- pass the input file name to our program:
    (f:_) <- getArgs
    file  <- readFile f

     -- start parsing, solve problem, and prepare output: 
    let inp  = parseWith mainParser file
        solution        = map algorithm inp
        solutionStrings = map formatCase solution
        outp = zipWith (++) prefixes solutionStrings
     
     -- write the prepared output to screen:
    putStr $ unlines outp


-- dies with error, or returns some datatype with our parsed data:
parseWith :: Parser a -> String -> a
parseWith p = either (error . show) id . parse p "" 

-- to begin parsing, we read in a line containing the number of test cases 
-- to follow. We parse them with caseParser, returning a list:
mainParser :: Parser Input
mainParser = do
    n  <- word
    ms <- count (read n) caseParser 
    return ms
    <?> "mainParser"

-- strings to prepend to output:
prefixes = [ "Case #" ++ show n ++ ": " | n <- [1..]]





    ---------------------
    -- VARIOUS PARSERS --
    ---------------------


-- -- LINE PARSERS -- --


-- a single line String, up to the newline:
wholeLine :: Parser String
wholeLine = manyTill anyChar (try newline) <?> "wholeLine"

-- parse a String with whitespace-separated values into [String]
whiteSepLine = manyTill spaceSepWord (newline <|> (eof >> return '\n')) <?> "whiteSepLine"


-- -- WORD PARSERS -- -- 


-- a single word followed by whitespace (space, newline, etc.):
word = do
    w <- many1 nonWhite
    spaces
    return w
    <?> "word"

-- a single word followed by one or more ' ' characters (won't consume '\n')
spaceSepWord = do
    w <- many1 nonWhite
    many (char ' ')
    return w
    <?> "spaceSepWord"

-- e.g. "hello:world" ---> ("hello","world")
-- won't consume newlines
twoWordsSepBy c = do
    x <- manyTill nonWhite (try$ char c)
    y <- many1 nonWhite
    many (char ' ')
    return (x,y)
    <?> "twoWordsSepBy"


-- -- CHARACTER PARSERS -- --


-- non-whitespace character:
nonWhite = noneOf " \v\f\t\r\n" <?> "nonWhite"


