//向右看齐-洛谷-p2947,题目链接<https://www.luogu.com.cn/problem/P2947>
//不会做自己反思
#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int main(){
    int n;cin>>n;
    vector<int> arr(n+1);
    for(int i = 1;i<=n;i++) cin>>arr[i];
    vector<int> ans(n+1);
    for(int i =1;i<=n;i++){
        while(!s.empty()&&arr[s.top()]<arr[i]){//比我小的出去
            ans[s.top()] = i;//记录
            s.pop();//出栈
        }
        s.push(i);//入栈
    }
    for(int i = 1;i<=n;i++){//遍历答案
        cout<<ans[i]<<endl;
    }
    return 0;
}