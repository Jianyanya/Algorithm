#include <bits/stdc++.h>
using namespace std;
#define ve vector
using ll = long long;
using ull = unsigned long long;
using sr = string;
using db = double;
int T;
/*
这个题看懂很简单
以每个数为根节点(最右端最大点),找到能覆盖的范围(即最大区间)
找到每个最大区间后,再进行区间合并,如果有不能合并的区间,则输出No,相反则输出yes
*/
void solve(){
    int n;cin>>n;
    ve<int> arr(n+1),pos(n+1),lazy,mx(n+1);
    set<int> st;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        st.insert(arr[i]);
        pos[arr[i]] = i;
    }
    //找到最大区间,mx为最大端点
    for(int i = n-1;i>=0;i--){
        for(int x:st){
            if(x>arr[i]) break;;
            lazy.push_back(x);
            mx[pos[x]] = i;
        }
        for(int x:lazy) st.erase(x);
        lazy.clear();
    }
    ve<pair<int,int> > seg;
    //分配最小端点,跟上面的pos的位置是一样的,只是构造为pair对而已
    for(int i = 0;i<n;i++) seg.emplace_back(i,mx[i]);
    //对其进行排序,小的在左边,使区间有序
    sort(seg.begin(),seg.end());
    int right = seg[0].second;
    for(int i = 1;i<n;i++){
        auto [l,r] = seg[i];
        if(right<l){
            cout<<"No"<<endl;
            return;
        }
        right = max(right,r);
    }
    cout<<"Yes"<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}