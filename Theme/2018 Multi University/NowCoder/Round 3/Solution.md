# H. Diff-prime Pairs

根据题目要求，明显可知$i=j$的情况被排除，考虑$g=\gcd(i,j)$, 我们可以得到$i=p_1g, j=p_2g$。这里直接考虑$g$，显然对于任意$g$都是可以的，所以我们计算有多少个$g$对当前的质数对$(p_1,p_2)$有贡献即可。不妨令$p_1<p_2$，显然有$\lfloor n/p_2\rfloor$个$g$满足条件。根据题目描述，由于质数对是一一对应的，最终答案需要乘2（因为$(p_1,p_2),(p_2,p_1)$按题目描述是两个质数对）接下来考虑质数对，很显然的是按照递增方向考虑，第$i$个质数给答案的贡献值是$i-1$（前面有$i-1$个质数比当前质数小)。

所以本题答案很简单（$p(i)$是第$i$个质数）：
$$
ans = 2\sum^{p(i)\le n}_{i=2}\lfloor\frac{n}{p(i)}\rfloor\times(i-1)
$$

$O(n)$预处理质数表加上$O(n)$统计答案即可。