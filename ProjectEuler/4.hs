--找由两个三位数乘积构成的最大回文数
solution = maximum [ x | a <-[100..999], b <-[100..999], let x = a * b , let s = show x , s == reverse s ]