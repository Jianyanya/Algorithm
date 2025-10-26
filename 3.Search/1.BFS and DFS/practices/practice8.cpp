//poj-1426-Find The Multiple,题目链接<http://poj.org/problem?id=1426>
#include <iostream>
#include <cstdlib>
#include <vector>
#include<algorithm>
#include <cmath>
#include <fstream>
#include<cstring>
#include<climits>
#include<queue>
using namespace std;
long long n;
long long bfs(){
    queue<long long> q;
    q.push(1);
    while(!q.empty()){
                long long num = q.front();q.pop();
                if(num%n==0) return num;
                if(num>1111111111111111110LL) continue;
                q.push(num*10);
                q.push(num*10+1);
        }
        return -1;
}
/*
1
10 11
100 101 110 111
1000 1001 1010 1011 1100 1101 1110 1111
*/
int main() {
    while(cin>>n&&n) cout<<bfs()<<endl;
    return 0;
}