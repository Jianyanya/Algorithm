#include <iostream>
#include <string>
#include <vector>
using namespace std;
class BigInt : public vector<int> {
public:
	int float_ind = 0;
	BigInt(string str) {
		int ind = 0;
		for (int x = str.size() - 1; x >= 0; x--, ind++) {
			if (str[x] == '.') {
				float_ind = ind;
				continue;
			}
			push_back(str[x] - '0');
		}
		clear_front_zero();
	}
	//自增 四舍五入的时候用来进位
	void add() {
		at(0)++;
		int carry = at(0) / 10, ind = 1;
		at(0) %= 10;
		while (carry) {
			if (ind >= size()) push_back(0);
			at(ind)++;
			carry = at(ind) / 10;
			at(ind) %= 10;
			ind++;
		}
		clear_front_zero();
	}
	//清除前导零
	void clear_front_zero() {
		for (int x = size() - 1; x != float_ind; x--) {
			if (at(x)) break;
			pop_back();
		}
	}
	//左位移(乘1eX)
	void left_shift(int x) {
		if (!x) return;
		int n = size();
		for (int i = 0; i < x; i++) push_back(0);
		for (int i = size() - 1; i >= x; i--) {
			at(i) = at(i - x);
			at(i - x) = 0;
		}
		clear_front_zero();
	}
	//两个大整数相加 逻辑与自增相似
	BigInt operator+ (const BigInt& other) const {
		BigInt ret(*this);
		int m = other.size(), ind = 0, carry = 0;
		while (ind < m || carry) {
			if (ind >= ret.size()) ret.push_back(0); 
			if (ind < m) ret[ind] += other[ind]; //对位相加
			if (carry) ret[ind]++; //处理进位
			carry = ret[ind] / 10;
			ret[ind] %= 10;
			ind++;
		}
		ret.clear_front_zero();
		return ret;
	}
	BigInt operator* (const int& other) const {
		BigInt ret(*this);
		int carry = 0, ind = 0, n = ret.size();
		while (carry || ind < n) {
			if (ind >= ret.size()) ret.push_back(0);
			if (ind < n) ret[ind] *= other;
			if (carry) ret[ind] += carry;
			carry = ret[ind] / 10;
			ret[ind] %= 10;
			ind++;
		}
		ret.clear_front_zero();
		return ret;
	}
	//模拟竖式计算
	BigInt operator* (const BigInt& other) const {
		BigInt ret("0");
		//乘数中小数点有几位，结果就有几位
		ret.float_ind = float_ind;
		int m = other.size();
		for (int x = 0; x < m; x++) {
			BigInt temp = *this * other[x];
			temp.left_shift(x);
			ret = ret + temp;
		}
		ret.clear_front_zero();
		return ret;
	}
	//四舍五入去除小数
	BigInt round() {
		string ret = "";
		for (int x = size() - 1; x >= float_ind; x--) ret += at(x) + '0';
		BigInt res(ret);
		if (float_ind) if (at(float_ind - 1) >= 5) res.add();
		return res;
	}
	void print(bool int_mode) {
		int n = size();
		for (int x = n - 1; x >= 0; x--) {
			printf("%d", at(x));
			if (x == float_ind) {
				if (int_mode) break;
				printf(".");
			}
		}
		printf("\n");
	}
};
BigInt quick_mi(int b) {
	BigInt ret("1"), a("2");
	while (b) {
		if (b % 2) ret = ret * a;
		a = a * a;
		b /= 2;
	}
	return ret;
}
int main() {
    BigInt a("111");
    BigInt b("222");
    (a+b).print(true);
	return 0;
}