# Ramen's ACM Templates

## Standard Answer Template

注意：

1. 标准解答模板里面涉及到关闭`cin/cout`与`std`流同步的部分，关闭后不能与`scanf/printf`混用。
2. 如果编译器不支持`#include <bits/stdc++.h>`，换成对应头文件的写法。

```c++
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}
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
    long long ans = 1;
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

## Graph

### Maxflow

**最大流问题**

```c++
bool vis[200001];
int dist[200001];
//解释一下各数组的含义：vis两个用处：spfa里的访问标记，増广时候的访问标记，dist是每个点的距离标号
int n, m, s, t, ans = 0;
//s是起点，t是终点，ans是费用答案
int nedge = -1, p[200001], c[200001], cc[200001], nex[200001], head[200001];
//这里是边表，解释一下各数组的含义：p[i]表示以某一点出发的编号为i的边对应点，c表示编号为i的边的流量，cc表示编号为i的边的费用，nex和head不说了吧。。。
inline void addedge(int x, int y, int z, int zz)
{
    p[++nedge] = y;
    c[nedge] = z;
    cc[nedge] = zz;
    nex[nedge] = head[x];
    head[x] = nedge;
}
//建边（数组模拟边表倒挂）
inline bool spfa(int s, int t)
{
    memset(vis, 0, sizeof vis);
    for (int i = 0; i <= n; i++)
        dist[i] = 1e9;
    dist[t] = 0;
    vis[t] = 1;
    //首先SPFA我们维护距离标号的时候要倒着跑，这样可以维护出到终点的最短路径
    deque<int> q;
    q.push_back(t);
    //使用了SPFA的SLF优化（SLF可以自行百度或Google）
    while (!q.empty())
    {
        int now = q.front();
        q.pop_front();
        for (int k = head[now]; k > -1; k = nex[k])
            if (c[k ^ 1] && dist[p[k]] > dist[now] - cc[k])
            {
                //首先c[k^1]是为什么呢，因为我们要保证正流，但是SPFA是倒着跑的，所以说我们要求c[k]的对应反向边是正的，这样保证走的方向是正确的
                dist[p[k]] = dist[now] - cc[k];
                //因为已经是倒着的了，我们也可以很清楚明白地知道建边的时候反向边的边权是负的，所以减一下就对了（负负得正）
                if (!vis[p[k]])
                {
                    vis[p[k]] = 1;
                    if (!q.empty() && dist[p[k]] < dist[q.front()])
                        q.push_front(p[k]);
                    else
                        q.push_back(p[k]);
                    //SLF优化
                }
            }
        vis[now] = 0;
    }
    return dist[s] < 1e9;
    //判断起点终点是否连通
}
inline int dfs(int x, int low)
{
    //这里就是进行増广了
    if (x == t)
    {
        vis[t] = 1;
        return low;
    }
    int used = 0, a;
    vis[x] = 1;
    //这边是不是和dinic很像啊
    for (int k = head[x]; k > -1; k = nex[k])
        if (!vis[p[k]] && c[k] && dist[x] - cc[k] == dist[p[k]])
        {
            //这个条件就表示这条边可以进行増广
            a = dfs(p[k], min(c[k], low - used));
            if (a)
                ans += a * cc[k], c[k] -= a, c[k ^ 1] += a, used += a;
            //累加答案，加流等操作都在这了
            if (used == low)
                break;
        }
    return used;
}
inline int costflow()
{
    int flow = 0;
    while (spfa(s, t))
    {
        //判断起点终点是否连通，不连通说明满流，做完了退出
        vis[t] = 1;
        while (vis[t])
        {
            memset(vis, 0, sizeof vis);
            flow += dfs(s, 1e9);
            //一直増广直到走不到为止（这样也可以省时间哦）
        }
    }
    return flow; //这里返回的是最大流，费用的答案在ans里
}
int main()
{
    memset(nex, -1, sizeof nex);
    memset(head, -1, sizeof head);
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1; i <= m; i++)
    {
        int x, y, z, zz;
        scanf("%d%d%d%d", &x, &y, &z, &zz);
        addedge(x, y, z, zz);
        addedge(y, x, 0, -zz);
    }
    printf("%d ", costflow());
    printf("%d", ans);
    return 0;
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

