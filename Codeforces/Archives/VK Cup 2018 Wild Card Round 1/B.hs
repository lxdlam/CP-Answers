import Data.List

main :: IO ()
main = do
    num <- getLine
    temp <- getLine
    let arr = toSub . sorted $ temp
    print $ cal arr (minimum . toGcd $ arr)

sorted :: String -> [Int]
sorted = sort . map read . words

toSub :: [Int] -> [Int]
toSub [_] = []
toSub (x:rest@(y:ys)) = (y - x) : toSub rest

toGcd :: [Int] -> [Int]
toGcd [_] = []
toGcd (x:rest@(y:ys)) = gcd x y : toGcd rest

cal :: [Int] -> Int -> Int
cal lst dis = sum (map (`div` dis) lst) - length lst