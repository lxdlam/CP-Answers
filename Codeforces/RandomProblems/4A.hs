main :: IO ()
main = do
  n <- getLine
  putStrLn $ check $ read n

check :: Int -> String
check n
  | n == 2 = "NO"
  | (n - 2) `mod` 2 == 0 = "YES"
  | otherwise = "NO"
