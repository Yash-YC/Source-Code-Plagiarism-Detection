import Text.Printf
import Control.Monad

getInt = (read <$> getLine) :: IO Int

write a "" = a
write a r = let
  h = (take 1 r)
  b = max (h ++ a) (a ++ h)
  in
  write b (drop 1 r)

main = do
  t <- getInt
  forM_ [1..t] $ \c -> do
    s <- getLine
    printf "Case #%d: %s\n" c $ write (take 1 s) (drop 1 s)
