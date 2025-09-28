#include<iostream>
#include<vector>
using namespace std;
const int N = 200005;
vector<int> arr(N);
vector<int> e[N];
//0
bool dfs(int i,int fa,int end,int &ans){
    if(i==end){
        ans |= 1<<arr[i];
        return true;
    }
    for(int &d:e[i]){
        if(d!=fa){
            int temp = ans;
            ans |= 1<<arr[i];
            if(dfs(d,i,end,ans)) return true;
            ans = temp;
        }
    }
    return false;
}
int main(){
    int n,m;cin>>n>>m;
    for(int i = 1;i<=n;i++) cin>>arr[i];
    for(int i = 0;i<n-1;i++){
        int x,y;cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    vector<int> arr;
    while(m--){
        int b,end;cin>>b>>end;
        int ans = 0;
        ans |= 1<<arr[b];
        if(dfs(b,0,end,ans)){
            for(int i = 0;i<32;i++){
                if((ans&(1<<i))==0){
                    cout<<i;
                    break;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}