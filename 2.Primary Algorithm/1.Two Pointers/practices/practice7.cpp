//cf,题目链接<https://codeforces.com/problemset/problem/2000/D>
/*
关键词：贪心 双指针
问题分析：
题目给出两个数组,两个关联数组,一个代表数组对应的值,一个只有字符l,r两个字符组成的数组,我们要选择l和r得到数值a[l]+a[l+1]...a[r-1]+a[r]的总和
要求这个数值最大,而且每次选完后,都会把从l到r中的所有字符都改成*,就是说不能再选择了

核心思路:
我们先直接看,我们要尽量的去重复使用数值,而我们看,最保底的情况就是找到数组的最左和最右直接进行总和,而且进行之后就不能再进行了
所以我们一定要利用之间的数进行累加,例如
{1,2,3,4,5,6}
{l,l,l,r,r,r}
我们如果直接选择1和6,则只能得到21,但是我们从中间开始,可以得到3+4+2+3+4+5+1+2+3+4+5+6 = 41,这是最大值,所以问题就解决了
*/
#include <bits/stdc++.h>
using namespace std;
#define ve vector
using ll = long long;
using ull = unsigned long long;
using sr = string;
using db = double;
const int MOD=998244353;
const ll INF=1e18;
const int DIR[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int T;
void solve(){
    int n;cin>>n;
    ve<ll> arr(n),pre(n+1);
    ve<char> lr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        pre[i+1] = pre[i] + arr[i];
    }
    for(int i = 0;i<n;i++) cin>>lr[i];
    int left = 0,right = n-1;
    ll sum = 0;
    while(left<right){
        if(lr[left]=='L'&&lr[right]=='R'){
             sum += pre[right+1] - pre[left];
             left++;
             right--;
        }
        if(lr[left]!='L') left++;
        if(lr[right]!='R') right--;
    }
    cout<<sum<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}