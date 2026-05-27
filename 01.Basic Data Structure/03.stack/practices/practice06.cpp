//https://www.luogu.com.cn/problem/P12271
/*
这个题本质就是用栈计算括号匹配的数量
那么这里还有个问题就是关于两个括号之间的字母的数量
我们可以使用前缀和计算出区间里字母的总和,然后往答案里加两个括号之间的字母数量就行
在统计ans的时候往后面累加,因为满足括号数量多的包括数量少的
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;cin>>str;
    int n = str.size();
    vector<vector<int> > pre(26,vector<int>(n+2));
    vector<vector<int> > ans(26,vector<int>(n+2));
    stack<int> st;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<26;j++) pre[j][i+1] = pre[j][i] + (str[i] == 'a' + j);
        if(str[i]=='(') st.push(i);
        else if(str[i]==')'){
            int id = st.top();st.pop();
            for(int j = 0;j<26;j++) ans[j][pre[j][i+1] - pre[j][id]]++;
        }
    }
    for(int j = 0;j<26;j++){
        for(int i = n;i>=0;i--) ans[j][i] += ans[j][i+1];
    }
    int m;cin>>m;
    while(m--){
        char c;
        int p;cin>>c>>p;
        cout<<ans[c - 'a'][p]<<endl;
    }
    return 0;
}