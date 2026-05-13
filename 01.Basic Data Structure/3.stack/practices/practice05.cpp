//https://ac.nowcoder.com/acm/contest/130222/F
//经典的单调栈使用
/*
此题目就是统计 连续子段长度等于子段内最大元素的数量
用暴力的眼光来看,对每个位置进行讨论,以该位置的值作为最大值,然后从该位置往左右找,找左边小于该值的数,右边小于该值的数,遇到大的就停下
找到后直接加起来,由于该序列是排列,故符合条件的子段唯一,这里看出,就是找到该元素的左边和右边第一个大于该元素的位置
这个问题就用单调栈来解决
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
void solve(){
    int n;cin>>n;
    ve<ll> arr(n+1),pre(n+1),suf(n+1);
    fo(i,1,n) cin>>arr[i];
    stack<ll> st;
    fo(i,1,n){
        while(!st.empty()&&arr[st.top()]<arr[i]) st.pop();
        pre[i] = st.empty()?0:st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i = n;i>0;i--){
        while(!st.empty()&&arr[st.top()]<arr[i]) st.pop();
        suf[i] = st.empty()?n+1:st.top();
        st.push(i);
    }
    ll ans = 0;
    fo(i,1,n){
        if(suf[i] - pre[i] - 1 == arr[i]) ans++;
    }
    cout<<ans<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}