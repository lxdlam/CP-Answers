main = do
  _ <- getLine
  route <- getLine
  putStrLn $ check $ helper route 0 0

check :: (Int, Int) -> String
check (sf, fs)
  | sf > fs = "YES"
  | otherwise = "NO"

helper :: String -> Int -> Int -> (Int, Int)
helper [_] sf fs = (sf, fs)
helper (x:rest@(y:_)) sf fs
  | x == 'S' && y == 'F' = helper rest (sf + 1) fs
  | x == 'F' && y == 'S' = helper rest sf (fs + 1)
  | otherwise = helper rest sf fs
