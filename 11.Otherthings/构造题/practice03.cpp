//https://codeforces.com/contest/2231/problem/D
#include <bits/stdc++.h>
using namespace std;
#define fo(i,l,r) for(int i=(l);i<=(r);++i)
#define ve vector
#define endl '\n'
using ll = long long;
using ull = unsigned long long;
using sr = string;
using db = double;
using dll = long double;
const int MOD=998244353;
const int MX = 1e9;
const ll INF=1e18;
const int DIR[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int T;
// void jianyanya(){
//     int n;
//     cin>>n;

//     string s;
//     cin>>s;
//     s=" "+s;

//     ve<ll>a(n+1),c(n+1),b(n+1);
//     fo(i,1,n) cin>>a[i];
//     fo(i,1,n) cin>>c[i];

//     fo(i,2,n){
//         if(c[i]<c[i-1]){
//             cout<<"NO"<<endl;
//             return;
//         }
//     }

//     ve<int> must(n+1,0);
//     must[1]=1;
//     fo(i,2,n){
//         if(c[i]>c[i-1]) must[i]=1;
//     }
//     bool ok=true;
//     for(int l=0;l<=n;){
//         int r=l;
//         while(r+1<=n&&s[r+1]=='1') r++;

//         ve<ll> pre(r-l+1,0);
//         fo(i,l+1,r){
//             pre[i-l]=pre[i-l-1]+a[i];
//         }

//         bool fixed=false;
//         ll base=0;

//         if(l==0){
//             fixed=true;
//             base=0;
//         }
//         fo(i,max(1,l),r){
//             if(must[i]){
//                 ll need=c[i]-pre[i-l];
//                 if(!fixed){
//                     fixed=true;
//                     base=need;
//                 }else if(base!=need){
//                     ok=false;
//                 }
//             }
//         }

//         if(!ok) break;

//         if(!fixed){
//             base=LLONG_MAX;
//             fo(i,max(1,l),r){
//                 base=min(base,c[i]-pre[i-l]);
//             }
//         }

//         fo(i,max(1,l),r){
//             b[i]=base+pre[i-l];
//             if(must[i]&&b[i]!=c[i]) ok=false;
//             if(!must[i]&&b[i]>c[i]) ok=false;
//         }
//         if(!ok) break;
//         if(r==n) break;
//         l=r+1;
//     }
//     if(!ok){
//         cout<<"NO"<<endl;
//         return;
//     }
//     fo(i,1,n){
//         if(s[i]=='0'){
//             a[i]=b[i]-b[i-1];
//         }
//     }
//     cout<<"YES"<<endl;
//     fo(i,1,n){
//         cout<<a[i]<<" \n"[i==n];
//     }
// }
void jianyanya(){
    int n;cin>>n;
    sr str;cin>>str;
    str = " "+str;
    ve<ll> arr(n+1),maxpre(n+1),pre(n+1);
    fo(i,1,n) cin>>arr[i];
    fo(i,1,n) cin>>maxpre[i];
    ve<bool> must(n+1,false);
    must[1] = true;
    fo(i,2,n){
        if(maxpre[i] > maxpre[i-1]){
            must[i] = true;
        }
    }
    bool flg = true;
    for(int i=0;i<=n;){
        int j = i;
        ll sum = 0;
        ve<ll> rel;
        rel.push_back(0);
        while(j + 1 <= n && str[j+1] == '1'){
            sum += arr[j+1];
            rel.push_back(sum);
            j++;
        }
        bool fixed = false;
        ll base=0;
        if(i==0){
            fixed = true;
            base=0;
        }
        for(int p=i;p<=j;p++){
            if(p>=1&&must[p]){
                ll need = maxpre[p] - rel[p-i];
                if(!fixed){
                    fixed = true;
                    base = need;
                }else if(base != need){
                    flg = false;
                    break;
                }
            }
        }
        if(!flg) break;
        if(!fixed){
            base = LLONG_MAX;
            for(int p=max(1,i);p<=j;p++){
                base = min(base,maxpre[p] - rel[p-i]);
            }
        }
        for(int p=i;p<=j;p++){
            pre[p] = base + rel[p-i];
            if(p >= 1){
                if(pre[p] > maxpre[p]) flg = false;
                if(must[p] && pre[p]!=maxpre[p]) flg = false;
            }
        }
        if(!flg) break;
        i = j + 1;
    }
    if(!flg){
        cout<<"NO"<<endl;
        return;
    }else cout<<"YES"<<endl;
    fo(i,1,n){
        if(str[i]=='0'){
            arr[i]=pre[i]-pre[i-1];
        }
    }
    fo(i,1,n) cout<<arr[i]<<" ";
    cout<<endl;
}
// void jianyanya(){
//     int n;cin>>n;
//     sr str;cin>>str;
//     str = " " + str;
//     ve<ll> arr(n+1),maxpre(n+1),pre(n+1);
//     fo(i,1,n) cin>>arr[i];
//     fo(i,1,n) cin>>maxpre[i];
//     ve<bool> vis(n+1,false);
//     if(str[1] == '1' && arr[1] != maxpre[1]){
//         cout<<"NO"<<endl;
//         return ;
//     }
//     arr[1] = maxpre[1];
//     pre[1] = maxpre[1];
//     vis[1] = true;
//     fo(i,2,n){
//         if(maxpre[i - 1] != maxpre[i]){
//             pre[i] = maxpre[i];
//             vis[i] = true;
//         }
//     }
//     bool flg = true;
//     for(int i = 0;i<n;){
//         int j = i;
//         ll sum = 0;
//         int base = maxpre[i];
//         while(j + 1 <= n && str[j + 1] == '1'){
//             sum += arr[j + 1];
//             if(vis[j + 1] && base == maxpre[i]){
//                 base = pre[j + 1] - sum;
//             }else if(vis[j + 1] && base != pre[j + 1] - sum){
//                 flg = false;
//             }
//             if(!flg) break;
//             j++;
//         }
//         if(base > maxpre[i]) flg = false;
//         if(!flg) break;
//         pre[i] = base;
//         vis[i] = true;
//         for(int l = i + 1;l<=j;l++){
//             pre[l] = pre[l - 1] + arr[l];
//             if(pre[l] > maxpre[l]){
//                 cout<<"NO"<<endl;
//                 return ;
//             }
//             vis[l] = true;
//         }
//         i = j + 1;
//     }
//     if(flg) cout<<"YES"<<endl;
//     else{
//         cout<<"NO"<<endl;
//         return ;
//     }
//     fo(i,1,n){
//         if(str[i] == '0'){
//             if(!vis[i]) pre[i] = maxpre[i];
//             arr[i] = pre[i] - pre[i - 1];
//         }
//     }
//     fo(i,1,n) cout<<arr[i]<<" ";
//     cout<<endl;
// }
// void jianyanya(){
//     int n;cin>>n;
//     sr str;cin>>str;
//     ve<int> arr(n),maxpre(n),pre(n);
//     ve<bool> vis(n);
//     fo(i,0,n-1) cin>>arr[i];
//     fo(i,0,n-1) cin>>maxpre[i];
//     if(str[0] == '1' && arr[0] != maxpre[0]){
//         cout<<"NO"<<endl;
//         return ;
//     }
//     //arr[i] + pre[i - 1] = pre[i]
//     //arr[i - 1] + pre[i - 2] = pre[i - 1];
//     arr[0] = maxpre[0];
//     pre[0] = maxpre[0];
//     vis[0] = true;
//     fo(i,1,n-1){
//         if(maxpre[i] != maxpre[i - 1]){
//             pre[i] = maxpre[i];
//             vis[i] = true;
//             if(str[i] == '1'){
//                 int p = pre[i] - arr[i];
//                 if((vis[i - 1] && pre[i - 1] != p) || (!vis[i - 1] && p > maxpre[i - 1])){
//                     cout<<"NO"<<endl;
//                     return ;
//                 }
//                 pre[i - 1] = p;
//             }else{
//                 str[i] = '1';
//                 if(vis[i - 1]){
//                     arr[i] = pre[i] - pre[i - 1];
//                 }else{
//                     arr[i] = pre[i] - maxpre[i - 1];
//                     pre[i - 1] = maxpre[i - 1];
//                     vis[i - 1] = true;
//                 }
//             }
//         }
//     }
//     pre[n - 1] = maxpre[n - 1];
//     vis[n - 1] = true;
//     bool flg = true;
//     for(int i = 1;i<n;i++){
//         if(str[i] == '1' && !vis[i - 1]){
//             pre[i - 1] = pre[i] - arr[i];
//             if(pre[i - 1] > maxpre[i - 1]){
//                 flg = false;
//                 break;
//             }
//             vis[i - 1] = true;
//         }else if(str[i] == '0' && vis[i - 1]){
//             arr[i] = pre[i] - pre[i - 1];
//             str[i] = '1';
//         }else if(str[i] == '0' && !vis[i - 1]){
//             pre[i - 1] = maxpre[i - 1];
//             vis[i - 1] = true;
//             arr[i] = pre[i] - pre[i - 1];
//         }
//         // if(str[i] == '1'){
//         //     if(!vis[i] && !vis[i - 1]){
//         //         pre[i] = maxpre[i];
//         //         pre[i - 1] = pre[i] - arr[i];
//         //         vis[i] = vis[i - 1] = true;
//         //     }
//         //     if(vis[i] && !vis[i - 1]){
//         //         int p = pre[i] - arr[i];
//         //         pre[i - 1] = p;
//         //         vis[i - 1] = true;
//         //     }else if(!vis[i] && vis[i - 1]){
//         //         pre[i] = arr[i] + pre[i - 1];
//         //         vis[i] = true;
//         //     }
//         // }else{
//         //     if(!vis[i] && !vis[i - 1]){
//         //         pre[i] = maxpre[i];
//         //         pre[i - 1] = pre[i] - arr[i];
//         //         vis[i] = vis[i - 1] = true;
//         //     }
//         //     if(vis[i] && !vis[i - 1]){
//         //         int p = pre[i] - arr[i];
//         //         pre[i - 1] = p;
//         //         vis[i - 1] = true;
//         //     }else if(!vis[i] && vis[i - 1]){
//         //         pre[i] = arr[i] + pre[i - 1];
//         //         vis[i] = true;
//         //     }
//         // }
//         // if(str[i] == '1' && vis[i] && !vis[i - 1]){
            
//         // }else if(str[i] == '1' && !vis[i] && vis[i - 1]){

//         // }else if(!vis[i] && !vis[i - 1]){
            
//         // }
//     }
//     if(flg) cout<<"YES"<<endl;
//     else{
//         cout<<"NO"<<endl;
//         return ;
//     }
//     for(auto x:arr) cout<<x<<" ";
//     cout<<endl;
// }
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) jianyanya();
}