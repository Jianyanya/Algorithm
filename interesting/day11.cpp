#include<bits/stdc++.h>
using namespace std;

const int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    int y1 = 2239,m1 = 9,d1 = 9;
    int y2 = 9876,m2 = 1,d2 = 1;
    int mx = 0;
    auto run = [&](int y) -> bool {
        if(y%400==0||y%4==0) return true;
        else return false;
    };
    auto check = [&](int y,int m,int d) -> bool {
        vector<int> cnt(10,0);
        while(y>0){
            int p = y%10;
            cnt[p]++;
            y /= 10;
        }
        while(m>0){
            int p = m%10;
            cnt[p]++;
            m /= 10;
        }
        while(d>0){
            int p = d%10;
            cnt[p]++;
            d /= 10;
        }
        int ans = -1;
        for(int i = 0;i<10;i++){
            if(ans==-1&&cnt[i]!=0) ans = cnt[i];
            if(ans!=-1&&cnt[i]!=0&&ans!=cnt[i]) return false;
        }
        return true;
    };
    if(check(y2,m2,d2)) mx++;
    for(int d = 9;d<=month[9];d++){
        if(check(y1,m1,d)) mx++;
    }
    for(int m = 10;m<=12;m++){
        for(int d = 1;d<=month[m];d++){
            if(check(y1,m,d)) mx++;
        }
    }
    for(int y = y1+1;y<y2;y++){
        for(int m = 1;m<=12;m++){
            for(int d = 1;d<=month[m] + (run(y)&&m==2);d++){
                if(check(y,m,d)) mx++;
            }
        }
    }
    cout<<mx;
    return 0;
}