//使用两个数组来模拟双向链表
//因为此场景还是算罕见的,我只能用我做过的题来解释,这题还是强行用链表的知识,所以难度较大
//题目链接<https://leetcode.cn/problems/minimum-time-to-activate-string>
#include<bits/stdc++.h>
#include <numeric>
using namespace std;
/*
我们从全为星号的情况开始，倒着遍历 order，把星号还原回字母。
一开始有 cnt= n(n+1)/2个有效子串。
把 s[i] 还原回字母，设 i 左侧最近星号为 L（若不存在则 L=−1），i 右侧最近星号为 R（若不存在则 R=n）。
那么原本左端点在 [L+1,i]，右端点在 [i,R−1] 中的有效子串就变成非有效子串了，根据乘法原理，这一共有(i−L)(R−i)个，从 cnt 中减去。
如果减去后 cnt<k，那么答案就是当前时刻。
代码实现时，用数组模拟双向链表，以及链表的节点删除操作，从而快速知道上文中的 L 和 R 的值。
*/
int minTime(string s,int order[], int k) {
        int n = s.size();
        long long sum = 1LL*n*(n+1)/2;
        if(sum<k) return -1;//特判,全改都不行
        vector<int> pre(n+1);
        vector<int> nxt(n);
        iota(pre.begin(),pre.end(),-1);//不知道自己搜
        iota(nxt.begin(),nxt.end(),1);
        for(int t = n-1;;t--){
            int i = order[t];
            int left = pre[i],right = nxt[i];
            sum -= 1LL*(i-left)*(right-i);
            if(sum<k) return t;
            if(left>=0) nxt[left] = right;
            pre[right] = left;
        }
    }
//不用管main
int main(){
    string str;cin>>str;
    int n = str.length();
    int arr[n];
    unordered_set<int> st;
    //输入时一定要尽量按照输入规则,即使我加了判断
    for(int i = 0;i<n;){
        int m;cin>>m;
        if(m>0&&m<n&&st.insert(m).second) i++,arr[i] = m;
    }
    int k;cin>>k;
    int ans = minTime(str,arr,k);
    cout<<ans;
    return 0;
}