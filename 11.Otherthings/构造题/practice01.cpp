//https://codeforces.com/contest/2226/problem/D
/*
这个题目的主要思路是:
奇数和偶数之间可以随意翻转,但是同奇偶的数不能直接进行翻转,于是这个题就变成讨论同奇偶的逆序对数是否能改变相对顺序
为什么相邻,因为对偶数对是依靠另一个奇数进行多次翻转操作,相互可以任意交换
于是把数组分为奇偶两个数组,因为要满足最大和最小,同时奇偶搭配,所以记录偶数和奇数的最大值和最小值
然后在讨论偶数的时候,我们找相邻的逆序对(mx,now),其中mx > now
需要一个odd < now || odd > mx;使用德摩根定律得判定条件,odd_mn > now && odd_mx < mx;
奇数同理
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
    ve<int> even,odd;
    int odd_mx = 0,odd_mn = INT_MAX,even_mx = 0,even_mn = INT_MAX;
    fo(i,0,n-1){
        int p;cin>>p;
        if(p%2){
            odd.push_back(p);
            odd_mx = max(p,odd_mx);
            odd_mn = min(p,odd_mn);
        }else{
            even.push_back(p);
            even_mx = max(p,even_mx);
            even_mn = min(p,even_mn);
        }
    }
    bool flg = true;
    if(even.size()>1){
        int mx = even[0];
        fo(i,1,even.size()-1){
            if(mx > even[i]){
                if(odd_mn > even[i] && odd_mx < mx){
                    flg = false;
                    break;
                }
            }else mx = even[i];
        }
    }
    if(odd.size()>1){
        int mx = odd[0];
        fo(i,1,odd.size()-1){
            if(mx > odd[i]){
                if(even_mn > odd[i] && even_mx < mx){
                    flg = false;
                    break;
                }
            }else mx = odd[i];
        }
    }
    if(flg) cout<<"YES";
    else cout<<"NO";
    cout<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) jianyanya();
}