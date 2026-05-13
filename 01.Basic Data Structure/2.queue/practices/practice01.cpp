//题目链接<https://www.luogu.com.cn/problem/P1440>
//很简单的一道题,自己做把,跟模板题中的意思差不多
//想用stl?恭喜你超时是必然的,优化读写用scanf,printf就行了,c语言的有福了
//最好手写一个
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;scanf("%d %d",&n,&m);
    vector<int> arr(n+1);
    for(int i = 1;i<=n;i++) scanf("%d",&arr[i]);
    deque<int> dq;
    for(int i = 1;i<=n;i++){
        while(!dq.empty()&&dq.front()<i-m) dq.pop_front();
        if(dq.empty()) printf("%d\n",0);
        else printf("%d\n",arr[dq.front()]);
        while(!dq.empty()&&arr[dq.back()]>=arr[i]) dq.pop_back();
        dq.push_back(i);
    }
    return 0;
}