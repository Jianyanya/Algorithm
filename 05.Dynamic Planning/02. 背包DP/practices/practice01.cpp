//https://www.luogu.com.cn/problem/P8803
/*
带间隔限制的 0/1 背包 DP
这个题的话用按天dp是最好的,时间复杂度为O(365*m+n);
设dp[day][sum]为在day天凑齐sum金额,然后每次去找dp[day - k][sum]是否满足条件
1. 当前不选的时候,我们要处理之前的所有金额,次时dp[day][sum] = dp[day - 1][sum],因为不加,所以在之前就要凑齐sum金额
2. 选择当前的时候,我们就要判断之前k的间隔天数是否满足条件,此时dp[day][sum] = dp[day - k][sum - v]
还有其他做法,比如前驱背包
这时,设dp[i][sum] = 只考虑前 i 张票据,看能否凑出金额sum
就是对每个票据找到之前最近的一次满足条件的天数的票据,这时候要排序,还有预处理找,如果非要优化的话可以用双指针降到O(n),但是跟后面的n*m比起来太小了
1. 当前不选的时候,dp[i][sum] = dp[i - 1][sum]
2. 当前选的时候,dp[i][sum] = dp[pre[i]][s - v[i]]
这时候就发现,这个dp的状态只跟n和m有关,其实就是对票据直接进行处理,时间复杂度为O(n*m);
但是这个题目的日期范围特别小,所以直接按天dp就完了
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int moth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int n,m,k;
//我们来计算天数
vector<int> pre(13,0);

void solve1(){
    cin>>n>>m>>k;
    vector<vector<int> > vals(366); 
    for(int i = 1;i<=n;i++){
        int m1,d1,v;cin>>m1>>d1>>v;
        int sum = pre[m1 - 1] + d1;
        vals[sum].push_back(v);
    }
    vector<vector<bool> > dp(366,vector<bool>(m+1,false));
    dp[0][0] = true;
    for(int i = 1;i<=365;i++){
        for(int s = 0;s<=m;s++){
            dp[i][s] = dp[i - 1][s];
        }
        int last = max(0,i - k);
        for(int v:vals[i]){
            for(int s = v;s<=m;s++){
                if(dp[last][s - v]){
                    dp[i][s] = true;
                }
            }
        }
    }
    ll ans = 0;
    for(int s = m;s>=0;s--){
        if(dp[365][s]){
            ans = s;
            break;
        }
    }
    cout<<ans;
}

void solve2(){
    cin>>n>>m>>k;
    vector<pair<ll,int> > arr(n+1);
    vector<int> last(n+1,0);
    vector<vector<ll> > dp(n+1,vector<ll>(m+1,0));
    for(int i = 1;i<=n;i++){
        int m1,d1,v;cin>>m1>>d1>>v;
        int sum = pre[m1 - 1] + d1;
        arr[i] = {sum,v};
    }
    sort(arr.begin() + 1,arr.end(),[&](const auto& a,const auto& b){
        return a.first < b.first;
    });
    int pos = 0;
    for(int i = 1;i<=n;i++){
        while(pos + 1 < i && arr[i].first - arr[pos + 1].first >= k) pos++;
        last[i] = pos;
    }
    for(int i = 1;i<=n;i++){
        for(int j = m;j >= 0;j--){
            dp[i][j] = dp[i - 1][j];
            if(j >= arr[i].second) dp[i][j] = max(dp[i][j],dp[last[i]][j - arr[i].second] + arr[i].second);
        }
    }
    cout<<dp[n][m]<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 1;i<=12;i++){
        pre[i] = pre[i - 1] + moth[i];
    }
    //方法一: 
    //solve1();
    //方法二: 
    solve2();
    return 0;
}