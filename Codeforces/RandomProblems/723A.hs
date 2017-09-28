import Data.List

main :: IO ()
main = do
  t <- getLine
  let num = toIntList t
  print $ maximum num - minimum num

toIntList :: String -> [Int]
toIntList = map read . words
