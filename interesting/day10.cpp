#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int minOperations(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int re = 0;
    for (int i = 0;i<n;i++)
        re += abs(nums1[i]-nums2[i]);
    int ans = LLONG_MAX;
    for (int k = 0;k<n;k++){
        int l = min(nums1[k],nums2[k]);
        int h = max(nums1[k],nums2[k]);
        int e;
        if(nums2[n]>=l&&nums2[n]<=h) e = 0;
        else e = min(abs(l-nums2[n]),abs(h-nums2[n]));
        ans = min(ans,re+1+e);
    }
    return ans;
}

int main() {
    vector<int> nums1 = {2};
    vector<int> nums2 = {3, 4};
    cout << minOperations(nums1, nums2) << endl; // 输出 3
    return 0;
}