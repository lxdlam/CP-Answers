#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    set<int> a,b,res;
    int n,m,t;
    bool first;
    set<int>::iterator it;
    while(cin>>n>>m){
        first=false;
        a.clear();
        b.clear();
        res.clear();
        while(n--){
            cin>>t;
            a.insert(t);
        }
        while(m--){
cin>>t;
b.insert(t);
        }
        set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(res,res.begin()));
        it = res.begin();
        for(;it!=res.end();it++){
            if(!first)
            cout<<*it;
            else
            cout<<" "<<*it;
            first=true;
        }
        cout<<endl;
    }

    return 0;
}