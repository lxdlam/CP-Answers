# Ramen's ACM Templates

[TOC]

## 1. Random Stuff

### 标准解答模板

```c++
#include <bits/stdc++.h>

using namespace std;

typedef long long ll; // 可以使用__int64代替，但是最好使用long long
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef set<int> si;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> cb; // char[][]的替代品，可能会超时

#define FOR(_i, _begin, _end) for (int _i = _begin; _i < _end; _i++)

#define mp make_pair
#define pb push_back

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); // 事先测试是否支持C++11
    cout.tie(nullptr);
    
    #ifdef LOCAL
    clock_t _begin = clock(); // time.h
    #endif
    
    // 解题代码
    
    #ifdef LOCAL
    cerr << "Time elapsed: " << (double)(clock() - _begin) * 1000 / CLOCKS_PER_SEC << "ms." << endl; // 时间测试，打到stderr上
    #endif
    
    return 0;
}
```

### 现场赛常用测试

- C++11支持：

  ```c++
  for(auto &i : v)
      cin >> i;
  ```

  编译成功即有支持。

  也可以选择：

  ```c++
  #if __cplusplus >= 201103L
  int test[(ll)1e12];
  #endif
  ```

  精准测试，只要支持必定有RE。C++14：201402L

- 最大内存

  开栈：

  ```c++
  const int SIZE = 1e7 + 10;
  int test[SIZE];
  ```

  看RE时机。

- 最大时间

  $O(n)$：

  ```c++
  const int BOUND = 1e7;
  int t = 1;
  FOR(i, 1, BOUND)
      t  = (t * i) % 10007
  ```

  $O(n^2)$：

  ```c++
  const int BOUND = 1e4;
  int t = 1;
  FOR(i, 1, BOUND)
      FOR(j, 1, BOUND)
          t  = (t * i * j) % 10007
  ```

- 排版问题

  - 行尾空行
  - 行尾空格

### Java解答模板

```java
import java.util.*;
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

// 大数问题选择
```

## 2. 数学相关

### 组合数表

```c++
ll c[SIZE][SIZE] = {0};

void getCom()
{
    c[0][0] = 1;
    for (int i = 1; i < SIZE; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1]; // 必要的一步一模
    }
}
```

### 错排问题

```c++
ll d[SIZE];

void getD()
{
    ll res;
    d[1] = 0, d[2] = 1;
    for (int i = 3; i < SIZE; i++)
        d[i] = (i - 1) * (d[i - 1] + d[i - 2]);
}
```

### 两种GCD与LCM

```c++
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll sgcd(ll a, ll b)
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

ll lcm(ll a, ll b)
{
    return a / sgcd(a, b) * b;
}
```

### 质数表

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

### 简易欧拉筛

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

### 合数分解

```c++
ll factor[100][2];
int fatCnt;
int getFactors(ll x)
{
    fatCnt = 0;
    ll tmp = x;
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

### 扩展GCD以及逆元

```c++
ll extend_gcd(ll a, ll b, ll &x, ll &y)
{
    if (a == 0 && b == 0)
        return -1;
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extend_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll mod_reverse(ll a, ll n)
{
    ll x, y;
    ll d = extend_gcd(a, n, x, y);
    if (d == 1)
        return (x % n + n) % n;
    else
        return -1;
}

// Solve a*x + b*y = n
ll cal(ll a, ll b, ll n)
{
    ll x, y;
    ll gcd = extend_gcd(a, b, x, y);
    if (n % gcd != 0)
        return -1;
    x *= n / gcd;
    b /= gcd;
    if (b < 0)
        b = -b;
    ll ans = x % b;
    if (ans <= 0)
        ans += b;
    return ans;
    // answer:
    // x = ans, y = (n - ans * a) / b
}
```

### 快速幂与逆元

```c++
ll fp(ll base, ll expr, ll mod = 1e9 + 7)
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

ll inverse(ll a, ll mod = 1e9 + 7)
{
    return fp(a, mod - 2);
}
```

## 3. 字符串

### KMP

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

// 注意，必要时把vector改成数组
// next数组意义：最长前缀与后缀匹配长度
// 最小循环节长度：i / next[i]当i % next[i] == 0
```

### Trie树

```c++
const int CHARSIZE = 26; // 字母表大小
const char START = 'a'; // 字母表起点

struct Node
{
    Node *next[CHARSIZE]; // 无规律字母表：离散化或者map<char, Node*>
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

### AC自动机

#### 链式实现

```C++
const int CHARSIZE = 26;
const char START = 'a';

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

#### 静态数组

```c++
const int CHARSIZE = 26;
const char START = 'a';

const int SIZE = 5e5 + 10; // 小心RE

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

## 4. 数据结构

### 区间查询

#### 树状数组

```c++
template <typename T> // 不用泛型
class FenTree
{
  private:
    vector<T> v;
    size_t size;

    inline int lowbit(int k)
    {
        return k & -k;
    }

  public:
    void init(size_t size)
    {
        this->size = size + 1;
        v.clear();
        v.resize(size + 1);
    }

    void update(int pos, T val)
    {
        while (pos < size)
        {
            v[pos] += val;
            pos += lowbit(pos);
        }
    }

    T get(int pos)
    {
        T res = 0;
        while (pos)
        {
            res += v[pos];
            pos -= lowbit(pos);
        }
        return res;
    }

    T getSeg(int l, int r)
    {
        return get(r) - get(l - 1);
    }
};

// 比线段树好写且快
// 支持单点修改，而且必须具有前缀和性质
// 进一步来说，支持交换群操作
// 区间修改还是敲线段树
```

#### 线段树

```c++
template <typename T>
class SegTree
{
  private:
    size_t size;
    vector<T> data;
    vector<T> flag;  
    vector<T> *base;

    void pushup(int pos)
    {
        data[pos] = data[pos << 1] + data[pos << 1 | 1];
    }

    void pushdown(int pos, int lcnt, int rcnt)
    {
        if (flag[pos])
        {
            flag[pos << 1] += flag[pos];
            flag[pos << 1 | 1] += flag[pos];
            data[pos << 1] += flag[pos] * lcnt;
            data[pos << 1 | 1] += flag[pos] * rcnt;
            flag[pos] = 0;
        }
    }

    int calSize(int num)
    {
        int i = 1, j = num;
        while ((j >>= 1) || (i < num))
            i <<= 1;
        return i * 2;
    }

    void build(int l, int r, int cur)
    {
        if (l == r)
        {
            data[cur] = (*base)[l - 1];
            return;
        }

        int m = ((r - l) >> 1) + l;
        build(l, m, cur << 1);
        build(m + 1, r, cur << 1 | 1);
        pushup(cur);
    }

    void update(int pos, T val, int l, int r, int cur)
    {
        if (l == r)
        {
            data[cur] += val;
            return;
        }

        int m = ((r - l) >> 1) + l;
        pushdown(cur, m - l + 1, r - m);
        if (pos <= m)
            update(pos, val, l, m, cur << 1);
        else
            update(pos, val, m + 1, r, cur << 1 | 1);
        pushup(cur);
    }

    void update(int ul, int ur, T val, int l, int r, int cur)
    {
        if (ul <= l && r <= ur)
        {
            data[cur] += val * (r - l + 1);
            flag[cur] += val;
            return;
        }

        int m = ((r - l) >> 1) + l;
        pushdown(cur, m - l + 1, r - m);

        if (ul <= m)
            update(ul, ur, val, l, m, cur << 1);
        if (ur > m)
            update(ul, ur, val, m + 1, r, cur << 1 | 1);
        pushup(cur);
    }

    T query(int ql, int qr, int l, int r, int cur)
    {
        if (ql <= l && r <= qr)
            return data[cur];

        int m = ((r - l) >> 1) + l;
        pushdown(cur, m - l + 1, r - m);

        T ans = 0;
        if (ql <= m)
            ans += query(ql, qr, l, m, cur << 1);
        if (qr > m)
            ans += query(ql, qr, m + 1, r, cur << 1 | 1);
        return ans;
    }

  public:
    void build(vector<T> v)
    {
        size = v.size();
        data.clear();
        flag.clear();
        data.resize(calSize(size));
        flag.resize(calSize(size));
        base = &v;
        build(1, size, 1);
    }

    void update(int pos, T val)
    {
        update(pos, val, 1, size, 1);
    }

    void update(int ul, int ur, T val)
    {
        update(ul, ur, val, 1, size, 1);
    }

    T query(int l, int r)
    {
        return query(l, r, 1, size, 1);
    }
};

// 类封装使用方便
// 但是实际上基本不用类封装
// 只需要实现以下重要函数
// build, pushup, pushdown, updatePoint, updateSeg, query
// 注意大小，要求不严格就*4，否则是大于它最近的2指数幂的2倍
// 尤其注意pushdown，多种标记时推标记先后顺序
```

### 并查集

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

    int find(int p) // 找根节点
    {
        int k = p, j;
        while (p != id[p])
            p = id[p];
        while (k != p) // 路径压缩
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

        if (sz[pRoot] < sz[qRoot]) // 按秩合并
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
    vector<int> id; // 如果key不是int，做离散化
    vector<int> sz;
    int length;
};
```

