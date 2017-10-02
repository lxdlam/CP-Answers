-- Source: https://open.kattis.com/problems/r2
-- From: Croatian Open Competition in Informatics 2006/2007, contest #2
main :: IO ()
main = do
  contents <- getLine
  let [r1, s] = readInts contents
  print (2 * s - r1)

readInts :: String -> [Int]
readInts = map read . words
