#include <iostream>

using namespace std;

long long p, q, k;
#define MOD 1000000007
typedef long long LL;
typedef double DB;


LL e_gcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    LL ans=e_gcd(b,a%b,x,y);
    LL temp=x;
    x=y;
    y=temp-a/b*y;
    return ans;
}

LL cal(LL a,LL b,LL c)
{
    LL x,y;
    LL gcd=e_gcd(a,b,x,y);
    if(c%gcd!=0) return -1;
    x*=c/gcd;
    b/=gcd;
    if(b<0) b=-b;
    LL ans=x%b;
    if(ans<=0) ans+=b;
    return ans;
}

long long pow(long long n,long long k)
{
    long long ans=1;
    while(k)
    {
        if(k&1)
        {
            ans=((ans%MOD)*(n%MOD))%MOD;
        }
        n=((n%MOD)*(n%MOD))%MOD;
        k>>=1;
    }
    return ans;
}


void solve()
{
    cin>>p>>q>>k;
    long long ans =500000004;
    long long ans_1 = pow(p-2*q,k);
    long long ans_2 = pow(p,k);
    ans_1 += ans_2;
    ans_2 *= 2;
    ans_2 = cal(ans_2, MOD, 1);
    ans = ans_1*ans_2 % MOD;
    cout<<ans<<endl;
}

int main()
{
    int T;
    cin>>T;
    while(T--)  solve();
    return 0;
}