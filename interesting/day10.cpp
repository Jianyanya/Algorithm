#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
struct List{
    ll l = -1,r = -1,val = 0;
};
//值和下标
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
int main(){
    int n,k;cin>>n>>k;
    vector<List> arr(n+5);
    vector<ll> cnt(n+5,0);
    arr[0].r = 1;
    arr[n+1].l = n;
    for(int i = 1;i<=n;i++){
        ll p;cin>>p;
        arr[i].l = i-1,arr[i].r = i+1;
        arr[i].val = p;
        auto mk = make_pair(p,i);
        pq.push(mk);
        cnt[i] = p;
    }
    // for(int i = 0;i<=n;i++){
    //     cout<<arr[i].val<<" ";
    // }
    // cout<<endl;
    for(int i = 0;i<k;i++){
        while(!pq.empty()){
            auto p = pq.top();
            if(p.first != cnt[p.second]) pq.pop();
            else break;
        }
        auto p = pq.top();
        pq.pop();
        ll x = p.first,y = p.second;
        arr[arr[y].l].val += x,arr[arr[y].r].val += x;
        arr[arr[y].l].r = arr[y].r;
        arr[arr[y].r].l = arr[y].l;
        if(arr[y].l!=0) pq.push({arr[arr[y].l].val,arr[y].l}),cnt[arr[y].l] = arr[arr[y].l].val;;
        if(arr[y].r<=n) pq.push({arr[arr[y].r].val,arr[y].r}),cnt[arr[y].r] = arr[arr[y].r].val;
        cnt[y] = -1;
    }
    // while(!pq.empty()){
    //     auto p = pq.top();
    //     if(p.first==cnt[p.second]) cout<<p.first<<endl;
    //     pq.pop();
    // }
    // cout<<endl;
    for(int i = 0;i<=n;){
        i = arr[i].r;
        if(i>n) break;
        cout<<arr[i].val<<" ";
    }
    return 0;
}