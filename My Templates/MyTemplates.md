# Ramen's ACM Templates

## FenwickTree

**树状数组**

两点注意：

1. 数组下标从1开始

2. 匹配修改位置，可求和、差、积、最大最小值等

```c++
typedef vector<int> vi;

inline int lowbit(int k)
{
    return k & -k;
}

void update(vi &v, int pos, int val)
{
    int len = v.size();
    while (pos < len)
    {
        //change behavior here
        v[pos] += val;
        pos += lowbit(pos);
    }
}

int getVal(vi &v, int pos)
{
    int res = 0;
    while (pos)
    {
        res += v[pos];
        pos -= lowbit(pos);
    }
    return res;
}
```

## Big Integer

**大数模板**，使用Java

五点注意:

1. 没有运算符可以直接运算，所有的都是方法

2. 除法包含两个部分，得数和余数

3. 内置常量：`BigInteger.ONE`、`BigInteger.ZERO`、`BigInteger.TEN`

4. 可以使用字符串构造，如果从输入输出流直接读取就`sc.nextBigInteger()`

5. 一些输入输出流方法要掌握，如`sc.hasNext()`

```java
import java.util.Scanner;
import java.math.BigInteger;

public class BigIntTemplate {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger a, b;
        while (sc.hasNext()) {
            a = sc.nextBigInteger();
            b = sc.nextBigInteger();
            System.out.println(a.add(b.negate()).abs());
        }
        sc.close();
    }
}
```

## KMP

**标准KMP算法**

两点注意：

1. 使用了`vector<int>`重构，必要时可以换成数组，注意方法的修改

2. `next`数组意义：最长前缀与后缀匹配长度，最小循环节长度：`i / next[i]`当`i % next[i] == 0`

3. 启动新匹配流程以及匹配行为的修改

```c++
void getNext(const string &s, vector<int> &next)
{
    int j = -1;
    next.push_back(-1);
    for (int i = 0; i < s.size(); i++)
    {
        while (j != -1 && s[i] != s[j])
            j = next[j];
        next.push_back(++j);
    }
}

int match(const string &t, const string &p)
{
    int count = 0;
    int j = 0;
    vector<int> next;
    getNext(p, next);
    for (int i = 0; i < t.size(); i++)
    {
        while (j != -1 && t[i] != p[j])
            j = next[j];
        j++;
        if (j == p.size())
        {
            //matched, change behavior here
            count++;
            j = next[j]; // important, start a new match process
        }
    }
    return count;
}
```

## Union-Set

**并查集**

最终优化版。

```c++
class UF
{
  public:
    UF(int n)
    {
        count = length = n;
        id.resize(n);
        for (int i = 0; i < length; i++)
            id[i] = i;
        sz.resize(n);
        for (int i = 0; i < length; i++)
            sz[i] = 1;
    }

    int getCount()
    {
        return count;
    }

    bool connected(int p, int q)
    {
        return find(p) == find(q);
    }

    int find(int p)
    {
        int k = p, j;
        while (p != id[p])
            p = id[p];
        while (k != p)
        {
            j = id[k];
            id[k] = p;
            k = j;
        }
        return p;
    }

    void Union(int p, int q)
    {
        int pRoot = find(p);
        int qRoot = find(q);

        if (pRoot == qRoot)
            return;

        if (sz[pRoot] < sz[qRoot])
        {
            id[pRoot] = qRoot;
            sz[qRoot] += sz[pRoot];
        }
        else
        {
            id[qRoot] = pRoot;
            sz[pRoot] += sz[qRoot];
        }
        count--;
    }

  private:
    int count;
    vector<int> id;
    vector<int> sz;
    int length;
};
```

## Maths

一些常用**数学算法**与**打表算法**

一般有定义：

```c++
const int SIZE = 1e6 + 10;
```

### Factorials

**阶乘表**

```c++
long long n[SIZE] = {1};

void getFac()
{
    for (int i = 1; i < SIZE; i++)
        n[i] = n[i - 1] * i;
}
```

### Combinations

**组合数表**

```c++
long long c[SIZE][SIZE] = {0};

void getCom()
{
    c[0][0] = 1;
    for (int i = 1; i < SIZE; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            // Will be extremely large!
    }
}
```

### GCD for small integer

**较小型数据的最大公约数**

```c++
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
```

## Utilities

**一些标准库没有的工具函数**

### Split String

**切割字符串**

注意：修改匹配位置

```c++
vector<string> split(const string &s)
{
    vector<string> res;
    int i = 0;
    for (int pos = 0; pos < s.size(); pos++)
    {
        if (s[pos] <= 'Z' && s[pos] >= 'A')
        {
            res.push_back(s.substr(i, pos - i));
            i = pos + 1;
        }
    }
    res.push_back(s.substr(i, s.size() - i));
    return res;
}
```