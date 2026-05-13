#include<bits/stdc++.h>
using namespace std;
const int N = 10000000;
vector<bool> is_prime(N,true);
vector<int> primes;
//埃式筛
void init1(){
    is_prime[0] = is_prime[1] = false;
    for(int i = 2;i<N;i++){
        if(is_prime[i]){
            primes.push_back(i);
            for(long long j = 1LL*i*i;j<N;j+=i){
                is_prime[j] = false;
            }
        }
    }
}
//性能更好的欧拉筛
//为线性筛,从0~1e8每个数只会筛一次
void init2() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) primes.push_back(i);
        for (int j = 0; j < primes.size() && i * primes[j] < N; j++) {
            is_prime[i * primes[j]] = false;
            if (i % primes[j] == 0) break;  // 关键优化
        }
    }
}
int n;
int main(){
    cin>>n;
    for(int i = 0;i<100;i++){
        cout<<primes[i]<<endl;
    }
    return 0;
}