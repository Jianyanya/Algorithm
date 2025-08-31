//黑匣子-洛谷-p1801,题目链接<https://www.luogu.com.cn/problem/P1801>
//经典求第i大或小的数,对顶堆
//保证左堆的长度为i就行
#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    cin>>n>>m;
    vector<int> arr(n+1);
    vector<int> get(m+1);
    priority_queue<int,vector<int>> left;
    priority_queue<int,vector<int>,greater<int>> right;
    for(int i = 1;i<=n;i++) cin>>arr[i];
    for(int i = 1;i<=m;i++) cin>>get[i];
    int j = 1;
    for(int i = 1;i<=n;i++){
        int p = arr[i];
        left.push(p);
        while(left.size()>j) right.push(left.top()),left.pop();
        if(i==get[j]) cout<<left.top()<<endl;
    }
    return 0;
}