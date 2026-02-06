#include <bits/stdc++.h>
using namespace std;
#define ve vector
using ll = long long;
using ull = unsigned long long;
using sr = string;
using db = double;
using dll = double long;
const int MOD=998244353;
const ll INF=1e18;
const int DIR[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int T;
// void solve(){
//     int n,m;cin>>n>>m;
//     ve<int> arr(n+1);
//     ve<pair<int,int>> app;
//     ll sum = 0;
//     for(int i = 1;i<=n;i++){
//         cin>>arr[i];
//         sum += arr[i];
//     }
//     int a,b;
//     for(int i = 0;i<m;i++){
//         cin>>a>>b;
//         app.emplace_back(a,b);
//     }
//     ll ans = sum;
//     int pos = 0;
//     for(auto [x,y]:app){
//         int d = x - pos;
//         if(sum>=d){
//             if(arr[y]>d) ans += d;
//             else ans += arr[y];
//             sum -= d;
//         }else break;
//         if(sum == 0) break;
//         pos = x;
//     }
//     cout<<ans<<endl;
// }
void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<ll> cap(n + 1);  // 电池容量
    vector<ll> cur(n + 1);  // 当前电量
    ll total = 0;           // 总电量
    
    for (int i = 1; i <= n; i++) {
        cin >> cap[i];
        cur[i] = cap[i];
        total += cap[i];
    }
    
    vector<pair<int, int>> stations(m);
    for (int i = 0; i < m; i++) {
        cin >> stations[i].first >> stations[i].second;
    }
    
    // 按位置排序（题目已保证有序，但为了安全还是排序）
    sort(stations.begin(), stations.end());
    
    int pos = 0;  // 当前位置
    ll ans = 0;
    
    // 遍历所有充电站
    for (auto [x, t] : stations) {
        int dist = x - pos;  // 需要行驶的距离
        
        // 如果当前电量不够到达这个充电站
        if (total < dist) {
            // 只能行驶total公里
            ans = pos + total;
            cout << ans << "\n";
            return;
        }
        
        // 行驶到充电站
        total -= dist;
        pos = x;
        
        // 优先使用非目标电池的电量
        // 我们尽量让目标电池保留更多电量
        // 这样充电时才能补充更多
        ll used_from_target = 0;
        
        // 计算我们需要从目标电池使用多少电量
        // 如果其他电池的电量足够，我们尽量不使用目标电池
        ll other_battery_power = total - cur[t];
        
        if (other_battery_power >= dist) {
            // 其他电池的电量足够，不使用目标电池
            // 只需要从总电量中减去dist
            // 更新各个电池的电量（这里简化处理，不具体分配）
        } else {
            // 需要使用部分目标电池的电量
            used_from_target = dist - other_battery_power;
            cur[t] -= used_from_target;
        }
        
        // 更新总电量（由于行驶消耗）
        // 注意：我们已经从total中减去了dist
        
        // 在充电站充电
        ll charge = cap[t] - cur[t];
        if (charge > 0) {
            total += charge;
            cur[t] = cap[t];
        }
    }
    
    // 经过所有充电站后，还能行驶total公里
    ans = pos + total;
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) solve();
}
