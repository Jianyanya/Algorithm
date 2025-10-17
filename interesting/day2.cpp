#include<bits/stdc++.h>
using namespace std;
const int N = 100000001;
vector
vector<int> primes;
void init(){
    is_prime[0] = is_prime[1] = false;
    for(int i = 2;i<N;i++){
        if(!is_prime[i]){
            primes.push_back(i);
            for(int j = i;j<N;j+=i){
                is_prime[j*j] = false;
            }
        }
    }
}
int n;
int main(){
    cin>>n;
    fill(is_prime.begin(),is_prime.end(),true);
    init();
    for(int i = 0;i<100;i++){
        cout<<primes[i];
    }
    return 0;
}