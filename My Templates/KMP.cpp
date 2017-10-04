#include <bits/stdc++.h>

using namespace std;

// j holds the last state
// First, if now s[i] does not match s[j]
// we reset the state to next[0], i.e., -1
// we can call it initial state
// Second, if s[i] matches s[j]
// it means that current state is j+1
// now j holds that state, and for next
// character, if also matches, for now we
// know last state, we can use such info
// so the current state is last state plus 1
// i.e. j+1+1, otherwise, reset the state to
// initial state.
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

// the match progress is pretty easy now
// we got the next array, think such a case:
// a b a b a c a
// a b a c a
// a b a mathces, but c does not match b
// now, we get the info that next[3] = 2
// so we just forward the pointer j 2 units
// now we got such patterns
// a b a b a c a
//     a b a c a
// mathces!
int match(const string &t, const string &p)
{
    //change size here
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
            j = next[j]; // important, start new match process
        }
    }
    return count;
}