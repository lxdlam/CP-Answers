fib :: Integer -> Integer
fib 1 = 1
fib 2 = 1
fib x = fib (x - 1) + fib (x - 2)
