#include<bits/stdc++.h>
using namespace std;
struct BigInt {
    vector<int> d;   // 低位在前
    bool neg = false;
    /* ===== 构造 ===== */
    BigInt() {
        d.push_back(0);
        neg = false;
    }
    BigInt(long long x) {
        if (x < 0) {
            neg = true;
            x = -x;
        } else neg = false;
        if (x == 0) d.push_back(0);
        else {
            while (x) {
                d.push_back(x % 10);
                x /= 10;
            }
        }
    }
    BigInt(const string& s) {
        int i = 0;
        if (s[0] == '-') {
            neg = true;
            i = 1;
        } else neg = false;
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
            if (a.d[i] != b.d[i]) return a.d[i] < b.d[i] ? -1 : 1;
        }
        return 0;
    }
    /* ===== < 运算 ===== */
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
            res.d.clear();
            int carry = 0;
            for (size_t i = 0; i < max(a.d.size(), b.d.size()) || carry; i++) {
                int s = carry;
                if (i < a.d.size()) s += a.d[i];
                if (i < b.d.size()) s += b.d[i];
                res.d.push_back(s % 10);
                carry = s / 10;
            }
            // 如果结果是0，确保有至少一位
            if (res.d.empty()) res.d.push_back(0);
            res.trim();
            return res;
        }
        // 异号转换为减法
        if (a.neg) {
            BigInt temp = a;
            temp.neg = false;
            return b - temp;
        } else {
            BigInt temp = b;
            temp.neg = false;
            return a - temp;
        }
    }
    /* ===== 减法 ===== */
    friend BigInt operator-(const BigInt& a, const BigInt& b) {
        if (a.neg != b.neg) {
            BigInt nb = b;
            nb.neg ^= 1;
            return a + nb;
        }
        int comp = cmp_abs(a, b);
        if (comp == 0) return BigInt(0);
        if (comp > 0) {
            BigInt res;
            res.neg = a.neg;
            res.d.clear();
            
            int borrow = 0;
            for (size_t i = 0; i < a.d.size(); i++) {
                int s = a.d[i] - borrow;
                if (i < b.d.size()) s -= b.d[i];
                if (s < 0) {
                    s += 10;
                    borrow = 1;
                } else borrow = 0;
                res.d.push_back(s);
            }
            // 如果结果是0，确保有至少一位
            if (res.d.empty()) res.d.push_back(0);
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
        res.d.clear();
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
        while(carry){
            res.d.push_back(carry%10);
            carry /= 10;
        }
        res.trim();
        return res;
    }
    /* ===== 除以 long long ===== */
    friend BigInt operator/(const BigInt& a, long long b) {
        BigInt res;
        if (b < 0) res.neg = !a.neg, b = -b;
        else res.neg = a.neg;
        res.d.clear();
        res.d.resize(a.d.size());
        long long rem = 0;
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
        for (int i = x.d.size() - 1; i >= 0; i--) os << x.d[i];
        return os;
    }
};
int main(){
    BigInt a("222");
    BigInt b("111");
    cout<<b+a<<endl;
    return 0;
}