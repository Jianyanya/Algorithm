#include <vector>
#include <map>
#include <algorithm>
using namespace std;

long long countStableSubarrays(vector<int>& capacity) {
    int n = capacity.size();
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + capacity[i];
    }
    map<pair<int, long long>, vector<int>> mp;
    for (int r = 0; r < n; r++) {
        mp[{capacity[r], prefix[r]}].push_back(r);
    }
    long long ans = 0;
    for (int l = 0; l < n; l++) {
        long long target_prefix = prefix[l] + 2LL * capacity[l];
        auto key = make_pair(capacity[l], target_prefix);
        if (mp.count(key)) {
            const auto& indices = mp[key];
            int pos = lower_bound(indices.begin(), indices.end(), l + 2) - indices.begin();
            ans += (indices.size() - pos);
        }
    }
    return ans;
}