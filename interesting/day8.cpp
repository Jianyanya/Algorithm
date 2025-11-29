//梦组csp模拟
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
x,y很大,肯定是不能简单枚举的,也不能模拟画图,只能找规律
就是这个逆时针不知道是什么意思,我可以直接往右上角一个接一个,但是题目说逆时针
(−1,0)→(0,1)，边长 1
(−1,−1)→(0,0)，边长 1
(0,−1)→(2,1)，边长 2
(−1,1)→(2,4)，边长 3
(−1,−2)→(4,3)，边长 5
(2,−2)→(10,6)，边长 8
(2,6)→(15,19)，边长 13
(−12,3)→(2,24)，边长 21
(−12,−10)→(2,3)，边长 34
(−12,−10)→(43,−1)，边长 55
(−12,−99)→(43,−10)，边长 89
(−12,−99)→(43,45)，边长 144
(−245,−99)→(43,45)，边长 233
(−245,−99)→(43,324)，边长 377
(−245,−423)→(43,324)，边长 610
(−245,−423)→(742,324)，边长 987
*/
struct SQ {
    ll x1, y1, x2, y2, len;
};
vector<SQ> sq;
vector<ll> F;
void init() {
    F.push_back(1);
    F.push_back(1);
    for (int i = 2; i < 100; i++) 
        F.push_back(F[i-1] + F[i-2]);
    sq.push_back({-1,0,0,1,1});
    sq.push_back({-1,-1,0,0,1});
    ll minX = -1, maxX = 0, minY = -1, maxY = 1;
    for (int n = 3;n<=100;n++) {
        ll len = F[n-1];
        int dir = (n-2) % 4;
        ll lx,ly;
        if (dir==0){
            lx = minX;
            ly = minY-len;
        }else if(dir==1){
            lx = maxX;
            ly = minY;
        }else if(dir==2){
            lx = maxX-len;
            ly = maxY;
        }else{
            lx = minX-len;
            ly = maxY-len;
        }
        ll rx = lx + len, ry = ly + len;
        sq.push_back({lx, ly, rx, ry, len});
        minX = min(minX, lx);
        maxX = max(maxX, rx);
        minY = min(minY, ly);
        maxY = max(maxY, ry);
    }
}
int main() {
    init();
    int T;
    cin >> T;
    while (T--) {
        ll x, y;
        cin >> x >> y;
        ll ans = 1e18;
        for (const auto&s:sq) 
            if (x >= s.x1 && x <= s.x2 && y >= s.y1 && y <= s.y2) ans = min(ans, s.len);
        cout<<ans<<"\n";
    }
    return 0;
}