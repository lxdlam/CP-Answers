# Ramen's ACM Templates

## 1. Random Stuff

### 标准解答模板

```c++
#include <bits/stdc++.h>

using namespace std;

typedef long long ll; // 可以使用__int64代替，但是最好使用long long
typedef unsigned long long ull; // 自然溢出即对2^64取模
typedef pair<int, int> pii;
typedef set<int> si;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> cb; // char[][]的替代品，可能会超时

#define FOR(_i, _begin, _end) for (int _i = _begin; _i < _end; _i++)

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int INF = 0x3f3f3f3f;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
// memset(dp, 0x3f, sizeof dp)来初始化成INF

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); // 事先测试是否支持C++11
    cout.tie(nullptr)；
    
    // 解题代码
    
    // 废弃常用时间测试，不精准
    // Linux下直接使用time
    // 使用'\n' 代替 endl!!!
    
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
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.math.BigInteger;
import java.util.StringTokenizer;
import java.io.IOException;

public class Main {
    public static void main(String[] args){
        new Solver().solve(new Reader(System.in));
    }
}

class Solver {
    public void solve(Reader in) {
        // 解答代码
    }
}

// Java快读，按空格分隔并按字符串读入
// 自己做处理
class Reader {
    BufferedReader br;
    StringTokenizer st;

    public Reader(InputStream in) {
        br = new BufferedReader(new InputStreamReader(in), 1 << 22);
        eat("");
    }

    private void eat(String s) {
        st = new StringTokenizer(s);
    }

    public String nextLine() {
        try {
            return br.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    public boolean hasNext() {
        while (!st.hasMoreTokens()) {
            String s = nextLine();
            if (s == null)
                return false;
            eat(s);
        }
        return true;
    }

    public String next() {
        hasNext();
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}

// 大数问题选择
```

### C++快读快写

```c++
namespace io
{
const int MAXSIZE = 1 << 22;
inline char gc()
{
    static char In[MAXSIZE], *at = In, *en = In;
    if (at == en)
        en = (at = In) + fread(In, 1, MAXSIZE, stdin);
    return at == en ? EOF : *at++;
}
template <class T>
inline void read(T &x)
{
    char c;
    while (c = gc(), !isdigit(c) && c != '-')
        ;
    bool f = c == '-';
    x = f ? 0 : c - '0';
    for (c = gc(); isdigit(c); c = gc())
        x = x * 10 + c - '0';
    if (f)
        x = -x;
}
template <>
inline void read(string &x)
{
    stringstream ss;
    char c;
    while ((c = gc()) && c != ' ' && c != '\n')
        ss << c;
    x = ss.str();
}
char Out[MAXSIZE], *cur = Out, *end = Out + MAXSIZE - 100;
void flush()
{
    fwrite(Out, 1, cur - Out, stdout);
    cur = Out;
}
template <typename T>
inline void write(T x, char c = '\n')
{
    static int S[20], *top;
    top = S;
    if (x < 0)
        *cur++ = '-', x = -x;
    do
    {
        *++top = x % 10, x /= 10;
    } while (x);
    while (top != S)
        *cur++ = *top-- + '0';
    *cur++ = c;
    if (cur >= end)
        flush();
}
template <>
inline void write(string x, char c)
{
    for (auto i : x)
        *cur++ = i;
    *cur++ = c;
    if (cur >= end)
        flush();
}
} // namespace io
```

注：

- 快读不能处理使用`EOF`作为文件结束的输入
- `return 0;`之前一定要`flush()`一次
- 如无**特殊情况**使用**杭电版本**的快读

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

// 线性时间处理逆元
ll inv[SIZE];
const ll MOD = 1e9 + 7;

void getInv()
{
    inv[1] = 1;
    for (int i = 2; i <= SIZE; i++)
        inv[i] = MOD - (MOD / i * inv[MOD % i]) % MOD;
}
```

### 欧拉$\phi$函数

```c++
// 线性预处理phi函数表
// 同时需要声明如下：
// prime[SIZE + 1];
ll phi[SIZE + 1];

void getPhi()
{
    phi[1] = 1;
    for (int i = 2; i <= SIZE; i++)
    {
        if (!phi[i])
            phi[prime[++prime[0]] = i] = i - 1;
        for (int j = 1; j <= prime[0] && prime[j] <= SIZE / i; j++)
        {
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
}

// O(sqrt(n)) 时间内得到某一个数的phi值
ll Phi(ll n)
{
    ll phi = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            phi /= i;
            phi *= i - 1;
            while (n % i == 0)
                n /= i;
        }
    }
    if (n != 1)
    {
        phi /= n;
        phi *= n - 1;
    }
    return phi;
}

// 如果是质数，直接-1即可
// 用途：欧拉降幂等
```

#### 例：HDU 2837

```c++
// f(0) = 1 and 0^0=1. f(n) = (n%10)^f(n/10)
// 求f(n)%m
ll Mod(ll a, ll b)
{
    return a < b ? a : a % b + b;
}

ll fp(ll base, ll expr, ll mod = 1e9 + 7)
{
    ll ans = 1;
    //base %= mod;
    while (expr)
    {
        if (expr & 1LL)
            ans = Mod(ans * base, mod); // 注意Mod的改写
        base = Mod(base * base, mod);
        expr >>= 1LL;
    }
    return Mod(ans, mod);
}

ll Phi(ll n)
{
    ll phi = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            phi /= i;
            phi *= i - 1;
            while (n % i == 0)
                n /= i;
        }
    }
    if (n != 1)
    {
        phi /= n;
        phi *= n - 1;
    }
    return phi;
}

ll f(ll n, ll m)
{
    if (n == 0)
        return 1;
    if (m == 1)
        return 0;
    ll phi = Phi(m);
    return fp(n % 10, f(n / 10, phi), m);
}

// Actual Solver
inline void solve()
{
    ll n, m;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        cout << f(n, m) % m << '\n';
    }
}
```

### 快速傅里叶变换与快速数论变换

```c++
// 注意精度问题
namespace FFT
{
typedef std::complex<double> Complex;
typedef std::vector<Complex> vc;

const double EPS = 0.5;

const int MaxL = 18, MaxN = 1 << MaxL;
vc eps(MaxN), inv_eps(MaxN);

void init_eps(int p)
{
    if (p > MaxN)
    {
        eps.resize(p);
        inv_eps.resize(p);
    }
    double pi = acos(-1);
    double angle = 2.0 * pi / p;
    for (int i = 0; i != p; i++)
    {
        eps[i] = Complex(cos(i * angle), sin(i * angle));
        inv_eps[i] = conj(eps[i]);
    }
}

void transform(int n, vc &x, const vc &w)
{
    for (int i = 0, j = 0; i != n; ++i)
    {
        if (i > j)
            swap(x[i], x[j]);
        for (int l = n >> 1; (j ^= l) < l; l >>= 1)
            ;
    }

    for (int i = 2; i <= n; i <<= 1)
    {
        int m = i >> 1;
        for (int j = 0; j < n; j += i)
        {
            for (int k = 0; k != m; ++k)
            {
                Complex z = x[j + m + k] * w[n / i * k];
                x[j + m + k] = x[j + k] - z;
                x[j + k] += z;
            }
        }
    }
}
} // namespace FFT

/* Accelarated FFT
 * See http://blog.miskcoo.com/2018/01/real-dft for more details
 * for (int i = 0; i <= n; ++i)
 * {
 *     double a;
 *     std::scanf("%lf", &a);
 *     A[i] = a;
 * }

 * for (int i = 0; i <= m; ++i)
 * {
 *     double a;
 *     std::scanf("%lf", &a);
 *     A[i] += std::complex<double>{0, a};
 * }

 * int p = 1;
 * while (p < n + m + 1)
 *     p <<= 1;
 * transform(p, A, eps);
 * for (int i = 1; i != p; ++i)
 * {
 *     double x1 = A[i].real(), y1 = A[i].imag();
 *     double x2 = A[p - i].real(), y2 = A[p - i].imag();
 *     std::complex<double> a = {(x1 + x2) * 0.5, (y1 - y2) * 0.5};
 *     std::complex<double> b = {(y1 + y2) * 0.5, -(x1 - x2) * 0.5};
 *     B[i] = a * b;
 * }

 * B[0] = A[0].imag() * A[0].real();

 * transform(p, B, eps_inv);
 */

// 对某数取模或者答案小于某个范围都是可以用的
// 取模数如果不是质数就对两个质数取模然后使用中国剩余定理合并
namespace NTT
{
typedef long long ll;
typedef std::vector<ll> vll;

/*
 * P = Rx2^K+1, G is pr
 * Three recommend choices:
 * p = 2281701377, r = 17, g = 3, k = 27
 * p = 1004535809, r = 479, g = 3, k = 21
 * p = 998244353, r = 119, g = 3, k = 23
 * For more, see NTT_table.md
 */
const int P = 998244353, R = 119, G = 3, K = 2;

inline ll fp(ll base, ll expr, ll mod = P)
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

inline ll add(ll n, ll m)
{
    n += m;
    if (n >= P)
        n -= P;
    return n;
}

inline ll sub(ll n, ll m)
{
    n -= m;
    if (n < 0)
        n += P;
    return n;
}

inline ll mul(ll n, ll m)
{
    return (n % P) * (m % P) % P;
}

inline ll div(ll n, ll m)
{
    ll inv = fp(m, P - 2);
    return mul(n, inv);
}

void transform(int n, vll &x, bool idft = false)
{
    for (int i = 0, j = 0; i != n; ++i)
    {
        if (i > j)
            swap(x[i], x[j]);
        for (int l = n >> 1; (j ^= l) < l; l >>= 1)
            ;
    }

    for (int i = 2; i <= n; i <<= 1)
    {
        int m = i >> 1;
        ll eps = fp(G, idft ? (P - 1) / i : P - 1 - (P - 1) / i, P);
        for (int j = 0; j < n; j += i)
        {
            ll t = 1;
            for (int k = 0; k != m; ++k)
            {
                ll z = mul(x[j + m + k], t);
                x[j + m + k] = sub(x[j + k], z);
                x[j + k] = add(x[j + k], z);
                t = mul(t, eps);
            }
        }
    }

    if (idft)
    {
        ll inv = fp(n, P - 2, P);
        for (int i = 0; i < n; i++)
            x[i] = mul(x[i], inv);
    }
}
} // namespace NTT
```

#### 4个卷积恒等式：

$$
\sum_{i=0}^{N}\sum_{j=0}^ia_{i,j}=\sum_{j=0}^{N}\sum_{i=j}^Na_{i,j}\\
\sum_{j=0}^{N}\sum_{i=j}^Na_{i,i-j}=\sum_{j=0}^{N}\sum_{i=0}^{N-j}a_{i+j,i}\\
\sum_{j=0}^{N}\sum_{i=0}^{N-j}a_{i+j,i}=\sum_{j=0}^{N}\sum_{i=0}^jb_{N-j-i}\times c_j\ (b_i=a_{N-i},c_i=a_i)\\
\sum_{j=0}^N\sum_{i=0}^jb_{N-j-i}\times c_j=\sum_{j=0}^N\sum_{i=0}^jb_{j-i}\times c_j
$$

### FWT

```c++
// 解决一类集合卷积问题
namespace FWT
{
typedef long long ll;
typedef std::vector<ll> vll;

inline ll fp(ll base, ll expr, ll mod = 1e9 + 7)
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

void fwt_or(int n, vll &x, bool fwt = true)
{
    for (int i = 2; i <= n; i <<= 1)
        for (int p = i >> 1, j = 0; j < n; j += i)
            for (int k = j; k < j + p; ++k)
                x[k + p] += x[k] * (fwt ? 1 : -1);
}

void fwt_and(int n, vll &x, bool fwt = true)
{
    for (int i = 2; i <= n; i <<= 1)
        for (int p = i >> 1, j = 0; j < n; j += i)
            for (int k = j; k < j + p; ++k)
                x[k] += x[k + p] * (fwt ? 1 : -1);
}

void fwt_xor(int n, vll &x, const ll MOD = 1e9 + 7, bool fwt = true)
{
    ll inv2 = fp(2, MOD - 2, MOD);
    for (int i = 2; i <= n; i <<= 1)
        for (int p = i >> 1, j = 0; j < n; j += i)
            for (int k = j; k < j + p; ++k)
            {
                int a = x[k], b = x[k + p];
                x[k] = (a + b) % MOD;
                x[k + p] = (a - b + MOD) % MOD;
                if (!fwt)
                    x[k] = 1LL * x[k] * inv2 % MOD, x[k + p] = 1LL * x[k + p] * inv2 % MOD;
            }
}
} // namespace FWT
```

### 线性基

```c++
// 求子集最大异或和
// 或者每个数按01对齐展开构成的矩阵的秩
struct LB
{
    using ll = long long;
    int MaxL; // 最长位数，如60即最大为2^60

    vector<ll> data;

    LB(int size = 60)
    {
        MaxL = size;
        data.resize(size + 1);
    }

    void insert(ll t)
    {
        for (int j = MaxL; j >= 0; j--)
        {
            if (!(t & (1LL << j)))
                continue;

            if (data[j])
                t ^= data[j];
            else
            {
                for (int k = 0; k < j; k++)
                    if (t & (1LL << k))
                        t ^= data[k];

                for (int k = j + 1; k <= MaxL; k++)
                    if (data[k] & (1LL << j))
                        data[k] ^= t;

                data[j] = t;

                return;
            }
        }
    }

    void merge(const LB &l)
    {
        for (int i = 0; i <= MaxL; i++)
            insert(l.data[i]);
    }

    ll queryMax()
    {
        ll ans = 0;
        for (auto i : data)
            ans ^= i;
        return ans;
    }

    int rank()
    {
        int ans = 0;
        for (auto i : data)
            if (i)
                ans++;
        return ans;
    }
};
```

### 矩阵相关

```c++
// 缺：高斯消元
template <class T>
struct Matrix
{
    int row;
    int col;
    vector<vector<T>> data;

    Matrix(int _row = 0, int _col = 0)
    {
        resize(_row, _col);
    }

    Matrix(vector<vector<T>> d)
    {
        row = d.size();
        col = d[0].size();
        data.resize(row);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                data[i].push_back(d[i][j]);
    }

    void resize(int _row, int _col)
    {
        row = _row;
        col = _col;
        data.resize(row);
        for (auto &i : data)
            i.resize(col);
    }

    T trace()
    {
        if (col != row)
            return -1;
        T ans = 0;
        for (int i = 0; i < row; i++)
            ans += data[i][i];
        return ans;
    }

    vector<T> &operator[](int pos)
    {
        return ref(data[pos]);
    }

    Matrix<T> operator-()
    {
        Matrix t(this->data);
        for (auto &i : t.data)
        {
            for (auto &j : i)
            {
                j = -j;
            }
        }
        return t;
    }

    bool empty()
    {
        return row == 0 || col == 0;
    }
};

template <class T>
Matrix<T> add(Matrix<T> a, Matrix<T> b, T mod = 1e9 + 7)
{
    Matrix<T> temp;

    if (a.row != b.row || a.col != b.col)
        return temp;

    temp.resize(a.row, a.col);

    for (int i = 0; i < temp.row; i++)
    {
        for (int j = 0; j < temp.col; j++)
            temp[i][j] = (a[i][j] + b[i][j]) % mod;
    }
}

template <class T>
Matrix<T> minus(Matrix<T> a, Matrix<T> b, T mod = 1e9 + 7)
{
    return add(a, -b);
}

template <class T>
Matrix<T> mul(Matrix<T> a, Matrix<T> b, T mod = 1e9 + 7)
{
    Matrix<T> temp;

    if (a.col != b.row)
        return temp;

    temp.resize(a.row, b.col);

    for (int i = 0; i < a.row; i++)
    {
        for (int k = 0; k < a.col; k++)
        {
            auto t = a[i][k] % mod;
            for (int j = 0; j < b.col; j++)
                temp[i][j] = (temp[i][j] + t * b[k][j] % mod) % mod;
        }
    }

    return temp;
}

template <class T>
Matrix<T> fp(Matrix<T> base, T expr, T mod = 1e9 + 7)
{
    Matrix<T> ans(base.data), t(base.data);
    expr--;
    while (expr)
    {
        if (expr & 1)
            ans = mul(ans, t, mod);
        t = mul(t, t, mod);
        expr >>= 1;
    }
    return ans;
}
```

### Polya定理

```c++
// 2017 青岛 现场赛 E
// 1x3x3魔方的n着色，对P取模
#include <bits/stdc++.h>

#define ff first
#define ss second
#define y0 wc_y0
#define y1 wc_y1
#define yn wc_yn
#define j0 wc_j0
#define j1 wc_j1
#define jn wc_jn

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;

template <class T>
inline void umin(T &a, T b)
{
    a = min(a, b);
}

template <class T>
inline void umax(T &a, T b)
{
    a = max(a, b);
}

const int INF = 0x3f3f3f3f;
const int N = 100005;

const int c1[] = {6, 3, 0, 7, 4, 1, 8, 5, 2};
void op1(const vector<int> &a, vector<int> &b)
{
    for (int i = 0; i < 9; i++)
    {
        b[i] = a[c1[i]];
        b[i + 9] = a[c1[i] + 9];
    }
    for (int i = 18; i < 30; i++)
    {
        int t = i - 3;
        if (t < 18)
            t += 12;
        b[i] = a[t];
    }
}

void op2(const vector<int> &a, vector<int> &b)
{
    for (int i = 0; i < 30; i++)
    {
        b[i] = a[i];
    }
    b[0] = a[11], b[1] = a[10], b[2] = a[9];
    b[9] = a[2], b[10] = a[1], b[11] = a[0];
    b[18] = a[20], b[20] = a[18];
    b[21] = a[29], b[29] = a[21];
}

const int c2[30] = {11, 10, 9, 14, 13, 12, 17, 16, 15, 2, 1, 0, 5, 4, 3, 8, 7, 9, 20, 19, 18, 29, 28, 27, 26, 25, 24, 23, 22, 21};
void op3(const vector<int> &a, vector<int> &b)
{
    for (int i = 0; i < 30; i++)
    {
        b[i] = a[c2[i]];
    }
}
int d[31], vis[30];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    queue<vector<int>> q;
    set<vector<int>> se;
    vector<int> tmp(30);
    for (int i = 0; i < 30; i++)
        tmp[i] = i;
    q.push(tmp);
    se.insert(tmp);
    int tot = 0;
    while (!q.empty())
    {
        vector<int> now = q.front();
        q.pop();
        tot++;
        op1(now, tmp);
        if (se.find(tmp) == se.end())
        {
            se.insert(tmp);
            q.push(tmp);
        }

        op2(now, tmp);
        if (se.find(tmp) == se.end())
        {
            se.insert(tmp);
            q.push(tmp);
        }

        op3(now, tmp);
        if (se.find(tmp) == se.end())
        {
            se.insert(tmp);
            q.push(tmp);
        }
    }
    cout << tot << endl;

    for (auto &a : se)
    {
        int cnt = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < 30; i++)
        {
            if (vis[i])
                continue;
            cnt++;
            int t = i;
            vis[t] = 1;
            t = a[t];
            while (t != i)
            {
                vis[t] = 1;
                t = a[t];
            }
        }
        d[cnt]++;
    }
    int T;
    cin >> T;
    while (T--)
    {
        int n, p;
        cin >> n >> p;
        __int128 ans = 0, mod = (__int128)p * tot, e = 1;
        for (int i = 1; i <= 30; i++)
        {
            e = e * n % mod;
            ans = (ans + d[i] * e) % mod;
        }
        int wc = ans / tot;
        cout << wc << endl;
    }

    return 0;
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

### 回文树/回文自动机

```c++
const int CHAR_SIZE = 26;
const char CHAR_START = 'a';
const int SIZE = 1e5 + 10; // String size

struct PAM
{
    int node[SIZE][CHAR_SIZE];
    int fail[SIZE];
    int cnt[SIZE]; // distinct palindromes at node i
    int num[SIZE]; // the number of palindroms which end with the end of longest palindrome at node i
    int len[SIZE]; // length of the palindrome at node i
    int s[SIZE];

    int last; // the longest palindrome's node
    int n;    // count of character
    int p;    // count of nodes

    int new_node(int le)
    {
        for (int i = 0; i < CHAR_SIZE; i++)
            node[p][i] = 0;
        cnt[p] = 0;
        num[p] = 0;
        len[p] = le;
        return p++;
    }

    void init()
    {
        p = 0;
        new_node(0);
        new_node(-1);

        last = n = 0;
        s[0] = -1;
        fail[0] = 1;
    }

    int get_fail(int x)
    {
        while (s[n - len[x] - 1] != s[n])
            x = fail[x];
        return x;
    }

    void add(char ch)
    {
        int c = ch - CHAR_START;
        s[++n] = c;
        int cur = get_fail(last);
        if (!node[cur][c])
        {
            int now = new_node(len[cur] + 2);
            fail[now] = node[get_fail(fail[cur])][c];
            node[cur][c] = now;
            num[now] = num[fail[now]] + 1;
        }
        last = node[cur][c];
        cnt[last]++;
    }

    void get_cnt()
    {
        for (int i = p - 1; i >= 0; i--)
            cnt[fail[i]] += cnt[i];
    }

    int get_num() { return num[n]; }
} pam;
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

### Splay树

```c++
// 排序splay树，非区间Splay树
struct Splay
{
    static const int SIZE = 1e5 + 10;
    int rt;          // root
    int tot;         // total nodes
    int fa[SIZE];    // father of node i
    int ch[SIZE][2]; // child of node i, 0 is left
    int val[SIZE];   // value of node i
    int cnt[SIZE];   // Count of the number of val i
    int sz[SIZE];    // size of subtree of node i

    void mt(int x)
    {
        sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + cnt[x];
    }

    bool get(int x)
    {
        return x == ch[fa[x]][1];
    }

    void reset(int x)
    {
        ch[x][0] = ch[x][1] = fa[x] = val[x] = sz[x] = cnt[x] = 0;
    }

    void rotate(int x)
    {
        int y = fa[x], z = fa[y], chk = get(x);

        ch[y][chk] = ch[x][chk ^ 1];
        fa[ch[x][chk ^ 1]] = y;

        ch[x][chk ^ 1] = y;
        fa[y] = x;

        fa[x] = z;
        if (z)
            ch[z][y == ch[z][1]] = x;

        mt(x);
        mt(y);
    }

    void splay(int x)
    {
        for (int f = fa[x]; f = fa[x], f; rotate(x))
            if (fa[f])
                rotate(get(x) == get(f) ? f : x);
        rt = x;
    }

    void insert(int k)
    {
        if (!rt)
        {
            val[++tot] = k;
            cnt[tot]++;
            rt = tot;
            mt(rt);
            return;
        }

        int cur = rt, f = 0;
        while (true)
        {
            if (val[cur] == k)
            {
                cnt[cur]++;
                mt(cur);
                mt(f);
                splay(cur);
                break;
            }
            f = cur;
            cur = ch[cur][val[cur] < k];
            if (!cur)
            {
                val[++tot] = k;
                cnt[tot]++;
                fa[tot] = f;
                ch[f][val[f] < k] = tot;
                mt(tot);
                mt(f);
                splay(tot);
                break;
            }
        }
    }

    void init()
    {
        tot = rt = 0;
    }

    int rk(int k)
    {
        int res = 0, cur = rt;
        while (true)
        {
            if (k < val[cur])
                cur = ch[cur][0];
            else
            {
                res += sz[ch[cur][0]];
                if (k == val[cur])
                {
                    splay(cur);
                    return res + 1;
                }
                res += cnt[cur];
                cur = ch[cur][1];
            }
        }
    }

    int kth(int k)
    {
        int cur = rt;
        while (true)
        {
            if (ch[cur][0] && k <= sz[ch[cur][0]])
                cur = ch[cur][0];
            else
            {
                k -= cnt[cur] + sz[ch[cur][0]];
                if (k <= 0)
                    return val[cur];
                cur = ch[cur][1];
            }
        }
    }

    int pred()
    {
        int cur = ch[rt][0];
        while (ch[cur][1])
            cur = ch[cur][1];
        return cur;
    }

    int succ()
    {
        int cur = ch[rt][1];
        while (ch[cur][0])
            cur = ch[cur][0];
        return cur;
    }

    void erase(int k)
    {
        rk(k);
        if (cnt[rt] > 1)
        {
            cnt[rt]--;
            mt(rt);
            return;
        }
        if (!ch[rt][0] && !ch[rt][1])
        {
            reset(rt);
            rt = 0;
            return;
        }
        if (!ch[rt][0])
        {
            int cur = rt;
            rt = ch[rt][1];
            fa[rt] = 0;
            reset(cur);
            return;
        }
        if (!ch[rt][1])
        {
            int cur = rt;
            rt = ch[rt][0];
            fa[rt] = 0;
            reset(cur);
            return;
        }
        int x = pred(), cur = rt;
        splay(x);
        fa[ch[cur][1]] = x;
        ch[x][1] = ch[cur][1];
        reset(cur);
        mt(rt);
    }

} sp;
```

## 5. 图相关

### 链式前向星

```c++
const int SIZE = 1e5 + 10;

struct Edge
{
    int next, to, w;

    Edge() : next(0), to(0), w(0) {}
};

Edge E[SIZE]; // 无向边size*2
int last[SIZE];
int cnt = 0;

void add_edge(int u, int v, int w = 1)
{
    E[++cnt].next = last[u];
    E[cnt].to = v;
    E[cnt].w = w;
    last[u] = cnt;
}

// 遍历一个节点u的所有边
// for(int i = last[u];i;i=E[i].next)
//     E[i].to
```

### 优先队列优化Dijkstra

```c++
// 无负环单元最短路径最快解决方案

// pbds配顶堆优化，最快
#include <ext/pb_ds/priority_queue.hpp>
using pqii = __gnu_pbds::priority_queue<pii, greater<pii>, __gnu_pbds::pairing_heap_tag>;

// 如果不支持，就用标准库自带
using pqii = priority_queue<pii, deque<pii>, greater<pii>>;

void dijkstra(int n, int s)
{
    pqii pq;
    memset(dis, 0x3f, sizeof(dis));

    dis[s] = 0;
    pq.push(make_pair(0, s));

    while (pq.size())
    {
        auto p = pq.top();
        pq.pop();
        int x = p.second;
        if (dis[x] < p.first)
            continue;
        for (int i = last[x]; i; i = E[i].next)
        {
            if (dis[E[i].to] > dis[x] + E[i].w)
            {
                dis[E[i].to] = dis[x] + E[i].w;
                pq.push(mp(dis[E[i].to], E[i].to));
            }
        }
    }
}
```

### 树链剖分

```c++
const int maxn = 1e5 + 10;

struct edge
{
    int next, to;
} e[2 * maxn];

struct Node
{
    int sum, lazy, l, r, ls, rs;
} node[2 * maxn];

int rt, n, m, r, cnt, a[maxn], head[maxn];
int f[maxn];     //保存结点u的父亲结点
int d[maxn];     //保存节点u的深度值
int sizet[maxn]; //保存以u为根的子树结点个数
int son[maxn];   //保存重儿子
int rk[maxn];    //保存当前dfs标号在树中所对应的节点
int top[maxn];   //保存当前结点所在链的顶端结点
int id[maxn];    //保存树中每个节点剖分以后的新编号（DFS的执行顺序）
int tid[maxn];
void add_edge(int x, int y)
{
    e[++cnt].next = head[x];
    e[cnt].to = y;
    head[x] = cnt;
}

//对于一个点首先找出他所在的子树大小，找到他的重儿子，处理出size和son数组
//在一边dfs过程中顺便记录其父亲以及深度，即f和d数组
//进入：dfs1(root,0,1)
void dfs1(int u, int fa, int depth)
{ //当前结点、父节点、层次深度

    f[u] = fa;
    d[u] = depth;
    sizet[u] = 1; //该点本身size为1
    for (int i = head[u]; i; i = e[i].next)
    {

        int v = e[i].to;
        if (v == fa)
            continue;
        dfs1(v, u, depth + 1); //层次深度+1
        sizet[u] += sizet[v];  //用子节点size更新父节点size
        if (sizet[v] > sizet[son[u]])
        {
            son[u] = v; //选取size最大的作为重儿子
        }
    }
}

//第二遍dfs，然后连接重链，同时标记每一个结点的dfs序
//为了用数据结构维护重链，在dfs时保证一条重链上各个结点的dfs序连续
//即处理出数组top、id、rk
void dfs2(int u, int t)
{ //当前节点、重链顶端
    top[u] = t;
    tid[u] = ++cnt; //标记dfs序
    rk[cnt] = u;    //序号cnt对应结点u
    if (!son[u])
        return;
    dfs2(son[u], t); //选择优先进入重儿子来保证一条重链上各个结点的dfs序连续
    //一个点和他的重儿子处于同一条重链，所以重儿子所在重链的顶端还是t
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v != son[u] && v != f[u])
        {
            dfs2(v, v);
        }
    }
}
void pushup(int x)
{
    node[x].sum = (node[node[x].ls].sum + node[node[x].rs].sum + node[x].lazy * (node[x].r - node[x].l + 1));
}
void build(int li, int ri, int cur)
{
    if (li == ri)
    {
        node[cur].ls = node[cur].rs = -1;
        node[cur].l = node[cur].r = li;
        node[cur].sum = a[rk[li]];
        return;
    }
    int mid = (li + ri) >> 1;
    node[cur].ls = cnt++;
    node[cur].rs = cnt++;
    build(li, mid, node[cur].ls);
    build(mid + 1, ri, node[cur].rs);
    node[cur].l = node[node[cur].ls].l;
    node[cur].r = node[node[cur].rs].r;
    pushup(cur);
}
void update(int li, int ri, int c, int cur)
{
    if (li <= node[cur].l && node[cur].r <= ri)
    {
        node[cur].sum += c * (node[cur].r - node[cur].l + 1);
        node[cur].lazy += c;
        return;
    }
    int mid = (node[cur].l + node[cur].r) >> 1;
    if (li <= mid)
        update(li, ri, c, node[cur].ls);
    if (mid < ri)
        update(li, ri, c, node[cur].rs);
    pushup(cur);
}
int query(int li, int ri, int cur)
{
    if (li <= node[cur].l && node[cur].r <= ri)
        return node[cur].sum;
    int tot = node[cur].lazy * (min(node[cur].r, ri) - max(node[cur].l, li) + 1);
    int mid = (node[cur].l + node[cur].r) >> 1;
    if (li <= mid)
        tot += query(li, ri, node[cur].ls);
    if (mid < ri)
        tot += query(li, ri, node[cur].rs);
    return tot;
}
int sum(int x, int y)
{
    int ans = 0, fx = top[x], fy = top[y];
    while (fx != fy)
    {
        if (d[fx] >= d[fy])
        {
            ans += query(tid[fx], tid[x], rt);
            x = f[fx];
        }
        else
        {
            ans += query(tid[fy], tid[y], rt);
            y = f[fy];
        }
        fx = top[x];
        fy = top[y];
    }
    if (tid[x] <= tid[y])
        ans += query(tid[x], tid[y], rt);
    else
        ans += query(tid[y], tid[x], rt);
    return ans;
}
void updates(int x, int y, int c)
{
    int fx = top[x], fy = top[y];
    while (fx != fy)
    {
        if (d[fx] >= d[fy])
        {
            update(tid[fx], tid[x], c, rt);
            x = f[fx];
        }
        else
        {
            update(tid[fy], tid[y], c, rt);
            y = f[fy];
        }
        fx = top[x];
        fy = top[y];
    }
    if (tid[x] <= tid[y])
        update(tid[x], tid[y], c, rt);
    else
        update(tid[y], tid[x], c, rt);
}

// Pre-Build Function
inline void build()
{
}

// Actual Solver
inline void solve()
{
    int p;
    cin >> n >> m >> r >> p;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        add_edge(x, y);
        add_edge(y, x);
    }
    cnt = 0;
    dfs1(r, 0, 1);
    dfs2(r, r);
    cnt = 0;
    rt = cnt++;
    build(1, n, rt);

    for (int i = 1; i <= m; i++)
    {
        int op, x, y, z;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y >> z;
            updates(x, y, z);
        }
        else if (op == 2)
        {
            cin >> x >> y;
            cout << sum(x, y) % p << endl;
        }
        else if (op == 3)
        {
            cin >> x >> z;
            //子树也有连续区间的性质
            update(tid[x], tid[x] + sizet[x] - 1, z, rt);
        }
        else if (op == 4)
        {
            cin >> x;

            cout << query(tid[x], tid[x] + sizet[x] - 1, rt) % p << endl;
        }
    }
}
```

#### 例：2018 焦作网络赛 E

```c++
const int INF = 0x3f3f3f3f;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef vector<string> cb;
const int SIZE = 1e5 + 10;

struct edge
{
    int next, to;
} e[SIZE << 1];

int rt, n, r, cnt, head[SIZE];
int f[SIZE];
int d[SIZE];
int sizet[SIZE];
int son[SIZE];
int rk[SIZE];
int top[SIZE];
int tid[SIZE];

ull s[SIZE << 2];
ull add[SIZE << 2], mul[SIZE << 2];

void init()
{
    memset(e, 0, sizeof e);
    memset(head, 0, sizeof head);
    memset(f, 0, sizeof f);
    memset(d, 0, sizeof d);
    memset(sizet, 0, sizeof sizet);
    memset(son, 0, sizeof son);
    memset(rk, 0, sizeof rk);
    memset(top, 0, sizeof top);
    memset(tid, 0, sizeof tid);
    memset(s, 0, sizeof s);
    memset(add, 0, sizeof add);
    memset(mul, 0, sizeof mul);
}

void add_edge(int x, int y)
{
    e[++cnt].next = head[x];
    e[cnt].to = y;
    head[x] = cnt;
}

void dfs1(int u, int fa, int depth)
{
    f[u] = fa;
    d[u] = depth;
    sizet[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        dfs1(v, u, depth + 1);
        sizet[u] += sizet[v];
        if (sizet[v] > sizet[son[u]])
        {
            son[u] = v;
        }
    }
}

void dfs2(int u, int t)
{
    top[u] = t;
    tid[u] = ++cnt;
    rk[cnt] = u;
    if (!son[u])
        return;
    dfs2(son[u], t);

    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v != son[u] && v != f[u])
        {
            dfs2(v, v);
        }
    }
}

void pushup(int pos)
{
    s[pos] = s[pos << 1] + s[pos << 1 | 1];
}

void pushdown(int pos, int lt, int rt)
{
    if (mul[pos] != 1)
    {
        mul[pos << 1] = mul[pos << 1] * mul[pos];
        mul[pos << 1 | 1] = mul[pos << 1 | 1] * mul[pos];
        if (add[pos << 1])
            add[pos << 1] = add[pos << 1] * mul[pos];
        if (add[pos << 1 | 1])
            add[pos << 1 | 1] = add[pos << 1 | 1] * mul[pos];

        s[pos << 1] = s[pos << 1] * mul[pos];
        s[pos << 1 | 1] = s[pos << 1 | 1] * mul[pos];

        mul[pos] = 1;
    }
    if (add[pos])
    {
        add[pos << 1] = add[pos << 1] + add[pos];
        add[pos << 1 | 1] = add[pos << 1 | 1] + add[pos];

        s[pos << 1] = s[pos << 1] + lt * add[pos];
        s[pos << 1 | 1] = s[pos << 1 | 1] + rt * add[pos];

        add[pos] = 0;
    }
}

void update(int ul, int ur, int type, ull val, int l, int r, int cur)
{
    if (ul <= l && r <= ur)
    {
        if (type == 2)
        {
            mul[cur] = mul[cur] * val;
            if (add[cur])
                add[cur] = add[cur] * val;
            s[cur] = s[cur] * val;
        }
        else
        {
            add[cur] = add[cur] + val;
            s[cur] = s[cur] + (r - l + 1) * val;
        }
        return;
    }

    int m = ((r - l) >> 1) + l;
    pushdown(cur, m - l + 1, r - m);
    if (ul <= m)
        update(ul, ur, type, val, l, m, cur << 1);
    if (ur > m)
        update(ul, ur, type, val, m + 1, r, cur << 1 | 1);
    pushup(cur);
}

void build(int l, int r, int cur)
{
    add[cur] = 0;
    mul[cur] = 1;
    if (l == r)
    {
        s[cur] = 0;
        return;
    }

    int m = ((r - l) >> 1) + l;
    build(l, m, cur << 1);
    build(m + 1, r, cur << 1 | 1);
    pushup(cur);
}

ull query(int ql, int qr, int l, int r, int cur)
{
    if (ql <= l && r <= qr)
        return s[cur];

    int m = ((r - l) >> 1) + l;
    pushdown(cur, m - l + 1, r - m);
    ull ans = 0;
    if (ql <= m)
        ans = ans + query(ql, qr, l, m, cur << 1);
    if (qr > m)
        ans = ans + query(ql, qr, m + 1, r, cur << 1 | 1);
    return ans;
}

void updateTree(int x, int y, ull val, int type)
{
    int fx = top[x], fy = top[y];
    while (fx != fy)
    {
        if (d[fx] >= d[fy])
        {
            update(tid[fx], tid[x], type, val, 1, n, 1);
            x = f[fx];
        }
        else
        {
            update(tid[fy], tid[y], type, val, 1, n, 1);
            y = f[fy];
        }
        fx = top[x];
        fy = top[y];
    }
    if (tid[x] <= tid[y])
        update(tid[x], tid[y], type, val, 1, n, 1);
    else
        update(tid[y], tid[x], type, val, 1, n, 1);
}

ull sum(int x, int y)
{
    ull ans = 0;
    int fx = top[x], fy = top[y];
    while (fx != fy)
    {
        if (d[fx] >= d[fy])
        {
            ans += query(tid[fx], tid[x], 1, n, 1);
            x = f[fx];
        }
        else
        {
            ans += query(tid[fy], tid[y], 1, n, 1);
            y = f[fy];
        }
        fx = top[x];
        fy = top[y];
    }
    if (tid[x] <= tid[y])
        ans += query(tid[x], tid[y], 1, n, 1);
    else
        ans += query(tid[y], tid[x], 1, n, 1);
    return ans;
}

// Actual Solver
inline void solve()
{
    while (cin >> n)
    {
        init();
        int t, m;
        FOR(i, 1, n)
        {
            cin >> t;
            add_edge(t, i + 1);
            add_edge(i + 1, t);
        }
        cnt = 0;
        dfs1(1, 0, 1);
        dfs2(1, 1);
        cnt = 0;
        rt = cnt++;
        build(1, n, 1);
        cin >> m;
        while (m--)
        {
            int opt, u, v;
            ull z;
            readln(opt, u, v);
            if (opt == 1)
            {
                cin >> z;
                updateTree(u, v, z, 2);
            }
            else if (opt == 2)
            {
                cin >> z;
                updateTree(u, v, z, 1);
            }
            else if (opt == 3)
            {
                updateTree(u, v, -1, 2);
                updateTree(u, v, -1, 1);
            }
            else if (opt == 4)
                cout << sum(u, v) << '\n';
        }
    }
}
```

## 6. 计算几何

用到什么打什么，这板子太长了。

```c++
// Constants
// BE CAREFUL!!!!
// EPS IS THE MOST IMPORTANT VALUE!
const double EPS = 1e-8;
const double PI = acos(-1);
const double FAC = 1e-18;

typedef double db;

int sgn(db x)
{
    if (abs(x) < EPS)
        return 0;
    if (x < 0)
        return -1;
    return 1;
}

inline db Min(db a, db b) { return sgn(a - b) > 0 ? b : a; }
inline db Max(db a, db b) { return sgn(a - b) > 0 ? a : b; }

// Point/Vector
struct Point
{
    db x, y;

    Point() : x(0.0), y(0.0) {}

    Point(db _x, db _y) : x(_x), y(_y) {}

    bool operator==(const Point &p)
    {
        return sgn(x - p.x) == 0 && sgn(y - p.y) == 0;
    }

    bool operator<(const Point &p)
    {
        int c = sgn(x - p.x);
        if (c)
            return c == -1;
        return sgn(y - p.y) == -1;
    }

    Point operator+(const Point &p) { return Point(x + p.x, y + p.y); }
    Point operator-(const Point &p) { return Point(x - p.x, y - p.y); }
    Point operator*(db d) { return Point(x * d, y * d); }
    Point operator/(db d) { return Point(x / d, y / d); }

    db operator^(const Point &p) { return x * p.y - y * p.x; }
    db operator*(const Point &p) { return x * p.x + y * p.y; }

    db dis(const Point &p) { return (*this - p).len(); }
    db alpha() { return atan2(y, x); }

    Point unit() { return *this / len(); }
    Point scale(db r) { return unit() * r; }

    Point rotCC() { return Point(-y, x); }
    Point rotCL() { return Point(y, -x); }

    Point rot(Point p, db angle)
    {
        Point v = *this - p;
        db c = cos(angle), s = sin(angle);
        return Point(p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c);
    }

    db len() { return hypot(x, y); }
    db len2() { return x * x + y * y; }

    db rad(Point a, Point b)
    {
        Point ap = a - *this, bp = b - *this;
        return abs(atan2(abs(ap ^ bp), ap * bp));
    }

    // Point P,A,B
    // -2 -> B is at back of PA
    // -1 -> PB is on the clock-wise side of PA
    // 0 -> B is on PA
    // 1 -> PB is on the counter clock-wise side of PA
    // 2 -> B is at the front of PA
    int relation(Point a, Point b)
    {
        Point p = *this;
        if (sgn((a - p) ^ (b - p)) > 0)
            return 1;
        if (sgn((a - p) ^ (b - p)) < 0)
            return -1;
        if (sgn((a - p) * (b - p)) < 0)
            return -2;
        if (sgn((p - a) * (b - a)) < 0)
            return 2;
        return 0;
    }

    void read() { cin >> x >> y; }
    void write(char trail = ' ') { cout << x << ' ' << y << trail; }
    void Debug() { cerr << "Point: (" << x << ", " << y << ")\n"; }
};

db cross(Point a, Point b, Point c) { return (b - a) ^ (c - a); }

// Line
struct Line
{
    Point s, e;

    Line(){};

    Line(Point _s, Point _e) : s(_s), e(_e) {}

    Line(Point p, db angle)
    {
        s = p;
        if (sgn(angle - PI / 2))
            e = (s + Point(1, tan(angle)));
        else
            e = (s + Point(0, 1));
    }

    //ax+by+c=0
    Line(db a, db b, db c)
    {
        if (sgn(a) == 0)
        {
            s = Point(0, -c / b);
            e = Point(1, -c / b);
        }
        else if (sgn(b) == 0)
        {
            s = Point(-c / a, 0);
            e = Point(-c / a, 1);
        }
        else
        {
            s = Point(0, -c / b);
            e = Point(1, -(c + a) / b);
        }
    }

    db len() { return s.dis(e); }
    db angle()
    {
        db ans = atan2(e.y - s.y, e.x - s.x);
        if (sgn(ans) == -1)
            ans += PI;
        if (sgn(ans - PI) == 0)
            ans -= PI;
        return ans;
    }

    int relation(Point p) { return s.relation(e, p); }

    bool parallel(Line l) { return sgn((e - s) ^ (l.e - l.s)) == 0; }

    // 0 -> Not Intersect
    // 1 -> Informal
    // 2 -> Formal Intersection
    int crossSS(Line l)
    {
        int d1 = sgn((e - s) ^ (l.s - s));
        int d2 = sgn((e - s) ^ (l.e - s));
        int d3 = sgn((l.e - l.s) ^ (s - l.s));
        int d4 = sgn((l.e - l.s) ^ (e - l.s));
        if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2)
            return 2;
        return (d1 == 0 && sgn((l.s - s) * (l.s - e)) <= 0) ||
               (d2 == 0 && sgn((l.e - s) * (l.e - e)) <= 0) ||
               (d3 == 0 && sgn((s - l.s) * (s - l.e)) <= 0) ||
               (d4 == 0 && sgn((e - l.s) * (e - l.e)) <= 0);
    }

    // 0 -> Not Intersect
    // 1 -> Informal
    // 2 -> Formal Intersection
    int crossLS(Line l)
    {
        int d1 = sgn((e - s) ^ (l.s - s));
        int d2 = sgn((e - s) ^ (l.e - s));
        if ((d1 ^ d2) == -2)
            return 2;
        return (d1 == 0 || d2 == 0);
    }

    // 0 -> Parallel
    // 1 -> Same
    // 2 -> Intersect
    int crossLL(Line l)
    {
        if (this->parallel(l))
            return l.relation(s) == 3;
        return 2;
    }

    Point intersec(Line l)
    {
        db a1 = (l.e - l.s) ^ (s - l.s);
        db a2 = (l.e - l.s) ^ (e - l.s);
        return Point((s.x * a2 - e.x * a1) / (a2 - a1), (s.y * a2 - e.y * a1) / (a2 - a1));
    }

    db disPL(Point p) { return abs((p - s) ^ (e - s)) / len(); }
    db disPS(Point p)
    {
        if (sgn((p - s) * (e - s)) < 0 || sgn((p - e) * (s - e)) < 0)
            return min(p.dis(s), p.dis(e));
        return disPL(p);
    }
    db disSS(Line l) { return min(min(disPS(l.s), disPS(l.e)), min(l.disPS(s), l.disPS(e))); }

    Point proj(Point p) { return s + ((e - s) * ((e - s) * (p - s))) / ((e - s).len2()); }
    Point refl(Point p)
    {
        Point q = proj(p);
        return Point(2 * q.x - p.x, 2 * q.y - p.y);
    }

    bool operator==(Line l) { return s == l.s && e == l.e; }

    void adjust()
    {
        if (e < s)
            swap(s, e);
    }

    void read()
    {
        s.read();
        e.read();
    }

    void Debug() { cerr << "Line: Start: (" << s.x << ", " << s.y << ") End: (" << e.x << ", " << e.y << ")\n"; }
};

// Circle
struct Circle
{
    Point p;
    db r;

    Circle(){};

    Circle(Point _p, db _r) : p(_p), r(_r) {}

    Circle(db x, db y, db _r) : p({x, y}), r(_r) {}

    Circle(Point a, Point b, Point c, bool in = false)
    {
        if (!in)
        {
            Line u = Line((a + b) / 2, (a + b) / 2 + (b - a).rotCC());
            Line v = Line((b + c) / 2, (b + c) / 2 + (c - b).rotCC());
            p = u.intersec(v);
            r = p.dis(a);
        }
        else
        {
            Line u, v;
            db m = atan2(b.y - a.y, b.x - a.x), n = atan2(c.y - a.y, c.x - a.x);
            u.s = a;
            u.e = a + Point(cos((n + m) / 2), sin((n + m) / 2));
            v.s = b;
            m = atan2(a.y - b.y, a.x - b.x), n = atan2(c.y - b.y, c.x - b.x);
            v.e = b + Point(cos((n + m) / 2), sin((n + m) / 2));
            p = u.intersec(v);
            r = Line(a, b).disPS(p);
        }
    }

    bool operator==(const Circle &c) { return p == c.p && sgn(r - c.r) == 0; }

    bool operator<(const Circle &c) { return (p < c.p) || (p == c.p && sgn(r - c.r) < 0); }

    db area() { return PI * r * r; }

    db cir() { return 2 * PI * r; }

    Point on(db ang) { return Point(p.x + r * cos(ang), p.y + r * sin(ang)); }

    // 0 -> Outside
    // 1 -> On
    // 2 -> Inside
    int relationP(Point v)
    {
        db dis = v.dis(p);
        if (sgn(dis - r) < 0)
            return 2;
        else if (sgn(dis - r) == 0)
            return 1;
        return 0;
    }

    // The number of intersections
    int relationS(Line l)
    {
        db dis = l.disPS(p);
        if (sgn(dis - r) < 0)
            return 2;
        else if (sgn(dis - r) == 0)
            return 1;
        return 0;
    }

    // The number of intersections
    int relationL(Line l)
    {
        db dis = l.disPL(p);
        if (sgn(dis - r) < 0)
            return 2;
        else if (sgn(dis - r) == 0)
            return 1;
        return 0;
    }

    // 1 -> Inside
    // 2 -> Internally-tangent
    // 3 -> Intersect
    // 4 -> Externally-tangent
    // 5 -> Disjoint
    int relationC(Circle c)
    {
        db d = p.dis(c.p);
        if (sgn(d - r - c.r) > 0)
            return 5;
        if (sgn(d - r - c.r) == 0)
            return 4;
        db l = abs(r - c.r);
        if (sgn(d - r - c.r) < 0 && sgn(d - l) > 0)
            return 3;
        if (sgn(d - l) == 0)
            return 2;
        // TODO: Check if this one is necessary
        // if (sgn(d - l) < 0)
        return 1;
    }

    // The return value is the number of intersections
    int crossC(Circle c, Point &p1, Point &p2)
    {
        int re = relationC(c);
        if (re == 1 || re == 5)
            return 0;
        db d = p.dis(c.p), l = (d * d + r * r - c.r * c.r) / (2.0 * d), h = sqrt(r * r - l * l);
        Point tmp = p + (c.p - p).scale(l);
        p1 = tmp + (c.p - p).rotCC().scale(h);
        p2 = tmp + (c.p - p).rotCL().scale(h);
        if (re == 2 || re == 4)
            return 1;
        return 2;
    }

    // Same as above
    int crossL(Line l, Point &p1, Point &p2)
    {
        if (!this->relationL(l))
            return 0;
        Point a = l.proj(p);
        db d = l.disPL(p);
        d = sqrt(r * r - d * d);
        if (sgn(d) == 0)
        {
            p1 = a;
            p2 = a;
            return 1;
        }
        p1 = a + (l.e - l.s).scale(d);
        p2 = a - (l.e - l.s).scale(d);
        return 2;
    }

    int tangent(Point q, Point &u, Point &v)
    {
        int x = relationP(q);
        if (x == 2)
            return 0;
        if (x == 1)
        {
            u = q + (q - p).rotCC();
            v = u;
            return 1;
        }
        db d = p.dis(q);
        db l = r * r / d;
        db h = sqrt(r * r - l * l);
        u = p + ((q - p).scale(l) + (q - p).rotCC().scale(h));
        v = p + ((q - p).scale(l) + (q - p).rotCL().scale(h));
        return 2;
    }

    int tangent(Circle c, vector<Point> &u, vector<Point> &v)
    {
        if (sgn(r - c.r) < 0)
            return c.tangent(*this, v, u);

        int ret = relationC(c) - 1;
        if (!ret || *this == c)
            return 0;
        u.clear();
        v.clear();

        db b = (c.p - p).alpha();

        if (ret == 1 || ret == 3)
        {
            u.push_back(on(b));
            v.push_back(on(b));
        }

        db ang = acos((r - c.r) / p.dis(c.p));

        if (ret != 1)
        {
            u.push_back(on(b + ang));
            u.push_back(on(b - ang));
            v.push_back(c.on(b + ang));
            v.push_back(c.on(b - ang));
        }

        if (ret == 4)
        {
            ang = acos((r + c.r) / p.dis(c.p));
            u.push_back(on(b + ang));
            u.push_back(on(b - ang));
            v.push_back(c.on(PI + b + ang));
            v.push_back(c.on(PI + b - ang));
        }

        return ret;
    }

    // The area of intersecting space
    // With circle c
    db area(Circle c)
    {
        int re = relationC(c);
        if (re >= 4)
            return 0;
        if (re <= 2)
            return min(area(), c.area());
        db d = p.dis(c.p);
        db hf = (r + c.r + d) / 2.0;
        db ss = 2 * sqrt(hf * (hf - r) * (hf - c.r) * (hf - d));
        db a1 = acos((r * r + d * d - c.r * c.r) / (2.0 * r * d));
        a1 = a1 * r * r;
        db a2 = acos((c.r * c.r + d * d - r * r) / (2.0 * c.r * d));
        a2 = a2 * c.r * c.r;
        return a1 + a2 - ss;
    }

    // The area of intersecting space
    // With triangle PAB
    db area(Point a, Point b)
    {
        if (sgn((p - a) ^ (p - b)) == 0)
            return 0.0;
        Point q[5];
        int len = 0;
        q[len++] = a;
        Line l(a, b);
        Point p1, p2;
        if (crossL(l, q[1], q[2]) == 2)
        {
            if (sgn((a - q[1]) * (b - q[1])) < 0)
                q[len++] = q[1];
            if (sgn((a - q[2]) * (b - q[2])) < 0)
                q[len++] = q[2];
        }
        q[len++] = b;
        if (len == 4 && sgn((q[0] - q[1]) * (q[2] - q[1])) > 0)
            swap(q[1], q[2]);
        db res = 0;
        for (int i = 0; i < len - 1; i++)
        {
            if (relationP(q[i]) == 0 || relationP(q[i + 1]) == 0)
            {
                db arg = p.rad(q[i], q[i + 1]);
                res += r * r * arg / 2.0;
            }
            else
                res += abs((q[i] - p) ^ (q[i + 1] - p)) / 2.0;
        }
        return res;
    }

    // Two circle whose center are a and b respectivelly
    static int GetCircle(Point a, Point b, db r, Circle &c1, Circle &c2)
    {
        Circle x(a, r), y(b, r);
        int t = x.crossC(y, c1.p, c2.p);
        if (!t)
            return 0;
        c1.r = c2.r = r;
        return t;
    }

    // The circle which tangent is l and point p on it
    static int GetCircle(Line l, Point p, db r, Circle &c1, Circle &c2)
    {
        db dis = l.disPL(p);
        if (sgn(dis - r * 2) > 0)
            return 0;
        if (sgn(dis) == 0)
        {
            c1.p = p + ((l.e - l.s).rotCC().scale(r));
            c2.p = p + ((l.e - l.s).rotCL().scale(r));
            c1.r = c2.r = r;
            return 2;
        }
        Line u1 = Line((l.s + (l.e - l.s).rotCC().scale(r)), (l.e + (l.e - l.s).rotCC().scale(r)));
        Line u2 = Line((l.s + (l.e - l.s).rotCL().scale(r)), (l.e + (l.e - l.s).rotCL().scale(r)));
        Circle cc(p, r);
        Point p1, p2;
        if (!cc.crossL(u1, p1, p2))
            cc.crossL(u2, p1, p2);
        c1 = Circle(p1, r);
        if (p1 == p2)
        {
            c2 = c1;
            return 1;
        }
        c2 = Circle(p2, r);
        return 2;
    }

    // u and v are the common tangent of the four circles
    static int GetCircle(Line u, Line v, db r, Circle &c1, Circle &c2, Circle &c3, Circle &c4)
    {
        if (u.parallel(v))
            return 0;
        Line u1 = Line(u.s + (u.e - u.s).rotCC().scale(r), u.e + (u.e - u.s).rotCC().scale(r));
        Line u2 = Line(u.s + (u.e - u.s).rotCL().scale(r), u.e + (u.e - u.s).rotCL().scale(r));
        Line v1 = Line(v.s + (v.e - v.s).rotCC().scale(r), v.e + (v.e - v.s).rotCC().scale(r));
        Line v2 = Line(v.s + (v.e - v.s).rotCL().scale(r), v.e + (v.e - v.s).rotCL().scale(r));
        c1.r = c2.r = c3.r = c4.r = r;
        c1.p = u1.intersec(v1);
        c2.p = u1.intersec(v2);
        c3.p = u2.intersec(v1);
        c4.p = u2.intersec(v2);
        return 4;
    }

    // Tangent with circle cx and cy
    static int GetCircle(Circle cx, Circle cy, db r, Circle &c1, Circle &c2)
    {
        Circle x(cx.p, r + cx.r), y(cy.p, r + cy.r);
        int t = x.crossC(y, c1.p, c2.p);
        if (!t)
            return 0;
        c1.r = c2.r = r;
        return t;
    }

    void read()
    {
        p.read();
        cin >> r;
    }

    void Debug() { cerr << "Circle: Center: (" << p.x << ", " << p.y << ") Radius: " << r << '\n'; }
};

// Polygon
struct Polygon
{
    // Functor for sorting by polar angle
    struct cmp
    {
        Point p;
        cmp(const Point &b) { p = b; }
        bool operator()(const Point &a, const Point &b)
        {
            Point x = a, y = b;
            int d = sgn((x - p) ^ (y - p));
            if (!d)
                return sgn(x.dis(p) - y.dis(p)) > 0;
            return d > 0;
        }
    };

    vector<Point> ps;
    vector<Line> ls;

    Polygon() {}

    void add(Point p) { ps.push_back(p); }

    int size() { return static_cast<int>(ps.size()); }

    void getLines()
    {
        int s = size();
        for (int i = 0; i < s; i++)
            ls.push_back(Line(ps[i], ps[(i + 1) % s]));
    }

    void norm()
    {
        Point p = ps[0];
        for (int i = 1; i < size(); i++)
        {
            if (p < ps[i])
                continue;
            p = ps[i];
        }
        sort(ps.begin(), ps.end(), cmp(p));
    }

    void getConvexJarvis(Polygon &conv)
    {
        sort(ps.begin(), ps.end());
        conv.ps.resize(2 * size());

        int n = size();
        for (int i = 0; i < min(2, n); i++)
            conv.ps[i] = ps[i];
        if (conv.size() == 2 && (conv.ps[0] == conv.ps[1]))
            conv.ps.resize(1);

        if (n <= 2)
            return;

        int top = 1;

        for (int i = 2; i < n; i++)
        {
            while (top && sgn((conv.ps[top] - ps[i]) ^ (conv.ps[top - 1] - ps[i])) <= 0)
                top--;
            conv.ps[++top] = ps[i];
        }

        int t = top;
        conv.ps[++top] = ps[n - 2];

        for (int i = n - 3; i >= 0; i--)
        {
            while (top != t && sgn((conv.ps[top] - ps[i]) ^ (conv.ps[top - 1] - ps[i])) <= 0)
                top--;
            conv.ps[++top] = ps[i];
        }

        while (conv.size() > top)
            conv.ps.pop_back();

        if (top == 2 && (conv.ps[0] == conv.ps[1]))
            conv.ps.pop_back();

        conv.norm(); // Counter Clock-wise
    }

    void getConvexWithPointOnLine(Polygon &conv)
    {
        int m, n = size();
        if (n < 3)
        {
            for (auto i : ps)
                conv.add(i);
            return;
        }

        vector<Point> &g = conv.ps;

        sort(ps.begin(), ps.end());
        for (int i = 0; i < n; i++)
        {
            while ((m = g.size()) >= 2 && g[m - 2].relation(g[m - 1], ps[i]) <= 0)
                g.pop_back();
            g.push_back(ps[i]);
        }

        int t = g.size();

        for (int i = n - 2; i >= 0; i--)
        {
            while ((m = g.size()) > t && g[m - 2].relation(g[m - 1], ps[i]) <= 0)
                g.pop_back();
            g.push_back(ps[i]);
        }

        g.pop_back();
    }

    // Cannot get the point on the edge
    void getConvexGraham(Polygon &conv)
    {
        norm();
        int top = 0, n = size();
        if (n == 1)
        {
            conv.add(ps[0]);
            return;
        }

        if (n == 2)
        {
            conv.add(ps[0]);
            conv.add(ps[1]);
            if (conv.ps[0] == conv.ps[1])
                conv.ps.pop_back();
            return;
        }

        conv.ps.resize(size());
        conv.ps[0] = ps[0];
        conv.ps[1] = ps[1];
        top = 2;
        for (int i = 2; i < n; i++)
        {
            while (top > 1 && sgn((conv.ps[top - 1] - conv.ps[top - 2]) ^ (ps[i] - conv.ps[top - 2])) <= 0)
                top--;
            conv.ps[top++] = ps[i];
        }

        while (conv.size() > top)
            conv.ps.pop_back();

        if (top == 2 && (conv.ps[0] == conv.ps[1]))
            conv.ps.pop_back();
    }

    bool isConvex()
    {
        bitset<3> s;
        int n = size();
        for (int i = 0; i < n; i++)
        {
            int j = (i + 1) % n;
            int k = (j + 1) % n;
            s.set(sgn((ps[j] - ps[i]) ^ (ps[k] - ps[i])) + 1);
            if (s[0] && s[2])
                return false;
        }
        return true;
    }

    db diameter()
    {
        int q = 1, n = size();
        db ans = 0;
        ps.push_back(ps[0]);
        for (int i = 0; i < n; i++)
        {
            while (sgn(cross(ps[i + 1], ps[q + 1], ps[i]) - cross(ps[i + 1], ps[q], ps[i])) > 0)
                q = (q + 1) % n;
            ans = Max(ans, Max(ps[i].dis(ps[q]), ps[i + 1].dis(ps[q + 1])));
        }
        ps.pop_back();
        return ans;
    }

    // 3 -> On Corner
    // 2 -> On Edge
    // 1 -> Inside
    // 0 -> Outside
    int relationP(Point q)
    {
        int n = size();
        for (int i = 0; i < n; i++)
            if (ps[i] == q)
                return 3;
        getLines();
        for (int i = 0; i < n; i++)
            if (!ls[i].relation(q))
                return 2;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int j = (i + 1) % n;
            int k = sgn((q - ps[j]) ^ (ps[i] - ps[j]));
            int u = sgn(ps[i].y - q.y);
            int v = sgn(ps[j].y - q.y);
            if (k > 0 && u < 0 && v >= 0)
                cnt++;
            if (k < 0 && v < 0 && u >= 0)
                cnt--;
        }
        return cnt != 0;
    }

    void convexCut(Line l, Polygon &po)
    {
        for (int i = 0; i < size(); i++)
        {
            int d1 = sgn((l.e - l.s) ^ (ps[i] - l.s));
            int d2 = sgn((l.e - l.s) ^ (ps[(i + 1) % size()] - l.s));
            if (d1 >= 0)
                po.add(ps[i]);
            if (d1 * d2 < 0)
                po.add(l.intersec(Line(ps[i], ps[(i + 1) % size()])));
        }
    }

    db cir()
    {
        int n = size();
        db sum = 0;
        for (int i = 0; i < n; i++)
            sum += ps[i].dis(ps[(i + 1) % n]);
        return sum;
    }

    db area()
    {
        int n = size();
        db sum = 0;
        for (int i = 0; i < n; i++)
            sum += (ps[i] ^ ps[(i + 1) % n]);
        return abs(sum) / 2;
    }

    // 0 -> Clock-wise
    // 1 -> Counter Clock-wise
    bool dir()
    {
        int n = size();
        db sum = 0;
        for (int i = 0; i < n; i++)
            sum += (ps[i] ^ ps[(i + 1) % n]);
        return sgn(sum) > 0;
    }

    Point baryCenter()
    {
        Point ret;
        db area = 0;
        for (int i = 1; i < size() - 1; i++)
        {
            db tmp = (ps[i] - ps[0]) ^ (ps[i + 1] - ps[0]);
            if (sgn(tmp) == 0)
                continue;
            area += tmp;
            ret.x += (ps[0].x + ps[i].x + ps[i + 1].x) / 3 * tmp;
            ret.y += (ps[0].y + ps[i].y + ps[i + 1].y) / 3 * tmp;
        }
        if (sgn(area))
            ret = ret / area;
        return ret;
    }

    db area(Circle c)
    {
        double ans = 0;
        for (int i = 0; i < size(); i++)
        {
            int j = (i + 1) % size();
            if (sgn((ps[j] - c.p) ^ (ps[i] - c.p)) >= 0)
                ans += c.area(ps[i], ps[j]);
            else
                ans -= c.area(ps[i], ps[j]);
        }
        return abs(ans);
    }

    // 2 -> The circle is entirely in the polygon
    // 1 -> The circle in in the circle and intersected with the boundary
    // 0 -> Otherwise
    int relationC(Circle c)
    {
        getLines();
        int x = 2;
        if (relationP(c.p) != 1)
            return 0;
        for (int i = 0; i < size(); i++)
        {
            if (c.relationS(ls[i]) == 2)
                return 0;
            if (c.relationS(ls[i]) == 1)
                x = 1;
        }
        return x;
    }

    void read(int s)
    {
        for (int i = 0; i < s; i++)
        {
            Point p;
            p.read();
            ps.push_back(p);
        }
    }

    void Debug()
    {
        cerr << "Polygon:\nPoints:\n";
        for (auto i : ps)
            i.Debug();
        cerr << "Lines:\n";
        for (auto i : ls)
            i.Debug();
    }
};

// Other
struct Simpson
{
    typedef double db;

    // If supports C++11
    function<db(db)> f = [](db x) -> db {
        db t = sin(x);
        return 1.0 / (sqrt(t * t + 3) - t);
    };

    // Otherwise
    //db f(db x) { return x * x; }

    db simpson(db L, db R)
    {
        db m = (L + R) / 2.0;
        return (f(L) + 4.0 * f(m) + f(R)) * (R - L) / 6.0;
    }

    db go(db L, db R, db EPS)
    {
        db m = (L + R) / 2.0;
        db sl = simpson(L, m), sr = simpson(m, R), st = simpson(L, R);
        if (abs(sl + sr - st) <= 15.0 * EPS)
            return sl + sr + (sl + sr - st) / 15.0;
        return go(L, m, EPS / 2.0) + go(m, R, EPS / 2.0);
    }
} sim;
```

