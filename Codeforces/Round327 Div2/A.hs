main :: IO ()
main = do
  a <- getLine
  b <- getLine
  c <- getLine
  let l = read a :: Float
      p = read b :: Float
      q = read c :: Float
  print (l / (p + q) * p)
