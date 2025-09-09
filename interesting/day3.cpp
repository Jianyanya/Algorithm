//把j>i的且颜色与i相同的数尽量小
//把i均分给后面所有的i+nk
//因为重复所以其实只需要思考第一个k范围内的值
//8 2 4  ->5 5 4
//5 2 ->4 3
//5 3 -> 4 4
//4 16 1 1  ->4 6 6 6
/*
特殊情况:
小遇到大直接放弃

大遇到小,均分
中间大值,怎么往后分
*/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int answer = INT_MAX;
    for (int i = 0; i < k; i++) {
        vector<int> group;
        // 收集第i组的瓶子
        for (int j = i; j < n; j += k) {
            group.push_back(a[j]);
        }
        
        if (group.empty()) continue;
        
        // 计算前缀和
        vector<long long> prefix(group.size() + 1, 0);
        for (int j = 0; j < group.size(); j++) {
            prefix[j + 1] = prefix[j] + group[j];
        }
        
        // 二分查找该组能达到的最大目标值t
        int left = 0, right = prefix.back() / group.size();
        int best_t = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            bool valid = true;
            
            // 检查每个前缀是否满足条件
            for (int j = 1; j <= group.size(); j++) {
                if (prefix[j] < (long long)j * mid) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                best_t = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        answer = min(answer, best_t);
    }
    
    cout << answer << endl;
    return 0;
}