#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;

long long countGoodSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> pre(n+1,0);
    for (int i = 1;i<=n;i++) {
        pre[i+1] = pre[i]+nums[i];
    }
    vector<int> premod(n+1);
    for (int i = 0;i<=n;i++) {
        premod[i] = (pre[i]%k+k)%k;
    }
    unordered_map<int,vector<int>> mp;
    for (int i = 0;i<=n;i++) {
        mp[premod[i]].push_back(i);
    }
    set<pair<int,int>> st;
    for (int i = 0; i < n; i++) {
        int t = premod[i+1];
        if (!mp.count(t)) continue;
        const auto& arr = mp[t];
        int l = 0,r= arr.size()-1;
        int idx = -1;
        while (l<=r) {
            int mid = l+(r-l)/2;
            if (arr[mid]<=r){
                idx = mid;
                l = mid+1;
            }else r = mid-1;
        }
        if (idx >= 0) {
            for (int j = 0; j <= idx; j++) {
                int l = arr[j];
                if (l <= i) st.insert({nums[l],i-l+1});
            }
        }
    }
    return st.size();
}