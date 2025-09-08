//把j>i的且颜色与i相同的数尽量小
//把i均分给后面所有的i+nk
//因为重复所以其实只需要思考第一个k范围内的值
//8 2 4  ->5 5 4
//5 2 ->4 3
//5 3 -> 4 4
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
    int min_val = INT_MAX;
    for (int i = 0; i < k; i++) {
        long long sum = 0;
        int count = 0;
        // 计算第i组的瓶子数量和总水量
        for (int j = i; j < n; j += k) {
            sum += a[j];
            count++;
        }
        // 该组能保证的最小值最大为 sum / count
        if (count > 0) {
            min_val = min(min_val, (int)(sum / count));
        }
    }
    cout << min_val << endl;
    return 0;
}