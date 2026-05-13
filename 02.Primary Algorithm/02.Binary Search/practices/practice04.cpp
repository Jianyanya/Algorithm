//luogu,题目链接<https://www.luogu.com.cn/problem/P14575?contestId=242706>
#include <bits/stdc++.h>
using namespace std;
/*
这个题目的答案是单调的,越小的答案越符号条件,但是我们要找到最大的,所以二分答案
就是这个贪心难想
在答案已经知道的情况下,我们怎么验证
每科的老师,需要班级数都是固定的,所以我们可以对不同的科目进行逐个计算
由于题目没说科目是从1开始的,所以使用map记录
对于每个科目,先统计能教1的老师有多少,如果够的话,就证明可以把多余的老师当班主任(把多余的累加到一起)
如果中途计算发现连教科目的老师都不够,就直接返回false
最后看班主任是否够就行了
*/
int n, m;
map<int, pair<long long, int>> mp;
bool check(int k) {
    if (k == 0) return true;
    if (mp.size() < m) return false;
    long long tal = 0;
    for (auto& [s, f] : mp) {
        long long sum = f.first;
        int ters = f.second;
        if(sum < k) return false;
        long long chi = sum - k;
        if(chi >= ters) tal += ters;
        else tal += chi;
    }
    return tal >= k;
}
void solve() {
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        mp[a].first += b;
        if (c == 1) {
            mp[a].second++;
        }
    }
    int ans = 0;
    int left = 0, right = n;
    while(left <= right){
        int mid = (left + right) / 2;
        if (check(mid)) {
            ans = mid;
            left = mid + 1;
        }else right = mid - 1;
    }
    cout<<ans<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}