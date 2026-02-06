/*
归并排序
经典应用:
找顺序对和逆序对
这个问题还可以使用线段树,但是归并排序明显简单
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n), temp(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    auto merge = [&](this auto&& merge, int l, int r) -> long long {
        if (l >= r) return 0;
        int mid = l + (r - l) / 2;
        long long cnt = merge(l, mid) + merge(mid + 1, r);
        int i = l, j = mid + 1, k = l;
        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                cnt += mid - i + 1;
            }
        }
        while (i <= mid) temp[k++] = arr[i++];
        while (j <= r) temp[k++] = arr[j++];
        for (int p = l; p <= r; p++) arr[p] = temp[p];
        return cnt;
    };
    cout<<merge(0,n-1);
    return 0;
}
