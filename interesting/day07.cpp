#include <bits/stdc++.h>
using namespace std;
#define fo(i,l,r) for(int i=(l);i<=(r);++i)
#define ve vector
#define endl '\n'
using ll = long long;

int T,n,d;
ve<ve<int>> g;
using Arr = array<ll,4>;

ve<ve<Arr>> dp;
ll threeLeaf;

void dfs(int u,int fa){
    ve<Arr> no(2),has(2);
    ve<Arr> t0(2),t1(2),t2(2);

    no[1][1]=1;   // 和父亲相连，且没有选儿子，则 u 是叶子
    t0[1][0]=1;   // 作为最高点，单点没有叶子

    for(int v:g[u]){
        if(v==fa) continue;
        dfs(v,u);

        ve<tuple<int,int,ll>> child;
        fo(sz,1,(int)dp[v].size()-1){
            fo(le,0,3){
                if(dp[v][sz][le]){
                    child.push_back({sz,le,dp[v][sz][le]});
                }
            }
        }

        int old=(int)no.size()-1;
        int lim=min(d,old+(int)dp[v].size()-1);

        ve<Arr> nno=no,nhas=has;
        ve<Arr> nt0=t0,nt1=t1,nt2=t2;

        nno.resize(lim+1);
        nhas.resize(lim+1);
        nt0.resize(lim+1);
        nt1.resize(lim+1);
        nt2.resize(lim+1);

        fo(sz,1,old){
            fo(le,0,3){
                if(no[sz][le]){
                    for(auto [cs,cl,val]:child){
                        if(sz+cs>d) continue;
                        int nl=le+cl-1;
                        if(0<=nl&&nl<=3) nhas[sz+cs][nl]+=no[sz][le]*val;
                    }
                }

                if(has[sz][le]){
                    for(auto [cs,cl,val]:child){
                        if(sz+cs>d) continue;
                        int nl=le+cl;
                        if(nl<=3) nhas[sz+cs][nl]+=has[sz][le]*val;
                    }
                }

                if(t0[sz][le]){
                    for(auto [cs,cl,val]:child){
                        if(sz+cs>d) continue;
                        int nl=le+cl+1;
                        if(nl<=3) nt1[sz+cs][nl]+=t0[sz][le]*val;
                    }
                }

                if(t1[sz][le]){
                    for(auto [cs,cl,val]:child){
                        if(sz+cs>d) continue;
                        int nl=le+cl-1;
                        if(0<=nl&&nl<=3) nt2[sz+cs][nl]+=t1[sz][le]*val;
                    }
                }

                if(t2[sz][le]){
                    for(auto [cs,cl,val]:child){
                        if(sz+cs>d) continue;
                        int nl=le+cl;
                        if(nl<=3) nt2[sz+cs][nl]+=t2[sz][le]*val;
                    }
                }
            }
        }

        no.swap(nno);
        has.swap(nhas);
        t0.swap(nt0);
        t1.swap(nt1);
        t2.swap(nt2);
    }

    if((int)t0.size()>d){
        threeLeaf+=t0[d][3]+t1[d][3]+t2[d][3];
    }

    int lim=(int)no.size()-1;
    dp[u].assign(lim+1,Arr{});
    fo(sz,1,lim){
        fo(le,0,3){
            dp[u][sz][le]=no[sz][le]+has[sz][le];
        }
    }
}

ll pathCnt;
void getDist(int u,int fa,int dep,int src){
    if(dep==d-1){
        if(u>src) pathCnt++;
        return;
    }
    for(int v:g[u]){
        if(v!=fa) getDist(v,u,dep+1,src);
    }
}

void jianyanya(){
    cin>>n>>d;

    g.assign(n+1,{});
    fo(i,1,n-1){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    pathCnt=0;
    fo(i,1,n){
        getDist(i,0,0,i);
    }

    dp.assign(n+1,{});
    threeLeaf=0;
    dfs(1,0);

    ll ans=pathCnt*(d-2)+threeLeaf;
    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--) jianyanya();
}