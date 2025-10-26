//洛谷-P5440-[XR-2]奇迹,题目链接<https://www.luogu.com.cn/problem/P5440>
/*
核心思路
看到要检验质数,我先想到了用筛法来筛出所有的质数,可明显是不行的,要筛1e8的质数,使用欧拉线性筛也超时,所以直接筛肯定是不行的
可以发现题目中的年月日是分开的,而且又不是要验证所有数字,月就12个月,月对应的日也是固定天数,那31天中也没几个质数,可以先打表预处理这些数据
对这些数进行拼接,但是质数和质数拼接并不一定是质数,所以要进行判断
tip:记得闰年要特判,天数中2虽然是质数但是与别的数组合一定不是质数
*/
#include <bits/stdc++.h>
using namespace std;
int p[] = {0,3,5,7,11,13,17,19,23,29,31,37};
int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int T;
string str;
vector<int> a;
vector<int> arr;
bool isprime(int n){
    if(n<=1) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    for(int i = 2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //月日组合
    for(int i = 1;i<=12;i++){
        for(int j = 1;p[j]<=days[i];j++){
            int m = i*100+p[j];
            if(isprime(m)) a.push_back(m);
        }
    }
    //先检查闰年的特殊天
    //2月29号
    for(int i = 4;i<=9999;i+=4){
        if(((i%100)||!(i%400))&&isprime(i*10000+229)) arr.push_back(i*10000+229);
    }
    //拼接年和月日组合
    for(int i = 1;i<=9999;i++){
        for(int x:a){
            if(isprime(i*10000+x)) arr.push_back(i*10000+x);
        }
    }
    cin>>T;
    while(T--){
        cin>>str;
        int cnt = 0;
        for(int x:arr){
            int f = 1;
            for(int j = 7;f&&j>=0;x/=10,j--){
                if(str[j]!='-'&&str[j]-'0'!=x%10) f = 0;
            }
            cnt += f;
        }
        cout<<cnt<<endl;
    }
    return 0;
}