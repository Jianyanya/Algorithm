//堆-洛谷-p3378,优先队列写法
//就是堆的一些常用方法
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    priority_queue<int,vector<int>,greater<int>> pq;
    while(n--){
        int m;cin>>m;
        if(m==1){
            int p;cin>>p;
            pq.push(p);
        }else if(m==2) cout<<pq.top()<<endl;
        else if(m==3) pq.pop();
    }
    return 0;
}