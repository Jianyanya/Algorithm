#include <vector>
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 20; // 2^20 > 1e6
const int MAXM = 1 << N;
typedef long long ll;

class Solution {
public:
    int subsequenceCount(vector<int>& nums) {
        int N = 1<<20;
        vector<int> cnt(N,0);
        for (int x :nums) cnt[x]++;
        vector<int> f(N,0);
        for(int i = 0;i < N;i++) f[i] = cnt[i];
        for(int i = 0;i < N;i++){
            for(int m = 0;m < N;m++){
                if(m>>i&1) f[m] += f[m^(1<<i)];
            }
        }
        int sum  = 0;
        int temp = N - 1;
        ll ans = 0;
        for(int i = sum;i > 0;i = (i-1)&sum){
            ll cnt = f[temp^i];
            ll w = 1;
            ll a = 2, res = 1;
            while(cnt > 0){
                if (cnt & 1) res = res*a%MOD;
                a = a*a%MOD;
                cnt >>= 1;
            }
            w = res;
            int bits = __builtin_popcount(i);
            if(bits%2 == 1) ans = (ans + w)%MOD;
            else ans = (ans - w + MOD)%MOD;
        }
        return ans;
    }
};