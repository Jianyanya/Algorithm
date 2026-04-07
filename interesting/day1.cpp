#include <bits/stdc++.h>
using namespace std;

int main() {
    int mat[6][6] = {
        {11, 8, 3, 27, 24, 1},
        {2, 21, 16, 35, 17, 4},
        {9, 29, 20, 30, 5, 10},
        {36, 33, 13, 6, 23, 7},
        {31, 14, 15, 28, 12, 25},
        {34, 19, 18, 37, 22, 39}
    };

    // 存储所有可能的1x2或2x1骨牌，每个骨牌用一个vector<int>存储两个格子的坐标 (r,c)
    vector<pair<int,int>> dominoes; // 每个骨牌用起始格子表示，方向：0=水平，1=垂直
    // 也可以直接存两个格子编号，但为了不重叠检查，存格子坐标
    struct Domino {
        int r1, c1, r2, c2;
    };
    vector<Domino> doms;

    // 水平
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            if ((mat[i][j] + mat[i][j+1]) % 2 == 1) {
                doms.push_back({i, j, i, j+1});
            }
        }
    }
    // 垂直
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            if ((mat[i][j] + mat[i+1][j]) % 2 == 1) {
                doms.push_back({i, j, i+1, j});
            }
        }
    }

    int m = doms.size();
    set<set<int>> ansSet; // 用集合存储三个骨牌的索引，自动去重顺序

    for (int i = 0; i < m; i++) {
        for (int j = i+1; j < m; j++) {
            // 检查 i 和 j 是否重叠
            bool overlap = false;
            auto &d1 = doms[i];
            auto &d2 = doms[j];
            // 判断两个骨牌是否有公共格子
            if ((d1.r1 == d2.r1 && d1.c1 == d2.c1) ||
                (d1.r1 == d2.r2 && d1.c1 == d2.c2) ||
                (d1.r2 == d2.r1 && d1.c2 == d2.c1) ||
                (d1.r2 == d2.r2 && d1.c2 == d2.c2)) {
                overlap = true;
            }
            if (overlap) continue;

            for (int k = j+1; k < m; k++) {
                auto &d3 = doms[k];
                bool ok = true;
                if ((d3.r1 == d1.r1 && d3.c1 == d1.c1) ||
                    (d3.r1 == d1.r2 && d3.c1 == d1.c2) ||
                    (d3.r2 == d1.r1 && d3.c2 == d1.c1) ||
                    (d3.r2 == d1.r2 && d3.c2 == d1.c2)) {
                    ok = false;
                }
                if (ok && ((d3.r1 == d2.r1 && d3.c1 == d2.c1) ||
                           (d3.r1 == d2.r2 && d3.c1 == d2.c2) ||
                           (d3.r2 == d2.r1 && d3.c2 == d2.c1) ||
                           (d3.r2 == d2.r2 && d3.c2 == d2.c2))) {
                    ok = false;
                }
                if (ok) {
                    ansSet.insert({i, j, k});
                }
            }
        }
    }

    cout << ansSet.size() << endl;
    return 0;
}