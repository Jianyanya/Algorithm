//lc,题目链接<https://leetcode.cn/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii/description/>
/*
很简单的一道题,题目无疑要做三件事
1. 求数字值的前缀和
2. 数字拼接,此题主要是前缀和,所以,拼接数字要使用前缀和的方法对其进行O(1)的优化
    怎么弄,1020304,从前往后统计,1,1,12,12,123,123,1234,1234-12*100 == 34,所以要提前记录位数
3. 统计数位,以方便拼接
*/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    const int mod = 1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long> pre(n+1),cnt(n+1),preval(n+1);
        for(int i = 1;i<=n;i++){
            pre[i] = pre[i-1]+(s[i-1]-'0');
            preval[i] = preval[i-1];
            cnt[i] = cnt[i-1];
            if(s[i-1]!='0'){
                cnt[i]++;
                preval[i] = ((preval[i-1]%mod*10)%mod+(s[i-1]-'0'))%mod;
            }
        }
        int mx = cnt[n];
        vector<long long> powsum(mx+1,1);
        for(int i = 1;i<=mx;i++) powsum[i] = (powsum[i-1]*10)%mod;
        vector<int> ans;
        for(auto &q:queries){
            int l = q[0],r = q[1];
            int t = cnt[r+1] - cnt[l];
            int sum = pre[r+1] - pre[l];
            int x = (preval[r+1] - preval[l]*powsum[t]%mod+mod)%mod;
            ans.push_back(1LL*x*sum%mod);
        }
        return ans;
    }
};