# D. Rikka with Stone-Paper-Scissors

听了jls讲题才掉头回去看的题目，由于Yuta出牌策略是随机的，那么Rikka不存在任何最优策略，所以期望就是得分平均数，而得分是比较容易计算的，就是得分概率乘以期望，最后做一下gcd就行。

# K. Rikka with Badminton

简单容斥一下，结果是$|S_1\cup S_2|=|S_1|+|S_2|-|S_1\cap S_2|$，其中$S_1$是拍子小于2的方案数，$S_2$是球小于1的方案数，最终答案是$(1+b+d)2^{a+c}+2^{a+b}-(1+b)2^a$。