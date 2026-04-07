#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N,K,M;cin>>N>>M>>K;
    vector<ll> C(N),A(N);
    for(int i=0;i<N-1;i++) cin>>C[i];
    for(int i=0;i<N;i++) cin>>A[i];
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    ll sum = 0,move = 0,ans = 0;
    for(int i=0;i<N;i++){
        if(i>0) move += C[i-1];
        if(move > M) break;
        pq.push(A[i]);
        sum += A[i];
        if(pq.size() > K){
            sum -= pq.top();
            pq.pop();
        }
        ll p = M - move;
        ans = max(ans, min(sum, p));
    }
    cout<<ans;
}