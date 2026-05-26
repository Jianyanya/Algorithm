//https://www.luogu.com.cn/problem/P1347
/*
这个题要输出第几次排序完成或出现矛盾,出现矛盾好判断,直接用邻接矩阵存边就行
但是怎么判断成功呢,这看起来像是要边输入边,边查询啊,确实如此
因为题目数据量极小,所以我们可以用暴力的手段实现,每次输入边都跑一次拓扑排序判断就行了,我们可以用二分答案的方式优化暴力
但是这里给出最优解法,就是Pearce-Kelly简称(PK算法),仅理解即可,不需要掌握
对于这个题使用pk算法实在不划算,因为数据太小了
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    vector<pair<int,int>> rel(m+1);
    for(int i=1;i<=m;i++){
        string s;
        cin>>s;
        int u=s[0]-'A';
        int v=s[2]-'A';
        rel[i]={u,v};
    }
    
    vector<vector<int>> g(n),rg(n);
    vector<vector<int>> has(n,vector<int>(n,0));
    vector<int> ord(n),pos(n);

    for(int i=0;i<n;i++){
        ord[i]=i;
        pos[i]=i;
    }
    auto rebuildPos = [&](){
        for(int i=0;i<n;i++){
            pos[ord[i]]=i;
        }
    };
    auto insertEdge = [&](int u,int v) -> bool {
        if(has[u][v]) return true;
        has[u][v]=1;
        g[u].push_back(v);
        rg[v].push_back(u);
        if(pos[u]<pos[v]) return true;
        int L=pos[v], R=pos[u];
        vector<int> inF(n,0),inB(n,0);
        vector<int> F,B;
        queue<int> q;
        q.push(v);
        inF[v]=1;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            F.push_back(x);
            for(int y:g[x]){
                if(pos[y]>R) continue;
                if(inF[y]) continue;
                inF[y]=1;
                q.push(y);
            }
        }
        q.push(u);
        inB[u]=1;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            B.push_back(x);
            for(int y:rg[x]){
                if(pos[y]<L) continue;
                if(inB[y]) continue;
                inB[y]=1;
                q.push(y);
            }
        }
        for(int i=0;i<n;i++){
            if(inF[i]&&inB[i]){
                return false;
            }
        }
        vector<int> nb,nf,mid;
        for(int i=L;i<=R;i++){
            int x=ord[i];
            if(inB[x]) nb.push_back(x);
            else if(inF[x]) nf.push_back(x);
            else mid.push_back(x);
        }
        int p=L;
        for(int x:nb) ord[p++]=x;
        for(int x:mid) ord[p++]=x;
        for(int x:nf) ord[p++]=x;
        rebuildPos();
        return true;
    };
    auto uniqueTopo = [&]() -> bool {
        for(int i=0;i+1<n;i++){
            if(!has[ord[i]][ord[i+1]]) return false;
        }
        return true;
    };
    for(int i=1;i<=m;i++){
        auto [u,v]=rel[i];
        if(!insertEdge(u,v)){
            cout<<"Inconsistency found after "<<i<<" relations."<<endl;
            return 0;
        }
        if(uniqueTopo()){
            cout<<"Sorted sequence determined after "<<i<<" relations: ";
            for(int x:ord){
                cout<<char('A'+x);
            }
            cout<<"."<<endl;
            return 0;
        }
    }
    cout<<"Sorted sequence cannot be determined."<<endl;
    return 0;
}