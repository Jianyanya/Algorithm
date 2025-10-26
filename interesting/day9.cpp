#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int minOperations(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    bool flage = false;
    for (int i = 0;i<n;i++){
        if (nums2[i] == nums2[n]) {
            flage = true;
            break;
        }
    }
    nums1.push_back(nums2[n]);
    int ans = 0;
    for (int i = 0;i<n;i++){
        ans += abs(nums1[i]-nums2[i]);
    }
    if(!flage) ans++;
    return ans+1;
}

int main() {
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 2, 3, 2};
    cout << minOperations(nums1, nums2) << endl; // 输出 3
    return 0;
}