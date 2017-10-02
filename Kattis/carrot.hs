-- Source: https://open.kattis.com/problems/carrots
-- From: KTH Training
main :: IO ()
main = do
  contents <- getLine
  let [_, c] = readInts contents
  print c

readInts :: String -> [Int]
readInts = map read . words
