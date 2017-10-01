import Control.Monad

main :: IO ()
main = do
  cases <- getLine
  forM_
    [1 .. read cases]
    (\_ -> do
       line <- getLine
       putStrLn $encode line)

encode :: String -> String
encode x
  | length x <= 10 = x
  | otherwise = [head x] ++ show (length x - 2) ++ [last x]
