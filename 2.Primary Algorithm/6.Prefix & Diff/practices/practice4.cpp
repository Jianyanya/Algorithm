//lc,题目链接<https://leetcode.cn/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii/description/>
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