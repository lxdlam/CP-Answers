--求斐波那契数列400万以内奇数之和
solution = sum $ filter even $ takeWhile (<= 4000000) fibs
  where
    fibs = 1 : 1 : zipWith (+) fibs (tail fibs)
