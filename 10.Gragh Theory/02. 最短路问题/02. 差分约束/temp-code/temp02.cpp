//https://www.luogu.com.cn/problem/P4926
/*
这个题的核心思路:倍数约束 -> 取对数 -> 差分约束 -> 二分答案
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e18;

struct Edge{
    int u,v;
    double w;
};

struct node{
    int o,a,b,k;
};

int main(){
    int n,s,t;cin>>n>>s>>t;
    vector<node> arr(s);
    vector<pair<int,int> > ts(t);
    for(int i = 0;i<s;i++) cin>>arr[i].o>>arr[i].a>>arr[i].b>>arr[i].k;
    for(int i = 0;i<t;i++){
        int c,x;cin>>c>>x;
        ts[i] = {c,x};
    }
    auto check = [&](double T) -> bool {
        vector<Edge> e;
        for(auto [o,a,b,k]:arr){
            if(o == 1){
                double c = k - T;
                if(c > 0) e.push_back({a,b,-log(c)});
            }else e.push_back({a,b,log(k + T)});
        }
        for(auto [c,val]:ts){
            double x = log(val);
            e.push_back({0,c,x});
            e.push_back({c,0,-x});
        }
        vector<double> dis(n+1,0);
        bool flg = false;
        for(int i = 1;i<=n;i++){
            flg = false;
            for(auto [u,v,w]:e){
                if(dis[v] > dis[u] + w + 1e-12){
                    dis[v] = dis[u] + w;
                    flg = true;
                }
            }
            if(!flg) break;
        }
        return flg;
    };
    if(!check(0)){
        cout<<-1;
        return 0;
    }
    double l = 0,r = 1.0*1e9,ans = 0;
    while(r - l >= 0.00001){
        double mid = l + (r - l)/2;
        if(check(mid)) l = mid,ans = mid;
        else r = mid;
    }
    cout<<ans;
    return 0;
}