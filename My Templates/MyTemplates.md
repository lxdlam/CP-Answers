# Ramen's ACM Templates

## Standard Answer Template

注意：原版解答模板太长，仅摘取必要部分

- 运行时间计算：

  ```c++
  // C风格
  clock_t begin = now();
  cout << "Elapsed Time: " << (double)(clock() - begin) * 1000 / CLOCKS_PER_SEC << "ms." << endl;
  // C++风格
  auto _begin = chrono::steady_clock::now();
  chrono::duration<double, milli> _duration = chrono::steady_clock::now() - _begin;
  cerr << "Elapsed Time: " << _duration.count() << "ms." << endl;
  ```

- 快速`cin/cout`：

  ```c++
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ```

- Debug宏：

  ```c++
  #define debug(_a) cout << #a << " = " << a << endl;
  ```

## Data Structures

### FenwickTree

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

### Union-Set

**并查集**

最终优化版。

```c++
class UF
{
  public:
    void init(int n)
    {
        id.clear();
        sz.clear();
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

## Big Integer

**大数模板**，裸模板题强烈建议使用Python3，否则可以选择Java。

C++下的NTT适用于很多种情况。

### Python3

无论是速度还是占用秒杀Java。

```python
def main():
    a = int(input())
    b = int(input())
    print(a * b)


main()
```

### Java

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

### C++ With NTT

NTT是快速数论变换，速度极快。

（等待补完）

## Strings

### KMP

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

### Trie

**链式Trie树**

两点注意：

1. `START`是字母表首的字符，`CHARSIZE`是字母表大小。一些常见的取值有：

   A~Z：`START = 'a', CHARSIZE = 26`

   0~9：`START = '0', CHARSIZE = 10`

2. 注意如何修改插入行为和匹配行为

```c++
const int CHARSIZE = 26;
const char START = 'a';

struct Node
{
    Node *next[CHARSIZE];
    int num;

    Node() : num(0)
    {
        for (int i = 0; i < CHARSIZE; i++)
        {
            next[i] = NULL;
        }
    }
};

struct Trie
{
    Node *root;

    ~Trie()
    {
        makeEmpty(root);
        delete root;
    }

    Trie()
    {
        root = new Node;
    }

    void insert(const string &s)
    {
        Node *node = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (node->next[s[i] - START] == NULL)
                node->next[s[i] - START] = new Node;
            node = node->next[s[i] - START];
            node->num++;
        }
    }

    int query(const string &s)
    {
        Node *node = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (node->next[s[i] - START] == NULL)
                return 0;
            node = node->next[s[i] - START];
        }
        return node->num;
    }

    void clear()
    {
        this->~Trie();
        root = new Node;
    }

  private:
    void makeEmpty(Node *s)
    {
        if (s == NULL)
            return;
        for (int i = 0; i < CHARSIZE; i++)
        {
            if (s->next[i] != NULL)
            {
                makeEmpty(s->next[i]);
                delete s->next[i];
            }
        }
    }
};
```

### AC Automation

**AC自动机**

注意定义：

```c++
const int CHARSIZE = 26; // 字母表大小
const char START = 'a'; // 字母表起始
```

#### Linked Trie

**链树实现**

```c++
struct Node
{
    Node *next[CHARSIZE];
    Node *fail;
    int num;

    Node() : num(0), fail(NULL)
    {
        for (int i = 0; i < CHARSIZE; i++)
        {
            next[i] = NULL;
        }
    }
};

struct ACAuto
{
    Node *root;

    ACAuto()
    {
        root = new Node;
    }

    void insert(const string &s)
    {
        Node *node = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (node->next[s[i] - START] == NULL)
                node->next[s[i] - START] = new Node;
            node = node->next[s[i] - START];
        }
        node->num++;
    }

    int query(const string &s)
    {
        Node *cur = root;
        Node *temp;
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            cur = cur->next[s[i] - START];
            temp = cur;
            while (temp != root)
            {
                res += temp->num;
                temp->num = 0; // Avoid matches too many times
                temp = temp->fail;
            }
        }
        return res;
    }

    void build()
    {
        queue<Node *> q;
        Node *cur;
        root->fail = root;
        for (int i = 0; i < CHARSIZE; i++)
        {
            if (root->next[i] == NULL)
                root->next[i] = root;
            else
            {
                root->next[i]->fail = root;
                q.push(root->next[i]);
            }
        }
        while (!q.empty())
        {
            cur = q.front();
            q.pop();
            for (int i = 0; i < CHARSIZE; i++)
            {
                if (cur->next[i] == NULL)
                    cur->next[i] = cur->fail->next[i];
                else
                {
                    cur->next[i]->fail = cur->fail->next[i];
                    q.push(cur->next[i]);
                }
            }
        }
    }
};
```

#### Static Array Trie

**静态数组**，注意调整`SIZE`预防超时

```c++
struct ACAuto
{
    int next[SIZE][CHARSIZE];
    int fail[SIZE], num[SIZE];
    int root;
    int size;

    ACAuto()
    {
        memset(next, 0, sizeof(next));
        memset(fail, 0, sizeof(fail));
        memset(num, 0, sizeof(num));
        init();
    }

    void init()
    {
        size = 0;
        root = newnode();
    }

    int newnode()
    {
        for (int i = 0; i < CHARSIZE; i++)
            next[size][i] = -1;
        num[size++] = 0;

        return size - 1;
    }

    void insert(const string &s)
    {
        int cur = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (next[cur][s[i] - START] == -1)
                next[cur][s[i] - START] = newnode();
            cur = next[cur][s[i] - START];
        }
        num[cur]++;
    }

    void build()
    {
        queue<int> q;
        int cur;
        fail[root] = root;
        for (int i = 0; i < CHARSIZE; i++)
        {
            if (next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                q.push(next[root][i]);
            }
        }
        while (!q.empty())
        {
            cur = q.front();
            q.pop();
            for (int i = 0; i < CHARSIZE; i++)
            {
                if (next[cur][i] == -1)
                    next[cur][i] = next[fail[cur]][i];
                else
                {
                    fail[next[cur][i]] = next[fail[cur]][i];
                    q.push(next[cur][i]);
                }
            }
        }
    }

    int query(const string &s)
    {
        int cur = root, res = 0, temp;
        for (int i = 0; i < s.size(); i++)
        {
            cur = next[cur][s[i] - 'a'];
            temp = cur;
            while (temp != root)
            {
                res += num[temp];
                num[temp] = 0;
                temp = fail[temp];
            }
        }
        return res;
    }
};
```

## Dynamic Programming

### Backpack

**背包问题**

注意预存在代码：

```c++
vector<int> dp;

void init(int size)
{
    dp.resize(size);
}
```

#### Zero-One

注意：需要跑`n`次，`cost`和`value`一一对应。

```c++
void ZeroOnePack(int cost, int value, int size)
{
    for (int i = size; i >= cost; i--)
        dp[i] = max(dp[i], dp[i - cost] + value);
}
```

示例代码：

```c++
for (int i = 0; i < costs.size(); i++)
        ZeroOnePack(costs[i], values[i], size);
```

#### Complete

注意：与上面注意一样，不再给出示例代码。

```c++
void CompletePack(int cost, int value, int size)
{
    for (int i = cost; i <= size; i++)
        dp[i] = max(dp[i], dp[i - cost] + value);
}
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

### GCD

#### Euclid

**欧几里得法**，大素数较慢

```c++
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
```

#### Stein

**Stein**法，大素数下也能取得很高的效率。

```c++
int sgcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a % 2 == 0 && b % 2 == 0)
        return 2 * sgcd(a >> 1, b >> 1);
    else if (a % 2 == 0)
        return sgcd(a >> 1, b);
    else if (b % 2 == 0)
        return sgcd(a, b >> 1);
    else
        return sgcd(abs(a - b), min(a, b));
}
```

### Extend GCD

**扩展GCD算法**，用于求$ax+by=gcd(a,b)$中的一组$x$与$y$。

注意：`x`与`y`均为引用变量。

```c++
long long extend_gcd(long long a, long long b, long long &x, long long &y)
{
    if (a == 0 && b == 0)
        return -1;
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extend_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
```

### Inverse element

**乘法逆元**，用于求解下列方程式$ax\equiv1(\mod m)$中的$x$。

注意：必须有上面的扩展GCD算法。

```c++
long long mod_reverse(long long a, long long n)
{
    long long x, y;
    long long d = extend_gcd(a, n, x, y);
    if (d == 1)
        return (x % n + n) % n;
    else
        return -1;
}
```

### Primes

#### Prime Check

**检测素数表**

用法：假设待检测的数字是`num`，则`notprime[num] == true`意味着`num`不是素数。

```c++
bool notprime[SIZE] = {false};

void init()
{
    notprime[0] = notprime[1] = true;
    for (int i = 2; i < SIZE; i++)
        if (!notprime[i])
        {
            if (i > SIZE / i)
                continue;
            for (int j = i * i; j < SIZE; j += i)
                notprime[j] = true;
        }
}
```

#### Primes Table

**素数表**

注意：`prime[0]`代表素数表长度。

```c++
int prime[SIZE + 1] = {0};
void getPrime()
{
    for (int i = 2; i <= SIZE; i++)
    {
        if (!prime[i])
            prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && prime[j] <= SIZE / i; j++)
        {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
```

### Factors

**质因数分解**

注意：必须先得到上面的素数表才能进行分解

```c++
long long factor[100][2];
int fatCnt;
int getFactors(long long x)
{
    fatCnt = 0;
    long long tmp = x;
    for (int i = 1; prime[i] <= tmp / prime[i]; i++)
    {
        factor[fatCnt][1] = 0;
        if (tmp % prime[i] == 0)
        {
            factor[fatCnt][0] = prime[i];
            while (tmp % prime[i] == 0)
            {
                factor[fatCnt][1]++;
                tmp /= prime[i];
            }
            fatCnt++;
        }
    }
    if (tmp != 1)
    {
        factor[fatCnt][0] = tmp;
        factor[fatCnt++][1] = 1;
    }
    return fatCnt;
}
```

### Fast Pow

**快速幂**，原理即对于$a^b$，考虑把$b$转化为二进制，则加上位运算能大大减少运算次数和难度。

注意：根据同余定理，假设要计算$a^b\mod m$，只需对每一步都取余即可，注意修改余数，默认$1000000007$

```c++
long long fp(long long base, long long expr, long long mod = 1e9 + 7)
{
    ll ans = 1;
    base %= mod;
    while (expr)
    {
        if (expr & 1LL)
            ans = (ans * base) % mod;
        base = (base * base) % mod;
        expr >>= 1LL;
    }
    return ans % mod;
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
### Reverse String

**翻转字符串**

```c++
string reverse(const string &s)
{
  string res = s;
  reverse(res.begin(), res.end());
  return res;
}
```

