/*
适用于限制询问大小次数的排序
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // 已排序序列
    vector<char> ord;
    ord.push_back('A');   // 第一个元素直接放入

    for (int i = 1; i < N; i++) {
        char x = 'A' + i;

        int l = 0, r = ord.size(); // 插入到 [l, r)
        while (l < r) {
            int mid = (l + r) / 2;
            cout << "? " << x << " " << ord[mid] << endl;
            fflush(stdout);

            char res;
            cin >> res;
            if (res == '<') {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        ord.insert(ord.begin() + l, x);
    }
    cout << "! ";
    for (char c : ord) cout << c;
    cout << endl;
    fflush(stdout);

    return 0;
}
