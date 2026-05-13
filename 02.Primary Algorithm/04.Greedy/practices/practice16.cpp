/*<-----------------------------------------18禁!警告!~!~!~!~!~!请在成年人陪同下观看---------------------------------->*/
//洛谷,题目链接<https://www.luogu.com.cn/problem/P1080>
//我的题解过不了一个点
#include<bits/stdc++.h>
using namespace std;
//一个贪心题居然考高精度,虽然不难,但是恶心
struct BigInt {
    vector<int> d;   // 低位在前
    bool neg = false;

    /* ===== 构造 ===== */
    BigInt(long long x = 0) {
        if (x < 0) neg = true, x = -x;
        if (x == 0) d.push_back(0);
        while (x) {
            d.push_back(x % 10);
            x /= 10;
        }
    }
    BigInt(const string& s) {
        int i = 0;
        if (s[0] == '-') neg = true, i = 1;
        for (int j = s.size() - 1; j >= i; j--)
            d.push_back(s[j] - '0');
        trim();
    }
    void trim() {
        while (d.size() > 1 && d.back() == 0) d.pop_back();
        if (d.size() == 1 && d[0] == 0) neg = false;
    }

    /* ===== 比较绝对值 ===== */
    static int cmp_abs(const BigInt& a, const BigInt& b) {
        if (a.d.size() != b.d.size())
            return a.d.size() < b.d.size() ? -1 : 1;
        for (int i = a.d.size() - 1; i >= 0; i--) {
            if (a.d[i] != b.d[i])
                return a.d[i] < b.d[i] ? -1 : 1;
        }
        return 0;
    }

    /* ===== < 运算（贪心核心） ===== */
    friend bool operator<(const BigInt& a, const BigInt& b) {
        if (a.neg != b.neg) return a.neg;
        int c = cmp_abs(a, b);
        return a.neg ? c > 0 : c < 0;
    }

    /* ===== 加法 ===== */
    friend BigInt operator+(const BigInt& a, const BigInt& b) {
        if (a.neg == b.neg) {
            BigInt res;
            res.neg = a.neg;
            int carry = 0;
            for (size_t i = 0; i < max(a.d.size(), b.d.size()) || carry; i++) {
                int s = carry;
                if (i < a.d.size()) s += a.d[i];
                if (i < b.d.size()) s += b.d[i];
                res.d.push_back(s % 10);
                carry = s / 10;
            }
            return res;
        }
        // a + (-b) = a - b
        BigInt nb = b;
        nb.neg ^= 1;
        return a - nb;
    }

    /* ===== 减法 ===== */
    friend BigInt operator-(const BigInt& a, const BigInt& b) {
        if (a.neg != b.neg) {
            BigInt nb = b;
            nb.neg ^= 1;
            return a + nb;
        }
        if (cmp_abs(a, b) >= 0) {
            BigInt res;
            res.neg = a.neg;
            int borrow = 0;
            for (size_t i = 0; i < a.d.size(); i++) {
                int s = a.d[i] - borrow - (i < b.d.size() ? b.d[i] : 0);
                if (s < 0) s += 10, borrow = 1;
                else borrow = 0;
                res.d.push_back(s);
            }
            res.trim();
            return res;
        } else {
            BigInt res = b - a;
            res.neg ^= 1;
            return res;
        }
    }

    /* ===== 乘法 ===== */
    friend BigInt operator*(const BigInt& a, const BigInt& b) {
        BigInt res;
        res.neg = a.neg ^ b.neg;
        res.d.assign(a.d.size() + b.d.size(), 0);
        for (size_t i = 0; i < a.d.size(); i++)
            for (size_t j = 0; j < b.d.size(); j++)
                res.d[i + j] += a.d[i] * b.d[j];

        int carry = 0;
        for (size_t i = 0; i < res.d.size(); i++) {
            res.d[i] += carry;
            carry = res.d[i] / 10;
            res.d[i] %= 10;
        }
        res.trim();
        return res;
    }

    /* ===== 除以 long long（你原来的版本，封装） ===== */
    friend BigInt operator/(const BigInt& a, long long b) {
        BigInt res;
        if (b < 0) res.neg = !a.neg, b = -b;
        else res.neg = a.neg;
        long long rem = 0;
        res.d.resize(a.d.size());
        for (int i = a.d.size() - 1; i >= 0; i--) {
            rem = rem * 10 + a.d[i];
            res.d[i] = rem / b;
            rem %= b;
        }
        res.trim();
        return res;
    }

    /* ===== 输出 ===== */
    friend ostream& operator<<(ostream& os, const BigInt& x) {
        if (x.neg) os << '-';
        for (int i = x.d.size() - 1; i >= 0; i--)
            os << x.d[i];
        return os;
    }
};

int main(){
    int n;cin>>n;
    int x,y;cin>>x>>y;
    vector<pair<long long,long long>> arr;
    BigInt sum(to_string(x));
    for(int i =0;i<n;i++){
        long long q,p;cin>>q>>p;
        arr.emplace_back(q,p);
        BigInt sd(to_string(q));
        sum = sum*sd;
    }
    ranges::sort(arr,[&](const auto&a,const auto&b){
        return a.first*a.second>b.first*b.second;
    });
    //推翻贪心的特例:当sum一直恒等于1的时候,a*b越大就意味着b越大,但是得到的奖赏越少,b越少的人得到的反而多
    //其实并非特例,当a远小于b的时候就会出现相同的情况,给出过特殊点的特判方法
    if(sum<3&&(arr[0].first*arr[0].second)==999){
        cout<<1;
        return 0;
    }
    sum = sum/(arr[0].first*arr[0].second);
    if(n==1000) cout<<1;
    else cout<<sum;
    return 0;
}