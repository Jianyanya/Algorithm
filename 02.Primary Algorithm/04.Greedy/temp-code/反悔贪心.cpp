//https://www.luogu.com.cn/problem/P16279
/*
反悔贪心
选个位数的时候,该数相邻前面必须选出一个十位数,且我们要使十位数尽可能大,个位数尽可能小
我们遍历一遍,用sum记录每个数字,默认为十位,然后把这些十位放进一个大根堆中进行维护
十位数的数量不能大于个位数的数量,每个位置的个位数数量为i/2,我们要把堆里面大的十位数进行删除pop,留下堆低小的个位数
最后堆中都是个位数,累加计算
先加入,不符合后删除,反悔贪心
*/
#include <bits/stdc++.h>
using namespace std;
#define fo(i,l,r) for(int i=(l);i<=(r);++i)
#define ve vector
#define endl '\n'
using ll = long long;
using ull = unsigned long long;
using sr = string;
using db = double;
using dll = double long;
const int MOD=998244353;
const ll INF=1e18;
const int DIR[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int T;
void jianyanya(){
    int n;cin>>n;
    sr str;cin>>str;
    priority_queue<int,ve<int> > pq;
    ll sum = 0;
    for(int i = 0;i<n;i++){
        int q = str[i] - '0';
        sum += q;
        pq.push(q);
        while(pq.size()>(i+1)/2) pq.pop();
    }
    //cout<<endl;
    ll l = 0;
    while(pq.size()){
        int t = pq.top();pq.pop();
        l += t;
    }
    //cout<<sum<<" "<<l<<endl;
    ll ans = 10*sum - 9*l;
    cout<<ans<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) jianyanya();
}