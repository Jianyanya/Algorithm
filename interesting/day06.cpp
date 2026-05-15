//https://www.luogu.com.cn/problem/P4447
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;cin>>n;
    map<int,int> mp;
    for(int i = 0;i<n;i++){
        int p;cin>>p;
        mp[p]++;
    }
    int ans = INT_MAX;
        while(!mp.empty()){
            auto i = mp.begin(),j = mp.begin();
            j++;
            --(*i).second;
            int len = 1;
            for(;j!=mp.end() && (*j).first == (*i).first + 1 && (*j).second > (*i).second;++i,++j){
                len++;
                --(*j).second;
            }
            i = mp.begin();
            while(i != mp.end() && (*i).second == 0) mp.erase((*i++).first);
            if(len < ans) ans = len;
        }
    cout<<ans;
    return 0;
}