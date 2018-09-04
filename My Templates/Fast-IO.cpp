#include <bits/stdc++.h>

using namespace std;

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