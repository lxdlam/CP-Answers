import Data.List

main :: IO ()
main = do
  t <- getLine
  temp <- getLine
  let res = maximum $ toIntList temp
  print $
    case res > 25 of
      True -> res - 25
      otherwise -> 0

toIntList :: String -> [Int]
toIntList = map read . words
