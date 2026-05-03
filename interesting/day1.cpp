// #include <bits/stdc++.h>
// using namespace std;
// #define fo(i,l,r) for(int i=(l);i<=(r);++i)
// #define ve vector
// #define endl '\n'
// using ll = long long;
// using ull = unsigned long long;
// using sr = string;
// using db = double;
// using dll = double long;
// const int MOD=998244353;
// const ll INF=1e18;
// const int DIR[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
// int T;
// int n, k, l;
// string s;
// void solve(){
//     int n, k, l;
//         string s;
//         cin>>n>>l>>k>>s;
//         // 1. 初步可行性判断
//         if (n<k*l) {
//             cout << "NO"<<endl;
//             return ;
//         }
//         if(k==1){
//             cout<<"YES"<<endl;
//             cout<<s<<endl;
//             return  ;
//         }
//         int p = n - k*l;
//         char mx = 'a';
//         for(char c:s) mx = max(mx,c);
//         sr ans = "";
//         for(int i = 0;i<n;i++){
//             if(s[i]==mx){
//                 int pr = (l - i%l)%l;
//                 if(pr!=0&&p<pr) continue;
//                 int wer = 0;
//                 if(pr<=p) wer = p - pr;
//                 sr str = s.substr(i+pr,l+wer);
//                 //cout<<str<<endl;
//                 ans = max(ans,str);
//             }
//         }
//         cout << "YES\n";
//         cout << ans << '\n';
// }
// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin>>T;
//     while(T--) solve();
// }
#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

const ull base = 131;

int n, k, l;
string s;
vector<ull> h, p;

// 取子串 hash
ull get(int l, int r){
    return h[r] - h[l-1] * p[r-l+1];
}

// 比较 s[a..a+len-1] 和 s[b..b+len-1]
bool geq(int a, int b, int len){
    int low = 0, high = len;
    while(low < high){
        int mid = (low + high + 1) >> 1;
        if(get(a, a+mid-1) == get(b, b+mid-1)) low = mid;
        else high = mid-1;
    }
    if(low == len) return true;
    return s[a+low] >= s[b+low];
}

// 判断某个子串作为 T 是否可行
bool check(int st, int len){
    int cnt = 0;
    int i = 1;

    while(i <= n){
        int j = i + l - 1;
        if(j > n) break;

        int cur_len = l;

        // 延长直到 >= T
        while(j <= n){
            if(cur_len >= len){
                if(geq(i, st, len)){
                    cnt++;
                    i = j + 1;
                    break;
                }
            }
            j++;
            cur_len++;
        }

        if(j > n) break;
    }

    return cnt >= k;
}

void solve(){
    cin >> n >> k >> l >> s;
    s = " " + s;

    if(n < k * l){
        cout << "NO\n";
        return;
    }

    // 预处理哈希
    h.assign(n+1, 0);
    p.assign(n+1, 1);
    for(int i = 1; i <= n; i++){
        h[i] = h[i-1] * base + s[i];
        p[i] = p[i-1] * base;
    }

    string ans = "";

    // 枚举起点
    for(int i = 1; i <= n; i++){
        int L = l, R = n - i + 1;
        string best = "";

        while(L <= R){
            int mid = (L + R) >> 1;
            if(check(i, mid)){
                best = s.substr(i, mid);
                L = mid + 1;
            }else{
                R = mid - 1;
            }
        }

        if(best > ans) ans = best;
    }

    cout << "YES\n";
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) solve();
}