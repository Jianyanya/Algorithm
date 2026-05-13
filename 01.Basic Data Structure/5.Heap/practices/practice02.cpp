//黑匣子-洛谷-p1801,题目链接<https://www.luogu.com.cn/problem/P1801>
//经典求第i大或小的数,对顶堆
//保证左堆的长度为i就行,左堆堆顶就是第i大的数
//插入时新数如果比左堆堆顶大,则插入右堆,再从右堆中取出最小的放入left中,保证了堆的长度
#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    cin>>n>>m;
    vector<int> arr(n+1);
    priority_queue<int,vector<int>> left;
    priority_queue<int,vector<int>,greater<int>> right;
    for(int i = 0;i<n;i++) cin>>arr[i];
    int pos = 0;
    for(int i = 1;i<=m;i++){
        int get;cin>>get;
        for(int j = pos;j<get;j++){
            if(!left.empty()&&arr[j]>left.top()){
                right.push(arr[j]);
                left.push(right.top());
                right.pop();
            }
            else left.push(arr[j]);//你无法想象我因为这个else吃了两波wr
        }
        //保证堆的长度,虽然是循环,但有前面入堆的处理,这里其实没运行几次,最保险的写法
        while(!left.empty()&&left.size()>i) right.push(left.top()),left.pop();
        while(!right.empty()&&left.size()<i) left.push(right.top()),right.pop();
        pos = get;
        cout<<left.top()<<endl;
    }
    return 0;
}